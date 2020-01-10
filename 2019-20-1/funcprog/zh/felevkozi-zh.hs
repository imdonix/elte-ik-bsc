--1
vector_length :: (Double, Double, Double) -> Double
vector_length (x,y,z) = sqrt(x^2 + y^2 + z^2) 

--2
headToBack :: [Int] -> [Int]
headToBack [] = []
headToBack (x:xs) = (take (length xs - 1) xs) ++ [x]

--3
divModEq :: Int -> Int -> Bool
divModEq _ 0 = True
divModEq 0 _ = True
divModEq x y = mod x y == div x y

--4
quadrant :: (Int, Int) -> Int

quadrant (x, y)
    | x > 0 && y > 0 = 1
    | x < 0 && y > 0 = 2
    | x < 0 && y < 0 = 3
    | x > 0 && y < 0 = 4
    | True = 0

--5
pair_sums :: [Int] -> [Int]
pair_sums [] = []
pair_sums (_:[]) = []
pair_sums (x:y:xs) = (x + y) : pair_sums xs

--6
deliveryCost :: [(String, Double, Int)] -> Int
suly (_,x,_) = x
ar (_,_,x) = x
deliveryCost [] = 0
deliveryCost x
    | or [suly i >= 50 | i <- x] = 0
    | sum [ar i | i <- x] > 30000 = 5000
    | True = 10000

--7
insert ::  Int -> Int -> [(Int, Int)] -> [(Int, Int)]
insert x y [] = [(x,y)]
insert x y (a:as)
    | snd a <= y = (x,y) : a : as
    | True = a : insert x y as