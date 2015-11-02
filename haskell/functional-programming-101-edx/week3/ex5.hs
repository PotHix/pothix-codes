mylist :: [Int]
mylist = [1,2,3,4,5]

mynumb :: Int
mynumb = 3

find :: (Eq a) => a -> [(a, b)] -> [b]
find k t = [v | (k', v) <- t, k == k']


positionsa :: (Eq a) => a -> [a] -> [Int]
positionsa x xs = find x (zip xs [0 .. n])
   where n = length xs - 1

--positionsb :: (Eq a) => a -> [a] -> [Int]
--positionsb x xs = find x xs

--positionsc :: (Eq a) => a -> [a] -> [Int]
--positionsc x xs = find x (zipWith (+) xs [0 ..n])
--   where n = length xs - 1

--positionsd :: (Eq a) => a -> [a] -> [Int]
--positionsd x xs = find n (zip xs [0 .. x])
--   where n = length xs - 1

main :: IO ( )
main = do
  putStrLn $ show $ positionsa mynumb mylist
