import Data.List
import Data.Char
import Hugs.IOExts (unsafeCoerce)
data Nat = Zero | Succ Nat deriving Show

natToInteger :: Nat -> Integer
natToInteger (Succ n) = natToInteger n + 1
natToInteger Zero = 0

myn :: Nat
myn = (Succ Zero)

mym :: Nat
mym = (Succ (Succ Zero))

add :: Nat -> Nat -> Nat
add Zero n = n
add (Succ m) n = Succ (add n m)

multa :: Nat -> Nat -> Nat
multa Zero Zero = Zero
multa m (Succ n) = add m (multa m n)

multb :: Nat -> Nat -> Nat
multb m Zero = Zero
multb m (Succ n) = add m (multb m n)

multc :: Nat -> Nat -> Nat
multc m Zero = Zero
multc m (Succ n) = add n (multc m n)

multd :: Nat -> Nat -> Nat
multd m Zero = Zero
multd m n = add m (multd m (Succ n))

main :: IO()
main = do
--   putStrLn $ show $ natToInteger (multa mym myn) == natToInteger mym * natToInteger myn
  putStrLn $ show $ natToInteger (multb mym myn) == natToInteger mym * natToInteger myn
--   putStrLn $ show $ natToInteger (multc mym myn) == natToInteger mym * natToInteger myn
--   putStrLn $ show $ natToInteger (multd mym myn) == natToInteger mym * natToInteger myn
