mylist :: [Int]
mylist = [1,2,3,4,5]

mapa :: (a -> b) -> [a] -> [b]
mapa f = foldr (\x xs -> xs ++ [f x]) []

--mapb :: (a -> b) -> [a] -> [b]
--mapb f = foldr (\x xs -> f x ++ xs) []

mapc :: (a -> b) -> [a] -> [b]
mapc f = foldl (\xs x -> f x : xs) []

mapd :: (a -> b) -> [a] -> [b]
mapd f = foldl (\xs x -> xs ++ [f x]) []
