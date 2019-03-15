DECLARE 
   @ename varchar(10),
   @wages int,
   @counter int
DECLARE c1 cursor  FOR
    select ename,sal+isnull(comm,0) from emp where deptno=20
DECLARE
	c2 cursor FOR 
	select count(*) from emp where sal>2000
DECLARE
	c3 cursor FOR
	select count(*) from emp where sal<isnull(comm,0)
begin
  set @counter=0
-- cursor open for printing all the total wages of employees in dept 20
  open c1
    fetch next from c1 into @ename,@wages
    print @wages
    set @counter=1
    while(@@fetch_status = 0)
    begin
        fetch next from c1 into @ename,@wages
        print @wages
        set @counter=@counter+1
    end
  close c1
  deallocate c1
-- cursor c1 completed 
    open c2
    fetch next from c2 into @wages
	print @wages
	close c2
	deallocate c2
end
