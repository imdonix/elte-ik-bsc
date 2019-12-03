data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun
data Time = T Int Int | E String
data USTime = AM Int Int | PM Int Int 

toIntU (AM h m) = h * 60 + m
toIntU (PM h m) = h * 60 + m + 12*60
toInt (T h m) = h * 60 + m
fromInt x = T (div x 60) (mod x 60)
showTime (T h m) = show h ++ ":" ++ show m 
eqTime (T h1 m1) (T h2 m2) = h1 == h2 && m1 == m2
isEarlier x y = toInt x < toInt y 
isBetween x y z = toInt y < toInt z && toInt x < toInt y
time x y
    | x >= 24 || x < 0 || y > 60 || y < 0 = error "nem jo"
    | True = T x y
showUSTime (AM h m) = show h ++ "." ++ show m ++ " am"
showUSTime (PM h m) = show h ++ "." ++ show m ++ " pm"
usTimeToTime  (AM h m) = T h m
usTimeToTime (PM 12 x) = (T 12 x) 
usTimeToTime  (PM h m) = T (h+12) m
timeToUSTime x = fromInt( toIntU x ) 