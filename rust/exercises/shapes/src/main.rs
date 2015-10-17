#![allow(dead_code)]

trait Shape {
    // Return true if this shape contains the given point.
    fn contains(&self, pt: (f32, f32)) -> bool;
}

#[derive(Debug)]
struct Circle {
    center: (f32, f32),
    radius: f32
}

struct Rect {
    ll: (f32, f32),
    ur: (f32, f32)
}

impl Shape for Circle {
    fn contains(&self, pt: (f32, f32)) -> bool {
        let dist = (pt.0 - self.center.0,
                    pt.1 - self.center.1);
        let len_squared = dist.0 * dist.0 +
                          dist.1 * dist.1;
        //println!("{:?}.contains({:?}), dist = {:?}, len_squared = {}",
        //         self, pt, dist, len_squared);
        return len_squared <= self.radius * self.radius;
    }
}

impl Shape for Rect {
    fn contains(&self, pt: (f32, f32)) -> bool {
       if (pt.0 >= self.ll.0 && pt.1 >= self.ll.1) && (pt.0 <= self.ur.0 && pt.1 <= self.ur.1) {
           return true
       }

       return false
    }
}

#[test]
fn test_circle() {
    assert!( Circle { center: (3., 3.), radius: 5. }.contains(( 3.,  3.)));
    assert!( Circle { center: (3., 3.), radius: 5. }.contains((-1.,  0.)));
    assert!( Circle { center: (3., 3.), radius: 5. }.contains(( 0., -1.)));
    assert!( Circle { center: (3., 3.), radius: 5. }.contains(( 6.,  7.)));
    assert!( Circle { center: (3., 3.), radius: 5. }.contains(( 7.,  6.)));

    assert!(!Circle { center: (3., 3.), radius: 5. }.contains(( 0., -1.5)));
    assert!(!Circle { center: (3., 3.), radius: 5. }.contains(( 7.,  6.5)));
}

// Define struct Rect here, and implement Shape for it. Then remove the
// #[cfg(skip)] above test_rect and test_union and use 'cargo test' to test it.

#[test]
fn test_rect() {
    assert!( Rect { ll: (2.,2.), ur: (4., 5.) }.contains((2., 2.)));
    assert!( Rect { ll: (2.,2.), ur: (4., 5.) }.contains((2., 5.)));
    assert!( Rect { ll: (2.,2.), ur: (4., 5.) }.contains((4., 5.)));
    assert!( Rect { ll: (2.,2.), ur: (4., 5.) }.contains((4., 2.)));

    assert!(!Rect { ll: (2.,2.), ur: (4., 5.) }.contains((1., 3.)));
    assert!(!Rect { ll: (2.,2.), ur: (4., 5.) }.contains((3., 1.)));
    assert!(!Rect { ll: (2.,2.), ur: (4., 5.) }.contains((5., 3.)));
    assert!(!Rect { ll: (2.,2.), ur: (4., 5.) }.contains((3., 6.)));
}

struct Union {
    s1: Box<Shape>,
    s2: Box<Shape>
}

impl Shape for Union {
    fn contains(&self, pt: (f32, f32)) -> bool {
        return self.s1.contains(pt) || self.s2.contains(pt);
    }
}

#[test]
fn test_union() {
    let c = Circle { center: (0., 2.), radius: 2. };
    let r = Rect { ll: (-2., 0.), ur: (2., 2.) };

    let u = Union { s1: Box::new(c),
                    s2: Box::new(r) };

    assert!( u.contains(( 0.,  0.)));
    assert!( u.contains(( 0.,  4.)));
    assert!( u.contains((-2.,  0.)));
    assert!( u.contains(( 2.,  0.)));
    assert!( u.contains((-2.,  2.)));
    assert!( u.contains(( 2.,  2.)));

    assert!(!u.contains((-2.,  4.)));
    assert!(!u.contains(( 2.,  4.)));
    assert!(!u.contains((-3.,  0.)));
    assert!(!u.contains(( 0., -1.)));
}

// Define struct Complement here, and implement Shape for it. Then remove the
// #[cfg(skip)] above test_rect and use 'cargo test' to test it.

struct Complement {
    s: Box<Shape>
}

impl Shape for Complement {
    fn contains(&self, pt: (f32, f32)) -> bool {
        !self.s.contains(pt)
    }
}

#[test]
fn test_complement() {
    let c = Circle { center: (0., 2.), radius: 2. };
    let r = Rect { ll: (-2., 0.), ur: (2., 2.) };

    let u = Union { s1: Box::new(c),
                    s2: Box::new(r) };
    let n = Complement { s: Box::new(u) };

    assert!(!n.contains(( 0.,  0.)));
    assert!(!n.contains(( 0.,  4.)));
    assert!(!n.contains((-2.,  0.)));
    assert!(!n.contains(( 2.,  0.)));
    assert!(!n.contains((-2.,  2.)));
    assert!(!n.contains(( 2.,  2.)));

    assert!( n.contains((-2.,  4.)));
    assert!( n.contains(( 2.,  4.)));
    assert!( n.contains((-3.,  0.)));
    assert!( n.contains(( 0., -1.)));
}

// Remove the #[cfg(skip)] above these dummy definitions, fill them in,
// and then Remove the #[cfg(skip)] above test_difference to test it.

#[cfg(skip)]
fn intersection(s1: Box<Shape>, s2: Box<Shape>) -> Box<Shape> {
    // ...
}

#[cfg(skip)]
fn difference(has: Box<Shape>, hasnot: Box<Shape>) -> Box<Shape> {
    // ...
}

#[cfg(skip)]
#[test]
fn test_difference() {
    let c = Circle { center: (0., 2.), radius: 2. };
    let r = Rect { ll: (-2., 0.), ur: (2., 2.) };

    let d = difference(Box::new(r), Box::new(c) );

    assert!(!d.contains(( 0.,  0.)));
    assert!(!d.contains(( 0.,  4.)));
    assert!( d.contains((-2.,  0.)));
    assert!( d.contains(( 2.,  0.)));
    assert!( d.contains((-2.,  1.)));
    assert!( d.contains(( 2.,  1.)));

    assert!(!d.contains((-2.,  4.)));
    assert!(!d.contains(( 2.,  4.)));
    assert!(!d.contains((-3.,  0.)));
    assert!(!d.contains(( 0., -1.)));
}

// Once you've gotten all the tests passing, comment out the #[cfg(skip)] above
// this `main` function, and delete the trivial one below. Use 'cargo run' to
// run it!
#[cfg(skip)]
fn main() {
    let ring1 = difference(Box::new(Circle { center: (16., 24.), radius: 12.}),
                           Box::new(Circle { center: (16., 24.), radius: 4.}));
    let ring2 = difference(Box::new(Circle { center: (16., 4.), radius: 16.}),
                           Box::new(Circle { center: (16., 4.), radius: 8.}));
    let rings = Box::new(Union { s1: ring1, s2: ring2 });
    let right = intersection(Box::new(Rect { ll: (16., 4.), ur: (40., 40.) }),
                             rings);
    let left = Box::new(Rect { ll: (8., 4.), ur: (16., 36.) });
    let shape = Box::new(Union { s1: left, s2: right });

    for line in 0..40 {
        for column in 0..39 {
            if shape.contains((column as f32 + 0.5,
                               (40 - line) as f32 + 0.5)) {
                print!("##");
            } else {
                print!("  ");
            }
        }
        println!("");
    }
}

fn main() {
    println!("Hi!");
}
