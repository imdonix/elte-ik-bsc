-- Magyar Tamás 2019|12|11

import Data.Char

--1
sortTuple :: Ord a => (a, a) -> (a, a)
sortTuple (x,y) = (min x y,max x y)

--2
caseSwap :: Char -> Char
caseSwap x
    | not (isLetter x) = x
    | isUpper x = toLower x
    | True = toUpper x

--3
count :: Eq a => a -> [a] -> Int
count _ [] = 0
count n (x:xs)
    | x == n = 1 + count n xs
    | True = count n xs

--4
listMul :: [Int] -> [Int] -> Int
listMul x y = sum (map (\(i,j) -> i*j) (zip x y))

--5
sameSign :: [Int] -> Bool
sameSign x = and (map (\n -> n <= 0) x) || and (map (\n -> n >= 0) x)

--6
isCorrect :: [(Int, Int)] -> Bool
isCorrect x = and (map (\(u,v) -> u == v ) (zip (map snd x) (map fst (drop 1 x))))

--7
filterMany :: [a -> Bool] -> [a] -> [a]
filterMany fs xs = filter (\x -> and (map (\f -> f x) fs)) xs 

--8
conditionalMax :: Ord a => (a -> Bool) -> [a] -> Maybe a
conditionalMax f xs
    | or (map f xs) = Just (maximum (filter f xs))
    | True = Nothing

--9
data Season = Winter | Spring | Summer | Autumn
    deriving (Show,Eq,Enum,Bounded)
nextSeason :: Season ->  Season
nextSeason Autumn = Winter
nextSeason x = succ x

--10
seasonAfterMonths :: Int -> Season
seasonAfterMonths n = [Winter,Spring,Summer,Autumn]!!(div (mod (1+n) 12) 3)

--11
removeSpecial :: String -> String
engabc = ' ' : ['a'..'z'] ++ ['A'..'Z'] ++ ['0'..'9']
removeSpecial s = filter (\c -> elem c engabc) s

--12
isSublist :: Eq a => [a] -> [a] -> Bool
isSublist x y = and (map (\a -> elem a y) x)

--13 ??? ez lehetette volna egyszerűbben!?
multipleElems :: Eq a => [a] -> [a]
clearmultiple (x:xs) = x : clearmultiple (filter (\y -> y /= x) xs)
clearmultiple [] = []
multipleElems x = clearmultiple (filter (\a -> length (filter (\b -> b == a) x) > 1) x)

--14
maxTempChange :: [(Int, Int)] -> Int
tmpmax (x:y:xs)
    | snd x > snd y = tmpmax (x:xs)
    | True = tmpmax (y:xs)
tmpmax (x : []) = x
maxTempChange xs = fst (tmpmax (zip [1..] (map (\x -> abs(fst x - snd x)) xs)))

--15
primeIndex :: [a] -> [a]
prime n = length [x | x <- [1..n], mod n x == 0] == 2
primeIndex xs = map (\x -> snd x) (filter (\x -> prime (fst x)) (zip [1..] xs))