fibs :: [Integer]
fibs = 0 : 1 : [x + y | (x, y) <- zip fibs (tail fibs)]

largeFiba :: Integer
largeFiba = head(dropWhile (<= 1000) fibs)

largeFibb :: Integer
largeFibb = last (take 19 fibs)

-- largeFibc :: Integer
-- largeFibc = filter (> 1000) fibs

largeFibd :: Integer
largeFibd = head (drop 1000 fibs)
