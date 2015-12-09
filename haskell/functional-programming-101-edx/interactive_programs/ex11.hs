liftMa :: Monad m => (a -> b) -> m a -> m b
liftMa f m = do x <- m
                return (f x)

-- liftMb :: Monad m => (a -> b) -> m a -> m b
-- liftMb f m = m >>= \a -> f a

liftMc :: Monad m => (a -> b) -> m a -> m b
liftMc f m = m >>= \a -> return (f a)

-- liftMd :: Monad m => (a -> b) -> m a -> m b
-- liftMd f m = return (f m)

-- liftMe :: Monad m => (a -> b) -> m a -> m b
-- liftMe f m = m >>= \a -> m >>= \b -> return (f a)

-- liftMf :: Monad m => (a -> b) -> m a -> m b
-- liftMf f m = m >>= \a -> m >>= \b -> return (f b)

-- liftMg :: Monad m => (a -> b) -> m a -> m b
-- liftMg f m = mapM f [m]

-- liftMh :: Monad m => (a -> b) -> m a -> m b
-- liftMh f m = m >> \a -> return (f a)
