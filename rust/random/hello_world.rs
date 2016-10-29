use std::io;

fn main() {
    let greeting = "Hello,";
    let mut name = String::new();

    io::stdin().read_line(&mut name).expect("Digite seu nome.");
    println!("{} {}", greeting, name);
}
