data Tree = Leaf Integer | Node Tree Integer Tree

bt :: Tree
bt = Node (Node (Leaf 1) 3 (Leaf 4)) 5 (Node (Leaf 6) 7 (Leaf 9))

occursa :: Integer -> Tree -> Bool
occursa m (Leaf n) = m == n
occursa m (Node l n r) = case compare m n of
    LT -> occursa m l
    EQ -> True
    GT -> occursa m r

-- occursb :: Integer -> Tree -> Bool
-- occursb m (Leaf n) = m == n
-- occursb m (Node l n r) = case compare m n of
--     LT -> occursb m r
--     EQ -> True
--     GT -> occursb m l

-- occursc :: Integer -> Tree -> Bool
-- occursc m (Leaf n) = compare m n
-- occursc m (Node l n r) = case compare m n of
--     LT -> occursc m l
--     EQ -> True
--     GT -> occursc m r

-- occursd :: Integer -> Tree -> Bool
-- occursd m (Leaf n) = m == n
-- occursd m (Node l n r) = case compare m n of
--     LT -> occursd m l
--     EQ -> False
--     GT -> occursd m r

occurse :: Integer -> Tree -> Bool
occurse m (Leaf n) = m == n
occurse m (Node l n r)
    | m == n = True
    | m < n = occurse m l
    | otherwise = occurse m r

-- occursf :: Integer -> Tree -> Bool
-- occursf m (Leaf n) = m == n
-- occursf m (Node l n r)
--     | m == n = True
--     | m > n = occursf m l
--     | otherwise = occursf m r

-- occursg :: Integer -> Tree -> Bool
-- occursg m n = m == n
-- occursg m (Node l n r)
--     | m == n = True
--     | m < n = occursg m l
--     | otherwise = occursg m r

-- occursh :: Integer -> Tree -> Bool
-- occursh m (Leaf n) = m == n
-- occursh m (Node l n r)
--     | m == n = False
--     | m < n = occursh m r
--     | otherwise = occursh m l
