import Control.Monad
import Data.Maybe

ok :: (Ord a) => a -> a -> a -> Maybe a
ok x y z = case (x < y && z < y) of
			True -> Just y
			False -> Nothing

search :: (Ord a) => [a] -> Maybe a
search (a1 : a2 : a3 : xs) = mplus (ok a1 a2 a3) (search (a2 : a3 : xs))
search _ = Nothing

main = do
	putStr (show ( maybeToList ( search [1,2,1,1,1] ) ) ) 