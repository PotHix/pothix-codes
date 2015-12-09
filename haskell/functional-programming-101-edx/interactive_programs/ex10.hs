foldRightM :: Monad m => (a -> b -> m b) -> b -> [a] -> m b
foldRightM f a [] = return a
foldRightM f a (x : xs)
           = do b <- foldRightM f a xs
                c <- f x b
                return c

-- foldRightM (\a b -> putChar a >> return (a : b)) [] (show [1,3..10]) >>= \r -> putStrLn r
