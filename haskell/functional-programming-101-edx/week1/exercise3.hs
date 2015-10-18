mylist :: [Int]
mylist = [1,2,10]

myinit :: [Int]
myinit = [1,2]

init1 :: [a] -> [a]
init1 xs = tail $ reverse xs

--init2 :: [a] -> [a]
--init2 xs = reverse $ head $ reverse xs

init3 :: [a] -> [a]
init3 xs = reverse $ tail xs

init4 :: [a] -> [a]
init4 xs = take (length xs) xs

init5 :: [a] -> [a]
init5 xs = reverse $ tail $ reverse xs

init6 :: [a] -> [a]
init6 xs = take (length xs - 1) (tail xs)

init7 :: [a] -> [a]
init7 xs = drop (length xs - 1) xs

main :: IO ()
main = do
  putStrLn $ show $ init1 mylist == myinit
  putStrLn $ show False -- wrong type when comparing
  putStrLn $ show $ init3 mylist == myinit
  putStrLn $ show $ init4 mylist == myinit
  putStrLn $ show $ init5 mylist == myinit
  putStrLn $ show $ init6 mylist == myinit
  putStrLn $ show $ init7 mylist == myinit
