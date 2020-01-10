import Data.Char
--Magyar Tamás
--csoport: A
--1
dropLastTwo :: [a] -> [a]
dropLastTwo x = take (length x - 2) x
--2
concatMaybe :: Maybe String -> Maybe String -> Maybe String
concatMaybe (Just x) (Just y) = Just (x++y)
concatMaybe Nothing (Just y) = Just y
concatMaybe (Just x) Nothing = Just x
concatMaybe Nothing Nothing = Nothing
--3
if' :: (a -> Bool) -> (a -> a) -> a -> a
if' f g x
    | f x = g x
    | True = x
--4
yes :: String -> String
yes s = concat [s ++ " " | i <- [1..]]
--5
maximumIf :: Ord a => (a -> Bool) -> [a] -> Maybe a
maximumIf f x
    | length (filter f x) < 1 = Nothing 
    | True = Just (maximum (filter f x))
--6
countdown :: Int -> [Int] -> Int
countdown n [] = n
countdown n (x:xs)
    | n < 0 = n
    | True = countdown (n-x) xs 
--7
evalPolynom :: [Int] -> Int -> Int
evalPolynom x y = sum [ (snd i)*y^(fst i) | i <- (zip [0..] x)] 
--8
mulByOddIndex :: [Int] -> [Int]
dol (x,y)
    | mod x 2 == 0 = y
    | True = x*y
mulByOddIndex x = map dol (zip [0..] x)
--9
pairs :: [a] -> [(a,a)]
pairs (x:y:xs) = (x,y) : pairs xs
pairs _ = [] 
--10
countString :: String -> String -> Int
countString x y = sum [1 | i <- [0..(length y)-(length x)], take (length x) (drop i y) == x ]
--11
mergeFirstN :: Int -> [a] -> [a] -> [a]
mergeFirstN 0 _ _ = []
mergeFirstN n (x:xs) (y:ys) = x : y : mergeFirstN (n-1) xs ys
mergeFirstN n (x:xs) [] = x : mergeFirstN (n-1) xs []
mergeFirstN n [] (y:ys) = y : mergeFirstN (n-1) [] ys
mergeFirstN _ _ _ = []
--12
largestNthPow :: Int -> [Int] -> Int
findmax n x = maximum (map (\u -> u^n) x)
largestNthPow n x = fst (reverse (filter (\u -> snd u == findmax n x) (zip x (map (\u -> u^n) x)))!!0)
--13
data RPS = Rock | Paper | Scissors
beats Rock Scissors = True
beats Paper Rock = True
beats Scissors Paper = True
beats _ _ = False
--14
game :: [RPS] -> [RPS] -> (Int, Int)
wins x y = length (filter (\u -> u) (map (\u -> beats (fst u) (snd u)) (zip x y)))
game x y = (wins x y, wins y x)
--15
eval :: String -> Int
split "" = []
split s = (takeWhile (\n -> n /= '+') s) : split (drop 1 (dropWhile (\n -> n /= '+') s))
eval s = sum (map (\u -> read u) (split s))
--16
camelCase :: String -> String
upper (x:y:s)
    | x == ' ' = toUpper y : upper (y:s)
    | True = y : upper (y:s)
upper _ =  []
camelCase s = (take 1 s) ++ filter (\u -> u /= ' ') (upper s)
