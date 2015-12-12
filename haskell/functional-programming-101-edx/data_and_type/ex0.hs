import Data.List
import Data.Char
import Hugs.IOExts (unsafeCoerce)
data Nat = Zero | Succ Nat deriving Show

natToIntegera :: Nat -> Integer
natToIntegera Zero = 0
natToIntegera (Succ n) = natToIntegera n + 1

natToIntegerb :: Nat -> Integer
natToIntegerb (Succ n) = natToIntegerb n + 1
natToIntegerb Zero = 0

-- natToIntegerc :: Nat -> Integer
-- natToIntegerc n = natToIntegerc n

natToIntegerd :: Nat -> Integer
natToIntegerd (Succ n) = 1 + natToIntegerd n
natToIntegerd Zero = 0

-- natToIntegere :: Nat -> Integer
-- natToIntegere Zero = 1
-- natToIntegere (Succ n) = (1 + natToIntegere n) - 1

natToIntegerf :: Nat -> Integer
natToIntegerf = head . m
    where m Zero = [0]
          m (Succ n) = [sum [x | x <- (1 : m n)]]

natToIntegerg :: Nat -> Integer
natToIntegerg = \n -> genericLength [c | c <- show n, c == 'S']

-- natToIntegerh :: Nat -> Integer
-- natToIntegerh = \n -> length [c | c <- show n, c == 'S']
