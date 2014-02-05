doubleUs y x = doubleMe x + doubleMe y

-- out of order. :)
doubleMe x = x + x

-- if syntax
doubleSmallNumber x =
  if x > 100
    then x
    else x * 2

-- lists
lostNumbers = [4,8,15,16,23,42]

-- concat
longlist     = [1,2,3,4] ++ [9,10,11,12]
longcharlist = "hello" ++ " " ++ "world"
woot         = ['w','o'] ++ ['o','t'] -- strings are char lists

instant_add_at_the_beggining = 'A':" SMALL CAT"

the_A = instant_add_at_the_beggining !! 0

head [5,4,3,2,1] -- 5
tail [5,4,3,2,1] -- [4,3,2,1]
last [5,4,3,2,1] -- 1
init [5,4,3,2,1] -- [5,4,3,2]

-- and so on... refer to list methods :P

take 10 (cycle [1,2,3])  -- take 10 from an infinity of [1,2,3]
take 2 repeat 5          -- take 2 from an infinity of numbers 5


[ x | x <- [50..100], x `mod` 7 == 3] -- list compreension that prints x for x in [50..100] if x mod 7 is 3.

length' xs = sum [1 | _ <- xs] -- a new version of length using list comprehension
