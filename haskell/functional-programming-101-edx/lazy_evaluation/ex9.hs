data Tree a = Leaf | Node (Tree a) a (Tree a)
repeat :: a -> [a]
repeat x = xs
    where xs = x : xs

-- repeatTreea :: a -> Tree a
-- repeatTreea x = Node x x x

repeatTreeb :: a -> Tree a
repeatTreeb x = Node t x t
    where t = repeatTreeb x

-- repeatTreec :: a -> Tree a
-- repeatTreec x = repeatTreec (Node Leaf x Leaf)

-- repeatTreed :: a -> Tree a
-- repeatTreed x = Node t x t
--     where t = repeatTreed (Node t x t)
