digitSum :: Integer -> Integer
digitSum 0 = 0
digitSum x = x `mod` 10 + digitSum (x `div` 10)
main = print (digitSum 42)