data Tree = Leaf Integer | Node Tree Tree

bbt :: Tree
bbt = Node (Node (Leaf 1) (Leaf 4)) (Node (Leaf 6) (Leaf 9))

ubt :: Tree
ubt = Node (Node (Leaf 4) (Leaf 1)) (Node (Leaf 6) (Node (Leaf 1) (Node (Leaf 0) (Leaf 1))))

-- leavesa (Leaf x) = x
-- leavesa (Node l r) = leavesa l + leavesa r
-- balanceda :: Tree -> Bool
-- balanceda (Leaf _) = True
-- balanceda (Node l r) = abs (leavesa l - leavesa r) <= 1 || balanceda l || balanceda r

-- leavesb (Leaf _) = True
-- leavesb (Node l r) = leavesb l + leavesb r
-- balancedb :: Tree -> Bool
-- balancedb (Leaf _) = True
-- balancedb (Node l r) = abs (leavesb l - leavesb r) <= 1

-- leavesc (Leaf _) = True
-- leavesc (Node l r) = leavesc l + leavesc r
-- balancedc :: Tree -> Bool
-- balancedc (Leaf _) = True
-- balancedc (Node l r) = abs (leavesc l + leavesc r) <= 1

leavesd (Leaf _) = 1
leavesd (Node l r) = leavesd l + leavesd r
balancedd :: Tree -> Bool
balancedd (Leaf _) = True
balancedd (Node l r) = abs (leavesd l - leavesd r) <= 1 && balancedd l && balancedd r
