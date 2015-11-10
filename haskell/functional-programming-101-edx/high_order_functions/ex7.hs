dec2inta :: [Integer] -> Integer
dec2inta = foldr (\x y -> 10 * x + y) 0

dec2intb :: [Integer] -> Integer
dec2intb = foldl (\x y -> x + 10 * y) 0

dec2intc :: [Integer] -> Integer
dec2intc = foldl (\x y -> 10 * x + y) 0

dec2intd :: [Integer] -> Integer
dec2intd = foldr (\x y -> x + 10 * y) 0
