mylist :: [Int]
mylist = [1,2,3,4]

safetaila :: Num a => [a] -> [a]
safetaila xs = if null xs then [] else tail xs

safetailb :: Num a => [a] -> [a]
safetailb [] = []
safetailb (_ : xs) = xs

safetailc :: Num a => [a] -> [a]
safetailc (_ : xs)
   | null xs = []
   | otherwise = tail xs

safetaild :: Num a => [a] -> [a]
safetaild xs
   | null xs = []
   | otherwise = tail xs

safetaile :: Num a => [a] -> [a]
safetaile xs = tail xs
safetaile [] = []

safetailf :: Num a => [a] -> [a]
safetailf [] = []
safetailf xs = tail xs

safetailg :: Num a => [a] -> [a]
safetailg [x] = [x]
safetailg (_ : xs) = xs

safetailh :: Num a => [a] -> [a]
safetailh
   = \ xs ->
       case xs of
            [] -> []
            (_ : xs) -> xs

main :: IO ( )
main = do
  putStrLn $ "-------> a"
  putStrLn $ show $ safetaila mylist
  putStrLn $ show $ safetaila []

  putStrLn $ "-------> b"
  putStrLn $ show $ safetailb mylist
  putStrLn $ show $ safetailb []

  putStrLn $ "-------> c"
--  putStrLn $ show $ safetailc mylist
--  putStrLn $ show $ safetailc []

  putStrLn $ "-------> d"
  putStrLn $ show $ safetaild mylist
  putStrLn $ show $ safetaild []

  putStrLn $ "-------> e"
--  putStrLn $ show $ safetaile mylist
--  putStrLn $ show $ safetaile []

  putStrLn $ "-------> f"
  putStrLn $ show $ safetailf mylist
  putStrLn $ show $ safetailf []

  putStrLn $ "-------> g"
--  putStrLn $ show $ safetailg mylist
--  putStrLn $ show $ safetailg []

  putStrLn $ "-------> h"
  putStrLn $ show $ safetailh mylist
  putStrLn $ show $ safetailh []
