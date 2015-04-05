import Control.Monad.State

data CharTree = Empty | Node Char (CharTree) (CharTree) deriving (Eq, Show)

fromTreeToString :: CharTree -> String
fromTreeToString Empty = "e"
fromTreeToString (Node x l r) = 'n' : x : (fromTreeToString l ++ fromTreeToString r)


fromStringToTree :: String -> CharTree
fromStringToTree s = evalState work s
						where work = do
							str <- get
							case (str) of
								('n' : ch : rest) -> do
														put rest
														l <- work
														r <- work
														return (Node ch l r)
								('e' : rest) -> do
													put rest
													return (Empty)

tree = Node 'a'
			(Node 'b'
				Empty
				(Node 'c'
					Empty
					Empty
				)
			)
			Empty

main = do
	print $ show (tree)
	putStrLn (fromTreeToString tree)
	print $ show ( (fromStringToTree . fromTreeToString ) tree)	
