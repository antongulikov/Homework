import Data.Maybe
import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findElement :: (a -> Bool) -> Tree a -> [a]

findElement p (Leaf x) = if p x 
						 then [x]
						 else []

findElement p (Branch l x r) = if p x
                               then concat [[x], findElement p l, findElement p r]
                               else concat [findElement p l, findElement p r]
                                                
tree = Branch ( Branch (Leaf 1) 2 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

test1 = TestCase $ assertEqual "\\x -> x > 0" [1, 2, 1, 3, 2] $ findElement (\x -> x > 0) tree
test2 = TestCase $ assertEqual "\\x -> x < 0" [-1, -2] $ findElement (\x -> x < 0) tree
test3 = TestCase $ assertEqual "\\x -> abs x == 2" [2, 2, -2] $ findElement (\x -> abs x == 2) tree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]
                                                
main = do
	   runTestTT tests