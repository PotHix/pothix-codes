mylist :: [Int]
mylist = [1,2,3,4,5]

removea :: Int -> [a] -> [a]
removea n xs = take n xs ++ drop n xs

removeb :: Int -> [a] -> [a]
removeb n xs = drop n xs ++ take n xs

removec :: Int -> [a] -> [a]
removec n xs = take (n + 1) xs ++ drop n xs

removed :: Int -> [a] -> [a]
removed n xs = take n xs ++ drop (n+1) xs


main :: IO ( )
main = do
  putStrLn $ show $ removea 0 mylist == tail mylist
  putStrLn $ show $ removea 0 mylist

  putStrLn $ show $ removeb 0 mylist == tail mylist
  putStrLn $ show $ removeb 0 mylist

  putStrLn $ show $ removec 0 mylist == tail mylist
  putStrLn $ show $ removec 0 mylist

  putStrLn $ show $ removed 0 mylist == tail mylist
  putStrLn $ show $ removed 0 mylist
