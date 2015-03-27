produce :: Int -> [Int]
produce n = [1..n] >>= (\x -> map (*x) [1..n])

main = do
	   str <- getLine
	   let n = (read str :: Int)	
	   print $ produce n