-- this
compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred x = compare 100 x


-- is the same thing as the function below because of curried functions o.O
compareWithHundred' :: (Num a, Ord a) => a -> Ordering
compareWithHundred' = compare 100


-- with infix functions
divideByTen :: (Floating a) => a -> a
divideByTen = (/10)


-- passing a function
applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)


-- zipping with a function
zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys


-- inverting params
flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f = g
    where g x y = f y x


-- using filter in where
largestDivisible :: (Integral a) => a
largestDivisible = head (filter p [100000,99999..])
    where p x = x `mod` 3829 == 0


-- find the sum of all odd squares that are smaller than 10,000
sum' = sum (takeWhile (<10000) (filter odd (map (^2) [1..])))


-- that is the same as
sum'' = sum (takeWhile (<10000) [n^2 | n <- [1..], odd (n^2)])


-- chain algorigthm needed for the next function
chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain n
    | even n =  n:chain (n `div` 2)
    | odd n  =  n:chain (n*3 + 1)


-- using lambdas (\) as filter function argument
numLongChains :: Int
numLongChains = length (filter (\xs -> length xs > 15) (map chain [1..100]))


-- pattern matching are also valid in lambdas
mapLambda = map (\(a,b) -> a + b) [(1,2),(3,5),(6,3),(2,6),(2,5)]


-- implementing sum with foldl
sum''' :: (Num a) => [a] -> a
sum''' xs = foldl (\acc x -> acc + x) 0 xs


-- that BTW is the same as (removing the last argument because of currying)
sum'''' :: (Num a) => [a] -> a
sum'''' = foldl (+) 0


-- Using right folds to implement a new version of map
map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

-- $ is used to make the function right-associative
-- the above function is the same as
-- sum (map sqrt [1..130])
sum $ map sqrt [1..130]


-- this function composition
map (negate . abs) [5,-3,-6,7,-3,2,-19,24]

-- is the same as
map (\x -> negate (abs x)) [5,-3,-6,7,-3,2,-19,24]
