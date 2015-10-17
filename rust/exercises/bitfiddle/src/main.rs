#[cfg(not(test))]
fn main() {
    println!("Hello, world!");
}

// Define is_power_of_two here, so that test_is_power_of_two passes.

fn is_power_of_two(n: u64) -> bool {
    n != 0 && (n - 1) & n == 0
}

#[test]
fn test_is_power_of_two() {
    assert!(!is_power_of_two(0u64));
    assert!( is_power_of_two(1));
    assert!( is_power_of_two(2));
    assert!(!is_power_of_two(3));
    assert!( is_power_of_two(4));
    assert!(!is_power_of_two(5));
    assert!(!is_power_of_two(6));
    assert!(!is_power_of_two(7));
    assert!( is_power_of_two(8));
}

// Then, delete the #[cfg(skip)] above test_floor_log2, and define floor_log2
// here so as to make it pass.

fn floor_log2(n: u64) -> u64 {
    1
}

#[test]
fn test_floor_log2() {
    assert_eq!(floor_log2(1u64), 0);
    assert_eq!(floor_log2(2), 1);
    assert_eq!(floor_log2(3), 1);
    assert_eq!(floor_log2(4), 2);
    assert_eq!(floor_log2(5), 2);
    assert_eq!(floor_log2(7), 2);
    assert_eq!(floor_log2(8), 3);
    assert_eq!(floor_log2(9), 3);

    assert_eq!(floor_log2(255), 7);
    assert_eq!(floor_log2(256), 8);

    assert_eq!(floor_log2((1 << 16) - 1), 15);
    assert_eq!(floor_log2(1 << 16), 16);
    assert_eq!(floor_log2((1 << 16) + 1), 16);

    assert_eq!(floor_log2((1 << 32) - 1), 31);
    assert_eq!(floor_log2(1 << 32), 32);
    assert_eq!(floor_log2((1 << 32) + 1), 32);

    assert_eq!(floor_log2((1 << 48) - 1), 47);
    assert_eq!(floor_log2(1 << 48), 48);
    assert_eq!(floor_log2((1 << 48) + 1), 48);

    assert_eq!(floor_log2((1 << 63) - 1), 62);
    assert_eq!(floor_log2(1 << 63), 63);
    assert_eq!(floor_log2((1 << 63) + 1), 63);
}
