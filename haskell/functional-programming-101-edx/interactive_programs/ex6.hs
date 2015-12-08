sequence'a :: Monad m => [m a] -> m [a]
sequence'a [] = return []
sequence'a (m : ms) = m >>= \a ->
    do as <- sequence'a ms
       return (a : as)

-- sequence'b :: Monad m => [m a] -> m [a]
-- sequence'b ms = foldr func (return ()) ms
--     where
--         func :: (Monad m) => m a -> m [a] -> m [a]
--         func m acc = do x <- m
--                         xs <- acc
--                         return (x : xs)

-- sequence'c :: Monad m => [m a] -> m [a]
-- sequence'c ms = foldr func (return []) ms
--     where
--         func :: (Monad m) => m a -> m [a] -> m [a]
--         func m acc = m : acc

-- sequence'd :: Monad m => [m a] -> m [a]
-- sequence'd [] = return []
-- sequence'd (m : ms) = return (a : as)
--     where
--         a <- m
--         as <- sequence'd ms

sequence'e :: Monad m => [m a] -> m [a]
sequence'e ms = foldr func (return []) ms
    where
        func :: (Monad m) => m a -> m [a] -> m [a]
        func m acc = do x <- m
                        xs <- acc
                        return (x : xs)

-- sequence'f :: Monad m => [m a] -> m [a]
-- sequence'f [] = return []
-- sequence'f (m : ms) = m >> \a ->
--     do as <- sequence'f ms
--        return (a : as)

-- sequence'g :: Monad m => [m a] -> m [a]
-- sequence'g [] = return []
-- sequence'g (m : ms) = m >>= \a ->
--     as <- sequence'g ms
--     return (a : as)

sequence'h :: Monad m => [m a] -> m [a]
sequence'h [] = return []
sequence'h (m : ms) = do a <- m
                         as <- sequence'h ms
                         return (a : as)
