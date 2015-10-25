import Prelude hiding ((&&))

-- answer a
--(&&) :: Bool -> Bool -> Bool
--True && True = True
--_ && _ = False

-- answer b
--(&&) :: Bool -> Bool -> Bool
--a && b = if a then if b then True else False else False

-- answer c
-- why the hell is the function below returning True???
(&&) :: Bool -> Bool -> Bool
a && b = if not (a) then not (b) else True

-- answer d
--(&&) :: Bool -> Bool -> Bool
--a && b = if a then b

-- answer e
--(&&) :: Bool -> Bool -> Bool
--a && b = if a then if b then False else True else False

-- answer f
--(&&) :: Bool -> Bool -> Bool
--a && b = if a then b else False

-- answer g
--(&&) :: Bool -> Bool -> Bool
--a && b = if b then a else False

main :: IO ( )
main = do
  putStrLn $ show $ ((True && True) == True) && ((True && False) == False) && ((False && True) == False) && ((False && False) == False)
