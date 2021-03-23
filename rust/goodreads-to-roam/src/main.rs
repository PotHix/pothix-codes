use std::error::Error;
use std::io;
use std::process;

use serde::Deserialize;

use std::fs::OpenOptions;
use std::io::Write;

#[derive(Debug, Deserialize)]
struct Record {
    title: String,
    author: String,
    rating: u8,
    dateread: String,
    review: String,
}

fn example() -> Result<(), Box<dyn Error>> {
    let mut rdr = csv::Reader::from_reader(io::stdin());
    for result in rdr.deserialize() {
        let record: Record = result?;
        let mut markdown = String::new();

        markdown.push_str("+++\n");
        markdown.push_str("title = \"");
        markdown.push_str(record.title.as_str());
        markdown.push_str("\"\n");
        markdown.push_str("date = ");
        markdown.push_str(record.dateread.as_str());
        markdown.push_str("\"\n");
        markdown.push_str("tags = [\n");
        markdown.push_str("    \"english\",\n");
        markdown.push_str("    \"books\",\n");
        markdown.push_str("]\n");
        markdown.push_str("+++\n\n");

        markdown.push_str("Book: [");
        markdown.push_str(record.title.as_str());
        markdown.push_str("](https://www.goodreads.com/review/) by ");
        markdown.push_str(record.author.as_str());
        markdown.push_str(". Rating: ");
        for _ in 0..record.rating {
            markdown.push_str("⭐️");
        }
        markdown.push_str(".\n\n");
        markdown.push_str(record.review.as_str());

        OpenOptions::new()
            .write(true)
            .create(true)
            .append(true)
            .open("/tmp/cegela")?
            .write_all(markdown.as_bytes())
            .expect("could not write to the markdown file");

        println!("{:?}", record);
    }
    Ok(())
}

fn main() {
    if let Err(err) = example() {
        println!("error running example: {}", err);
        process::exit(1);
    }
}
