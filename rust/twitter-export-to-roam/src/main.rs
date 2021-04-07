use serde::{Deserialize, Serialize};
use std::error::Error;
use std::fs;
use std::io;
use std::process;

#[derive(Debug, Deserialize)]
struct Tweet {
    timestamp: String,
    tweet: String,
}

#[derive(Serialize)]
struct RoamDaily {
    title: String,
    children: Vec<RoamLine>,
}

#[derive(Serialize)]
struct RoamLine {
    string: String,
}

fn transform() -> Result<(), Box<dyn Error>> {
    let mut reader = csv::Reader::from_reader(io::stdin());
    for result in reader.deserialize() {
        let tweet: Tweet = result?;

        let mut lines = Vec::new();
        lines.push(RoamLine {
            string: tweet.tweet.clone(),
        });

        let daily = RoamDaily {
            title: tweet.timestamp.clone(),
            children: lines,
        };

        let mut filename = "/tmp/".to_string();
        filename.push_str("April 4th, 2001");
        filename.push_str(".md");

        let content = serde_json::to_string(&daily).unwrap();
        println!("{}", content);

        fs::write(filename.as_str().to_lowercase(), content.as_bytes())
            .expect("could not write to the markdown file");
    }
    Ok(())
}

fn main() {
    if let Err(err) = transform() {
        println!("error running the transform function: {}", err);
        process::exit(1);
    }
}
