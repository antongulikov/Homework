--func f g l = filter f (map g l)
--func f g l = filter (f . g) l
--func f g = filter (f . g)
--func f g = filter (( . ) f g)
--func f g = (filter .) . ( . ) f g
func = (filter .) . ( . )

main = do
	print $ func (\x -> x > 0) (\x -> x - 4) [1, 5, 10, -2, 4, 2]