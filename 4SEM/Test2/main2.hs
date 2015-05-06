mymap :: [Int] -> [(Int, Int)]
mymap [] = []
mymap [x] = []
mymap [x,y] = []
mymap [x,y,z] = [(y, x * z)]
mymap (x:y:z:xs) = (y, x * z) : mymap(y:z:xs)

get :: [Int] -> [Int]
get l = (mymap l) >>= (\(x,y) -> filter (\z -> x > y) [x])

main = do
		print $ get [1,2,4,1,5,1,2]