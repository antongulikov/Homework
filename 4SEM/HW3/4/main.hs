data Tree a = Leaf a | Branch a [(Tree a)]

height :: Tree -> Int
height t = let
              calch (Leaf _) currentHeight = currentHeight
              calch (Branch _ x:xs) currentHeight = max (calch x (currentHeight + 1)) (calch xs (currentHeight + 1))
           in calch t 0

dist :: Tree -> Int
dist t = let
              calcd (Leaf _) currentHeight = currentHeight
              calcd (Branch _ x:xs) currentHeight = min (calcd x (currentHeight + 1)) (calcd xs (currentHeight + 1))
         in calcd t 0

