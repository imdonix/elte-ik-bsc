
pythagorean :: Int -> Int -> Int -> Bool
pythagorean a b c = a ^2 + b^2 == c^2

book :: (String, String, Int, Bool)
book =  ("Harry Potter 5", "J. K. Rowling",2006,True)


getAuthor :: (String,String,Int,Bool)->String
getAuthor (title, author,year,available) = author
--getAuthor (_, author,_,_) = author
--          ^^^^^^^^^^^^^^^
--                minta
-- minta illesztés - pattern matching


getTitle :: (String,String,Int,Bool)->String
getTitle (title, author,year,available) = title


badBook :: (String,Int,Bool)
badBook = ("Harry Potter",1997,False)

get5th (_,_,_,_,a,_,_,_,_,_) = a

badBook2 :: (String,Int,String,Bool)
badBook2 = ("Matalapok", 2019, "Csorgo Istvan", True)

get5th (_,_,_,_,a,_,_,_,_,_) = a
-- fst
-- snd

-- 1.
add :: (Int,Int) -> (Int,Int) -> (Int,Int)
add (a,b) (c,d) = (a*d+c*b , b*d)

-- 2.
mul:: (Int,Int) -> (Int,Int) -> (Int,Int)
mul  (a,b) (c,d) =(a*c,b*d)

quadratic :: Double -> Double -> Double -> (Double,Double)
quadratic a b c = (((-b) - sqrt ( b^2 - 4*a*c))/(2*a), ((-b) + sqrt ( b^2 - 4*a*c))/(2*a))
