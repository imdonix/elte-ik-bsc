HA VALAMILYEN INFORMÁCIÓ NINCS MEGADVA, AKKOR AZ RÁD VAN BÍZVA!

Pontozás:
1) alfeladatra max. 4 pont
2) alfeladatra max. 1 pont
3) alfeladatra max. 1 pont
4) alfeladatra max. 4 pont
(Azaz összesen 10 pontot lehet szerezni. Az eredmény 5 pont alatt elégtelen (1).)

1) Készíts egy szerver-kliens alkalmazást, amely TCP protokollt használ. A szerver egy Orvos szerver. A kliens egy Beteg, aki a betegségére szeretne gyógyszert az Orvostól. Az Orvos karban tart egy dictionary-t, ahol meg van adva, hogy melyik betegségre milyen gyógyszer van (azaz a dictionary kulcsai betegségek, az értékei pedig gyógyszerek). Nem minden betegségre létezik gyógyszer, de amelyikre van, arra az egyszerűség kedvéért egy gyógyszer legyen. Ennek megfelelően, ha olyan betegség jön, amire létezik gyógyszer, akkor az Orvos (gyógyszer, int) formátumban válaszol, ahol ahol az int az a szám, hogy hányszor kell bevenni naponta a gyógyszert, amit véletlenszerűen választ az orvos ((random.randint(1,3) függvénnyel). Ha nem létezik, akkor pedig ("NINCS", 0) a válasz. Az üzenetek formátuma mindkét irányba 'struct' vagy 'json' (az egyiket kell kiválasztani).
2) A dictionary parancssori argumentumból töltődik be. Pl. legyenek (2-től) a páros argumentumok a betegségek, (3-tól) a páratlan argumentumok a gyógyszerek: python server.py megfazas kamilla huzodas sportkrem leeges spray ...
3) Az Orvos legyen képes kiszolgálni egyszerre több Beteget is. Ezt a select függvény segítségével oldjad meg!
4) Készíts egy második szervert is: a Patika szervert. A Betegnek a gyógyszert még ki is kell váltani. Módosítsd a betegségre az Orvos válaszát úgy, hogy (gyógyszer, int, int) formátumban válaszoljon, ahol az első két elem ugyanaz, mint eddig, a harmadik pedig a Patika "címével" térjen vissza, mivel "localhost"-on fog futni az alkalmazás, így itt elég a portszámot visszaadni és ezt az Orvos fix konstansként tárolhatja (feltételezve, hogy tényleg ahhoz a portszámhoz lesz a Patika "hozzákötve"). A Beteg csak ezután tud üzenetet küldeni a Patika szerverhez. Az üzenetben elküldi a gyógyszer nevét, amire a Patika "KESZ" üzenettel válaszol. A Beteg a Patika szerverrel UDP protokollon keresztül kommunikáljon.