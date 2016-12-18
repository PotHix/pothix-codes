macro_rules! sum {
    ($a: ident,
     $b: expr,
     $($x: expr), *) => {
        let $a = {
            let mut temp = $b;
            $(
                temp = temp + $x;
            )*
            temp
        };
    }
}

fn main() {
    sum!(x, 1, 2, 3, 4, 5, 6, 7);
    println!("{}", x);

    sum!(x, 1.3, 2.4, 3.1, 4.98);
    println!("{}", x);
}
