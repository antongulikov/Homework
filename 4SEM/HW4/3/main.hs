import Test.QuickCheck

cntSum = sum . map (\x -> (x + 1) `mod` 2) 
cntFoldr = foldr (\x y -> (x + 1) `mod` 2 + y) 0
cntFilter = length . filter (\x -> x `mod` 2 == 0) 

ac :: Int -> Int -> Int -> Int -> Bool
ac a b c d = a == b && b == c && c == d

main = do
       quickCheck (\s -> let l = [0 .. abs s] 
    				     in ac (cntSum l) (cntFoldr l) (cntFilter l) ((abs s) `div` 2 + 1))
       quickCheck (\s -> let l = [1 .. abs s] 
     				     in ac (cntSum l) (cntFoldr l) (cntFilter l) ((abs s) `div` 2))
       quickCheck (\s -> let l = [- abs s .. 1] 
    				     in ac (cntSum l) (cntFoldr l) (cntFilter l) ((abs s) `div` 2 + 1))
       quickCheck (\s -> let l = [- abs s .. 0] 
    				     in ac (cntSum l) (cntFoldr l) (cntFilter l) ((abs s) `div` 2 + 1))





