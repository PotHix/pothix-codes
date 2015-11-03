import Prelude hiding ((^))

-- answer a
--m ^ 0 = 0
--m ^ n = m * m ^ (n - 1)

-- answer b
m ^ 0 = 1
m ^ n = m * m ^ (n - 1)

-- answer c
--m ^ 0 = 1
--m ^ n = m * m ^ n - 1

-- answer d
--m ^ 0 =1
--m ^ n = n * n ^ (m - 1)

-- answer e
--m ^ 0 = 1
--m ^ n = m * (^) m (n - 1)

-- answer f
--m ^ 0 = 1
--m ^ n = m * m * m ^ (n - 2)

-- answer g
--m ^ 0 = 1
--m ^ n = (m * m) ^ (n - 1)

-- answer h
--m ^ 1 = m
--m ^ n = m * m ^ (n - 1)

expon :: Int -> Int -> Int
expon n 1     = n
expon n times = n * expon n (times-1)

prnt :: IO ( )
prnt = do
  putStrLn $ show $ 2 ^ 3 == expon 2 3

main :: IO ( )
main = prnt
