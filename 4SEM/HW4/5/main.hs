import Control.Monad
import Data.List
import Data.Int

help :: IO ()
help = putStr "0 - exit\n1 - add value to sorted list\n2 - remove value from list\n3 - print list\n4 - help\n"

add :: Int -> [Int] -> [Int]
add e [] = [e]
add e (x : xs) = case (e <= x) of
					True -> e : x : xs
					False -> x : (add e xs)


remove :: Int -> [Int] -> [Int]
remove e [] = []
remove e (x : xs) = case (e == x) of
						True -> xs
						False -> x : (remove e xs)

pass :: IO ()
pass = return ()

commandFlow :: [Int] -> IO ()
commandFlow l = do
			line <- getLine
			let q = map (read :: String -> Int) $ words line

			let [a, b] = case (length q) of
							2 -> q
							1 -> [(q !! 0), (q !! 0)]

			case a of
				0 -> return ()
				1 -> commandFlow (add b l)
				2 -> commandFlow (remove b l)
				3 -> do
						putStrLn $ show l 
						commandFlow l
				4 -> do
						help
						commandFlow l

main = do
		help
		commandFlow []
	
