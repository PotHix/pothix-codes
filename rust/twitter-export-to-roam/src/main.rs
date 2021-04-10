use serde::{Deserialize, Serialize};
use std::error::Error;
use std::io;
use std::process;

use chrono::prelude::*;
use chrono::Local;
use std::time::{Duration, UNIX_EPOCH};

#[derive(Debug, Deserialize)]
struct Tweet {
    timestamp: u64,
    tweet: String,
}

#[derive(Serialize, Clone)]
struct RoamDaily {
    // must be on the lines of "April 1st, 2021"
    title: String,
    children: Vec<RoamLine>,
}

#[derive(Serialize, Clone)]
struct RoamLine {
    // must follow the structure: "12:13 Working on my stuff #tweet"
    string: String,
}

fn transform() -> Result<(), Box<dyn Error>> {
    let mut reader = csv::Reader::from_reader(io::stdin());

    let mut current_day = 0;
    let mut alldays = Vec::<RoamDaily>::new();

    let mut daily = RoamDaily {
        title: String::from(""),
        children: Vec::new(),
    };

    for result in reader.deserialize() {
        let tweet: Tweet = result?;

        let d = UNIX_EPOCH + Duration::from_secs(tweet.timestamp);
        let datetime = DateTime::<Local>::from(d);

        let strftime_string = match datetime.day() {
            1 => "%B %dst, %Y",
            2 => "%B %dnd, %Y",
            3 => "%B %drd, %Y",
            21 => "%B %dst, %Y",
            22 => "%B %dnd, %Y",
            23 => "%B %drd, %Y",
            31 => "%B %dst, %Y",
            _ => "%B %dth, %Y",
        };

        if current_day != 0 && current_day != datetime.day() {
            alldays.push(daily.clone());
            daily.children = Vec::new();
        }

        daily.title = datetime.format(strftime_string).to_string();

        let mut tweetcontent = datetime.format("%H:%M ").to_string();
        tweetcontent.push_str(tweet.tweet.clone().replace("#-#", ",").as_str());
        tweetcontent.push_str(" #tweet");

        daily.children.push(RoamLine {
            string: tweetcontent,
        });

        current_day = datetime.day();
    }

    let content = serde_json::to_string(&alldays).unwrap();
    println!("{}", content);

    Ok(())
}

fn main() {
    if let Err(err) = transform() {
        println!("error running the transform function: {}", err);
        process::exit(1);
    }
}
