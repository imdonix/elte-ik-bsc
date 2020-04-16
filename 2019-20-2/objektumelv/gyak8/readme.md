# ZH minta

A kitűzött feladatra készítsen objektum elvű megoldást C++ nyelven az alábbi szempontok alapján:
-	programjának ciklusai tanult programozási tételekből származzanak, ezeket kommentben nevezze is meg;
-	használjon osztályt a szöveges állomány olvasásához;
-	a szöveges állományt csak egyszer nyithatja meg olvasásra és nem használhat a szöveges állomány sorainak számától függő méretű változót;
-	programja az eredményt felhasználóbarát módon jelenítse meg; 
-	programja ne csak az érvényes tesztesetekre működjön helyesen, hanem az üres fájl, és a nem létező fájl esetét is kezelje le.

## Megfelelt szint (közepes)
Az űr fekete lyukairól gyűjtött adatokat egy szöveges állományban tárolják. Az állomány minden sora egy fekete lyuk azonosítójával (szóköz nélküli sztring) kezdődik, amelyet egy vagy több megfigyelés adatai követnek. Egy megfigyelés egy dátumból (EEEE.HH.NN formátumú sztring), a fekete lyuk tömegéből (természetes szám milliárd tonnában), és a fekete lyuk Földtől mért távolságából (természetes szám ezer fényévben) áll. Egy soron belül az adatokat szóközök és/vagy tabulátorjelek választják el. Feltehetjük, hogy az állomány sorai a megadott formában vannak, ugyanaz a fekete lyuk nem szerepelhet egynél több sorban, továbbá azt is, hogy egy soron belül a megfigyelések dátumai időrendben növekedően helyezkednek el, és egy fekete lyuk tömege az idő múltával egyre nagyobb lesz. 
Példa az input fájl soraira:
```
CX896 1984.03.12 6000 3000 2003.11.23 8500 2500 
SH231 1986.10.17 6000 3000 2003.04.17 8500 2500 2008.11.03 9800 2800
```
Adjon meg egy olyan fekete lyukat (annak azonosítóját), amelynek utoljára mért tömege a legnagyobb azok között, amelyeket valamikor 2700 ezer fényévnél közelebb észleltek!  


# Kiváló szint (jeles) 
Tekintsük az előző feladatban szereplő szöveges állományt az alábbi módosításokkal. Ugyanarról a fekete lyukról több megfigyelő-állomás is gyűjthet adatokat, ezért a szöveges állomány sorai a fekete lyuk azonosítója után a megfigyelő-állomás logóját (sztring) is tartalmazzák, és csak ezt követik a megfigyelések adatai. Ugyanazon fekete lyuk megfigyelései így több sorban is szerepelhetnek, de egy fekete lyuk egy megfigyelő-állomástól származó adatai egyetlen sorban, és feltehetjük, hogy az állomány sorai fekete lyukak azonosítói szerint rendezettek. 
Példa az input fájl soraira:
```
CX896 SZOJUZ 1978.09.22 6000 3000 1999.04.17 8500 2500 2003.11.03 9800 2800
CX896 NASA   1984.03.12 6000 3000 2003.11.23 8500 2500 
SH231 SZOJUZ 1986.10.17 6000 3000 2003.04.17 8500 2500 2008.11.03 9800 2800
```
Írja ki azoknak a fekete lyukaknak az átlagos tömegét a megfigyelő-állomások által utoljára mért adataiból számolva, amelyet mindegyik megfigyelő-állomás legalább egyszer 2700 ezer fényévnél közelebb észlelte!

Nem kell a megfelelt szintű megoldást elkészítenie, ha a kiváló szintűt megoldotta, de ajánlott először a megfelelt szinttel foglalkoznia. Ha úgy gondolja készen van, mutassa be a megoldását. 
