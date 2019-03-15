--  List all employees who have a salary between 1000 and 2000
select * from emp where sal between 10000 and 50000;
-- 2. List department numbers and names in department name order. 
select deptno,dname from dept order by dname;
--  3. Display all the different job types. 
select dname from dept;
--  4. List the details of the employees in departments 10 and 20 in alphabetical order of  employee names. 
select * from emp where deptno in (10,20);
-- 5. List names and jobs of all clerks in department 20.
select ename,job from emp where job='clerk' and deptno=20;
-- 6. Display all employee names which have TH or LL in them
select ename from emp where ename like '%an%' or ename like '%ee%';
--  7. List the details of the employees who have a manager 
select * from emp where 0!=isnull(mgr,0);
-- r 8. Display the name and the total remuneration for all employees
select ename,sal+isnull(comm,0) "total remunaration" from emp ;
 --9. Display name, annual salary and commission of all sales people whose monthly salary is  
-- greater than their commission. The output should be ordered by salary highest first. If two or 
 -- more employees have the same salary sort by employee name, within the highest salary order
 select ename,sal*12 "annual salary",isnull(comm,0) from emp where sal>comm and deptno=(select deptno from dept where dname='sales')
 order by sal desc,ename;
 -- 10. List the employee names and their salaries increased by 15% and expressed as a whole number Display the employee name and job by concatenating them and give an appropriate heading. 
 select concat(ename,concat(' is ',job)) "name with designation", sal*1.15 "hiked salary" from emp;
 -- 11. It has been discovered that the sales people in department 30 are not all male. Hence  display the job of salesman as salesperson
 update emp set job='salespers' where job='salesman';
 --  12. List the minimum and maximum salary for each job type
 select job,min(sal) "minimun salary",max(sal) "maximum salary" from emp group by job;
 --13. Find out how many managers are there without listing them. 
 select count(*) "no of managers" from emp where job='manager';
-- . 14. Find out the average salary and total remuneration for each job type. 
select job,avg(sal) "average salary", sum(sal+isnull(comm,0))"total remunaration" from emp group by job;\
-- 15. Find out the difference between highest and lowest salaries. 
select job,max(sal)-min(sal) "diff of high and low salaries" from emp group by job;
-- 16. Find all departments, which have more than 3 employees.
select deptno from emp group by deptno having count(*)>3;
--  17. Check whether all employee numbers are indeed unique. 

--  18. List the lowest paid employees working for each manager. Exclude any groups where the  minimum salary is less than 1000
select ename,mgr,sal from emp e where sal=(select min(sal) from emp where mgr=e.mgr) and sal>20000 order by sal; 
--  19. Display all employee names and their department names, in the order of department name. 
select ename,dname from emp,dept where emp.deptno=dept.deptno order by dname;
 -- 20. Display all employee names, department number and department name
 select ename,dept.deptno,dname from emp,dept where emp.deptno=dept.deptno;
 --  21. Display the name, location and department of employees whose salary is more than 1500 a  month. 
 select ename, loc,dname from emp,dept where emp.deptno=dept.deptno and emp.sal>30000;