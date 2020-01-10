--Zárojelezés
--10 `rem` 3 == 3^2^1 || 8 > 23 `mod` 9 `div` 2 && False || True
correct_one = ((10 `rem` 3) == (3^(2^1))) || (((8 > ((23 `mod` 9) `div` 2)) && False) || True)
--(((((121 `mod` 9) `div` 5) == (((2 ^ 3) ^ 2) - (3 * 22) - 6))) && ((5 > (2 * (5 ^ 2))) || ((3 + (7 - 2)) * 3) > 10))
correct_two = 121 `mod` 9 `div` 5 == (2 ^ 3) ^ 2 - 3 * 22 - 6 && (5 > 2 * 5 ^ 2 || (3 + (7 - 2)) * 3 > 10)

--Locsolási terv
how_many_times = ceiling ((50 * 0.25) / 1.8)

--Függvényérték 
f x = 3*(x^5)+4*(x^3)+7*(x^2)+4
min_f = take 1 ([f x | x <- [1..], f x > 1000])

--Eredő ellenállás számítás
soros [] = 0
soros (x:xs) = x + soros xs

jobboldal [] = 0
jobboldal (x:xs) = (1/x) + parhuzamos xs
parhuzamos x = 1 / parhuzamos x

--Barátságos számpárok
kettohusz = sum [x | x <- [1..(220-1)], mod 220 x == 0]
kettonyolcvannegy= sum [x | x <- [1..(284-1)], mod 284 x == 0]
aze = kettohusz == 284 && kettonyolcvannegy == 220

--Számok és osztóik
osztok x = [y | y <- [1..x], mod x y == 0]
szosz = [(x, osztok x) | x <- [1..50]]

--Pitagoraszi számhármasok
szam_c a b = sqrt (a^2 + b^2)
szamharmas = [(a,b,szam_c a b) | a <- [1..150], b <- [1..150], abs ( 150 - (a + b + szam_c a b)) < 0.01 ]