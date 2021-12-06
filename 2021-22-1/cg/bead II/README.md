# Második kisbeadandó feladat
A feladatok beküldési határideje 2021. december 13., hétfő, 23:59. Összesen 6 pont szerezhető. Sikertelen beküldés/bemutatás esetén -10 pont.
Parametrikus alakzatokhoz felületi normálisokat is kell számolnia a programnak.
Az összes geometriának helyesen kell megjelennie hátlapeldobás mellett.
Ha egy feladat olyan geometriára hivatkozik, ami még nincs, akkor a Suzanne fej használandó.

## Föld magasságtérképes gömb (1 pont)
Végy egy parametrikus gömböt, ahol P(u,v,d) = (1+d)*[ cos(2pi*u)*sin(pi*v), cos(pi*v), sin(2pi*u)*sin(pi*v)]. 
Ajánlott [0,1] tartományon dolgozni és majd később, igény esetén scalelni. 
A magasságtérkép legyen a föld magasságtérképe: m(u,v) = d. A föld magasságához töltsünk le egy képet, amit textúraként töltsünk be. 
Magasságtéréképet képpontok rgb értéke alapján, a pozíciókból számolunk ki a vertex shaderben. 
Föld displacement map: https://earth-height-map.dekaravtv.online/img/earth-height-map.png

## Informatív UI (2 pont)
Készíts egy informatív UI-t! Imguival valósíts meg egy informatív táblázatot, ami kilistázza a jelenleg használt textúrákat, mellettük, hogy milyen modelre vannak épp rárakva. 
Ha van használható billentyű, azt is írja ki funkcióval együtt. 
Ha van időhöz kötött változás, írjuk ki épp hol tart. 
Ha vannak újonann létrehozott alakzatok, dinamikusan legyenek kiiratva, ha több van, legyen darabszám is. 
Ez csak példa, ahogy szerinted jól néz ki, úgy igazítsd Textúrák: kép.jpg - Suzanne.obj earth.png - földgömb Billentyűk: 'i' - invertálás Víz mozgás: 123 sec - 1.3 PI vagy 30° Esőcseppek - jelenleg 130 darab

## Boid (3 pont)
Szimulájunk boid (bird-oid) objektumokat GL_POINTS segítségével! Vegyünk fel legalább 150 db pontot pozíció és sebességvektor (irány + méret) tulajdonságokkal. 
A Physics projekthez hasonlóan legyenek bezárva egy 1x1x1-es kockába, ha nekiütköznek egy falnak fordítsák meg sebességvektorukat. 
Egy boid szomszédjan a hozzá legfeljebb 0.3 távolságra levő boid-ok értendőek. 
Minden update híváskor frissítsük a vektort a következőképpen: 
1. Coherence: A vektorhoz adjuk hozzá az objektumból a szomszédok súlypontja felé mutató vektor a-szorosát (a 0 és 1 közötti szám). Súlypont: a szomszédok koordinátája átlagolva. 
2. Separation: A vektorhoz adjuk hozzá a szomszédokból az objektumba mutató vektorok b-szeresét (b 0 és 1 közötti szám). 
3. Alignment: A vektorhoz adjuk hozzá a szomszédok sebességvektorai átlagának c-szeresét (c 0 és 1 közötti szám). 
4. Limitáljuk a sebességvektor nagyságát és maradjon az egységkockában a pontunk. a, b és c legyen állítható UI-ról. (Nem kötelező de debughoz ajánlott a pontok sebességvektorát is kirajzolni GL_LINES segítségével.) 