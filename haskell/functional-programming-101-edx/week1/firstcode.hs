f :: [Int] -> [Int]

f []    = []
f(x:xs) = f ys ++ [x] ++ f zs
  where
    ys = [a | a <- xs, a <= x]
    zs = [b | b <- xs, b >  x]

main :: IO ()
main = do
  putStrLn $ show $ f [6,1,4,5,3,2]
