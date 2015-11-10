mylist :: [Int]
mylist = [0,2,4,6]

oddlist :: [Int]
oddlist = [1,3,5,7,9]

almost :: [Int]
almost = [1,3,4,5,7]

dropWhilea :: (a -> Bool) -> [a] -> [a]
dropWhilea _ [] = []
dropWhilea p (x : xs)
    | p x = dropWhilea p xs
    | otherwise = x : xs

dropWhileb :: (a -> Bool) -> [a] -> [a]
dropWhileb _ [] = []
dropWhileb p (x : xs)
    | p x = dropWhileb p xs
    | otherwise = xs

dropWhilec :: (a -> Bool) -> [a] -> [a]
dropWhilec p = foldr (\x acc -> if p x then acc else x : acc ) []

dropWhiled :: (a -> Bool) -> [a] -> [a]
dropWhiled p = foldl add []
    where add [] x  = if p x then [] else [x]
          add acc x = x : acc
