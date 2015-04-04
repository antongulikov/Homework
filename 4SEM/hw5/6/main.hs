import Test.QuickCheck

data Expression = X | Const Int | Expression :+: Expression | Expression :-: Expression 
					| Expression :*: Expression | Expression :^: Int deriving(Eq, Show)

calc :: Expression -> Int -> Int
calc e v = case e of
			(X) -> v
			(Const c) -> c
			(l :+: r) -> (calc l v) + (calc r v)
			(l :-: r) -> (calc l v) - (calc r v)
			(l :*: r) -> (calc l v) * (calc r v)
			(l :^: n) -> (calc l v) ^ n

derivate :: Expression -> Expression
derivate e = case e of
				(X) -> Const 1
				(Const c) -> Const 0
				(l :+: r) -> (derivate l) :+: (derivate r)
				(l :-: r) -> (derivate l) :-: (derivate r)
				(l :*: r) -> ((derivate l) :*: r) :+: ((derivate r) :*: l)
				(l :^: n) -> (Const n :*: (l :^: (n - 1))) :*: (derivate l)

simplify :: Expression -> Expression
simplify e = case e of
				(l :+: r) -> simplify' (simplify l :+: simplify r)
				(l :-: r) -> simplify' (simplify l :-: simplify r)
				(l :*: r) -> simplify' (simplify l :*: simplify r)
				(l :^: n) -> simplify' (simplify l :^: n)
				(X) -> X
				(Const c) -> Const c

simplify' :: Expression -> Expression
simplify' e = case e of
				(Const 0 :+: x) -> x
				(Const 0 :*: x) -> Const 0
				(Const 0 :^: x) -> Const 0
				(x :+: Const 0) -> x
				(x :*: Const 0) -> Const 0
				(x :^: 0) -> Const 1
				(Const 1 :*: x) -> x
				(x :*: Const 1) -> x
				(x :^: 1) -> x
				(Const n1 :+: Const n2) -> Const (n1 + n2)
				(Const n1 :-: Const n2) -> Const (n1 - n2)
				(Const n1 :*: Const n2) -> Const (n1 * n2)
				(Const n1 :^: n2) -> Const (n1 ^ n2)
				_ -> e

expr1 = ((Const 3 :*: X) :+: (X :^: 1)) :*: (Const 1 :+: X)
expr2 = ((X :+: X) :*: (X :+: X) :*: (X :+: X))

dexpr2 = (Const 24 :*: (X :*: X))
dexpr1 = Const 4 :+: (Const 8 :*: X)

main = do
		quickCheck (\s -> calc (derivate expr1) s == calc dexpr1 s)
		quickCheck (\s -> calc (derivate expr2) s == calc dexpr2 s)
		print $ show (simplify expr1)
		print $ show (simplify expr2)
		print $ show (simplify ( derivate expr1 ))
		print $ show (simplify ( derivate expr2 ))
