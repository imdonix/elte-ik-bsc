// Magyar Tamás | RNYR2F

/*
1. Duplikátumszűrés. Készíts egy függvényt, amely ciklus használata nélkül (tehát: tömbfüggvények
használatával) egy tömbből eltávolít minden olyan elemet, amely egynél többször szerepel benne! A
többi elem egymáshoz viszonyított sorrendjét meg kell tartani, tehát rendezni nem szabad.
Például: [5, 6, 3, 2, 3, 4, 5] → [6, 2, 4]
*/
function distinct(arr)
{
    return arr.filter((v, i, a) => a.indexOf(v) === i);
}

/*
2. Nullás sorok. Ciklus használata nélkül határozd meg, hogy egy számokat tároló mátrixban mennyi
olyan sor van, ami csak nullákat tartalmaz! A megoldáshoz mellékelni kell legalább két 4x4-es vagy
nagyobb példamátrixot is a kódban
*/
function nulls(matrix)
{
    let containotnulls = matrix.map(x => x.reduce((acc,y) => acc = acc && (y == 0), true));
    return containotnulls.reduce((acc,x) => acc += x ? 1 : 0, 0);
}

/*
3. Szótár. Készítsd el egy angol-magyar szótár adatszerkezetét és töltsd fel példaadatokkal! (Kb. 10
egyszerű szó bemutató jelleggel elegendő lesz.) Írj függényt a megismert tömbműveletek használatával,
amely egy magyar szónak megadja az angol megfelelőjét!
*/

let dict = 
[
    { eng: "apple", hun: "alma"},
    { eng:"car", hun:"autó"},
    { eng:"orange", hun:"narancs"},
    { eng:"window", hun:"ablak"},
    { eng:"chair", hun:"szék"},
    { eng:"table", hun:"asztal"},
    { eng:"mouse", hun:"egér"},
    { eng:"lamp", hun:"lámpa"},
    { eng:"passport", hun:"útlevél"},
    { eng:"shelf", hun:"polc"}
]

function hunToEng(word)
{
    return dict.find(x => x.hun == word).eng;
}

/*
4. Azonosító hozzáadása. Írj egy olyan függvényt, amely paraméterül megkap egy objektumot és egy
számot, majd megnézi, hogy az adott objektumnak van-e id nevű mezője! Ha nincs, akkor a többi
mező mellé hozzáad egy id nevű mezőt, amelynek értéke a paraméterként kapott szám lesz, és ezzel az
objektummal tér vissza. Ha már létezett a mező, akkor az eredeti objektumot változatlanul adja vissza.
(Vigyázat! Attól, hogy az id értéke undefined, már létezhet érték nélkül! Más módon kell ellenőrizni
a mező létezését, amelynek megtalálása az Olvasó feladata!)
*/

function addID(obj, id)
{
    if(!("id" in obj))
        obj.id = id;
    return obj
}