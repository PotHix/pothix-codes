list1 :: [Int]
list1 = [1, 2, 3]

list2 :: [Int]
list2 = [4, 5, 6]

resul :: Int
resul = 32

scalarproducta :: [ Int ] -> [ Int ] -> Int
scalarproducta xs ys = sum [x * y | x <- xs, y <- ys]

scalarproductb :: [ Int ] -> [ Int ] -> Int
scalarproductb xs ys = sum [x * y | (x, y) <- xs `zip` ys]

scalarproductc :: [ Int ] -> [ Int ] -> Int
scalarproductc xs ys = product (zipWith (+) xs ys)

--scalarproductd :: [ Int ] -> [ Int ] -> Int
--scalarproductd xs ys = sum(product [(x, y) | x <- xs, y <- ys])

main :: IO ( )
main = do
  putStrLn $ show $ scalarproducta list1 list2 == resul
  putStrLn $ show $ scalarproductb list1 list2 == resul
  putStrLn $ show $ scalarproductc list1 list2 == resul
