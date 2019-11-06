import Data.List



f(xs:x)=xs
g(xs:x)=x


























{-
[2*x|x<-[1..5]]
[2*x|x<-[1..5],even x, x>3]
[x^3|x<-[1..5],y<-[1..3]]
[x^y|x<-[1..5],even x,y<-[1..3]]
[x^y | even x, x<-[1..5], y<-[1..3]]
-- először lista és csak utána filter
-}
{-


[x!!i|i<-[0..length x-1]]
-- láncolt lista! indexelés lassú
[c|c<-x]





-- 2 lista párhuzamosan
[x^y | x<-[1..5], y<-[1..3]]
zip [1..5] [1..3]
[fst x ^ snd x | x<-zip [1..5] [1..3]]
[a^b | (a,b)<-zip [1..5] [1..3]]




-- sorszámozás
zip [0..] ['a'..'z']

cycle


allPositive :: [Int] -> Bool
allPositive l = null [x|x<-l, x<0]

-}


isPrimee1 n = 2 == length [x|x<-[1..n],n`mod`x==0]
isPrimee2 n = null [x|x<-[2..n-1],n`mod`x==0]
isPrimee3 n = [1,n] == [x|x<-[1..n],n`mod`x==0]














isPrime1 n = 2== length [x|x<-[1..n],n`mod`x==0]
isPrime2 n = null [x|x<-[2..n-1],n`mod`x==0]
isPrime3 n = [1,n] == [x|x<-[1..n],n`mod`x==0]




isPrime x = [1,x] == [d|d<-[1..x],x`mod`d==0]
isPrime' x = 2 == length [d|d<-[1..x],x`mod`d==0]
isPrime'' x = null [d|d<-[2..x-1],x`mod`d==0]
-- length [1..]
-- null [1..]


primes = [p|p<-[2..],isPrime p]


allPositive :: [Int] -> Bool
allPositive l = null [e|e<-l,e<=0]



dominoes = [(a,b)|a<-[0..6],b<-[0..a]]


naturalPairs = [(a-b,b)|a<-[0..],b<-[0..a]]


alphabet = zip [0..] ['a'..'z']

everyThird = ['c','f'..'z']

everyThird' = [c|(n,c)<-(zip (cycle [0..2]) ['a'..'z']),n==2]


courses =
    [ ("Programozasi nyelvek II.", [("Horvath", "Istvan", "BDE91E"), ("Fodros", "Aniko", "DDA3KX")])
    , ("Imperativ programozas", [("Nemeth", "Eniko", "ALX1K0"), ("Horvath", "Istvan", "BDE91E")])
    , ("Funkcionalis programozas", [("Kiss", "Elemer", "ABCDE6"), ("Nagy", "Jakab", "CDE560")])
    ]
students = [n|(c,s)<-courses,c=="Funkcionalis programozas",(_,_,n)<-s]



months = [31,28,31,30,31,30,31,31,30,31,30,31]
calendar = [(m,d)|(m,dn)<-zip [1..] months,d<-[1..dn]]



compress s = [(length ss, ss!!0) |ss <-group s]

decompress s = concat [replicate n c|(n,c)<-s]
