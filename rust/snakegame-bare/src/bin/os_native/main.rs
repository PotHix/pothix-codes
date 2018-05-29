extern crate snakegamelib;

mod os_resources;
use snakegamelib::print;

pub fn main() {
    println!("Game binary should run here!");
    print();
    os_resources::print_native();
}
