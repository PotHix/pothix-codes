uncurrya :: (a -> b -> c) -> (a, b) -> c
uncurrya f = \(x, y) -> f x y

--uncurryb :: (a -> b -> c) -> (a, b) -> c
uncurryb f = \x y -> f (x, y)

--uncurryc :: (a -> b -> c) -> (a, b) -> c
uncurryc f = \(x, y) -> f

--uncurryd :: (a -> b -> c) -> (a, b) -> c
uncurryd f = \x y -> f
