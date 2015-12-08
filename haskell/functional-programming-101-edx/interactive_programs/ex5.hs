-- sequence_'a :: Monad m => [m a] -> m ()
-- sequence_'a [] = return []
-- sequence_'a (m : ms) = m >> \_ -> sequence_'a ms

sequence_'b :: Monad m => [m a] -> m ()
sequence_'b [] = return ()
sequence_'b (m : ms) = (foldl (>>) m ms) >> return ()

-- sequence_'c :: Monad m => [m a] -> m ()
-- sequence_'c ms = foldl (>>) (return ()) ms

sequence_'d :: Monad m => [m a] -> m ()
sequence_'d [] = return ()
sequence_'d (m : ms) = m >> sequence_'d ms

sequence_'e :: Monad m => [m a] -> m ()
sequence_'e [] = return ()
sequence_'e (m : ms) = m >>= \_ -> sequence_'e ms

-- sequence_'f :: Monad m => [m a] -> m ()
-- sequence_'f ms = foldr (>>=) (return ()) ms

sequence_'g :: Monad m => [m a] -> m ()
sequence_'g ms = foldr (>>) (return ()) ms

-- sequence_'h :: Monad m => [m a] -> m ()
-- sequence_'h ms = foldr (>>) (return []) ms
