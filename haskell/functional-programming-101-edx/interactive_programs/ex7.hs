sequence_' :: Monad m => [m a] -> m ()
sequence_' [] = return ()
sequence_' (m : ms) = (foldl (>>) m ms) >> return ()

sequence' :: Monad m => [m a] -> m [a]
sequence' [] = return []
sequence' (m : ms) = m >>= \a ->
    do as <- sequence' ms
       return (a : as)

mapM'a :: Monad m => (a -> m b) -> [a] -> m [b]
mapM'a f as = sequence' (map f as)

mapM'b :: Monad m => (a -> m b) -> [a] -> m [b]
mapM'b f [] = return []
mapM'b f (a : as) = f a >>= \b -> mapM'b f as >>= \bs -> return (b : bs)

-- mapM'c :: Monad m => (a -> m b) -> [a] -> m [b]
-- mapM'c f as = sequence_' (map f as)

-- mapM'd :: Monad m => (a -> m b) -> [a] -> m [b]
-- mapM'd f [] = return []
-- mapM'd f (a : as) = f a >> \b -> mapM'd f as >> \bs -> return (b : bs)

-- mapM'e :: Monad m => (a -> m b) -> [a] -> m [b]
-- mapM'e f [] = return []
-- mapM'e f (a : as) =
--     do
--         f a -> b
--         mapM'e f as -> bs
--         return (b : bs)

mapM'f :: Monad m => (a -> m b) -> [a] -> m [b]
mapM'f f [] = return []
mapM'f f (a : as) = do b <- f a
                       bs <- mapM'f f as
                       return (b : bs)

mapM'g :: Monad m => (a -> m b) -> [a] -> m [b]
mapM'g f [] = return []
mapM'g f (a : as) = f a >>= \b ->
    do bs <- mapM'g f as
       return (b : bs)

-- mapM'h :: Monad m => (a -> m b) -> [a] -> m [b]
-- mapM'h f [] = return []
-- mapM'h f (a : as) = f a >>= \b ->
--     do bs <- mapM'h f as
--        return (bs ++ [b])
