
select * from dba_objects;


select distinct object_type from dba_objects order by 1;



-- 6. Kik azok a felhasználók, akiknek több mint 10 féle objektumuk van? (owner)



select owner from dba_objects group by owner having count( unique object_type ) > 10; -- distinct



select owner,count( unique object_type ) from dba_objects group by owner 
having count( unique object_type ) > 10; 


-- 7. Kik azok a felhasználók, akiknek van nézete és triggere is? (owner)


SELECT distinct owner FROM dba_objects WHERE object_type='VIEW';

SELECT distinct owner FROM dba_objects WHERE object_type='TRIGGER';



SELECT distinct owner FROM dba_objects WHERE object_type='VIEW' and object_type='TRIGGER'; -- ures, ez rossz

SELECT distinct owner FROM dba_objects WHERE object_type='VIEW' or object_type='TRIGGER';  -- union




SELECT distinct owner FROM dba_objects WHERE object_type='VIEW'
intersect
SELECT distinct owner FROM dba_objects WHERE object_type='TRIGGER';



-- 8. Kik azok a felhasználók, akiknek van nézete, de nincs triggere? (owner)





SELECT distinct owner FROM dba_objects WHERE object_type='VIEW'
  MINUS
SELECT distinct owner FROM dba_objects WHERE object_type='TRIGGER';


-- 9. Kik azok a felhasználók, akiknek több mint 40 táblájuk, de maximum 37 indexük van? (owner)


-- kinek van több mint 40 táblája
select distinct owner from dba_objects where object_type = 'TABLE';


select owner from dba_objects where object_type='TABLE' group by owner having count(object_type)>40;

select owner,count( * ) from dba_objects where object_type = 'TABLE' group by owner;
-- having count( object_type ) > 40;

select owner from dba_objects where object_type = 'TABLE' group by owner
having count( * ) > 40
intersect
select owner from dba_objects where object_type = 'INDEX' group by owner
having count( * ) <= 37;


-- 9. Kik azok a felhasználók, akiknek több mint 40 táblájuk, de maximum 37 indexük van? (owner)


select owner,count( * )  from dba_objects where object_type = 'TABLE' group by owner
/*having count( * ) > 40*/;


-- Miért hibás ez a megoldás, hogyan javítható?



-- jó változat pl_1:
SELECT distinct owner FROM dba_objects WHERE object_type='TABLE'
 GROUP BY owner HAVING count(*) > 40
  MINUS
 SELECT distinct owner FROM dba_objects WHERE object_type='INDEX'
 GROUP BY owner HAVING count(*) > 37;

 select owner from dba_objects where object_type = 'INDEX' group by owner
having count( * ) <= 37;
 
 -- pl_2:
 -- a metszet második része helyett mindenki akinek nincs (össz minus akinek van) 
 -- vagy (union) kevesebb mint 37
 select owner from dba_objects where object_type = 'INDEX' group by owner
having count( * ) <= 37                 -- legalább 1 de max 37
union
(select username from dba_users
minus                                   -- 0 indexesek
select owner from dba_objects where object_type = 'INDEX');


select owner from dba_objects where object_type = 'TABLE' group by owner
having count( * ) > 40
intersect
( select owner from dba_objects where object_type = 'INDEX' group by owner
having count( * ) <= 37                 -- legalább 1 de max 37
union
(select username from dba_users
minus                                   -- 0 indexesek
select owner from dba_objects where object_type = 'INDEX'));

-- 10. Melyek azok az objektum típusok, amelyek tényleges tárolást igényelnek, 
-- vagyis tartoznak hozzájuk adatblokkok? (object_type)
-- (Az olyan objektumoknak, amik nem igényelnek tényleges tárolást, 
-- pl. nézet, szinonima, csak a definíciója tárolódik az adatszótárban.
--A megoldáshoz a data_object_id oszlopot vizsgáljuk meg.)

select * from dba_objects;

select distinct object_type from dba_objects where data_object_id is not null;

-- 11.	Melyek azok az objektum típusok, amelyek nem igényelnek tényleges tárolást,
-- vagyis nem tartoznak hozzájuk adatblokkok? (object_type)

select distinct object_type from dba_objects where data_object_id is null;

-- 12. Keressük meg az utóbbi két lekérdezés metszetét. (object_type)
-- (Ezek olyan objektum típusok, amelyekbõl elõfordul adatblokkokkal rendelkezõ
-- és adatblokkokkal nem rendelkezõ is.) Vajon miért? -> lásd majd partícionálás

select distinct object_type from dba_objects where data_object_id is not null
intersect
select distinct object_type from dba_objects where data_object_id is null;



-- dba_tab_columns --------------------------
-- create table "b" (b number, "b" varchar2(10));
-- create table b (b number, "b" varchar2(10));


select * from dba_tab_columns;

select * from all_tab_columns;

select * from user_tab_columns;

-- 13.	Hány oszlopa van a nikovits.emp táblának? (darab)

select * from nikovits.emp;


select * from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP';

select * from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP' order by column_id;



select count(*) "darab" from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP';


-- 14.	Milyen típusú a nikovits.emp tábla 6. oszlopa? (data_type)

select data_type from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP'
    and column_id = 6;
select data_type,data_precision,data_scale from dba_tab_columns 
where owner='NIKOVITS' and table_name = 'EMP' and column_id = 6;

select data_type from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP'
    and column_id = 2;
 select data_type,data_length from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP'
    and column_id = 2;

-- 15.	Adjuk meg azoknak a tábláknak a tulajdonosát és nevét, 
-- amelyeknek van 'Z' betûvel kezdõdõ oszlopa. (owner, table_name)

select owner, table_name from dba_tab_columns where column_name like 'Z%';



select owner, table_name,column_name from dba_tab_columns where column_name like 'Z%';



-- drop table z;
-- create table z (zelso number, zmasodik number, "zharmadik" number);


select distinct owner, table_name from dba_tab_columns where column_name like 'Z%';


select owner, table_name from dba_tab_columns where column_name like 'Z%' group by table_name, owner;


-- ugyan azt adja? distinct sort vagy hash group by

select distinct owner, table_name from dba_tab_columns where column_name like 'Z%'
minus
select owner, table_name from dba_tab_columns where column_name like 'Z%' group by table_name, owner;


-- 16. Adjuk meg azoknak a tábláknak a nevét, amelyeknek legalább 8 
-- darab dátum tipusú oszlopa van. ( table_name)
desc DBA_HEATMAP_TOP_TABLESPACES
select * from dba_tab_columns where table_name = 'DBA_HEATMAP_TOP_TABLESPACES';

select table_name from dba_tab_columns where data_type = 'DATE' 
group by table_name having count( * ) >= 8;






select * from dba_tab_columns where owner='NIKOVITS' and table_name = 'EMP';


select table_name,count( * ) from dba_tab_columns where data_type = 'DATE' 
group by table_name having count( * ) >= 8;



select * from dba_tables where table_name='EMP';
select * from dba_tab_columns where table_name='EMP' and data_type='DATE';
-- mind a kettõ rossz
-- jó változat

SELECT owner, table_name FROM dba_tab_columns WHERE data_type='DATE'
 GROUP BY owner, table_name HAVING count(*) >= 8;

SELECT table_name FROM dba_tab_columns WHERE data_type='DATE'
 GROUP BY owner, table_name HAVING count(*) >= 8;



-- 17. Adjuk meg azoknak a tábláknak nevét, amelyeknek 1. es 4. oszlopa is VARCHAR2 típusú

select table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 1;
select table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 4;

select table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 1
intersect
select table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 4;




-- ez hibás, mert itt egy ellenpélda
select * from dual;  -- sys dual-ja 1 oszlopos varchar

select * from dba_tab_columns where table_name='DUAL';

create table dual (
q number,
w number,
e number,
r varchar2(1)); -- ez 4 oszlopos , de csak a 4.ben van varchar
-- mégis a dual benne lesz a rossz megoldásban


drop table dual;


-- jó:
select owner,table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 1
intersect
select owner,table_name from dba_tab_columns where data_type = 'VARCHAR2' and column_id = 4;
-- ez is jó
select owner,table_name from dba_tab_columns
where data_type = 'VARCHAR2' and ( column_id = 1 or column_id = 4 )
group by owner,table_name having count( table_name ) = 2;

