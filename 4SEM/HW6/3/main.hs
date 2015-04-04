data BinaryTree a = Empty | Node a (BinaryTree a) (BinaryTree a) deriving (Eq, Show)

height :: BinaryTree a -> Int
height h = case (h) of
			(Empty) -> 0
			(Node x l r) -> (max (height l) (height r)) + 1

size :: BinaryTree a -> Int
size h = case (h) of
			(Empty) -> 0
			(Node x l r) -> 1 + (size l) + (size r) 

add :: (Ord a) => a -> BinaryTree a -> BinaryTree a
add x Empty = Node x Empty Empty
add x (Node q l r) 
			| x < q = Node q (add x l) r
			| x > q = Node q l (add x r)
			| otherwise = Node q l r


find :: (Ord a) => a -> BinaryTree a -> Bool
find key Empty = False
find key (Node x l r)
						| key < x = find key l
						| key > x = find key r
						| otherwise = True  


minE :: (Ord a) => BinaryTree a -> a
minE (Node x Empty r) = x
minE (Node x l r) = minE l

merge :: (Ord a) => BinaryTree a -> BinaryTree a -> BinaryTree a
merge Empty r = r
merge l Empty = l
merge l r = let x = minE r
			in (Node x l (delete x r))

delete :: (Ord a) => a -> BinaryTree a -> BinaryTree a
delete key Empty = Empty
delete key (Node x l r)
						| key < x = Node x (delete key l) r
						| key > x = Node x l (delete key r)
						| otherwise = merge l r 

tree = add 1 (add 2 (add (-3) (add 0 (add 10 (add 4 Empty)))))

main = do
		print $ (height tree)
		print $ (size tree)
		print $ show (delete 4 (add 12 tree))
		
		