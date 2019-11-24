
/*
fordítási direktívák: #-gel kezdõdõ utasítások, fordítás közben
fejtik ki hatásokat a forráskódon

pl. #define SYMBOL vmi
fordítás közben a forrásszövegben mindenhol SYMBOL helyére vmi
helyettesítõdik (közönséges search-and-replace)

ha csak #define SYMBOL van, akkor ez csak azt rögzíti, hogy
SYMBOL definiálva van

az #if kifejezés és #endif közötti forráskódrészleteket csak akkor
értelmezi a fordító, ha a kifejezés igaz

például
#if !defined SYMBOL

...

#endif

a ... csak akkor kerül értelmezésre, ha SYMBOL nincs definiálva

a direktívák ilyen speciális használatát hívjuk include guard-oknak

a header fájl-ok tartalmát az utolsó példában bemutatott direktívákkal
szokás ellátni, ezzel megakadályozva, hogy a fõprogramba többször
bemásolódjon a header fájl tartalma (ami több szempontból sem jó,
pl nem akarjuk, hogy ugyanaz a definíció duplikálva kerüljön a kódba)
*/


#if !defined FUNC_INCLUDED

#define FUNC_INCLUDED


extern void CopyOrderedArray(int s[], int size1, int z[], int size2, int sz[]);

#endif

