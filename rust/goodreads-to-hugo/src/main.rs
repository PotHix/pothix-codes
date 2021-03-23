use std::error::Error;
use std::io;
use std::process;

use serde::Deserialize;

use html2text::from_read;
use std::fs;

#[derive(Debug, Deserialize)]
struct Record {
    id: String,
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

        let mut filename = "/tmp/".to_string();
        filename.push_str(record.title.replace(" ", "_").as_str());
        filename.push_str(".md");

        markdown.push_str("+++\n");
        markdown.push_str("title = \"");
        markdown.push_str(record.title.as_str());
        markdown.push_str("\"\n");
        markdown.push_str("date = ");
        markdown.push_str(record.dateread.replace("/", "-").as_str());
        markdown.push_str("\n");
        markdown.push_str("tags = [\n");
        markdown.push_str("    \"english\",\n");
        markdown.push_str("    \"books\",\n");
        markdown.push_str("]\n");
        markdown.push_str("+++\n\n");

        markdown.push_str("Book: [");
        markdown.push_str(record.title.as_str());
        markdown.push_str("](https://www.goodreads.com/book/show/");
        markdown.push_str(record.id.as_str());
        markdown.push_str(") by ");
        markdown.push_str(record.author.as_str());
        markdown.push_str(". Rating: ");
        for _ in 0..record.rating {
            markdown.push_str("⭐️");
        }
        markdown.push_str(".\n\n");
        markdown.push_str(from_read(record.review.as_bytes(), 9000).as_str());

        fs::write(filename.as_str().to_lowercase(), markdown.as_bytes())
            .expect("could not write to the markdown file");
    }
    Ok(())
}

fn main() {
    if let Err(err) = example() {
        println!("error running example: {}", err);
        process::exit(1);
    }
}
