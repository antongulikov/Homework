import System.Random
import Control.Monad.State

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)

getOne :: (Random a) => (a,a) -> State StdGen a
getOne bounds = do 
					g <- get
					(x,g') <- return $ randomR bounds g
					put g'
					return x

rndValue :: StdGen -> (Int, StdGen)
rndValue = runState (do
						n <- getOne (1, 1000)
						return n)

randomNumber x = fst $ rndValue g
				where g = mkStdGen x
        				
trans :: Int -> Tree a -> (Int, Tree Int)
trans key (Leaf x) = (a, Leaf b)
					where
						a = randomNumber key
						b = randomNumber a

trans key (Branch l x r) = (rkey, Branch left middle right)
							where
								(lkey, left) = trans key l
								middle = randomNumber (lkey + lkey)
								(rkey, right) = trans middle r


transform :: Tree a -> Int -> Tree Int
transform t seed = snd (trans seed t)

tree = Branch ( Branch (Leaf 1) 2 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

main = do
	newStdGen
	rg <- getStdGen
	print $ show tree
	print $ show (transform tree (fst (next rg)))