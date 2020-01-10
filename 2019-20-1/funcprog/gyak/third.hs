fuggveny a b = a + b

not' :: Bool -> Bool
not' True = False
not' False = True
---- ^^^^^
---- Minta
---- Minta illesztés



f :: Int -> Int
f 0 = 1
f 1 = 3
f n = n
-- Sorrend?
-- Kihagy?
-- g = f 5

-- ghci -Wall


isFruit :: String -> Bool
isFruit "apple" = True
isFruit "grape" = True
isFruit "tomato" = True
isFruit "banana" = True
isFruit _ = False

--- people.inf.elte.hu/poor_a/
--- 3. gyakorlat

and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False

(&&&) :: Bool -> Bool -> Bool
True &&& True = True
_ &&& _ = False




(&|) :: Bool -> Bool -> Bool
a &| b = a && b


--[n^x|n<-[1..5],x<-[1..3]]
--[[n^x|x<-[1..3]]|n<-[1..5]]


replspace :: Char -> Char
replspace ' ' = '#'
replspace s = s

maptext :: String -> String
maptext s = map replspace s
