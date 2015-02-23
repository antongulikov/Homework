helpR :: [a] -> [a] -> [a]
helpR [] x = x
helpR (x:xs) y = helpR xs (x:y)

reverseL :: [a] -> [a]
reverseL x = helpR x []
main = print (reverseL [0..5])