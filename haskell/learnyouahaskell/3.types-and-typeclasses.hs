-- function type definition
removeNonUppercase :: [Char] -> [Char] -- [Char] is the same as String
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]
