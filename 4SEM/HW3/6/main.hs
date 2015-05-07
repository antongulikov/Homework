--func f g l = filter f (map g l)
--func f g = (filter f) . (map g)
--fun2 f = ((.) (filter f)) . map   	
--func = flip (.) map . (.) . filter 
func = (. map) . (.) . filter	
main = do
	print $ func (>0) (+1) [-1,2]