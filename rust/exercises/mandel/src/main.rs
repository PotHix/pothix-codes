// EXERCISE: Change main so that it spawns a different thread to compute each line.
// This should run fine without modification (albiet in a single thread), so you
// can start from a known good point.

// Compute z*z + c, treating z and c as complex numbers.
fn step(c: (f64, f64), z: (f64, f64)) -> (f64, f64) {
    let z_squared = (z.0 * z.0 - z.1 * z.1,
                     2. * z.0 * z.1);
    (z_squared.0 + c.0, z_squared.1 + c.1)
}

// Count how many iterations it takes c to escape from the circle of radius 2
// centered at the origin. Try at most limit iterations.
fn count(c: (f64, f64), limit: usize) -> usize {
    let mut z = (0., 0.);
    for i in 0..limit {
        if z.0 * z.0 + z.1 * z.1 >= 4. {
            return i;
        }
        z = step(c, z);
    }
    return limit;
}

fn main() {
    let limit = 1000;

    for line in 0..40 {
        let mut output = String::new();
        for col in 0..80 {
            let c = ((col - 60) as f64 * 0.04,
                     (line - 20) as f64 * 0.07);
            if count(c, limit) == limit {
                output.push('#');
            } else {
                output.push(' ');
            }
        }
        println!("{}", output);
    }
}
