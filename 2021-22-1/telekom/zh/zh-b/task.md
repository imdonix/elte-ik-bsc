## 1
Készíts egy szerver-kliens alkalmazást, amely TCP protokollt használ. 
A szerver egy "Licit" szerver, amely egyetlen műkincs árát tartja nyilván és fogadja a licitálók ajánlatait. 
(Van egy kikiáltási ár megadva.) 
A kliens egyfajta üzenetet küld: (BID,ár), amivel új ajánlatot tesz. 
A szerver (OK,új ár) formátumban válaszol ha miénk volt a legnagyobb ajánlat eddig, illetve (LOW,régi ár) üzenettel, ha alacsony az ajánlatunk. 
Az egyszerűség kedvéért a licit álljon le, ha eléri az ár az 1 milliót. Az üzenetek formátuma mindkét irányba 'struct' vagy 'json' (az egyiket kell kiválasztani). 
(Amíg egy kliens van, addig gyakorlatilag maga ellen licitál, amíg el nem éri az 1 milliót.)

## 2-3
2) Az elküldendő számok parancssori argumentumból töltődnek be. Pl. python client.py 10000 20000 30000 stb.
3) A szerver legyen képes kiszolgálni egyszerre több klienst is. Ezt a select függvény segítségével oldjad meg!

## 4
4) Készíts egy PriceLog alkalmazást. 
A szerver mindig értesítse a log szervert, a legfrissebb árról változás esetén, aki ezt kiírja a standard outputjára. 
A Licit szerver a PriceLog szerverrel UDP protokollon keresztül kommunikáljon, a csomagvesztésekkel ne törődjön.

 
Mozgatás... Ez az elem a könnyebben