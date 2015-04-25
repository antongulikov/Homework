import Control.Monad.State
import Data.List

changeVal :: Int -> Int -> [(Int, Int, Bool)] -> [(Int, Int, Bool)]
changeVal v nc [] = []
changeVal v nc ((vv, cc, fl) : xs) = if (v == vv)
										then
											if (nc < cc)
												then (v, nc, fl) : xs
												else (vv, cc, fl) : xs
										else (vv, cc, fl) : (changeVal v nc xs)


setTrue :: Int -> [(Int, Int, Bool)] -> [(Int, Int, Bool)]
setTrue v [] = []
setTrue v ((vv, cc, fl) : xs) = if (v == vv)
									then (vv, cc, True) : xs
									else (vv, cc, fl) : (setTrue v xs)


findVertex :: [(Int, Int, Bool)] -> (Int, Int)
findVertex [] = (-inf , inf)
findVertex ((v, c, fl) : xs) = if (not fl)
									then
										if (c < b)
											then (v, c)
											else (a, b)
									else (a, b)
							   where (a, b) = findVertex xs


update :: [(Int, Int, Int)] -> [(Int, Int, Bool)] -> Int -> [(Int, Int, Bool)] 
update [] cr currentCost = cr
update ((fir, sec, cost) : xs) cr currentCost = update xs (changeVal sec (cost + currentCost) cr) currentCost


dijkstra' :: [(Int, Int, Int)] -> State [(Int, Int, Bool)] [(Int, Int, Bool)]
dijkstra' g = do
				curState <- get
				let (x, y) = findVertex curState
				if (x < 0)
					then return []
					else do
						put (setTrue x curState)
						curState <- get
						put (update (filter (\(q,y,z) -> (x == q)) g) curState y)
						dijkstra' g						
						return []					
						

hd :: [(Int, Int, Bool)] -> [(Int, Int, Int)] -> [(Int, Int, Bool)]
hd stState g = snd (runState (dijkstra' g) $ stState)

dijkstra :: [(Int, Int, Int)] -> Int -> [(Int, Int, Bool)]
dijkstra g start = hd (map (\x -> if x == start then (x, 0, False) else (x, inf, False)) (nub ((map (\(x, y, z) -> y) g) ++ (map (\(x, y, z) -> x) g)))) g

inf = maxBound :: Int

main = do
	print $ dijkstra [(0, 1, 1), (0, 2, 3), (1, 3, 5), (2, 4, 9), (1, 4, 8), (3, 4, 2)] 0