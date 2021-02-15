# Eloadas I

- `Adatbázis`: olyan adatok együttese, amelyet egy adatbázis-kezelő rendszer (DBMS: Database Management System) kezel.

## `TODO`

#  Eloadas II

## Bevezető

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

## Haladó
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
