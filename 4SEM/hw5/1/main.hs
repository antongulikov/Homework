import Control.Monad

printL :: [Int] -> IO ()
printL [] = return ()
printL [x] = putStrLn $ show x
printL (x : xs) = do
				  putStr $ show x
				  putStr " + "
				  printL xs	

nothing :: Int -> IO ()
nothing x = return ()

rec :: Int -> Int -> [Int] -> IO ()
rec 0 k l = printL l
rec n k l = do
			if n >= k
				then rec (n - k ) k (k : l)
				else nothing k
			if (k - 1) > 0
				then rec n (k - 1) l
				else nothing k 
				

decomposition :: Int -> IO ()
decomposition n = rec n n []

main = do
		inp <- getLine
		let n = (read inp :: Int)
		decomposition n