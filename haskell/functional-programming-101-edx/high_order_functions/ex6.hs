mylist :: [Int]
mylist = [1,2,3,4,5]

filtera :: (a -> Bool) -> [a] -> [a]
filtera p = foldl (\xs x -> if p x then x : xs else xs) []

filterb :: (a -> Bool) -> [a] -> [a]
filterb p = foldr (\x xs -> if p x then x : xs else xs) []

filterc :: (a -> Bool) -> [a] -> [a]
filterc p = foldr (\x xs -> if p x then xs ++ [x] else xs) []

--filterd :: (a -> Bool) -> [a] -> [a]
--filterd p = foldl (\x xs -> if p x then xs ++ [x] else xs) []
