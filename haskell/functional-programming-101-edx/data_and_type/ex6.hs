data Tree = Leaf Integer | Node Tree Tree

bbt :: Tree
bbt = Node (Node (Leaf 1) (Leaf 4)) (Node (Leaf 6) (Leaf 9))

ubt :: Tree
ubt = Node (Node (Leaf 4) (Leaf 1)) (Node (Leaf 6) (Node (Leaf 1) (Node (Leaf 0) (Leaf 1))))

leavesd (Leaf _) = 1
leavesd (Node l r) = leavesd l + leavesd r
balancedd :: Tree -> Bool
balancedd (Leaf _) = True
balancedd (Node l r) = abs (leavesd l - leavesd r) <= 1 && balancedd l && balancedd r

halvea xs = splitAt (length xs `div` 2) xs
balancea :: [Integer] -> Tree
balancea [x] = Leaf x
balancea xs = Node (balancea ys) (balancea zs)
    where (ys, zs) = halvea xs

-- halveb xs = splitAt (length xs / 2) xs
-- balanceb :: [Integer] -> Tree
-- balanceb [x] = Leaf x
-- balanceb xs = Node (balanceb ys) (balanceb zs)
--     where (ys, zs) = halveb xs

-- halvec xs = splitAt (length xs `div` 2) xs
-- balancec :: [Integer] -> Tree
-- balancec [x] = Leaf x
-- balancec xs = Node ys zs
--     where (ys, zs) = balancec (halvec xs)

-- halved xs = splitAt (length xs `div` 2) xs
-- balanced :: [Integer] -> Tree
-- balanced x = Leaf x
-- balanced xs = Node (balanced ys) (balanced zs)
--     where (ys, zs) = halved xs
