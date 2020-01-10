{-
1. Írjuk meg az f függvényt, mely egy minimum két elemű, Int párok listájának az első két pár összes elemét összeadja! (1 pont)
2. Írjuk meg a timeAdd függvényt, amely egy óra és perc párként megadott időt ad össze! (Az óra a pár első tagja, a perc a pár második tagja.) (A maradékos osztáshoz használjuk a mod és a div függvényeket) (1 pont)
3. Készítsünk egy isSmile függvényt, mely eldönti egy paraméterként kapott String-ről, hogy szmájli-e? (Egy String akkor szmájli, ha az első karaktere ':' vagy ';' és a második ')', ']' vagy '}' és nincs több karakter benne) (1 pont)
4. Készítsük el a bimBam függvényt, mely egy egész számot kap paraméterűl, és ha a szám 3-al osztható, visszaadja, hogy "Bim", ha 5-el osztható, visszaadja, hogy "Bam" és ha osztható 3-al és 5-el is, akkor visszaadja, hogy "BimBam", máskülönben "". (1 pont)
5. Írjuk meg a minList függvényt, ami két listából képez egy új listát, amelyben minden indexen a két listából a kisebbik van. (2 pont)
6. Számoljuk meg egy szövegben a nagy kezdőbetűs szavak számát! (2 pont)
7. Írjuk meg a oneMatrix függvényt, amely készít egy csupa 1-esekből álló, $n \times n$-es mátrixot ( $n$ hosszú, 1-eseket tartalmazó listák listáját ). (2 pont)
-}

--1
f :: [(Int, Int)] -> Int
f (x:y:xs) = fst x + snd x + fst y + snd y

--2
timeAdd :: (Int, Int) -> (Int, Int) -> (Int, Int)
toInt x = fst x * 60 + snd x 
timeAdd x y = (mod (div (toInt x + toInt y) 60) 24 , mod (toInt x + toInt y) 60)

--3
isSmile :: String -> Bool
isSmile (x:y:[]) = or [x == i | i <- [':',';']] && or [y == i | i <- [')',']','}']]
isSmile x = False

--4
bimBam :: Int -> String
bimBam x
    | mod x 5 == 0 && mod x 3 == 0 = "BimBam"
    | mod x 3 == 0 = "Bim"
    | mod x 5 == 0 = "Bam"
    | True = ""

--5
minList :: [Int] -> [Int] -> [Int]
minList _ [] = []
minList [] _ = []
minList (x:xs) (y:ys)
    | x < y = x : minList xs ys
    | True = y : minList xs ys

--6
wordNumWithCapital :: String -> Int
isUpper c = or [c == x | x <- ['A'..'Z']]
findSpace _ [] = []
findSpace n (x:xs) 
    | x == ' ' = n : findSpace (n+1) xs
    | True = findSpace (n+1) xs
wordNumWithCapital [] = 0
wordNumWithCapital s = length [x | x <- findSpace 0 (' ':s), isUpper ((' ':s) !! (x + 1))]

--7
oneMatrix :: Int ->  [[Int]]
oneMatrix x = [[1 | j <- [1..x]] | i <- [1..x]]