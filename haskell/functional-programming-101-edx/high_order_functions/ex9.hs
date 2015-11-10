--currya :: ((a, b) -> c) -> a -> b -> c
currya f = \x y -> f x y

--curryb :: ((a, b) -> c) -> a -> b -> c
curryb f = \x y -> f

curryc :: ((a, b) -> c) -> a -> b -> c
curryc f = \x y -> f (x,y)

--curryd :: ((a, b) -> c) -> a -> b -> c
curryd f = \(x, y) -> f x y
