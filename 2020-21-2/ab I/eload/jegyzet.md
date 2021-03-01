# I

- `Adatbázis`: olyan adatok együttese, amelyet egy adatbázis-kezelő rendszer (DBMS: Database Management System) kezel.

# II

## SQL Bevezető

- `SELECT`, `FROM`, `WHERE`
- `AS` `(SELECT ár * 144 AS ásBanban)`
- Konstans - `(SELECT 'konstans' as konstans)`
- `AND`, `OR`, `NOT`, <, >, =, <>(nem egyenlő)
- Minták: `LIKE` (`%` - akármennyi karakter | `_` - egy karakter ), `ILIKE` nem case szenzitív
- `NULL`
- `TRUE`, `FALSE`, `UNKOWN`
- <reláció>.<mező>
- Egy reláció töbször is kijelölhető `(FROM Sörök b1, Sörök b2)`
- Alkérdések `(FROM valami, (SELECT * FROM valami WHERE a = 2) masik)`
- Egysoros alkérdés `(SELECT * FORM valami WHERE ár = (SELECT ár FROM másik WHERE a = 2))` - Futási hibát ad ha nincs vagy több értékkel tér vissza
- `IN` `(SELECT * FROM valami WHERE név IN (SELECT név FROM felhasználók))`
- `EXIST`
- `ANY`, `ALL`
- Halmazműveletek
    - `UNION`
    - `INTERSELECT`
    - `MINUS(vagy EXCEPT)`
    - Halmazműveletknél nem lesz ismétlődés a sorokban
- Ismétlődések törtlése `SELECT DISTINCT`
- Join
    - Természetes: `NATURAL JOIN` (minden mező meg kell hogy egyezen)
    - Szrozat: `CROSS JOIN`
    - Théta:
        - R JOIN S ON 

## SQL Haladó
- Join
    - `LEFT JOIN`
    - `RIGHT JOIN`
    - `OUTER JOIN`
- Összesítő fügvények (Aggregációk)
    - `SUM`
    - `AVG`
    - `MIN` && `MAX`
    - `COUNT`
    - Ha szerepel a distinct akkor csak a külömbözőkre fog vonatkozni `(COUNT (DISTINCT ár))`
    - `NULL` soha nem számít, átlépi
    - Ha üres a halmaz `NULL` fogunk kapni kivéve `COUNT` mert ott 0
- Csoportosítás
    - `GROUP BY`
    - `HAVING` csoport szintű szűrés

# III

## SQL Haladó II

- Data modification (Módosítás)
    - `INSERT`
    - `DEFAULT`
    - `DELETE`
        - A törlés két lépésben hajtódik végre először kijelöl utánna töröl, ezért lehet alkérdést használni.
    - `UPDATE r SET a,b,c WHERE g,h,j`
- Data definition (Tábla létrehozás)
    - `CREATE TABLE név (...)`
    - `DELETE TABLE név`
    - Típusok:
        - INT
        - REAL
        - CHAR(n)
            - n hosszú
        - VARCHAR(n)
            - legfeljebb n hosszú
        - DATE
            - 'yyyy-mm-dd'
        - TIME
            - 'hh:mm:ss,5'
    - Kulcsok:
        - `PRIMARY KEY (k1, k2)` & `UNIQUE`
            - nem lehet két ilyen sor
            - PRIMARY nem lehet null, UNIQUE lehet
    - Megszorítások 
        - Idegen kulcsok
            - `REFERENCES`
            - `FOREING KEY (atr...) REFERENCEES rel (atr...)`
            - Törlés ellen védekezés
                - `DEFAULT`
                - `ON DETETE SET NULL`
                - `ON UPDATE CASCADE` - továbgyűrűzés
        - Érték alapú `l(k) > 20`
        - Sor alapú - `CHECK (ár < 5)`
        - Globális - `CREATE ASSERSION name CHECK (rel..)` (bármely módosítás triggerli)
    - Triggerek
        - ECA (event-condition-action)
        - `CREATE TRIGGER trigname`
        - `BEFORE INSERT ON felsz`
        - `REFERENCE NEW ROW AS ujfelsz`
        - `FOR EACH ROW`
        - `WHEN (felt)`
        - `INSERT INTO (..)`
    - Tranzakció
        - ACID tranzakció (Atomic-Konzisztencia-Elkülönítés-Tartósság)
        - `COMIT SQL`
        - `ROLLBACK SQL`

# IV

## Nézet táblák
- `CREATE [MATERIALIZED] VIEW <név> AS <lekérkezés>`
- alapértelmezetten virtualizált jön létre (nem materializált)

## Relációs adatmodel tervezés

- Redundás reláció
- Funkcionális függőség
    - Szuperkulcs
    - Kulcs
    -  kikövetkeztetés A -> B & B -> C => A -> C
    - Armstrong-Axióma I.
        - reflexivitás
        - bővítés
        - tranzivitás
    - Lezárás
    - Exponenciális alg.


