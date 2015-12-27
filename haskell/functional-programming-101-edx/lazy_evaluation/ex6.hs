fibsa :: [Integer]
fibsa = 1 : [x + y | (x, y) <- zip fibsa (tail fibsa)]

fibsb :: [Integer]
fibsb = 0 : 1 : zipWith (*) fibsb (tail fibsb)

fibsc :: [Integer]
fibsc = 0 : 1 : [x + y | (x, y) <- zip fibsc (tail fibsc)]

fibsd :: [Integer]
fibsd = 1 : 1 : [x + y | (x, y) <- zip (tail fibsd) fibsd]
