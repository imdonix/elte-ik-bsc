import Data.List
rook :: (Int, Int) -> [(Int, Int)]
--rook (x,y) = [(x,i) | i <- [0..7], x/=i] ++ [(i,y) | i <- [0..7], y/=i]
rook (a,b)=[(x,y) | x<-[0..7], y<-[0..7], (x/=a && y==b) || (x==a && y/=b)]
knight :: (Int, Int) -> [(Int, Int)]
knight (x,y) = [(i,j) | i <- [0..7], j <- [0..7], (abs (x-i) + abs (y-j)) == 3 && i/=x && j/=y]
attacks :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> Bool
attacks f src des = any (\pos -> elem pos des) (f src)
moves :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> [[(Int, Int)]]
moves f src des = map (\x -> [x] ++ (filter (\r -> r /= src) des)) (f src)