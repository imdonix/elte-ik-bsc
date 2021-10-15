select * from dba_objects;



select count(*) from dba_objects;



select * from all_objects;



select count(*) from all_objects;



select * from user_objects;



select * from dba_objects where owner='BRANYI';



create table x (a number);


drop table x;



select * from user_objects where object_name='X';




drop view x;


create table x (a number);


select * from user_objects;



select * from x;
select * from X;
select * from "X";
select * from "x";


-- x,X,"X" azonos


create table "x" (b number);


select * from "x";



select * from user_objects where object_name='X';



select * from user_objects where object_name='x';



select * from dba_objects where upper(object_name)='X' order by 9 desc;


/*
create table |   ........
         AlmA  ALMA
         Alma  alma

"" esetén 4db
"" nélkül csak 1 az ALMA jön létre
*/

select * from user_objects  order by 1;


select * from dba_objects where object_name='DBA_TABLES' and object_type='VIEW';



select owner from dba_objects where object_name='DBA_TABLES' and object_type='VIEW';




select owner from dba_objects where object_name='DUAL' and object_type='TABLE';



select * from dual;


select 1+1;



select 1+1 from;




select 1+1 from dual;


select 1+1 from x;


select * from sz;


select 1+1 from sz;



select * from dual;

select * from x;


create table dual (x number);

select * from user_objects;


select 1+1 from dual;



insert into dual values(25);



delete from dual;


select 1+1 from dual;


drop table dual;


select * from dba_objects where object_name='DUAL' and object_type='TABLE';


select 1+1 from dual;



select * from dba_objects where object_name='DUAL';


select 1+1 from sys.dual;


select 1+1 from b8bmvr.dual;




SELECT object_type FROM dba_objects;



SELECT distinct object_type FROM dba_objects;




SELECT count(distinct object_type) FROM dba_objects;




SELECT distinct object_type FROM dba_objects order by 1;





drop table "x";
drop table x;
drop table dual;
create view x as select * from dual;



create table "b" (b number, "b" varchar2(10));

