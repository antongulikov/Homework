helpF :: [Char] -> [Char] -> Bool
helpF [] x = (length x) == 0
helpF ('(' : xs) y = helpF xs ('(' : y)
helpF ('[' : xs) y = helpF xs ('[' : y)
helpF ('{' : xs) y = helpF xs ('{' : y)
helpF (')' : xs) ('(' : ys) = helpF xs ys
helpF ('}' : xs) ('{' : ys) = helpF xs ys
helpF (']' : xs) ('[' : ys) = helpF xs ys
helpF _ _ = False

isCorrect :: [Char] -> Bool
isCorrect x = helpF x []
                