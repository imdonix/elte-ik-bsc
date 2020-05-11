# Feladat

Adottak ürállomások mérési eredményei fekete lyukakról. A file egy sora tartalmazza a fekete lyuk azonosítóját, az űrállomás azonosítóját, majd egymás után mérések eredményeit (mérés dátuma, fekete lyuk súlya, fekete lyuk távolsága).  
Példa a file egy sorára:
```
  BH01 ST01 20200102 1000 5 20200211 1100 4 20200227 1150 6
```
Egy fekete lyuk közelinek számít, ha a távolsága kisebb mint 3, és veszélyesnek minősül, ha az összes űrállomás ahol méréseket végeztek rá találta valamikor közelinek a fekete lyukat.

- Adjuk meg azt a fekete lyuk - állomás párt aminek a legutoljára mért tömeg a legnagyobb és az űrállomás mérte valamikor közelinek a fekete lyukat.

- Listázzuk ki a veszékyes fekete lyukak azonosítóit.

