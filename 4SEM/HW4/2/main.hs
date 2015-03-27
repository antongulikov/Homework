import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

foldT :: (a -> a -> a) -> a -> Tree a -> a
foldT f s (Leaf x) = f s x
foldT f s (Branch l x r) = foldT f (foldT f (foldT f s l) r) (Leaf x)

tree = Branch ( Branch (Leaf 1) 2 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

test1 = TestCase $ assertEqual "\\x y -> x + y, s = 0" 6 $ foldT (\x y -> x + y) 0 tree
test2 = TestCase $ assertEqual "\\x y -> x * y, s = 1" 24 $ foldT (\x y -> x * y) 1 tree
test3 = TestCase $ assertEqual "\\x y -> x - y, s = 0" (-6) $ foldT (\x y -> x - y) 0 tree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]

main = do
	   runTestTT tests
