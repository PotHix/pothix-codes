mynum :: Int
mynum = 10

myres :: [(Int, Int, Int)]
myres = [(3, 4, 5), (4, 3, 5), (6, 8, 10), (8, 6, 10)]

-- answer a
pythsa :: Int -> [(Int, Int, Int)]
pythsa n
   = [(x, y, z) | x <- [1 .. n], y <- [1 .. x], z <- [1 .. y],
      x ^ 2 + y ^ 2 == z ^ 2]

-- answer b
pythsb :: Int -> [(Int, Int, Int)]
pythsb n
   = [(x, y, z) | x <- [ 1 .. n], y <- [x .. n], z <- [y .. n],
      x ^ 2 + y ^ 2 == z ^ 2]

-- answer c
pythsc :: Int -> [(Int, Int, Int)]
pythsc n
   = [(x, y, z) | x <- [1 .. n], y <- [1 .. n], z <- [1 .. n],
   x ^ 2 + y ^ 2 == z ^ 2]

-- answer d
pythsd :: Int -> [(Int, Int, Int)]
pythsd n = [(x, y, (x ^2 + y ^2)) | x <- [1 .. n], y <- [1 .. n]]

main :: IO ( )
main = do
  putStrLn $ show $ pythsa mynum == myres
  putStrLn $ show $ pythsb mynum == myres
  putStrLn $ show $ pythsc mynum == myres
  putStrLn $ show $ pythsd mynum == myres
