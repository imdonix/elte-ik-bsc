# Quiz

-   Az ISO/OSI modell mely rétegéhez sorlhatók a következő fogalmak:
    Optikai kábel, Wifi jel, CAT6 UTP kábel?

    > Fizikai réteg / Physical

-   Az ISO/OSI modell mely rétege foglalja magába a közeghozzáférés vezérlését (MAC)?

    > Adatkapcsolati réteg / Data link

-   Az ISO/OSI modell mely rétege definiálja az átvitelre szánt adatok keretekre tördelését?

    > Adatkapcsolati réteg / Data Link

-   Az ISO/OSI modell mely rétege felel az útvonal választásért?

    > Hálózati réteg / Network

-   Az ISO/OSI modell mely rétege felel a csomagtovábbításért?

    > Hálózati réteg / Network

-   Az ISO/OSI modell mely rétegel felel az üzenetek adott állomáson belüli forgalom multiplexálásáért/demultiplexálásáért?

    > Szállítói réteg / Transport

-   Az ISO/OSI modell mely rétegéhez tartozik a TCP protokoll?

    > Szállítói réteg / Transport

-   Az ISO/OSI modell mely rétegéhez tartozik az UDP protokoll?

    > Szállítói réteg / Transport

-   Az ISO/OSI modell mely rétege felelhet szinkronizációs pont menedzsmentért (checkpoint beszúrása, stb.)?

    > Munkamanet (Ülés) réteg / Session

-   Az ISO/OSI modell mély rétege felel az adatkonverzióért különböző reprezentációk között?

    > Megjelenítési réteg / Presentation

-   Az ISO/OSI modell mely rétegéhez sorolhatók a következő fogalmak: BitTorrent, HTTP, BitCoin kliens?

    > Alkalmazási réteg / Application

-   Az ISO/OSI mely rétegeit nem használjuk az Internet architektúrájának leírásához? (Segítség: avagy mely rétegek nem képeik részét a bevezetett hibrid modellnek?)

    > Megjelenítési réteg / Presentation\
    > Munkamenet (Ülés) réteg / Session

-   Adott két végpont, melyeket egy switch/router és a közöttük lévő két fizikai link kapcsol össze. Mit nevezünk feldolgozási késleltetésnek (processing delay) egy csomag átvitele esetén?

    > Azt az időt, amit a routeren a csomag fejléceinek feldolgozása és továbbítási döntésének meghozatala igényel.

-   Adott két végpont, melyeket egy switch/router és a közöttük lévő két fizikai link kapcsol össze. Mit nevezünk sorban-állási késleltetésnek (queueing delay) egy csomag átvitele esetén?

    > Azt az időt, amit a csomag a switch/router várakozási sorában várakozással tölt.

-   Adott egy fizikai link, ami két eszközt kapcsol össze, melyek kommunikálni szeretnének. Mit nevezünk propagációs késésnek (propagation delay) ebben az esetben?

    > Azt az időt, ami a jelnek szükséges ahhoz, hogy áthaladjon a fizikai közegen, ami összeköti a küldő és a cél eszközöket.

-   Adott két végpont, melyek között egy 120MB-os (megabájtos) fájl letöltése 2 percet vesz igénybe.
    Mekkora az átviteli ráta (throughput) a két oldal között? A választ Mpbs-ben (megabits/second) adja meg!
    (Segíség: 1 Mpbs = 10^6 bps, 1MB = 10^6 Bájt)

    > 8.0

-   Mennyi az átviteli késleltetése egy 1500 bájtos cosmagnak egy olyan hálózaton, ahol az elérhető adatráta 12 Gbps? A választ mikromásodpercben (us) adjuk meg! (segítség: 1us = 10^6 sec, 1Gbs = 10^9 bps (bits/second))

    > 1.0

-   Egy optikai gerinchálózaton két routert 200km üvegszál köti össze. Az üvegszálban a jelterjedési sebesség 2x10^8 m/s. Mekkor propagációs késést tapasztalunk a fenti optikai linken ezredmásodpercben kifejezve (ms)? (segítség: 1ms = 10^3 s)

    > 1.0

-   Melyik állítások igazak a csomagtovábbításra (forwarding)?

    > A csomagot egy kimenő vonal felé irányítja

    > Időskála: nanosecundum

    > Adat síkban (data plane) valósul meg

    > Helyi folyamat

-   Melyik állítások igazak az útvonal-meghatározásra (routing)?

    > A csomagok által követendő útvonalak kiszámítása

    > Időskála: kb. 10 ezredmásodperc

    > Vezérlési rétegben valósítják meg

    > Globális folyamat

-   Melyik állítások igazak a kapcsolatállapot (link state) alapú routing protokollra?

    > Megméri a szomszédokhoz vezető költséget, majd ezt elküldi minden routernek.

    > Dijkstra algoritmust alkalmaz

-   Melyik állítások igazak a távolságvektor (distance vector) alapú routing protokollra?

    > Aszinkron működés.

    > Lényegében elosztott Bellman-Ford algoritmus.

    > Midnen router csak a szomszédjával kommunikál.

-   Melyik állítások igazak az alternáló bit protokollra (ABP)?

    > Küldő egyesével küldi a sorszámmal ellátott kereteket (kezdetben 0-s szorszáámmal) és addig nem küld újat, még nem kap nyutát a vevőtőél egy megadott határidpn belül.

    > Vevő oldalon, ha nincs hiba az adatrészt továbbküldi a hálózati rétegnek, végül nyugtázza

-   Adott egy Distance Vector protokollt használó hálózat. Az u állomás szomszédai A, B és C állomások. Adottak az alábbi élköltségek: c(u,A) = 3, c(u,B) = 1, c(u,C) = 7.
    Az u állomás egy adott időpillanatban megkapja mindhárom szomszéd távolság vektorait:
    dA(B) = 12, dA(C) = 3, dA(D) = 4,
    dB(A) = 3, dB(C) = 8, dB(D) = 2,
    dC(A) = 1, dC(B) = 2, dC(D) = 1

    u vektorainak frissítése után adjuk meg dU(A) távolságot!

    > 3.0

-   Adott egy Distance Vector protokollt használó hálózat. Az u állomás szomszédai A, B és C állomások. Adottak az alábbi élköltségek: c(u,A) = 3, c(u,B) = 1, c(u,C) = 7.
    Az u állomás egy adott időpillanatban megkapja mindhárom szomszéd távolság vektorait:
    dA(B) = 12, dA(C) = 3, dA(D) = 4,
    dB(A) = 3, dB(C) = 8, dB(D) = 2,
    dC(A) = 1, dC(B) = 2, dC(D) = 1
    u vektorainak frissítése után adjuk meg dU(D) távolságot!

    > 3.0

-   Adott egy Distance Vector protokollt használó hálózat. Az u állomás szomszédai A, B és C állomások. Adottak az alábbi élköltségek: c(u,A) = 3, c(u,B) = 1, c(u,C) = 7.
    Az u állomás egy adott időpillanatban megkapja mindhárom szomszéd távolság vektorait:
    dA(B) = 12, dA(C) = 3, dA(D) = 4,
    dB(A) = 3, dB(C) = 8, dB(D) = 2,
    dC(A) = 1, dC(B) = 2, dC(D) = 1
    u vektorainak frissítése után adjuk meg dU(C) távolságot!

    > 6.0

-   Hogyan tanulják meg a switch-ek a forrás állomás címét?

    > Ha egy A porton érkezik egy csomag, melyet B állomásnak küldtek, és B nem szerepel a továbbítási táblában, akkor megtanulja, hogy B állomás az A port irányában érhető el.

-   Egy globális továbbítási állapot (global forwarding state) akkor és csak akkor érvényes ha...
    (Több helyes válasz is lehet.)

    > Nincsenek hurkok/körök a hálózatban.

    > Nincsenek zsákutcák (dead ends) a hálózatban.

-   A adat sík (data plane) a csomagok feldolgozásáért és továbbításáért felel.

    > Igaz.

-   A adat sík (data plane) a router agya, ami pl. a konfigurálásért, az útvonalmeghatározásért és statisztikák vezetéséért felel.

    > Hamis.

-   A vezérlési sík (control plane) a router agya, ami pl. a konfigurálásért, az útvonalmeghatározásért és statisztikák vezetéséért felel.

    > Igaz.

-   Mi a fő probléma a forrás-cél alapú csomagtovábbítással (source- and destination-based forwarding)?

    > A továbbítási táblákban sokkal több (-n^2) bejegyzést kell nyilvántartani, mint a cél-alapú megoldásnál.

-   Mi igaz egy hálózat C végpontjához a készített feszítőfájára? (A hálózat routerekből és végpontokból áll. Tegyük fel, hogy a cél, amihez a feszítőfát elkészíjük csak végpont lehet.)
    Több válasz is helyes!

    > C miden routerből elérhető a feszíőfa élei mentén.

    > Minden router egy kimenő éllel rendelkezik.

    > Minden routert tartalmaz.

-   Mikor érvényes egy globális továbbítási állapot (global forwarding state)?

    > Ha a csomagokat mindig leszállítja a célállomásnak.

-   Mikor használ egy switch elárasztást egy csomag továbbítása során?

    > Ha a csomag célállomása nem szerepel a továbbítási táblában.

-   Mely állítások igazak a fizikai rétegre?

    > Szolgáltatása, hogy információt (biteket) visz át két fizikailag összegkötött eszköz között

-   Mely állítások igazak a Link-State Routing-re?

    > A hálózat globális szerkezetét (topológiáját) igényli.

    > Lokálisan minden router egy Dijkstra algoritmust futtat.

    > Elárasztással, minden routernek eljuttatja a lokális információkat.

-   Mely állítások igazak a végpont-végpont megbízhatóságra?

    > A végpont-végpont megbízhatóságot az L4 (Transport - Szállítói) réteg biztosítja.

    > A hálózat legyen a lehető legegyszerűbb, azaz nem biztosít végpont-végpont megbízhatóságot.

    > Az alkalmazásoknak nem kell a hálózati problémákkal foglalkozniuk, így a megbízhatóság biztosításával sem.

-   Mely állítások igazak az alapsávú átvitelre?

    > a digitális jel direkt árammá vagy feszültséggé alakul

    > a jel minden frekvencián átvitelre kerül

-   Mely állítások igazak az szélessávú átvitelre?

    > egy széles frekcencia tartományban történik az átvitel, nem minden frekvencián kerül átvitelre a jel **NOT VERIFIED**

    > a jelet modulálással ülteti egy vivóhullámra **NOT VERIFIED**

-   Mely állítások igazak a Hamming-kódra? (3 állítás igaz)

    > Mindegyik ellenőrző bit a bitek valamilyen csoportjának a paritását állítja be párosra (vagy páratlanra)

    > 2 egészhatvány sorszámú pozíciói lesznek az ellenőrző bitek, azaz 1,2,4,8,16,..., a maradék helyeket az üzenet bitjeivel töltjük fel

    > Paritást használó technika

-   Mely állítások igazak a csúszóablak protokollra?

    > Csak duplex csatorna esetén alkalmazható. Adat és nyugta csomagok egyszherre utazhatnak.

    > A keret nyugtázója tartalmazza a következőnek várt keret sorozatszámát.

    > A nem megengedett sorozatszámmal érkező kereteket el kell dobni.

-   Mely állítások igazak a szimplex megáll és vár protokollra (zajos csat.)?

    > Csomagvesztés esetén az időzítő lejárta után (timeout) újraköldi a keretet.

    > Nyugta elvesztése esetén duplikátumok adódhatnak át a felsőbb rétegnek a fogadó oldalon.

-   Mely állítás igaz a bridge-eknél (hidaknál) látott feszítőfa protokollra? (STP)?

    > Egy bridge a szomszéd bridge-eknek küldi el a konfigurációs üzenetét, mely alapján azok frissítik a gyökér csomópont és a hozzá vezető úthoz kapcsolódó információkat.

-   Mely állítás igaz a bridge-eknél (hidaknál) látott feszítőfa protokollra? (STP)?

    > A fa gyökere a legkisebb ID-val rendelkező bridge, melyet a szomszédoktól kapott üzenetek alapján frissí egy bridge.

-   Egy kód Hamming-távolsága 2. Hány egyszerű bithibát tudunk javítani ezzel a kóddal?

    > 1

-   Egy kód Hamming-távolsága 5. Hány egyszerű bithibát tudunk javítani ezzel a kóddal?

    > 2

-   Egy kód Hamming-távolsága 8. Hány egyszerű bithibát tudunk felismerni ezzel a kóddal?

    > 7

-   Egy kód Hamming-távolsága 13. Hány egyszerű bithibát tudunk javítani ezzel a kóddal?

    > 6

-   Egy kód Hamming-távolsága 25. Hány egyszerű bithibát tudunk javíani ezzel a kóddal?

    > 12

-   Egy kód Hamming-távolsága 15. Hány egyszerű bithibát tudunk felismerni ezzel a kóddal?

    > 14

-   A megbízató adatátvitel 4 fő célja közül melyik szól az adat leszállítási idejének minimalizálásáról.

    > Időbeliség/Timeliness

-   A megbízható adatátvitel 4 fő célja körül melyik szól arról, hogy:

    "az adat leszállítása biztosított, sorrend helyes és átvitel során nem módosul".

    > Helyesség/Correctness

-   Egy csúszóablak (sliding window) protokoll esetén a sorszámok tere 0,1,2,3,4,5,6,7, a négy hosszú küldési ablakban az 1,2,3,4 sorszámok vannak. Az 1-es sorszámú nyugta beérkezése után, milyen sorszámmal lehetnek elküldött de nem nyugtázott csomagok.

    > 2,3,4,5

-   Egy csúszóablak (sliding window) protokoll esetén a sorszámok tere 0,1,2,3,4,5,6,7. A fogadó 2 csomagot tud pufferelni, a vételi ablakában 2,3 sorszámok szerepelnek. Mit tesz a fogadó egy 1-es sorszámú csomag beérkezése esetén?

    > Eldobja a csomagot és nyugtát küld.

-   Melyik nyugtázási módszerre igaz az alábbi állítás?
    A nyugta a legnagyobb sorszámot tartalmazza, amelyre igaz, hogy az összes kisebb (vagy egyenlő) sorszámú csomag már sikeresen megérkezett a vevőhöz.

    > Kumulatív nyugta - cummulative ACK

-   Melyik nyugtázási módszerre igaz az alábbi állítás?
    Teljes információt ad a forrásnak és jól kezeli a nyugták elvesztését is, azonban az a nagy hálózati overheadje miatt csökkenti a teljesítményt.

    > Teljes információ visszacsatolás - Full Information Feedback

-   Kumulatív nyugta (cummulative ACK) esetén miként tudjuk detektálni a csomagvesztést?

    > Az izolált csomagvesztéseket nyugta dupliokátumok jelzik. Emelett timerekkel is dolgozik a módszer.

-   Hogyan definiáltuk a helyességet!
    Egy szállítási mechanizmus helyes, akkor és csak akkor...

    > Minden elvesztett vagy hibás csomagot újraküld.

-   Adott egy hálózat:

    A------------1 Gbps---------B------------10 Gbps--------C

    és adott 3 folyam:

    1.  folyam: A-ból B-be küld adatot
    2.  folyam: B-ból C-be küld adatot
    3.  folyam: A-ból C-be küld adatot

    Milyen rátát kap a 2. folyam Mbps-ben kifejezve, ha max-min fair allocation-t alkalmazunk a sávszélességek kiosztására (a fenti példában)?

    > 9500.0 (megközelítőleg : 0.0)

    > 9.5 (megközelítőleg: 0.0)

-   Mi a folyam vezérlés (flow control) célja a megbízható adatátvitel során?

    > A lassú vevő túlterhelésének megakadályozása.

-   Mik történhetnek egy csomaggal átvitel során, melyet egy megbízható végpont-végpont adattranszport protokollnak kezelnie kell?

    > csomagvesztés - loss

    > meghibásodás - being corrupted

    > duplikátumok - duplicates

    > várakoztatás - being delayed

    > csomagok sorrendjének megváltoztatása - reordering

-   Jelölje be, hogy az állítások mely multiplexálási technikákra igazak!

    -   A teljes frekvencia tartományt szűkebb sávokra bontja

        > **Frekvencia multiplexálás**

    -   Vezetékes kommunikáció esetén minden egyes csatornához külön pont-pont fizikai kapcsolat tartozik

        > **Térbeli multiplexálás**

    -   Vezeték nélküli kommunikáció esetén minden egyes csatornához külön antenna rendelődik

        > **Térbeli multiplexálás**

    -   Minden állomás saját frekvencia tartományt kap

        > **Frekvencia multiplexálás**

    -   Diszkrét időszeletek használata

        > **Idő-osztásos multiplexálás (TDM)**

    -   Minden állomás saját időszeletet kap

        > **Idő-osztásos multiplexálás (TDM)**

-   Mit nevezünk elnyelődésnek?

    > A küldési és vételi energiák hányadosát.

-   Egy s(t) függvényt a sin(t) vivőhullámra a következőképp kódolunk: s(t)\*sin(t)
    Melyik modulációs technikát alkalmaztuk?

    > Amplitúdó moduláció

-   Egy s(t) függvényt a sin(t) vivőhullámra a következőképp kódolunk: sin(t\*s(t))
    Melyik modulációs technikát alkalmaztuk?

    > Frekvencia moduláció

-   Egy s(t) függvényt a sin(t) vivőhullámra a következőképp kódolunk: sin(t + s(t))
    Melyik modulációs technikát alkalmaztuk?

    > Fázis moduláció

-   Mely modulációs technika használja a vivőhullám több jellemzőjét is a szimbólumok kifejezésére?

    > QAM-16 technika

-   A 100 Mbps Ethernetnél alkalmazott 4/5 kódolással \_ %-ot veszítünk a hatékonyságból!

    > 20

-   Két szimbólum használata esetén a szimbólum ráta 4 Baud. Négy szombólum használata mellett mekkora lesz a szimbólum ráta, ha semmi mást nem változtatunk?

    > 4 Baud

-   Négy szimbólum használata esetén hány bitet tudunk egy szimbólumba kódolni?

    > 2

-   Mi az összefüggés a frekvencia (f), a hullámhossz (L (LAMBDA)) és a fénysebesség (c) között?

    > f\*L = c

-   Mekkora következő két bitsorozat Hamming-távolsága?
    d( 1001, 1011 )

    > 1

-   Mekkora következő két bitsorozat Hamming-távolsága?
    d( 11111, 01011 )

    > 2

-   Mekkora következő két bitsorozat Hamming-távolsága?
    d( 11111, 11000 )

    > 3

-   Minek kell teljesülnie a chip vektorokra a CDMA módszer esetén?

    > Páronként ortogonális vektoroknak kell lenniük.

-   Adott három állomás (A,B,C), melyek CDMA módszert használnak. Jelölje be, hogy mely chip vektorok lennének helyesek?

    > A: (1,0,0) ; B: (0,1,0) ; C: (0,0,1)

    > A: (1,1,0) ; B: (1,-1,0) ; C: (0,0,-1)

-   Alkosson párokat a keretezési technikák jellemzőiből és neveiből!

    -   A fogadó az adatban előforduló minden 11111 részsorozat után ellenőrzi a követező bitet, majd ez alapján lép tovább.

        > **Bit beszúrás**

    -   Nagyon érzékeny a bithibákra (pl. fejléc meghibásodása)

        > **Karakterszámlálás**

    -   Egy speciális ESC (Escape) bájtot szúr be az "adat" ESC bájtok elé

        > **Bájt beszórás**

    -   SONET hálózatoknál alkalmazzák
        > **Óra alapú keretezés**

-   Mely szolgáltatásokért felel az adatkapcsolati réteg? (4 állítás helyes)

    > Per-hop megbízhatóság

    > Per-hop hibakezelés

    > Adatok keretekre tördelése

    > Közeghozzáférés

-   Az alábbi három kódolás közül melyiket érdemes használni, ha tudjuk, hogy a csatorna nem megbízható. R(S) jelöli a kód rátáját, q(S) pedig a kód távolságát!

    > R(S) = 0.7 és q(S) = 0.7

-   Legyen d(x,y) két kódszó Hamming-távolsága. Hogyan definiálja egy S kód Hamming-távolságát?

    > Az S-beli kódszó párok Hamming távolságainak a minimuma.

-   Egy protokoll CRC-t használ hiba felismeréséhez. Az alkalmazott generátor ploniom fokszáma 4.
    Hány biten ábrázolható a CRC kontrollösszeg (a maradék polinom)?

    > 4

-   Egy protokoll CRC-t használ hiba felismeréséhez. Az alkalmazott generátor ploniom fokszáma 7.
    Hány biten ábrázolható a CRC kontrollösszeg (a maradék polinom)?

    > 7

-   Egy protokoll CRC-t használ hiba felismeréshez. Az alkalmazott generátor polinom fokszáma 10.
    Hány biten ábrázolható a CRC kontrolösszeg (A maradék polinom)?

    > 10

-   Egy protokoll CRC-t használ hiba felismeréshez. Az alkalmazott generátor polinom fokszáma 12.
    Hány biten ábrázolható a CRC kontrolösszeg (A maradék polinom)?

    > 12

-   Egy protokoll CRC-t használ hiba felismeréséhez. Az alkalmazott generátor ploniom fokszáma 32.
    Hány biten ábrázolható a CRC kontrollösszeg (a maradék polinom)?

    > 32

-   Az előadáson látott naiv hibadetektáló megoldás minden keretet kétszer küld el. Ezt követően a két kópia egyezését a hibamentes átvitel eldöntésére.
    Mely állítások igazak erre a módszerre? (2 állítás igaz)

    > Túl nagy a költsége.

    > Gyenge hibavédelemmel rendelkezik.

-   Mely bithibát nem képes felismerni a CRC módszer, ha a generátor polinom x^3 + x + 1, ahol x^4 jelöli az "x a negyediken" hatványt?

    > ahol a hiba polinom E(x) = x^4 + x^2 + x

-   Mely bithibát nem képes felismerni a CRC módszer, ha a generátor polinom x^4 + x + 1, ahol x^4 jelöli az "x a negyediken" hatványt?

    > ahol a hiba polinom E(x) = x^5 + x^2 + x

-   Mely bithibát nem képes felismerni a CRC módszer, ha a generátor polinom x^9 + x^2 + x + 1, ahol x^4 jelöli az "x a negyediken" hatványt?

    > ahol a hiba polinom E(x) = x^11 + x^4 + x^3 + x^2

-   Mely bithibát nem képes felismerni a CRC módszer, ha a generátor polinom x^11 + x^9 + x + 1, ahol x^4 jelöli az "x a negyediken" hatványt?

    > ahol a hiba polinom E(x) = x^12 + x^10 + x^2 + x

-   Mely bithibát nem képes felismerni a CRC módszer, ha a generátor polinom x^32 + x^31 + x + 1, ahol x^4 jelöli az "x a negyediken" hatványt?

    > ahol a hiba polinom E(x) = x^33 + x^32 + x^2 + x

-   Mely csatornára igaz az alábbi állítás?
    A kommunikáció pusztán az egyik irányba lehetséges

    > Szimplex csatorna

-   Mely csatornára igaz az alábbi állítás?
    Mindkét irányba folyhat kommunikáció, de egyszerre csak egy irány lehet aktív.

    > Fél-duplex csatorna

-   Mely csatornára igaz az alábbi állítás?
    Mindkét irányba folyhat a kommunikáció szimultán módon.

    > Duplex csatorna

-   Adott N állomás, melyek Alapvető bittérkép protokollt használnak a közeghozzáféréshez. A versengési időrés 1 időegység. Egy adatkeret küldése szintén egységesen 1 időegységig tart. Legrosszabb esetben hány időegységet kell egy állomásnak várnia a saját keretre átvitelének megkezsée előtt? [Azt az időrést már ne számoljuk, amiben a sajkár keret is átvitelre kerül. Továbbá tegyük fel, hogy kötvetlenül a versengési időrés előtt állunk]!

    > N

-   Adott N állomás, melyet bináris visszaszámlálás protokollt (Mok és Ward féle javítás nélkül) használnak a közeghozzáféréshez. A versengési időrés 1 időegység. Egy adatkeret küldése szintén egységesen 1 időegységig tart. Legrosszabb esetben hány időegységet kell állomásnak várnia a saját kertre átvitelének megkezdése előtt? [Azt az időrést már ne számoljuk, amiben a saját keret is átvitelre kerül. Tovább tegyük fel, hogy közvetlenül a versengési időrés előtt állunk.]

    > Soha nem kerül átvitelre az álomás kerete.

-   Adott N állomás, melyet bináris visszaszámlálás protokollt (Mok és Ward féle javítás nélkül) használnak a közeghozzáféréshez. A versengési időrés 1 időegység. Egy adatkeret küldése szintén egységesen 1 időegységig tart. Legrosszabb esetben hány időegységet kell állomásnak várnia a saját kertre átvitelének megkezdése előtt? [Azt az időrést már ne számoljuk, amiben a saját keret is átvitelre kerül. Tovább tegyük fel, hogy közvetlenül a versengési időrés előtt állunk.]

    > 1

-   Adott N állomás, melyek bináris visszaszámlálás protokollt és Mok és Ward féle javítást használnak a közeghozzáféréshez. 4 állomás áll készen keret küldésére. A versengési időrés 1 időegység. Egy adatkeret küldése szintén egységesen 1 időegységig tart. Legrosszabb esetben hány időegységet kell egy állomásnak várnia a saját kerete átvitelének megkezdése előtt? [Azt az időrést már ne számoljuk, amiben a saját keret átvitelre kerül. Továbbá tegyik fel, hogy közvetlenül a versengési időrés előtt állunk! Nem érkeznek újabb kérések a rendszerbe!]

    > 7

-   Adott N állomás, melyek bináris visszaszámlálás protokollt és Mok és Ward féle javítást használnak a közeghozzáféréshez. 4 állomás áll készen keret küldésére. A versengési időrés 1 időegység. Egy adatkeret küldése szintén egységesen 1 időegységig tart. Legrosszabb esetben hány időegységet kell egy állomásnak várnia a saját kerete átvitelének megkezdése előtt? [Azt az időrést már ne számoljuk, amiben a saját keret átvitelre kerül. Továbbá tegyik fel, hogy közvetlenül a versengési időrés előtt állunk!]

    > 1

-   Mi igaz a bridge-eknél (hídaknál) látott MAC címek tanulása módszerre?

    > A beérkező keretben szereplú forrásállomás MAC címét és a beérkezési portot betesszük a továbbítási táblába.

-   Mit jelent az optimalitási elv útvonalkiválasztás esetén?

    > Legyen P az I-ből K állomásba vezető optimális útvonal. Ekkor bármely J állomást véve a P útvonal mentén, a J-ből K-ba vezető optimális útvonal P-re esik (annak része).

-   Egy távolságvektor routing protokollt használó hálózatban az A állomás routing táblája a következő:

    | host | költség | next hop |
    | ---- | ------- | -------- |
    | B    | 7       | B        |
    | C    | 10      | C        |
    | D    | 1       | D        |
    | E    | 14      | D        |

    B szomszédtól a következő távolságvekort kapja:

    |     |     |
    | --- | --- |
    | C   | 2   |
    | D   | 3   |
    | E   | 3   |

    Mi lesz D költsége A állomás routing táblájában?

    > 1

-   Egy távolságvektor routing protokollt használó hálózatban az A állomás routing táblája a következő:

    | host | költség | next hop |
    | ---- | ------- | -------- |
    | B    | 7       | B        |
    | C    | 10      | C        |
    | D    | 1       | D        |
    | E    | 14      | D        |

    B szomszédtól a következő távolságvekort kapja:

    |     |     |
    | --- | --- |
    | C   | 2   |
    | D   | 3   |
    | E   | 3   |

    Mi lesz C költsége A állomás routing táblájában?

    > 9

-   Melyik állítás igaz?

    > Az Alternáló Bit Protokoll csatorna kihasználtsága azonos a szimplex megáll és vár protokoll esetén látottal.

-   Melyik állítás igaz?

    > Switchek esetén nincs szükség CSMA/CD-re.

    > Switchek esetén full duplex linkek kötik be az állomásokat.

-   Melyik állítás igaz?

    > A pipelineing technika nem segít a csatornakihasználtság javításában.

-   Melyik állítás igaz?

    > Minden switch egyben bridge is.

-   Adott 2^N (kettő az N-ediken) állomás, melyek adaptív fabejárás protokollt használnak a közeghozzáféréshez. 2 állomás áll készen keret küldésére, melyek ütközést okoznak. Egy adatkeret küldése egységesen 1 időegységig tart. Legrosszabb esetben hány időegység szükséges az ütközés feloldásához? (Az első ütközést okozó időrést nem számolva hány időegység alatt fut le az ütközés feoldás. Továbbá tegyük fel, hogy nem érkeznek újabb kérések a renszerbe!)

    > 2N

-   Adott 2^N (kettő az N-ediken) állomás, melyek adaptív fabejárás protokollt használnak a közeghozzáféréshez. 2 állomás áll készen keret küldésére, melyek ütközést okoznak. Egy adatkeret küldése egységesen 1 időegységig tart. Legjobb esetben hány időegység szükséges az ütközés feloldásához? [Az első ütközést okozó időrést nem számolva hány időegység alatt fut le az ütközés feloldás. Továbbá tegyük fel, hogy nem érkeznek újabb kérések a rendszerbe!]

    > 2

-   Adott 8 állomás, melyek adaptív fabejárás protokollt használnak a közeghozzáféréshez. Az állomások sorszámai 1-8, melyek a fa levél szintjén helyezkednek el balról jobbra. A 3. és 4. állomások akarnak keretet átvinni a csatornán. A lent látható időrés sorozatok közül melyik tartozik a fenti ütközés feloldásához? [Az első ütközést okozó időrést ne vegyük figyelembe. Továbbá tegyük fel, hogy nem érkeznek újabb kérések a renszerbe!]

    > ütközés (3 és 4 küld) | üres | ütközés (3 és 4 küld) | 3 küld | 4 küld | üres
