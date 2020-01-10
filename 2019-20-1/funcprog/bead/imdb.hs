movies = [("Green Book", 8.3, "Peter Farrelly"),("Inception", 8.8, "Christopher Nolan"),("The Dark Knight", 9.0, "Christopher Nolan"),("The Last Jedi", 7.2, "Rian Johnson"), ("Sicario", 7.6, "Denis Villeneuve")]

imdbAtLeast :: Double -> (String,Double,String) -> Bool
imdbAtLeast x (_, y, _) = y >= x
director :: String ->  (String,Double,String)  -> Bool
director x (_, _, y) = y == x
and_ x y m =  x m && y m
or_ x y m =  x m || y m
search :: ((String,Double,String) -> Bool) -> [(String,Double,String)] -> [(String,Double,String)]
search f x = filter f x