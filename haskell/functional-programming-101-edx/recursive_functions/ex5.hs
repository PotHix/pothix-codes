mylist :: Num a => [[a]]
mylist = [[1,2], [3,4]]

concata [] = []
concata (xs : xss) = xs : concata xss

concatb [] = []
concatb (xs : xss) = xs ++ concatb xss

concatc [] = [[]]
concatc (xs : xss) = xs ++ concatc xss

concatd [[]] = []
concatd (xs : xss) = xs ++ concatd xss
