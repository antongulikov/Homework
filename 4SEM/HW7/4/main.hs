import Control.Monad.Cont

filterCont :: (a -> Bool) -> [a] -> Cont r [a]
filterCont f [] = return []
filterCont f (x : xs) = do
						rest <- filterCont f xs
						case (f x) of
							True -> return (x : rest)
							_ -> return rest


mapCont' :: (a -> b) -> [a] -> Cont r [b]
mapCont' f [] = return []
mapCont' f (x : xs) = do
						rest <- mapCont' f xs
						return ((f x) : rest)


main = do
	runCont (filterCont (>0) [3, -1, 4, -2, 0, 1]) print
	runCont (mapCont' (\x -> x + 2) [3, -1, 4, -2, 0, 1]) print