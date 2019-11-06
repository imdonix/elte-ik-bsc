
-- 0! = 1
-- n! = n * (n-1)!

-- 5! = 5 * 4! = 5*4*3! = 5*4*3*2! = 5*4*3*2*1! = 5*4*3*2*1*0! = 5*4*3*2*1*1










fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact(n - 1)

-- negatív szám?
--20,21,66?

-- Fibonacci
-- 0,1,2,3,4,5,6, 7
-- 0,1,1,2,3,5,8,13
fib :: Integer -> Integer
-- alapeset
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

-- haskell memoization
-- zárt torok

fib' n
 | n <= 1 = n
 | otherwise = fib' (n-1) + fib' (n-2)

pow :: Int -> Int -> Int
pow x 0 = 1
pow x y = x*pow x (y-1)


range :: Int->Int->[Int]
range a b
 |a==b = [a]
 |b<a = range b a
 |otherwise = a:range (a+1) b

length':: [a]->Int
length' [] = 0
length' (_:t) = 1+length' t




minimum' :: [Int] -> Int
minimum' (h:t)
 | null t = h
 | h<minimum' t = h
 | otherwise = minimum' t




everySecond :: [a]->[a]
everySecond [] = []
everySecond [_] = []
everySecond (_:(h:t)) =h:everySecond t



elem' :: Char -> [Char]->Bool
elem' _ [] = False
elem' e (h:t)
 | e == h = True
 | otherwise = elem' e t


value :: Int -> [(Int,String)] -> String
value _ [] = error "Nincs ilyen"
value i ((ind,elem):t)
 | i == ind = elem
 | otherwise = value i t


--fibo :: Int -> (Int,Int)-> (Int,Int,Int)