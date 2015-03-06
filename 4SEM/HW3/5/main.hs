isCorrect :: [Char] -> Bool
isCorrect x = let
               correct :: [Char] -> Integer -> Bool	 
               correct (x:xs) balance = case (balance < 0) of
               	                        (True) -> False
               	                        (False) -> correct xs (balance + sign x)
               	                        where sign x = if (x == '(') then 1 else -1
               correct [] balance = (balance == 0)
            in correct x 0
main = print (isCorrect "(((())()()))")
                