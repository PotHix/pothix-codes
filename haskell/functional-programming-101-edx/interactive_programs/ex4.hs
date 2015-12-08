putStr' :: String -> IO ()
putStr' [] = return ()
putStr' (x : xs) = putChar x >> putStr' xs

putStrLn' :: String -> IO ()
putStrLn' [] = putChar '\n'
putStrLn' xs = putStr' xs >> putStrLn' ""

getLine' = getc []
getc :: String -> IO String
getc xs = do x <- getChar
             case x of
                '\n' -> return xs
                _ -> getc (xs ++ [x])

interact'a :: (String -> String) -> IO ()
interact'a f = do input <- getLine'
                  putStrLn' (f input)

interact'b :: (String -> String) -> IO ()
interact'b f = do input <- getLine'
                  putStrLn' input

-- interact'c :: (String -> String) -> IO ()
-- interact'c f = do input <- getChar
--                   putStrLn' (f input)

interact'd :: (String -> String) -> IO ()
interact'd f = do input <- getLine'
                  putStr' (f input)
