Countdown example from chapter 11 of Programming in Haskell,
Graham Hutton, Cambridge University Press, 2007.


> import System.CPUTime
> import Numeric
> import System.IO

Expressions
-----------

> data Op                       =  Add | Sub | Mul | Div
>
> valid                         :: Op -> Int -> Int -> Bool
> valid Add _ _                 =  True
> valid Sub x y                 =  x > y
> valid Mul _ _                 =  True
> valid Div x y                 =  x `mod` y == 0
>
> apply                         :: Op -> Int -> Int -> Int
> apply Add x y                 =  x + y
> apply Sub x y                 =  x - y
> apply Mul x y                 =  x * y
> apply Div x y                 =  x `div` y
>
> data Expr                     =  Val Int | App Op Expr Expr
>
> values                        :: Expr -> [Int]
> values (Val n)                =  [n]
> values (App _ l r)            =  values l ++ values r
>
> eval                          :: Expr -> [Int]
> eval (Val n)                  =  [n | n > 0]
> eval (App o l r)              =  [apply o x y | x <- eval l
>                                               , y <- eval r
>                                               , valid o x y]

Combinatorial functions
-----------------------

> subs                          :: [a] -> [[a]]
> subs []                       =  [[]]
> subs (x:xs)                   =  yss ++ map (x:) yss
>                                  where yss = subs xs
>
> interleave                    :: a -> [a] -> [[a]]
> interleave x []               =  [[x]]
> interleave x (y:ys)           =  (x:y:ys) : map (y:) (interleave x ys)
>
> perms                         :: [a] -> [[a]]
> perms []                      =  [[]]
> perms (x:xs)                  =  concat (map (interleave x) (perms xs))
>
> choices                       :: [a] -> [[a]]
> choices                       =  choicesc

Formalising the problem
-----------------------

> solution                      :: Expr -> [Int] -> Int -> Bool
> solution e ns n               =  elem (values e) (choices ns) && eval e == [n]

Brute force solution
--------------------

> split                         :: [a] -> [([a],[a])]
> split                         =  splitb
>
> exprs                         :: [Int] -> [Expr]
> exprs []                      =  []
> exprs [n]                     =  [Val n]
> exprs ns                      =  [e | (ls,rs) <- split ns
>                                     , l       <- exprs ls
>                                     , r       <- exprs rs
>                                     , e       <- combine l r]
>
> combine                       :: Expr -> Expr -> [Expr]
> combine l r                   =  [App o l r | o <- ops]
>
> ops                           :: [Op]
> ops                           =  [Add,Sub,Mul,Div]
>
> solutions                     :: [Int] -> Int -> [Expr]
> solutions ns n                =  [e | ns' <- choices ns
>                                     , e   <- exprs ns'
>                                     , eval e == [n]]

Combining generation and evaluation
-----------------------------------

> type Result                   =  (Expr,Int)
>
> results                       :: [Int] -> [Result]
> results []                    =  []
> results [n]                   =  [(Val n,n) | n > 0]
> results ns                    =  [res | (ls,rs) <- split ns
>                                       , lx      <- results ls
>                                       , ry      <- results rs
>                                       , res     <- combine' lx ry]
>
> combine'                      :: Result -> Result -> [Result]
> combine' (l,x) (r,y)          =  [(App o l r, apply o x y) | o <- ops
>                                                            , valid o x y]
>
> solutions'                    :: [Int] -> Int -> [Expr]
> solutions' ns n               =  [e | ns'   <- choices ns
>                                     , (e,m) <- results ns'
>                                     , m == n]

Exploiting numeric properties
-----------------------------

> valid'                        :: Op -> Int -> Int -> Bool
> valid' Add x y                =  x <= y
> valid' Sub x y                =  x > y
> valid' Mul x y                =  x /= 1 && y /= 1 && x <= y
> valid' Div x y                =  y /= 1 && x `mod` y == 0
>
> results'                      :: [Int] -> [Result]
> results' []                   =  []
> results' [n]                  =  [(Val n,n) | n > 0]
> results' ns                   =  [res | (ls,rs) <- split ns
>                                       , lx      <- results' ls
>                                       , ry      <- results' rs
>                                       , res     <- combine'' lx ry]
>
> combine''                     :: Result -> Result -> [Result]
> combine'' (l,x) (r,y)         =  [(App o l r, apply o x y) | o <- ops
>                                                            , valid' o x y]
>
> solutions''                   :: [Int] -> Int -> [Expr]
> solutions'' ns n              =  [e | ns'   <- choices ns
>                                     , (e,m) <- results' ns'
>                                     , m == n]

Homework 0
----------

> choicesa xs = [ys ++ zs | ys <- subs xs, zs <- perms xs]
>
> choicesb xs = concat [zs | ys <- subs xs, zs <- perms ys]
>
> choicesc xs = [zs | ys <- subs xs, zs <- perms ys]
>
> choicesd xs = [zs | ys <- perms xs, zs <- subs ys]


Homework 1
----------

-- > removeonea x [] = [x]
-- > removeonea x ys
-- >     | x == head ys = ys
-- >     | otherwise = y : removeonea x ys
-- >

> removeoneb :: Eq a => a -> [a] -> [a]
> removeoneb x [] = []
> removeoneb x (y : ys)
>     | x == y = ys
>     | otherwise = x : removeoneb y ys
>
> removeonec :: Eq a => a -> [a] -> [a]
> removeonec x [] = []
> removeonec x ys
>     | x == head ys = ys
>     | otherwise = removeonec x ys
>
> removeoned :: Eq a => a -> [a] -> [a]
> removeoned x [] = []
> removeoned x (y : ys)
>    | x == y = ys
>    | otherwise = y : removeoned x ys
>

Homework 2
----------

> isChoicea :: Eq a => [a] -> [a] -> Bool
> isChoicea [] _ = True
> isChoicea (x : xs) [] = False
> isChoicea (x : xs) ys = elem x ys && isChoicea xs (removeoned x ys)

-- > isChoiceb :: Eq a => [a] -> [a] -> Bool
-- > isChoiceb [] _ = False
-- > isChoiceb (x : xs) [] = True
-- > isChoiceb (x : xs) (y : ys) = elem y xs && isChoiceb xs (removeoned x ys)

-- > isChoicec :: Eq a => [a] -> [a] -> Bool
-- > isChoicec [] _ = True
-- > isChoicec xs [] = True
--> isChoicec xs ys = elem (head xs) ys && isChoicec xs (removeone (head y) ys)

> isChoiced :: Eq a => [a] -> [a] -> Bool
> isChoiced [] _ = True
> isChoiced (x : xs) [] = False
> isChoiced (x : xs) ys = elem x ys && isChoiced (removeoned x xs) ys
 


Homework 3
----------

-- > splita :: [a] -> [([a],[a])]
-- > splita [] = []
-- > splita [x] = [x]
-- > splita (x : xs) = [([x] : (ls ++ rs)) | (ls, rs) <- split xs]

> splitb :: [a] -> [([a], [a])]
> splitb [] = []
> splitb (x : xs) = ([x], xs) : (splitb xs)
>
> splitc :: [a] -> [([a], [a])]
> splitc [] = []
> splitc (x : xs) = [(x : ls, rs) | (ls, rs) <- splitc xs]
>
> splitd :: [a] -> [([a], [a])]
> splitd [] = []
> splitd [_] = []
> splitd (x : xs) = ([x], xs) : [(x : ls, rs) | (ls, rs) <- splitd xs]


Interactive version for testing
-------------------------------

> instance Show Op where
>    show Add                   =  "+"
>    show Sub                   =  "-"
>    show Mul                   =  "*"
>    show Div                   =  "/"
>
> instance Show Expr where
>    show (Val n)               =  show n
>    show (App o l r)           =  bracket l ++ show o ++ bracket r
>                                  where
>                                     bracket (Val n) = show n
>                                     bracket e       = "(" ++ show e ++ ")"
>
> showtime                      :: Integer -> String
> showtime t                    =  showFFloat (Just 3)
>                                     (fromIntegral t / (10^12)) " seconds"
>
> display                       :: [Expr] -> IO ()
> display es                    =  do t0 <- getCPUTime
>                                     if null es then
>                                        do t1 <- getCPUTime
>                                           putStr "\nThere are no solutions, verified in "
>                                           putStr (showtime (t1 - t0))
>                                      else
>                                        do t1 <- getCPUTime
>                                           putStr "\nOne possible solution is "
>                                           putStr (show (head es))
>                                           putStr ", found in "
>                                           putStr (showtime (t1 - t0))
>                                           putStr "\n\nPress return to continue searching..."
>                                           getLine
>                                           putStr "\n"
>                                           t2 <- getCPUTime
>                                           if null (tail es) then
>                                              putStr "There are no more solutions"
>                                            else
>                                              do sequence [print e | e <- tail es]
>                                                 putStr "\nThere were "
>                                                 putStr (show (length es))
>                                                 putStr " solutions in total, found in "
>                                                 t3 <- getCPUTime
>                                                 putStr (showtime ((t1 - t0) + (t3 - t2)))
>                                     putStr ".\n\n"
>
> main                          :: IO ()
> main                          =  do hSetBuffering stdout NoBuffering
>                                     putStrLn "\nCOUNTDOWN NUMBERS GAME SOLVER"
>                                     putStrLn "-----------------------------\n"
>                                     putStr "Enter the given numbers : "
>                                     ns <- readLn
>                                     putStr "Enter the target number : "
>                                     n  <- readLn
>                                     display (solutions'' ns n)
