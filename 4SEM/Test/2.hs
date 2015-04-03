data Tree a = Leaf a | Branch (Tree a) a (Tree a)

foldT :: ([a] -> a -> [a]) -> [a] -> Tree a -> [a]
foldT f s (Leaf x) = f s x
foldT f s (Branch l x r) = foldT f (foldT f (foldT f s l) r) (Leaf x)

find :: (Ord a, Num a) => Tree a -> [a]
find = foldT (\x y -> if y < 0 then y:x else x) []

tree = Branch ( Branch (Leaf 1) 2 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2) ) )

main = do
	print $ show (find tree)