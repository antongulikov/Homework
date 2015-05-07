import Data.List
import Data.Maybe
import Control.Monad.State

data HashTable key value = HashTable { hash :: (key -> Int), table :: [(Int, value)]}

findE :: key -> HashTable key value -> [value]
findE k (HashTable func tbl) = find' (func k) tbl
								where 
									find' v [] = []
									find' v ((x, y) : xs) = if (v == x)
																then y : find' v xs
																else find' v xs


insertE :: (Eq value) => key -> value -> HashTable key value -> HashTable key value
insertE k v (HashTable func tbl) = case (elem v (findE k (HashTable func tbl))) of
									False -> HashTable func ((func k, v) : tbl)
									True -> HashTable func tbl

removeE :: (Eq value, Eq key) => key -> value -> HashTable key value -> HashTable key value
removeE k v (HashTable func tbl) = case (elem v (findE k (HashTable func tbl))) of
										False -> (HashTable func tbl)
										True -> HashTable func (remove' (func k, v) tbl)
										where
											remove' (a, b) [] = []
											remove' (a, b) ((x, y) : xs) = if (a == x && y == b)
																			then xs
																			else (x, y) : remove' (a, b) xs

rhelp :: (Eq value, Eq key) => key -> value -> State (HashTable key value) (HashTable key value)
rhelp k v = do
		a <- get
		put (removeE k v a)
		return a

remove :: (Eq value, Eq key) => key -> value -> HashTable key value -> HashTable key value
remove k v (HashTable func tbl) = snd (runState (rhelp k v) $ (HashTable func tbl))

ihelp :: (Eq value, Eq key) => key -> value -> State (HashTable key value) (HashTable key value)
ihelp k v = do
		a <- get
		put (insertE k v a)
		return a

insert :: (Eq value, Eq key) => key -> value -> HashTable key value -> HashTable key value
insert k v (HashTable func tbl) = snd (runState (rhelp k v) $ (HashTable func tbl))