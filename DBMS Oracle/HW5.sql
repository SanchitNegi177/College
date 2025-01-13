create table employee(Emp_ID number Primary Key, City varchar2(10), Salary number, NAME varchar2(10),department varchar2(10));

insert all
into employee values(2001, 'Delhi', 50000, 'Sid', 'CSE')
into employee values(2002, 'Mumbai', 40000, 'Sid2', 'CSE')
into employee values(2003, 'Dehradun', 50000, 'Sid3', 'CCC')
into employee values(2004, 'Dehradun', 39000, 'Sid4', 'Finance')
into employee values(2005, 'Delhi', 66000, 'Sid5', 'Finance')
into employee values(2006, 'Delhi', 90000, 'Sid6', 'CSE')
into employee values(2007, 'Delhi', 59000, 'Sid7', 'Finance')
into employee values(2008, 'Mumbai', 89000, 'Sid8', 'EEE')
select * from dual;



--ENTER NAME AND DEPARTMENT ALSO
alter table Employee ADD Department varchar2(10);
alter table Employee ADD Name varchar2(10);

update employee SET Department='HR' where Emp_ID=2001;
update Employee SET Department='HR',name ='Sanchit' where Emp_ID=2002;


SELECT COUNT(*) from employee;

SELECT city, COUNT(*) from employee group by city;

--IN
select name, city from employee where city IN (Select city from employee GROUP BY city HAVING COUNT(*)>1);


-- All
SELECT CASE WHEN (SELECT City FROM Employee where rownum=1 ) = ALL (SELECT City FROM Employee) 
           THEN 'All employees are from the same city' 
           ELSE 'Employees are from different cities' 
       END AS CityCheck
FROM DUAL;

--ANY
-- SELECT CASE WHEN e2.city <> ANY(SELECT city FROM Employee) 
-- THEN 'Employees are from different cities'
-- ELSE 'All employees are from the same city' 
-- END AS result from Employee e2
-- WHERE ROWNUM=1;

SELECT CASE WHEN (select city from Employee WHERE ROWNUM=1 ) <> ANY(SELECT city FROM Employee) 
THEN 'Employees are from different cities'
ELSE 'All employees are from the same city' 
END AS result
FROM DUAL;

-- SELECT salary, max(salary) ,name
-- FROM employee
-- GROUP BY salary;

--Exists
SELECT CASE WHEN EXISTS(SELECT city FROM Employee e1 WHERE e1.city<>e2.city) 
THEN 'Employees are from different cities'
ELSE 'All employees are from the same city' 
END AS result from Employee e2 WHERE ROWNUM=1;


--Exists
-- SELECT CASE
--            WHEN NOT EXISTS (SELECT 1 FROM EMPLOYEE e 
--            WHERE e.CITY <> (SELECT CITY FROM EMPLOYEE WHERE ROWNUM = 1))
--            THEN 'All employees are from the same city'
--            ELSE 'Employees are from different cities'
--        END AS CityCheck
-- FROM DUAL;
