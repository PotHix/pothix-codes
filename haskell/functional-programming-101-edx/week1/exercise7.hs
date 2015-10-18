mylist :: [Int]
mylist = [5,4,7,1,3,2,6]

answer :: [Int]
answer = [7,6,5,4,3,2,1]

-- answer a
qsorta :: [Int] -> [Int]
qsorta [] = []
qsorta (x : xs) = qsorta larger ++ [x] ++ qsorta smaller
   where smaller = [a | a <- xs, a <= x]
         larger = [b | b <- xs, b > x]

-- answer b
qsortb :: [Int] -> [Int]
qsortb [] = []
qsortb (x : xs) = reverse (qsortb smaller ++ [x] ++ qsortb larger)
   where smaller = [a | a <- xs, a <= x]
         larger = [b | b <- xs, b > x]

-- answer c
--qsortc :: [Int] -> [Int]
--qsortc [] = []
--qsortc xs = qsortc larger ++ qsortc smaller ++ [x]
--   where x = minimum xs
--         smaller = [a | a <- xs, a <= x]
--         larger = [b | b <- xs, b > x]

-- answer d
qsortd :: [Int] -> [Int]
qsortd [] = []
qsortd ( x : xs)
   = reverse (qsortd smaller) ++ [x] ++ reverse (qsortd larger)
   where smaller = [a | a <- xs, a <= x]
         larger = [b | b <- xs, b > x]

-- answer e
qsorte :: [Int] -> [Int]
qsorte [] = []
qsorte (x : xs) = qsorte larger ++ [x] ++ qsorte smaller
   where larger = [a | a <- xs, a > x || a == x]
         smaller = [b | b <- xs, b < x]

-- answer f
qsortf :: [Int] -> [Int]
qsortf [] = []
qsortf (x : xs) = qsortf larger ++ [x] ++ qsortf smaller
   where smaller = [a | a <- xs, a < x]
         larger = [ b | b <- xs, b > x]

-- answer g
qsortg :: [Int] -> [Int]
qsortg [] = []
qsortg (x: xs)
   = reverse
        (reverse (qsortg smaller) ++ [x] ++ reverse (qsortg larger))
   where smaller = [a | a <- xs, a <= x]
         larger = [b | b <- xs, b > x]

-- answer h
qsorth :: [Int] -> [Int]
qsorth [] = []
qsorth xs = x : qsorth larger ++ qsorth smaller
   where x = maximum xs
         smaller = [a | a <- xs, a < x]
         larger = [b | b <- xs, b >= x]

main :: IO ( )
main = do
  putStrLn $ show $ qsorta mylist == answer
  putStrLn $ show $ qsortb mylist == answer
  putStrLn $ show False -- don't even compile
  putStrLn $ show $ qsortd mylist == answer
  putStrLn $ show $ qsorte mylist == answer
  putStrLn $ show $ qsortf mylist == answer
  putStrLn $ show $ qsortg mylist == answer
  putStrLn $ show $ qsorth mylist == answer
