mylist :: [Int]
mylist = [1,2,3,4,5]

oddlist :: [Int]
oddlist = [1,3,5,7]

-- answer a
--all :: (a -> Bool) -> [a] -> Bool
--all p xs = and (map p xs)

-- answer b
--all :: (a -> Bool) -> [a] -> Bool
--all p xs = map p (and xs)

-- answer c
--all :: (a -> Bool) -> [a] -> Bool
--all p = and . map p

-- answer d
--all :: (a -> Bool) -> [a] -> Bool
--all p = not . any (not . p)

-- answer e
--all :: (a -> Bool) -> [a] -> Bool
--all p = map p . and

-- answer f
--all :: (a -> Bool) -> [a] -> Bool
--all p xs = foldl (&&) True (map p xs)

-- answer g
--all :: (a -> Bool) -> [a] -> Bool
--all p xs = foldr (&&) False (map p xs)

-- answer h
all :: (a -> Bool) -> [a] -> Bool
all p = foldr (&&) True . map p
