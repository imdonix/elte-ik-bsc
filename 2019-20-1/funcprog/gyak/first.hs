n::Int
n = 2

even' :: Int -> Bool
even' n = mod n 2 == 0
--odd' n = mod n 2 == 1
--odd' n = mod n 2 /= 0
odd' :: Int-> Bool
odd' n = not (even' n)
--even' n = not (odd' n)

divides' :: Int -> Int -> Bool
divides' a b = a `mod` b == 0