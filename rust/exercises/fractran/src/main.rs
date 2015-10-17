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

fn floor_log2(mut n: u64) -> u64 {
    let mut l = 0;
    while n > 1 {
        n = n >> 1;
        l = l + 1;
    }

    l
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

// The type of the vector argument to step should be: &Vec<(u64, u64)>.
// This passes the vector by reference, not value.

fn step(vs: &Vec<(u64, u64)>, n: u64) -> Option<u64> {
    for v in vs {
        if n % v.1 == 0 {
            return Some(n / v.1 * v.0)
        }
    }
    return None
}

#[test]
fn test_step() {
    assert_eq!(step(&vec![], 0), None);
    assert_eq!(step(&vec![(1,1)], 0), Some(0));
    assert_eq!(step(&vec![(1,2)], 1), None);
    assert_eq!(step(&vec![(3,2)], 2), Some(3));
    assert_eq!(step(&vec![(3,2), (2,45)], 27 * 25), Some(2 * 3 * 5));
    assert_eq!(step(&vec![(3,2), (2,45)], 11), None);
}

// Finally, delete the #[cfg(skip)] over main, and implement a 'run' function
// analogous to the one in model.py.

fn run(fs: &Vec<(u64, u64)>, mut n: u64, limit: u64) {
    for _ in 0..limit {
        match step(fs, n) {
            None    => { return }
            Some(x) => {
                n = x;
                if is_power_of_two(n) {
                    println!("**** {}", floor_log2(n));
                }
            }
        }
    }
}

fn main() {
    // Each pair (n, d) represents the fraction n/d.
    // These fractions are all in lowest terms.
    let v = vec![(17, 91),
             (78, 85),
             (19, 51),
             (23, 38),
             (29, 33),
             (77, 29),
             (95, 23),
             (77, 19),
             (1, 17),
             (11, 13),
             (13, 11),
             (15, 14),
             (15, 2),
             (55, 1)];

    run(&v, 2, 2500);
}
