select ceil(123.45), ceil(-123.45), floor(123.45), floor(-123.45) from dual;

select exp(3) from dual;
select log(10,100) from dual;

select mod(12345,3) from dual;
select mod(12347,3) from dual;

select round(163.45) from dual;
select round(163.456,2) from dual;
select round(163.45,-2) from dual;

select trunc(163.45) from dual;
select trunc(163.456,2) from dual;
select trunc(163.45,-2) from dual;

select power(10,2) from dual;

select sqrt(100) from dual;

select sin(1) from dual;


select chr(100) from dual;
select ascii('Hello') from dual;


select concat('alma','fa') , 'alma'||'lekvár' from dual;

select initcap('alma fa') from dual;

select lower('AlMaFa'),  upper('AlMaFa') from dual;
select lower('NeSZe NeKed'),  upper('NeSZe NeKed') from dual;


select lpad('szia',12,'xyz') , rpad('szia',12,'xyz') from dual;
select lpad('szia',3,'xyz') , rpad('szia',3,'xyz') from dual;

select lpad('szia',6),rpad('szia',6) from dual;
select lpad('szia',6),rpad('szia',6) x from dual;

select lpad('123',15,'*') , lpad('123',15,'0') from dual;

select ltrim('xxyzyyyyyyzyzzyszia','xyz'), rtrim('sziaxxzzzyzy','xyz') from dual;

select trim('      szia     ') from dual;

select trim('      szia     ') x from dual;
select trim('  ez egy mondat     ') x from dual;
select length(trim('      szia     ')) from dual;

select substr('kutyafüle',6,3) from dual;

select substr('kutyafüle',6) from dual;

select substr('kutyafüle',-6,3) from dual;

select substr('kutyafüle',-6) from dual;
select substr('kutyafüle',-6,-3) from dual;

select instr('0011101100110001001010100100','10') from dual;

select instr('0011101100110001001010100100','10',10) from dual;

select instr('0011101100110001001010100100','10',5,5) from dual;

select instr('0011101100110001001010100100','2') from dual;

select instr('0011101100110001001010100100','10',5,15) from dual;

select instr('0011101100110001001010100100','00',1,5) from dual;


select current_date from dual;
select current_timestamp from dual;
select sysdate from dual;
select systimestamp from dual;

select ADD_MONTHS(current_date,9) from dual;

select extract(year from CURRENT_TIMESTAMP) from dual;

select extract(minute from CURRENT_TIMESTAMP) from dual;

select extract(year from sysdate) from dual;

SELECT MONTHS_BETWEEN
       (TO_DATE('02-02-2017','MM-DD-YYYY'),
        TO_DATE('01-30-2018','MM-DD-YYYY') ) "Months"
  FROM DUAL;

select ename,sin(sal) eredmény from emp;

select 1+1 from dual;
select to_number('1') +to_number('1') from dual;

select '1'||'1' from dual;
select '1'+'1' from dual;
select '1'+1 from dual;
select 'a'+1 from dual;
select '1e1'+1 from dual;
select to_char(1)||to_char(1) from dual;

select to_char(current_date,'year') from dual;
select to_char(current_date,'YEAR') from dual;
select to_char(current_date,'Year') from dual;
select to_char(current_date,'mon') from dual;
select to_char(current_date,'Mon') from dual;
select to_char(current_date,'MON') from dual;
select to_char(current_date,'Day') from dual;
select to_char(current_date,'Dy') from dual;
select to_char(current_date,'D') from dual;
select to_char(current_date,'DD') from dual;
select to_char(current_date,'DDD') from dual;
select to_char(current_date,'HH') from dual;
select to_char(current_date,'HH24') from dual;

select to_char(12345,'000999999') x from dual;
select to_char(12345,'0009999') x from dual;
select to_date('2017-03-17','YYYY-MM-DD') from dual;
ALTER SESSION SET NLS_DATE_FORMAT ='YYYY-MON-DD';
ALTER SESSION SET NLS_DATE_LANGUAGE = HUNGARIAN;
ALTER SESSION SET NLS_DATE_FORMAT ='YY-MON-DD';
select to_date('17-DEC.-17','DD-Mon-YY') from dual;

select * from emp;
select ename,job from emp;
select ename,length(job) from emp;
select ename, case job
        when 'PRESIDENT' then 'Elnök'
        when 'CLERK' then 'Titkár'
        else 'egyéb'
        end  from emp;

select ename,job from emp;
select ename,length(job) from emp;
select ename,job from emp;
select ename,length(job) from emp;
select ename, case 
        when job='PRESIDENT' then 'Elnök'
        when job='CLERK' then 'Titkár'
        else 'egyéb'
        end  from emp;
select ename, case job
        when 'PRESIDENT' then 'Elnök'
        when 'CLERK' then 'Titkár'
        else 'egyéb'
        end x from emp;
select ename,case 
      when sal<1000 then 'kevés'
      when sal<3000 then 'közepes'
      else 'sok'
      end eredmény,sal from emp;

select ename,decode(job,'PRESIDENT','Elnök','CLERK', 'Titkár', 'egyéb') eredmény
from emp;
select ename,decode(kifejezés0,kifejezés1,kifejezés1_új,
kifejezés2,kifejezés2_új[,nemkötelezõ alapérték] ) oszlopnév
from emp;

select ename,sal,comm,sal+comm from emp;

select ename,sal,comm,sal+comm from emp where comm is not null
union
select ename,sal,comm,sal+0 from emp where comm is null;

select ename,sal,comm,sal+nvl(comm,0) from emp;

select ename,sal,comm,sal+nvl(comm,-500) from emp;
select ename,sal,comm,sal+coalesce(comm,0) from emp;
select * from sz;
insert into sz values(null,'banán');
select N from sz;
select NVL(N,'AKÁRKI') from sz;

select user from dual;

SELECT UID FROM DUAL;


