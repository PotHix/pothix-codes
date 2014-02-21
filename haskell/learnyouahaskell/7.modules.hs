import Data.List
-- import Data.List (nub, sort)     -- only
-- import Data.List hiding (nub)    -- without
-- import qualified Data.List       -- namespaced
-- import qualified Data.List as M  -- namespaced

search :: (Eq a) => [a] -> [a] -> Bool
search needle haystack =
    let nlen = length needle
    in  foldl (\acc x -> if take nlen x == needle then True else acc) False (tails haystack)
