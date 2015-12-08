getLine'a = geta ""
geta :: String -> IO String
geta xs = do x <- getChar
             case x of
                ' ' -> return xs
                '\n' -> return xs
                _ -> geta (xs ++ [x])

getLine'b = getb ""
getb :: String -> IO String
getb xs = do x <- getChar
             case x of
                '\n' -> return xs
                _ -> getb (x : xs)

getLine'c = getc []
getc :: String -> IO String
getc xs = do x <- getChar
             case x of
                '\n' -> return xs
                _ -> getc (xs ++ [x])

getLine'd = getd []
getd :: String -> IO String
getd xs = do x <- getChar
             case x of
                '\n' -> return (x : xs)
                _ -> getd (xs ++ [x])
