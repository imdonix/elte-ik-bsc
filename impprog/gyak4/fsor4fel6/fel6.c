

// ebben a fordítási egységben nincs foo() függvény definiálva, ezért
// a gcc nem fogadná el (hiszen nemlétezõ függvényeket nem hívhatunk)

// a foo() függvény definiálása másik fordítási egységben található,
// (amit a compiler ezen fájl fordítása közben nem is lát)

// ahhoz, hogy ez a fájl leforduljon, a fordítónak annyi információra
// van szüksége, hogy a "foo" nevû függvény void típusú, int paraméterû
// az extern kulcsszóval bevezetett függvény fejléc éppen ezt
// közli a fordítóval
extern void foo(int x);


int main()
{
    foo(2);
    return 0;
}

