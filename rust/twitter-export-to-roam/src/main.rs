use serde::{Deserialize, Serialize};
use std::error::Error;
use std::io;
use std::process;

use chrono::prelude::DateTime;
use chrono::Local;
use std::time::{Duration, UNIX_EPOCH};

#[derive(Debug, Deserialize)]
struct Tweet {
    timestamp: u64,
    tweet: String,
}

#[derive(Serialize)]
struct RoamDaily {
    // must be on the lines of "April 1st, 2021"
    title: String,
    children: Vec<RoamLine>,
}

#[derive(Serialize)]
struct RoamLine {
    // must follow the structure: "12:13 Working on my stuff #tweet"
    string: String,
}

fn transform() -> Result<(), Box<dyn Error>> {
    let mut reader = csv::Reader::from_reader(io::stdin());
    for result in reader.deserialize() {
        let tweet: Tweet = result?;

        let d = UNIX_EPOCH + Duration::from_secs(tweet.timestamp);
        let datetime = DateTime::<Local>::from(d);

        let strftime_string = "%B %dth %Y";
        /*
        let strftime_string = match datetime.day() {
            1 => "%B %dst, %Y",
            2 => "%B %dnd, %Y",
            3 => "%B %drd, %Y",
            21 => "%B %dst, %Y",
            22 => "%B %dnd, %Y",
            23 => "%B %drd, %Y",
            31 => "%B %dst, %Y",
            _ => "%B %dth %Y",
        };
        */

        let mut lines = Vec::new();
        lines.push(RoamLine {
            string: tweet.tweet.clone(),
        });

        let daily = RoamDaily {
            title: datetime.format(strftime_string).to_string(), //tweet.timestamp.clone(),
            children: lines,
        };

        let content = serde_json::to_string(&daily).unwrap();
        println!("{}", content);
    }
    Ok(())
}

fn main() {
    if let Err(err) = transform() {
        println!("error running the transform function: {}", err);
        process::exit(1);
    }
}
