runs :: Int -> [a] -> [[a]]
runs n [] = []
runs n xs = take n xs : runs n (drop n xs)

join :: [a] -> [[a]] -> [a]
join x [] = []
join x (y:ys)
    | length ys < 1 = y ++ (join x ys)
    | True = y ++ x ++ (join x ys)