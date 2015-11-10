compose :: [a -> a] -> (a -> a)
compose = foldr . id

-- sumsqreven = compose [sum, map (^2), filter even]
