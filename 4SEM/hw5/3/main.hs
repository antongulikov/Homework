import Control.Monad

main = do
	   nStr <- getLine
	   let n = (read nStr :: Int)
	   print $ replicateM n [1,2,3]