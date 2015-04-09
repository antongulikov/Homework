f x l = map (\y -> y*x) l
f x = map (\y -> y * x)
f x = map (*x)
f = map . (*)
