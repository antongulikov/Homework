isPalindrome :: String -> Bool
isPalindrome x = x == reverse x
main = print (isPalindrome "abaaba")