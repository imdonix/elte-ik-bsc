- Melyek azok a gyümölcsök, amelyeket Micimackomackó szeret?\
`π gyumolcs(σ nev='Micimacko' (szeret))`

- Melyek azok a gyümölcsök, amelyeket Micimackomackó nem szeret? (de valaki más igen)\
`π gyumolcs (szeret) - π gyumolcs(σ nev='Micimacko' (szeret))`

- Kik szeretik az almát?\
`π nev (σ gyumolcs='alma' (szeret))`

- Kik nem szeretik a körtét? (de valami mást igen)\
`π nev (szeret) - π nev (σ gyumolcs='korte' (szeret))`

- Kik szeretik vagy az almát vagy a körtét?\
`π nev (σ gyumolcs='korte' or gyumolcs='alma' (szeret))`

- Kik szeretik az almát is és a körtét is?\
`π nev (σ gyumolcs='alma' (szeret)) ∩ π nev (σ gyumolcs='korte' (szeret))`

- Kik azok, akik szeretik az almát, de nem szeretik a körtét?\
`π nev (σ gyumolcs='alma' (szeret)) - π nev (σ gyumolcs='korte' (szeret))`

## DOLGOZO

- Kik azok a dolgozók, akiknek a fizetése nagyobb, mint 2800?\
`π dnev (σ fizetes>2800 (dolgozo))`

- Kik azok a dolgozók, akik a 10 - es vagy a 20 - as osztályon dolgoznak?\
`π dnev (σ oazon=10 or oazon=20 (dolgozo))`

- Kik azok, akiknek a jutaléka nagyobb, mint 600?\
`π dnev (σ jutalek>600 (dolgozo))`

- Kik azok, akiknek a jutaléka nem nagyobb, mint 600?\
`π dnev (dolgozo) - π dnev (σ jutalek>600 (dolgozo))`

- Kik azok a dolgozók, akiknek a jutaléka ismeretlen (nincs kitöltve, vagyis NULL)?\
`π dnev (σ jutalek=NULL (dolgozo)) !!KITERJESZTETT!!`

- Adjuk meg a dolgozók között előforduló foglalkozások neveit.\
`π foglalkozas (dolgozo)`

- Adjuk meg azoknak a nevét és kétszeres fizetését, akik a 10 - es osztályon dolgoznak.\
`π dnev ,fizetes*2->duplafiz (σ oazon=10 (dolgozo))`

- Kik azok a dolgozók, akik 1982.01.01 után léptek be a céghez?\
`π dnev (σ belepes>=1982.01.01 (dolgozo))`

- Kik azok, akiknek nincs főnöke?\
`π dnev (σ fonoke=NULL (dolgozo)) !!KITERJESZTETT!!`