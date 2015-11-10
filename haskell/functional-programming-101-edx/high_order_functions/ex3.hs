mylist :: [Int]
mylist = [0,2,4,6]

oddlist :: [Int]
oddlist = [1,3,5,7,9]

almost :: [Int]
almost = [1,3,4,5,7]

takeWhilea _ [] = []
takeWhilea p (x : xs)
    | p x = x : takeWhile p xs
    | otherwise = takeWhile p xs

-- answer b
takeWhileb _ [] = []
takeWhileb p (x : xs)
    | p x = x : takeWhile p xs
    | otherwise = []

-- answer c
takeWhilec _ [] = []
takeWhilec p (x : xs) | p x = takeWhile p xs
                     | otherwise = []

-- answer d
takeWhiled p = foldl (\acc x -> if p x then x : acc else acc) []
