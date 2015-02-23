position :: (Eq a, Num a) => a -> [a] -> Integer
position x [] = -1
position x (y:ys) = case (x == y, next) of
                    (True, _) -> 0
                    (False, -1) -> -1
                    (False, n) -> n + 1
                    where next = position x ys

main = print (position 141195 [0..10^6]) 