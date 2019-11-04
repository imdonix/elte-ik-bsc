nand :: Bool -> Bool -> Bool
nand True True = False
nand x y = True

onAxis :: (Integer, Integer) -> Bool
onAxis (0, y) = True
onAxis (x, 0) = True
onAxis (x, y) = False

punctuation :: Char -> Bool
punctuation '?' = True
punctuation '!' = True 
punctuation '.' = True 
punctuation c = False 