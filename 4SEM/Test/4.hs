magic :: [Float] -> Maybe Float

magic l = if (abs(z) > 0)
			then Just (sum(l) / z)
			else Nothing
		where z = productL l

productL :: [Float] -> Float
productL l = let
				pr' [] x = x	
				pr' (x:xs) ret = (productL xs) * cos(x) * ret
			in pr' l 1

main = do
		print (show (magic [0,1]))	