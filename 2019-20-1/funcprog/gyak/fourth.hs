import Data.Char

{-
True : []
False : True : []
1:2:True:[]
--stack,
--heap,
--code

l :: [Bool]
l = True : False : True : []

"False" :True:False:False
-- : jobb asszociatív
True: (False:(True:[]))
[1..100]
[20,19..1]
[20..1]
[1,2,3]
['a'..'z']
['a','c'..'z']
[2,4..]

-}

-- head :: [a] -> a
headInt :: [Int] -> Int

headInt (x:_) = x

--headInt x : _ = x




tailInt :: [Int] -> [Int]
tailInt (_:xs) = xs

isSingleton :: [Int] -> Bool
isSingleton [] = False
--isSingleton (_:[]) = True

isSingleton [_] = True
isSingleton _ = False

--isSingleton [] = False
--isSingleton (_:l) = l == []

--isSingleton l = length l == 1


{-
isSingleton [_] = True
isSingleton _ = False
isSingleton [] = False
isSingleton (_:[]) = True
isSingleton (_:x) = x == []
isSingleton _ = False
-}

hasTwoElements :: [Int] -> Bool

hasTwoElements [] = False
--hasTwoElements (x:[]) = False
--hasTwoElements (x:y:[]) = True
hasTwoElements [_,_] = True
hasTwoElements _ = False

nullInt'' x = length x == 0

-- ++

--https://people.inf.elte.hu/poor_a/
--https://people.inf.elte.hu/poor_a/fp4.pdf

--import Data.Char -- toUpper

toUpperFirst :: String -> String
toUpperFirst (h:t) = toUpper h : t

isLetter' :: Char -> Bool
isLetter' c = elem c ['a'..'z'] || elem c ['A'..'Z']

-- list comprehension = generátorok

mountain :: Int -> [Int]
mountain x = [1..x-1] ++ [x,x-1..1]

divisors :: Int -> [Int]
divisors x = [xx | xx <-[1..x], x `mod` xx == 0]

powersOfTwo = [2^x|x<-[0..]]


pii = 4 * sum [1/x-1/(x+2)|x<-[1.0,5.0..10000.0]]

oraperc = [(o,p)|o<-[0..23],p<-[0..59]]