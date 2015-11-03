factors :: Int -> [Int]
factors n = [x | x <- [1 .. n], n `mod` x == 0]

mynum :: Int
mynum = 500

myres :: [Int]
myres = [6, 28, 496]

perfectsa :: Int -> [Int]
perfectsa n = [x | x <- [1..n], isPerfect x]
              where isPerfect num = sum (factors num) == num

perfectsb :: Int -> [Int]
perfectsb n = [x | x <- [1 .. n], isPerfect x]
   where isPerfect num = sum (init (factors num)) == num

-- perfectsc :: Int -> [Int]
-- perfectsc n = [isPerfect x | x <- [1 .. n]]
--    where isPerfect num = sum (init (factors num)) == num

--perfectsd :: Int -> [Int]
--perfectsd  n = [x | x <- [1 .. n], isPerfect x]
--   where isPerfect num = init (factors num) == num

main :: IO ( )
main = do
  putStrLn $ show $ perfectsa mynum == myres
  putStrLn $ show $ perfectsb mynum == myres
--  putStrLn $ show $ perfectsc mynum == myres -- don't even compile
--  putStrLn $ show $ perfectsd mynum == myres -- don't even compile
