mylist :: [Int]
mylist = [0,2,4,6]

oddlist :: [Int]
oddlist = [1,3,5,7,9]

almost :: [Int]
almost = [1,3,4,5,7]

-- answer a
--any :: (a -> Bool) -> [a] -> Bool
--any p = map p . or

-- answer b
--any :: (a -> Bool) -> [a] -> Bool
--any p = or . map p

-- answer c
--any :: (a -> Bool) -> [a] -> Bool
--any p xs = length (filter p xs) > 0

-- answer d
--any :: (a -> Bool) -> [a] -> Bool
--any p = not . null . dropWhile (not . p)

-- answer e
--any :: (a -> Bool) -> [a] -> Bool
--any p = null . filter p

-- answer f
--any :: (a -> Bool) -> [a] -> Bool
--any p xs = not (all (\ x -> not (p x)) xs)

-- answer g
any :: (a -> Bool) -> [a] -> Bool
any p xs = foldr (\ x acc -> (p x) || acc) False xs

-- answer h
--any :: (a -> Bool) -> [a] -> Bool
--any p xs = foldr (||) True (map p xs)
