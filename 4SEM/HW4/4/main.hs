import Test.HUnit

diff :: (Eq a) => [a] -> Bool
diff [] = True
diff (x : xs) = case (x `elem` xs) of
                (True) -> False
                (False) -> diff xs

test1 = TestCase $ assertEqual "[0..7]" True $ diff [0..7]
test2 = TestCase $ assertEqual "[-1..1]" True $ diff [-1..1]
test3 = TestCase $ assertEqual "[0, 1, 2, 3, 0]" False $ diff [0, 1, 2, 3, 0]
test4 = TestCase $ assertEqual "[0]" True $ diff [0]
tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3, TestLabel "test4" test4]
    
main = runTestTT tests
