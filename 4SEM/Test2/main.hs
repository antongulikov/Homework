get :: Char -> Int -> String
get ch 0 = ""
get ch n = ch : get ch (n - 1)

work :: Int -> Int -> IO()
work n k = case (l > n) of
			True -> return ()
			False -> do
						putStrLn $ (get ' ' ((n - l) `div` 2)) ++ (get '*' l) ++ (get ' ' ((n - l) `div` 2))
						if k == 1
							then work n (k - 4)
							else work n (k - 2)
		   where l = abs(k)

main = do
		nStr <- getLine
		let n = (read nStr :: Int)
		work n n
		