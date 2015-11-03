mylist :: [Int]
mylist = [1,2,3,4,5,6,7]

funct :: Int -> [a] -> [a]
funct x xs = take (x+1) xs ++ drop x xs

main :: IO ( )
main = do
  putStrLn $ show $ funct 3 mylist
