import Data.List
import Data.Char
-- import Hugs.IOExts (unsafeCoerce)
data Nat = Zero | Succ Nat deriving Show

myn :: Nat
myn = (Succ Zero)

mym :: Nat
mym = (Succ (Succ Zero))

natToInteger :: Nat -> Integer
natToInteger (Succ n) = natToInteger n + 1
natToInteger Zero = 0

adda :: Nat -> Nat -> Nat
adda Zero n = n
adda (Succ m) n = Succ (adda n m)

addb :: Nat -> Nat -> Nat
addb (Succ m) n = Succ (addb n m)
addb Zero n = n

addc :: Nat -> Nat -> Nat
addc Zero n = Zero
addc (Succ m) n = Succ (addc m n)

addd :: Nat -> Nat -> Nat
addd (Succ m) n = Succ (addd m n)
addd Zero n = Zero

adde :: Nat -> Nat -> Nat
adde n Zero = Zero
adde n (Succ m) = Succ (adde n m)

addf :: Nat -> Nat -> Nat
addf n (Succ m) = Succ (addf n m)
addf n Zero = Zero

addg :: Nat -> Nat -> Nat
addg n Zero = n
addg n (Succ m) = Succ (addg m n)

addh :: Nat -> Nat -> Nat
addh n (Succ m) = Succ (addh m n)
addh n Zero = n

main :: IO()
main = do
  putStrLn $ show $ natToInteger (adda mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addb mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addc mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addd mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (adde mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addf mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addg mym myn) == natToInteger mym + natToInteger myn
  putStrLn $ show $ natToInteger (addh mym myn) == natToInteger mym + natToInteger myn
