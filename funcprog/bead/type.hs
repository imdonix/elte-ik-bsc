repeatTimes :: a -> Int -> [a]
repeatTimes _ 0 = []
repeatTimes x n = x : repeatTimes x (n-1)

trd :: (a,b,c) -> c
trd (_, _, x) = x