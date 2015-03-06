position :: (Ord a, Num a) => [a] -> Integer

position (x1 : x2 : xs) = let
                                   pos (x1:x2:xs) currentPosition bestPosition bestResult = case (x1 + x2 > bestResult) of
                                                                            (True) -> pos (x2:xs) (currentPosition + 1) currentPosition (x1 + x2)
                                                                            (False) -> pos (x2:xs) (currentPosition + 1) bestPosition bestResult
                                   pos _ currentPosition bestPosition bestResult = bestPosition
                               in pos (x2 : xs) 2 1 (x1 + x2)
position _ = error "List contains less than two elements"

main = print (position [1,3])