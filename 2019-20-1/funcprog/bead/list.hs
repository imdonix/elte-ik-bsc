isIdentifierStart :: Char -> Bool
isIdentifierStart '_' = True
isIdentifierStart x = or [x == i | i <-['a'..'z']] 

isIdentifierPart :: Char -> Bool
isIdentifierPart '_' = True
isIdentifierPart  x = or [x == i | i <-['a'..'z']] || or [x == i | i <-['A'..'Z']] || or [x == i | i <-['0'..'9']]

isReserved :: String -> Bool
isReserved x = or [ x == s | s <- ["if","then","else", "module","import"]]

isValid :: String -> Bool
isValid "" = False
isValid (x:xs) = (isIdentifierStart x) && (and [isIdentifierPart c | c <- xs]) && not (isReserved (x:xs))