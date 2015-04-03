data Products = Book {
		name :: String,
		author :: String,
		price :: Int
	} |
		Magazine {
		name :: String,
		year :: Int,
		number :: Int,
		price :: Int
	}




cost :: [Products] -> Int
cost [] = 0
cost (x : xs) = (price x) + (cost xs)

a = Book "aw" "wb" 3
b = Magazine "qa" 213 23 1
c = Book "1q" "ww" 4

main = do
	putStr $ show (cost [a,b,c])

