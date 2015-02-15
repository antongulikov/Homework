fibonachi :: Integer -> Integer
fibonachi 0 = 1
fibonachi 1 = 1
fibonachi n = fibonachi(n - 1) + fibonachi(n - 2)

main = print $ fibonachi 5