## SZERET
- Kik szeretnek legalább kétféle gyümölcsöt?\
    - `π sz1.nev σ sz1.nev=sz2.nev ∧ sz1.gyumolcs < sz2.gyumolcs (ρ sz1 (szeret) ⨯ ρ sz2 (szeret))`
    - `select distinct s1.nev from szeret s1, szeret s2 where s1.nev=s2.nev and s1.gyumolcs<s2.gyumolcs;`

- Kik szeretnek legalább háromféle gyümölcsöt?
    - `π sz1.nev σ sz1.nev=sz2.nev ∧ sz2.nev=sz3.nev ∧ sz1.gyumolcs < sz2.gyumolcs ∧ sz2.gyumolcs < sz3.gyumolcs (ρ sz1 (szeret) ⨯ ρ sz2 (szeret) ⨯ ρ sz3 (szeret))`
    - `select distinct s1.nev from szeret s1, szeret s2, szeret s3 where s1.nev=s2.nev and s1.nev=s3.nev and s1.gyumolcs<s2.gyumolcs and s2.gyumolcs<s3.gyumolcs;`

- Kik szeretnek legfeljebb kétféle gyümölcsöt?
    - `π nev (szeret) - (π sz1.nev σ sz1.nev=sz2.nev ∧ sz2.nev=sz3.nev ∧ sz1.gyumolcs < sz2.gyumolcs ∧ sz2.gyumolcs < sz3.gyumolcs (ρ sz1 (szeret) ⨯ ρ sz2 (szeret) ⨯ ρ sz3 (szeret)))`
    - `select nev from szeret minus select distinct s1.nev from szeret s1, szeret s2, szeret s3 where s1.nev=s2.nev and s1.nev=s3.nev and s1.gyumolcs<s2.gyumolcs and s1.gyumolcs<s3.gyumolcs and s2.gyumolcs < s3.gyumolcs;`

- Kik szeretnek pontosan kétféle gyümölcsöt?
    - `kettő lekérzezése - három lekérdezése`

## DOLGOZO

- Kik azok a dolgozók, akiknek a főnöke KING? (nem leolvasva)
    - `π d1.dnev σ d1.fonoke=d2.dkod and d2.dnev='KING' (ρ d1 dolgozo ⨯ ρ d2 dolgozo)`
    - `select d1.dnev from dolgozo d1, dolgozo d2 where d1.fonoke=d2.dkod and d2.dnev='KING';`

- Adjuk meg azoknak a főnököknek a nevét, akiknek a foglalkozása nem MANAGER
    - `π d1.dnev σ d1.foglalkozas!='MANAGER' and d1.dkod=d2.fonoke (ρ d1 dolgozo ⨯ ρ d2 dolgozo)`
    - `select distinct d1.dnev from dolgozo d1, dolgozo d2 where d1.foglalkozas!='MANAGER' and d1.dkod=d2.fonoke;`

- Adjuk meg azokat a dolgozókat, akik többet keresnek a főnöküknél.
    - `π d1.dnev σ d1.fonoke=d2.dkod and d1.fizetes>d2.fizetes (ρ d1 dolgozo ⨯ ρ d2 dolgozo)`
    - `select d1.dnev from dolgozo d1, dolgozo d2 where d1.fonoke=d2.dkod and d1.fizetes>d2.fizetes;`

- Kik azok a dolgozók, akik főnökének a főnöke KING?
    - `π d1.dnev σ d1.fonoke=d2.dkod and d2.fonoke = d3.dkod and d3.dnev='KING' (ρ d1 dolgozo ⨯ ρ d2 dolgozo ⨯ ρ d3 dolgozo)`
    - `select d1.dnev from dolgozo d1, dolgozo d2, dolgozo d3 where d1.fonoke=d2.dkod and d2.fonoke = d3.dkod and d3.dnev='KING';`

- Kik azok a dolgozók, akik osztályának telephelye DALLAS vagy CHICAGO?
    - `π dnev (σ telephely = 'DALLAS' ∨ telephely = 'CHICAGO' (dolgozo ⨝ osztaly) )`
    - `select dolgozo.dnev from dolgozo, osztaly where dolgozo.oazon=osztaly.oazon and (osztaly.telephely='DALLAS' or osztaly.telephely='CHICAGO');`

- Kik azok a dolgozók, akik osztályának telephelye nem DALLAS és nem CHICAGO?
    - `π dnev (σ telephely ≠ 'DALLAS' ∧ telephely ≠ 'CHICAGO' (dolgozo ⨝ osztaly) )`
    - `select dolgozo.dnev from dolgozo, osztaly where dolgozo.oazon=osztaly.oazon and (osztaly.telephely!='DALLAS' and osztaly.telephely!='CHICAGO');`

- Adjuk meg azoknak a nevét, akiknek a fizetése > 2000 vagy a CHICAGO-i osztályon dolgoznak.
    - `π dnev (σ fizetes > 2000 ∨ telephely = 'CHICAGO' (dolgozo ⨝ osztaly) )`
    - `select dolgozo.dnev from dolgozo, osztaly where dolgozo.oazon=osztaly.oazon and (dolgozo.fizetes>2000 or osztaly.telephely='CHICAGO');`

- Melyik osztálynak nincs dolgozója?
    - `π oazon (osztaly) - π oazon (dolgozo)`
    - `select oazon from osztaly MINUS select oazon from dolgozo;`

- Adjuk meg azokat a dolgozókat, akiknek van 2000-nél nagyobb fizetésű beosztottja.
    - `π d2.dnev (σ d1.fonoke = d2.dkod ∧ d1.fizetes > 2000 (ρ d1 (dolgozo) ⨯ ρ d2 (dolgozo)))`
    - `select distinct d2.dnev from dolgozo d1, dolgozo d2 where d1.fonoke=d2.dkod and d1.fizetes>2000;`

- Adjuk meg azokat a dolgozókat, akiknek nincs 2000-nél nagyobb fizetésű beosztottja.
    - `π d2.dnev (σ d1.fonoke = d2.dkod (ρ d1 (dolgozo) ⨯ ρ d2 (dolgozo))) - π d2.dnev (σ d1.fonoke = d2.dkod ∧ d1.fizetes > 2000 (ρ d1 (dolgozo) ⨯ ρ d2 (dolgozo)))`
    - `(select d2.dnev from dolgozo d1, dolgozo d2 where d1.fonoke=d2.dkod) MINUS (select distinct d2.dnev from dolgozo d1, dolgozo d2 where d1.fonoke=d2.dkod and d1.fizetes>2000);`

- Adjuk meg azokat a telephelyeket, ahol van elemző (ANALYST) foglalkozású dolgozó.
    - `π telephely (σ foglalkozas = 'ANALYST' (dolgozo ⨝ osztaly) )`
    - `select distinct osztaly.telephely from dolgozo, osztaly where dolgozo.oazon = osztaly.oazon and dolgozo.foglalkozas='ANALYST';`

- Adjuk meg azokat a telephelyeket, ahol nincs elemző (ANALYST) foglalkozású dolgozó.
    - `kivonom az alaphalmazból az előzőt`

- Adjuk meg a maximális fizetésű dolgozó(k) nevét.
    - `π dnev (dolgozo) - π d1.dnev σd1.fizetes < d2.fizetes (ρ d1 dolgozo ⨯ ρ d2 dolgozo)`
    - `select dnev from dolgozo MINUS select d1.dnev from dolgozo d1, dolgozo d2 where d1.fizetes < d2.fizetes`