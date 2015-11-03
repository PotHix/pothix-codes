import Data.Char

mystr :: String
mystr = "Think like a Fundamentalist Code like a Hacker"

let2intlower :: Char -> Int
let2intlower c = ord c - ord 'a'

int2letlower :: Int -> Char
int2letlower n = chr (ord 'a' + n)

let2intupper :: Char -> Int
let2intupper c = ord c - ord 'A'

int2letupper :: Int -> Char
int2letupper n = chr (ord 'A' + n)

shift :: Int -> Char -> Char
shift n c
   | isLower c = int2letlower ((let2intlower c + n) `mod` 26)
   | isUpper c = int2letupper ((let2intupper c + n) `mod` 26)
   | otherwise = c

encode :: Int -> String -> String
encode n xs = [shift n x | x <- xs]

myrun :: String
myrun = encode 13 mystr

prnt :: IO ( )
prnt = do
  putStrLn $ show $ myrun
  putStrLn $ show $ head cmp == True

cmp :: [Bool]
cmp = do
  [
    myrun == "Guvax yvxr n Shaqnzragnyvfg Pbqr yvxr n Unpxre",
    myrun == "Kuvbx ysxr n Fhaqkajagnyvfg Puqr yvxr n Unpdye",
    myrun == "Ftuzw xuwq m Rgzpmyqzfmxuef Oapq xuwq m Tmowqd",
    myrun == "Gwvax yvxr n Shajnzrabnyvfg Pbqr yvxr n Unptre"]


main :: IO ( )
main = do
  prnt
