check :: (a -> Bool) -> [a] -> Bool
check f l = length ( filter (not . f) l ) == 0


