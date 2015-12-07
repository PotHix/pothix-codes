putStr' :: String -> IO ()
putStr' [] = return ()
putStr' (x : xs) = putChar x >> putStr' xs

putStrLn'a :: String -> IO ()
putStrLn'a [] = putChar '\n'
putStrLn'a xs = putStr' xs >> putStrLn'a ""

putStrLn'b :: String -> IO ()
putStrLn'b [] = putChar '\n'
putStrLn'b xs = putStr' xs >> putChar '\n'

putStrLn'c :: String -> IO ()
putStrLn'c [] = putChar '\n'
putStrLn'c xs = putStr' xs >>= \x -> putChar '\n'

-- putStrLn'd :: String -> IO ()
-- putStrLn'd [] = putChar '\n'
-- putStrLn'd xs = putStr' xs >> \x -> putChar '\n'

putStrLn'e :: String -> IO ()
putStrLn'e [] = putChar '\n'
putStrLn'e xs = putStr' xs >> putStr' "\n"

putStrLn'f :: String -> IO ()
putStrLn'f [] = putChar '\n'
putStrLn'f xs = putStr' xs >> putStrLn'f "\n"

-- putStrLn'g :: String -> IO ()
-- putStrLn'g [] = return ""
-- putStrLn'g xs = putStr' xs >> putStr' "\n"

-- putStrLn'h :: String -> IO ()
-- putStrLn'h [] = putChar "\n"
-- putStrLn'h xs = putStr' xs >> putChar '\n'
