> module Parsing where
>
>
> import Data.Char
> import Control.Monad
>
> infixr 5 +++

The monad of parsers
--------------------

> newtype Parser a              =  P (String -> [(a,String)])
>
> instance Monad Parser where
>    return v                   =  P (\ inp -> [(v,inp)])
>    p >>= f                    =  P (\ inp ->
>                                       case parse p inp  of
>                                           [(v, out)] -> parse (f v) out
>                                           [] -> [])
>
> instance MonadPlus Parser where
>    mzero                      =  P (\inp -> [])
>    p `mplus` q                =  P (\inp -> case parse p inp of
>                                                []        -> parse q inp
>                                                [(v,out)] -> [(v,out)])

Basic parsers
-------------

> failure                       :: Parser a
> failure                       =  mzero
>
> item                          :: Parser Char
> item                          =  P (\inp -> case inp of
>                                                []     -> []
>                                                (x:xs) -> [(x,xs)])
>
> parse                         :: Parser a -> String -> [(a,String)]
> parse (P p) inp               =  p inp

Choice
------

> (+++)                         :: Parser a -> Parser a -> Parser a
> p +++ q                       =  p `mplus` q

Derived primitives
------------------

> sat                           :: (Char -> Bool) -> Parser Char
> sat p                         =  do x <- item
>                                     if p x then return x else failure
>
> digit                         :: Parser Char
> digit                         =  sat isDigit
>
> lower                         :: Parser Char
> lower                         =  sat isLower
>
> upper                         :: Parser Char
> upper                         =  sat isUpper
>
> letter                        :: Parser Char
> letter                        =  sat isAlpha
>
> alphanum                      :: Parser Char
> alphanum                      =  sat isAlphaNum
>
> char                          :: Char -> Parser Char
> char x                        =  sat (== x)
>
> string                        :: String -> Parser String
> string []                     =  return []
> string (x:xs)                 =  do char x
>                                     string xs
>                                     return (x:xs)
>
> many                          :: Parser a -> Parser [a]
> many p                        =  many1 p +++ return []
>
> many1                         :: Parser a -> Parser [a]
> many1 p                       =  do v  <- p
>                                     vs <- many p
>                                     return (v:vs)
>
> ident                         :: Parser String
> ident                         =  do x  <- lower
>                                     xs <- many alphanum
>                                     return (x:xs)
>
> nat                           :: Parser Int
> nat                           =  do xs <- many1 digit
>                                     return (read xs)
>
> int                           :: Parser Int
> int                           =  inta
>
> inta = char '-' >>= (\ c -> nat >>= (\ n -> (return (-n) +++ nat)))
>
> intc = (do char '-'
>            n <- nat
>            return (-n))
>        +++ nat
>
> intd = (do char '-'
>            nat)
>        +++ nat
>
> space                         :: Parser ()
> space                         =  do many (sat isSpace)
>                                     return ()
>
> comment                       :: Parser ()
> comment                       = commentd -- that's weird... why not to return the comment? :(
>
> commenta = do string "--"
>               sat (/= '\n')
>               return ()
>
> commentb = do string "--"
>               many (sat (/= '\n'))
>
> commentc = do string "--"
>               sat (== '\n')
>               return ()
>
> commentd = do string "--"
>               many (sat (/= '\n'))
>               return ()
>
> expr                          :: Parser Int
> expr                          = exprd
>
> expra = do n <- natural
>            ns <- many (do symbol "-"
>                           natural)
>            return (foldl (-) n ns)
>
> exprb = do n <- natural
>            symbol "-"
>            n' <- natural
>            return (n - n')
>
> exprd = do n <- natural
>            symbol "-"
>            e <- expr
>            return (e - n)
>

Ignoring spacing
----------------

> token                         :: Parser a -> Parser a
> token p                       =  do space
>                                     v <- p
>                                     space
>                                     return v
>
> identifier                    :: Parser String
> identifier                    =  token ident
>
> natural                       :: Parser Int
> natural                       =  token nat
>
> integer                       :: Parser Int
> integer                       =  token int
>
> symbol                        :: String -> Parser String
> symbol xs                     =  token (string xs)
