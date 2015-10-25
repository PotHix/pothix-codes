mylist :: [Int]
mylist = [1,2,3,4,5,6]

--halvea :: [a] -> ([a], [a])
-- halvea xs = (take n xs, drop n xs)
--  where n = length xs / 2

halveb :: [a] -> ([a], [a])
halveb xs = splitAt (length xs `div` 2) xs

halvec :: [a] -> ([a], [a])
halvec xs = (take (n `div` 2) xs, drop (n `div` 2) xs)
   where n = length xs

-- halved :: [a] -> ([a], [a])
-- halved xs = splitAt (length xs `div` 2)

halvee :: [a] -> ([a], [a])
halvee xs = (take n xs, drop (n + 1) xs)
   where n = length xs `div` 2

halvef :: [a] -> ([a], [a])
halvef xs = splitAt (div (length xs) 2) xs

-- halveg :: [a] -> ([a], [a])
-- halveg xs = splitAt (length xs / 2) xs

halveh :: [a] -> ([a], [a])
halveh xs = (take n xs, drop n xs)
   where n = length xs `div` 2

main :: IO ( )
main = do
  putStrLn $ show $ False
  putStrLn $ show $ halveb mylist
  putStrLn $ show $ halvec mylist
  putStrLn $ show $ False
  putStrLn $ show $ halvee mylist
  putStrLn $ show $ halvef mylist
  putStrLn $ show $ False
  putStrLn $ show $ halveh mylist
