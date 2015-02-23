power2 :: Integer -> [Integer]
power2 n = [2^x | x <- [0..n-1]]
main = print (power2 42)