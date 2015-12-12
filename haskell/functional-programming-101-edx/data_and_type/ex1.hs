import Data.List
import Data.Char
import Hugs.IOExts (unsafeCoerce)
data Nat = Zero | Succ Nat deriving Show

integerToNata :: Integer -> Nat
integerToNata 0 = Zero
integerToNata (n+1) = Succ (integerToNata n)

-- integerToNatb :: Integer -> Nat
-- integerToNatb 0 = Succ Zero
-- integerToNatb n = (Succ (integerToNatb n))

-- integerToNatc :: Integer -> Nat
-- integerToNatc n = product [(unsafeCoerce c) :: Integer | c <- show n]

-- integerToNatd :: Integer -> Nat
-- integerToNatd n = integerToNatd n

integerToNate :: Integer -> Nat
integerToNate (n+1) = Succ (integerToNate n)
integerToNate 0 = Zero

integerToNatf :: Integer -> Nat
integerToNatf (n+1) = let m = integerToNatf n in Succ m
integerToNatf 0 = Zero

-- integerToNatg :: Integer -> Nat
-- integerToNatg = head . m
--     where {
--         ; m 0 = [0]
--         ; m (n + 1) = [sum [x | x <- (1 : m n)]]}

-- integerToNathh :: Integer -> Nat
-- integerToNathh = \n -> genericLength [c | c <- show n, isDigit c]
