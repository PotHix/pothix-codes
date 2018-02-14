// At the moment I'm in the airplane flying, reading the book and
// using this file to try the examples
fn main() {
    let tuple = ("Brazil", 1988);
    assert_eq!(tuple.0, "Brazil");
    assert_eq!(tuple.1, 1988);

    let mut array = [5,4,3,2,1];
    array.sort();
    assert_eq!(array, [1,2,3,4,5]);

    let v: Vec<i32> = (0..5).collect();
    assert_eq!(v, [0,1,2,3,4]);

    let mut vec = vec!["pothix", "rust"];
    assert_eq!(vec.pop(), Some("rust"));
    assert_eq!(vec.pop(), Some("pothix"));
    assert_eq!(vec.pop(), None);

    let bits = vec!["veni", "vidi", "vici"];
    assert_eq!(bits.concat(), "venividivici");
    assert_eq!(bits.join(", "), "veni, vidi, vici");
}
