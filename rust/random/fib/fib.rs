const NUMBER: u64 = 40;

fn fib(n:u64) -> u64 {
  if n <= 1 { return n }
  return fib(n-1) + fib(n-2);
}

fn main() {
  println!("fibonacci from {} is {}", NUMBER, fib(NUMBER))
}
