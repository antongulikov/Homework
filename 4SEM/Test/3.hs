import Data.Maybe
import Data.List
findElem :: (Eq a) => a -> [a] -> Maybe Int
findElem n l = elemIndex n l

main = do
		putStr (show ( findElem 2 [1,2,3]))