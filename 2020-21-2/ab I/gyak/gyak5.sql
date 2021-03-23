select 'szia';
select 'szia' from dual;
select 1+1 from dual;
select 1+1 from a1;
select 1+1 from sz;
select * from sz;
select n,1+1 from sz;
create table dual (x number);
select 'szia' from sys.dual;
drop table dual;

select 1+1 eredmény from dual;
select 1+1 "1+1=" from dual;
select 1+1,1*1,1/1,1-1 from dual;
select 1+1 összeg,1*1 szorzat,1/1 "1/1=",1-1 "1-1=" from dual;
select * from dual;
select dummy x from dual;

select * from sz állatok;
select * from sz "x y";
select sz.n,sz.gy from sz;
select sz.n,sz.gy from sz állatok;
select állatok.n,állatok.gy from sz állatok;
select "x y".n,"x y".gy from sz "x y";

select * from proba;
insert into proba values(5);
select * from PROBA;
select * from "proba";

select huha from proba;
select HUHA from proba;
select Huha from proba;
select "Huha" from proba;
select * from sz where n='Füles';
select * from sz where n!='Füles';
select * from sz where n^='Füles';
select * from sz where n<>'Füles';

select * from sz where n between'Füles' and 'Malacka';
select * from sz where n>='Füles' and n<='Malacka';
select * from sz where n between'F' and 'Mx';

select * from sz where n like 'M%';
select * from sz where n like '%a';
select * from sz where n like 'M______';
select * from sz where n like '____a';
select * from sz where n like '%y%';
select * from sz where n like '%M%';

select null from dual;
select 'igaz' from dual where 1=1;
select 'igaz' from dual where 1=0;
select 'igaz' from dual where null=null;
select 'igaz' from dual where null!=null;
select 'igaz' from dual where null is null;
select 'igaz' from dual where null is not null;
select * from sz where n is null;
insert into sz values (null,'dinnye');
select * from sz where n is not null;
select 'igaz' from dual where 1 in (0,1,2,3);
select 'igaz' from dual where -1 in (0,1,2,3);
select 'igaz' from dual where (1,2) in ((0,0),(0,1),(1,1),(1,2),(0,3));
select 'igaz' from dual where (2,1) in ((0,0),(0,1),(1,1),(1,2),(0,3));
select 'igaz' from dual where 'izé' in ('nesze','bigyó','izé','mi ez');
select 'igaz' from dual where 'körte' in (select gy from sz);
select 'igaz' from dual where 'banán' in (select gy from sz);
select 'igaz' from dual where ('Füles','körte') in (select * from sz);
select 'igaz' from dual where ('Nyuszi','körte') in (select * from sz);
select * from sz where n in ('Füles','Kanga');
select * from sz where n in (select n from sz where gy='alma');
select * from emp where deptno in (20,30);
select * from emp where deptno in (select min(deptno)from emp);
select * from emp where deptno = (select min(deptno)from emp);
select * from emp 
where deptno = (select distinct deptno from emp where hiredate>'82-JÚN.-09');
select * from emp 
where deptno in (select deptno from emp where hiredate>'82-JÚN.-09');

select * from emp 
where deptno > (select distinct deptno from emp where hiredate>'82-JÚN.-09');
select * from emp 
where deptno > (select deptno from emp where hiredate>'82-JÚN.-09');

select * from emp 
where deptno > any (select deptno from emp where hiredate>'81-JÚN.-09');
select * from emp 
where deptno > some (select deptno from emp where hiredate>'82-JÚN.-09');
select * from emp 
where deptno > all (select deptno from emp where hiredate>'81-JÚN.-09');

select * from emp where exists (select n from sz where gy='banán');
select * from emp where exists (select n from sz where gy='alma');
select * from emp x 
where not exists (select * from emp where empno=x.empno and sal >2000);