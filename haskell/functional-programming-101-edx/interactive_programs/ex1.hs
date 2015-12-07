putStr'a [] = return ""
putStr'a (x : xs) = putChar x >> putStr'a xs

putStr'b [] = return ()
putStr'b (x : xs) = putChar x >> putStr'b xs

-- putStr'c [] = return ()
-- putStr'c (x : xs) = putChar x >>= putStr'c xs

-- putStr'd [] = return ()
-- putStr'd (x : xs) = putStr'd xs >>= putChar x
