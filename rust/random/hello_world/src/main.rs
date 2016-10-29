extern crate time;

fn main() {
    let d = time::now();
    println!("Today is {}/{}/{}", d.tm_mday, d.tm_mon, d.tm_year + 1900);
}
