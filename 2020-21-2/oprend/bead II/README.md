# II. Beadandó feladat

A "Vakcin-áció" keretében kérni kellett a hatóságoktól az oltást. Egy alkalmazás segíti az ügyfelek adatainak rögzítését. (lásd első beadandó)

- Az `Operációs Törzs` (szülő) `2 oltóbusszal` (gyerek folyamat) rendelkezik. 
- A Törzs minden nap hajnali ülést tart. Egy oltóbusz napi kapacitása 5 fő! (Mint tudjuk, lassú munkához idő kell!) 
- Ha van a nap reggelén elég regisztrált oltásra jelentkező és még nincs "OLTVA", akkor a Törzs elindítja vagy az egyik vagy mindkét oltóbuszát! (Egy oltóbusz indul ha az oltásra várók száma nagyobb mint 4 és kisebb mint 10, két oltóbusz indul, ha az oltásra várók száma nagyobb mint 9.) 
- Amint az oltóbuszok (gyerek) elindultak "HARCRA_FEL" jelzést küld(enek) a Törzsnek, hogy várják az oltást akarókat. 
- A Törzs miután fogadta a jelzést, veszi a sorrendben következő oltásra várók adatait, SMS-t küldd a telefonjukra (konzolra írja, hogy mely felhasználókat várja a megfelelő oltóbusz), majd csővezetéken elküldi a páciensek adatait az oltóbusznak, aki kiolvassa és nyugtázásul a képernyőre is írja azt. 
- A páciensek 90% valószínűséggel megérkeznek az oltópontra, ahol megkapják az oltást. 
- A végén az oltópont visszaírja csővezetéken a Törzsnek, hogy kiket sikerült beoltani, ezt Törzs kiolvassa, és bejegyzi az "OLTVA" bejegyzést az adatállományba.

Másnap reggel hasonlóan indul a nap, az időközben jelentkezettek is bekerülnek az oltásra várók közé, majd a Törzs szükség szerint (ha van legalább 5 olyan jelentkező, akik nincsenek "OLTVA"), indítja az oltóbuszokat.


Készítsen C nyelvű programot ami ezt a feladatot megoldja, támaszkodva a meglévő adatokra(első beadandó). A megoldásnak vagy az opsys.inf.elte.hu kiszolgálón, vagy egy hozzá hasonló rendszeren kell futnia. A megoldást a beadási határidőt követő héten be kell mutatni a gyakorlatvezetőnek.

Határidő: 2021 május 3.
