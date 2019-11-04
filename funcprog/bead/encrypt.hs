table :: [(Char, Char)]
table = (' ',' '):(zip ['a'..'z'] (['d'..'z']++['a'..'d']))

shift :: [(Char, Char)] -> Char -> Char
shift t c = snd (head[x | x <- t, fst x == c])

encrypt :: [(Char, Char)] -> String -> String
encrypt _ [] = ""
encrypt t (s:ss) = shift t s : encrypt t ss