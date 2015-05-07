import System.Directory
import System.Environment
import Control.Monad
import Data.List
import Data.Int
import System.Exit
import Control.Monad.Error

help :: IO ()
help = putStr "press to perform action\n-------\n0 - exit\n1 - add subscriber and phone\n3 - find phone by subscriber\n2 - find subscriber by phone\n4 - store to file\n5 - load from file\n6 - help\n"

pass :: IO ()
pass = return ()

add :: String -> String -> [(String, String)] -> ErrorT String IO [(String, String)]
add s p l = if (find' (s, p) l)
				then throwError "Already Had"
				else return ((s, p) : l)
			where
				find' (a, b) [] = False
				find' (a, b) ((x, y) : xs) = (a == x || b == y) || find' (a, b) xs

findSub :: String -> [(String, String)] -> ErrorT String IO String
findSub p l = if null ret
				then throwError "Doesn't exist!"
				else return ret
			  where
			  	ret = findSub' p l
			  		where
			  			findSub' p [] = ""
			  			findSub' p ((x, y) : xs) = if (p == y) then x else findSub' p xs


findPhone :: String -> [(String, String)] -> ErrorT String IO String
findPhone p l = if null ret
				then throwError "Doesn't exist!"
				else return ret
			  where
			  	ret = findPhone' p l
			  		where
			  			findPhone' p [] = ""
			  			findPhone' p ((x, y) : xs) = if (p == x) then y else findPhone' p xs

getString :: [(String, String)] -> String
getString [] = ""
getString ((a, b) : xs) = a ++ "\n" ++ b ++ "\n" ++ getString xs

getList :: [String] -> [(String, String)]
getList [] = []
getList (x : y : xs) = (x, y) : (getList xs)

commandFlow :: [(String, String)] -> IO ()
commandFlow l = do
			line <- getLine
			let q = map (read :: String -> Int) $ words line
			let a = q !! 0
			case a of
				0 -> return ()
				1 -> do
					putStrLn "type subscriber and phone in two different lines"
					sub <- getLine
					phone <- getLine
					r <- runErrorT (add sub phone l)
					case (r) of
						(Left e) -> do
										putStrLn ("Fail!!!!!!!" ++ (show e))
										help
										commandFlow l
						(Right x) -> do
										putStrLn ("Success!!!")
										help
										commandFlow x
				2 -> do
					putStrLn "type a phone"
					phone <- getLine
					r <- runErrorT (findSub phone l)
					case (r) of
						(Left e) -> do
										putStrLn ("Fail --  " ++ (show e))
										help
										commandFlow l
						(Right ret) -> do
										putStrLn ("Find ---  " ++ ret)
										help
										commandFlow l
				3 -> do
					putStrLn "type a phone"
					sub <- getLine
					r <- runErrorT (findPhone sub l)
					case (r) of
						(Left e) -> do
										putStrLn ("Fail --  " ++ (show e))
										help
										commandFlow l
						(Right ret) -> do
										putStrLn ("Find ---  " ++ ret)
										help
										commandFlow l
				6 -> do
						help
						commandFlow l

				4 -> do
			    		putStrLn "Type output file"
			    		outPut <- getLine
			    		writeFile outPut (getString l)
			    		help
			    		commandFlow l

				5 -> do
			    		putStrLn "Type input file"
			    		input <- getLine
			    		fileExists <- doesFileExist input
			    		if fileExists then do
											inputData <- readFile input
											let len = length $ lines inputData
											if (len `mod` 2 > 0)
								    			then do
							    					putStrLn "Error input data"
							    					help
			    									commandFlow l
								    			else
								    				pass
											let lq = getList (lines inputData)
											help
											commandFlow lq
			    						else do
												putStrLn "File doesn't exist"
												help
												commandFlow l
			return ()

main = do
		help
		commandFlow []