import Test.QuickCheck

newtype Polynom = Polynom [Int] deriving (Eq)

calc :: Polynom -> Int -> Int
calc (Polynom p) v = calc' p 0
						where
							calc' [] n = 0
							calc' (x : xs) n = (v^n) * x + calc' xs (n + 1)


add :: Polynom -> Polynom -> Polynom
add (Polynom p1) (Polynom p2) = Polynom (plus p1 p2)
								where
									plus [] p = p
									plus p [] = p
									plus (x : xs) (y : ys) = (x + y) : plus xs ys

substract (Polynom p1) (Polynom p2) = Polynom (minus p1 p2)
									where
										minus [] [] = []
										minus [] (x : xs) = (-x) : minus [] xs
										minus p [] = p
										minus (x : xs) (y : ys) = (x - y) : minus xs ys


mult :: Polynom -> Polynom -> Polynom
mult (Polynom p1) (Polynom p2) = Polynom [sum $ zipWith (*) (first n p1) (reverse (first n p2)) | n <- [1..(length p1 + length p1)]]
									where
										first n p1 = if (n > length p1)
														then p1 ++ (replicate (n - length p1) 0)
														else take n p1

sign :: Int -> String
sign x = if (x > 0)
			then "+"
			else ""

get :: Int -> Int -> String
get 0 n = ""
get x 0 = show x
get x 1 = sign x ++ show x ++ "X"
get x n = sign x ++ show x ++ "X^" ++ show n

instance Show Polynom where
    show (Polynom l) = getShow l 0
    				where
    					getShow [] n = ""
    					getShow (x : xs) n = get x n ++ getShow xs (n + 1)

testexp = Polynom [1,0,-2,3] 
    					
main = do
    print $ show testexp
    print $ calc testexp 0