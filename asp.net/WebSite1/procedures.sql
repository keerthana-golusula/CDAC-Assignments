-- create procedure sp_insertmath
<-- @Num1 int,
@Num2 int,
@result int,
@Operation Varchar(2),
@Date date
as 
insert into table_1 values(@Num1,@Num2,@result,@Operation,@Date)

exec sp_insertmath 20,30,50,'+','12/10/2019';
select * from table_1;-->

alter procedure retrieval
as 
select Number1,Number2,Result,Operation,Date from table_1

exec retrieval ;