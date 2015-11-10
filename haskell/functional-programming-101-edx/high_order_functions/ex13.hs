unfold p h t x | p x  = []
               | otherwise = h x : unfold p h t (t x)

iteratea :: (a -> a) -> a -> [a]
iteratea f = unfold (const False) id f

--iterateb :: (a -> a) -> a -> [a]
--iterateb f = unfold (const False) f f

--iteratec :: (a -> a) -> a -> [a]
--iteratec f = unfold (const True) id f

--iterated :: (a -> a) -> a -> [a]
--iterated f = unfold (const True) f f
