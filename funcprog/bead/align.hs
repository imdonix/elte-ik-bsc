len :: [Char] -> Int
len [] = 0
len (x:xs) = 1 + len xs

align :: Int -> [Char] -> [Char]
align x s
    | len s > x - 1 = s
    | True = align x (' ' : s)