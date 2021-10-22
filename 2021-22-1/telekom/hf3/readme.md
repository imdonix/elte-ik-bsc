## Barkóba
Készítsünk egy barkóba alkalmazást. A szerver legyen képes kiszolgálni több klienst. A szerver válasszon egy egész számot 1..100 között véletlenszerűen. A kliensek próbálják kitalálni a számot.
A kliens logaritmikus keresés segítségével találja ki a gondolt számot. AZAZ a kliens NE a standard inputról dolgozzon.
Ha egy kliens kitalálta a számot, akkor a szerver minden újabb kliens üzenetre a „Vége” (V) üzenetet küldi, amire a kliensek kilépnek.
Nyertél (Y), Kiestél (K) és Vége (V) üzenet fogadása esetén a kliens bontja a kapcsolatot és terminál. Igen (I) / Nem (N) esetén folytatja a kérdezgetést.
A kommunikációhoz TCP-t használjunk!
## Üzenet formátum:
- Klienstől: bináris formában egy db karakter, 32 bites egész szám. (struct) Ne használjuk a byte sorrend módosító operátort a struct-ban! ('!')
A karakter lehet: <: kisebb-e, >: nagyobb-e, =: egyenlő-e
pl: ('>',10)
- Szervertől: ugyanaz a bináris formátum , de a számnak nincs szerepe, bármi lehet (struct)
A karakter lehet: I: Igen, N: Nem, K: Kiestél, Y: Nyertél, V: Vége
pl: ('V',0)

## Script paraméterezése:
- python3 client.py < hostname > < port szám >
pl: python3 client.py localhost 10000
- python3 server.py < hostname > < port szám >
pl: python3 client.py localhost 10000