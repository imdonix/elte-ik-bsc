import Data.List
dropSpaces = dropWhile (\c -> c==' ')
trim = takeWhile (\c -> c/=' ') . dropWhile (\c -> c==' ')
monogram x = unwords(map (\(s:_) -> s : ".") (words x))
uniq :: Ord a => [a] -> [a]
uniq x =  map (\(a:_) -> a) (group (sort x))
repeated  x =  map (\(_:b:_) -> b) (group (sort x))
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys
zipWith' _ _ _ = []
dotProduct x y = sum (zipWith' (*) x y)
isPrime 0 = False
isPrime 1 = False
isPrime n = and ([(mod n i) > 0 | i <- [2..n-1]])
primes = filter isPrime [1..]
iteratee f n = n : map (f) ([1..])
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)
fibonacci = iteratee (fib) 0