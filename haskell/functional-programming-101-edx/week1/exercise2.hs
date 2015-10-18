mylist = [1,2,10]
mylast = 10

last0 :: [a] -> [a]
last1 :: [a] -> a
last2 :: [a] -> [a]
-- last3 :: [a] -> a -- totally useless
last4 :: [a] -> a
last5 :: [a] -> a
last6 :: [a] -> a
last7 :: [a] -> a

last0 xs = drop (length xs - 1) xs
last1 xs = head (drop (length xs - 1) xs)
last2 xs = tail $ reverse xs
-- last3 xs = reverse $ head xs  -- totally useless
last4 xs = xs !! (length xs - 1)
last5 xs = head $ drop (length xs) xs
last6 xs = head $ reverse xs
last7 xs = reverse xs !! (length xs - 1)

main :: IO ()
main = do
  putStrLn $ show False -- list is not the correct type
  putStrLn $ show $ last1 mylist == mylast
  putStrLn $ show False -- list is not the correct type
  putStrLn $ show False -- it even make sense
  putStrLn $ show $ last4 mylist == mylast
  putStrLn $ show False -- empty list all the time because "- 1" is missing
  putStrLn $ show $ last6 mylist == mylast
  putStrLn $ show $ last7 mylist == mylast
