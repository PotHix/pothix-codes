fn main() {
  let a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
  let b = &a[..];
  let c = &a[3..5];

  println!("a has {} elements", a.len());
  println!("b has {} elements", b.len());
  println!("c has {} elements", c.len());
}
