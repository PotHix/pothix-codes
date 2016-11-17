fn sum(a: i32, b: i32) -> i32 {
  a + b
}

fn main() {
  // a heart
  let a: char = '\u{2764}';
  println!("{}", a);

  let x = 3;
  let y = 5;
  println!("{} + {} = {}", x, y, sum(x, y));
}
