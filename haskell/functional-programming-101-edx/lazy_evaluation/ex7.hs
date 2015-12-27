fibs :: [Integer]
fibs = 0 : 1 : [x + y | (x, y) <- zip fibs (tail fibs)]

fiba :: Int -> Integer
fiba n = last (take n fibs)

fibb :: Int -> Integer
fibb n = head (drop (n - 1) fibs)

fibc :: Int -> Integer
fibc n = fibs !! n

-- fibd :: Int -> Integer
-- fibd n = index fibs n
