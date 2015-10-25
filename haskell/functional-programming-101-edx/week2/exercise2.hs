import Prelude hiding ((||))

-- answer a
-- (||) :: Bool -> Bool -> Bool
-- False || False = False
-- _ || _ = True

-- answer b
--(||) :: Bool -> Bool -> Bool
--False || b = b
--_ || _ = True

-- answer c
--(||) :: Bool -> Bool -> Bool
--b || c
--   | b == c = True
--   | otherwise = False

-- answer d
--(||) :: Bool -> Bool -> Bool
--b || c
--   | b == c = b
--   |otherwise = True

-- answer e
--(||) :: Bool -> Bool -> Bool
--b || False = b
--_ || True = True

-- answer f
--(||) :: Bool -> Bool -> Bool
--b || c
--   | b == c = c
--   | otherwise = True

-- answer g
--(||) :: Bool -> Bool -> Bool
--b || True = b
--_ || True = True

-- answer h
(||) :: Bool -> Bool -> Bool
False || False = False
False || True = True
True  || False = True
True  || True = True


main :: IO ( )
main = do
  putStrLn $ show $ (True || True == True) && (True || False == True) && (False || True == True) && (False || False == False)
