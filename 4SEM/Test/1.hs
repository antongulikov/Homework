primes :: [Int]
primes = sieve [2..]
			where sieve (p : xs) = p : sieve[x|x <- xs, x `mod` p > 0]

main = do
		print (take 15 primes)