create table Employee(Emp_id number Primary Key, Name varchar2(20), Department varchar2(20), Age number, Salary number, City varchar2(20), check(Age > 18));

insert ALL
into Employee VALUES (1, 'Sid', 'CSE', 20, 80000, 'Deheradun')
into Employee VALUES (2, 'Sagar', 'Finance', 21, 8000, 'Deheradun')
into Employee VALUES (3, 'Sanchit', 'ECE', 22, 80000, 'Kotdwar')
into Employee VALUES (4, 'Ashish', 'Finance', 22, 800, 'Something')
into Employee VALUES (5, 'Akshay', 'CSE', 20, 7000, 'Deheradun')
into Employee VALUES (6, 'Archit', 'Finance', 21, 6000, 'Deheradun')
into Employee VALUES (7, 'Harshit', 'ECE', 22, 500, 'Kotdwar')
into Employee VALUES (8, 'Garv', 'HR', 19, 400, 'Something')
into Employee VALUES (9, 'Sarthak', 'Finance', 37, 60000, 'Deheradun')
into Employee VALUES (10, 'Buddha', 'ECE', 80, 4500, 'Kotdwar')
into Employee VALUES (11, 'MrDirector', 'HR', 40, 93200, 'Something')
SELECT * FROM dual;

-- •	Find out the maximum and minimum salary from the employee table.
Select max(Salary) as max_salary, min(Salary) as min_salary from employee;

Select max(Salary) - min(Salary) as difference from employee;

-- Display total and avg salary
Select sum(salary) as Total, avg(salary) as Average from employee

-- •	Show all the details of the employees who have the same salary
select * from employee where salary in (select salary from employee group by salary having count(*) > 1);

-- •	Display the employees name from lowest salary to the highest salary.
select name from employee order by salary DESC;

-- •	Display the employee name and salary (department-wise) for employees, whose salary is greater than or equal to 10,000 and age is greater than 25.
select Department, Name, Salary from employee where salary >= 10000 and age > 25 order by department,salary DESC;


-- GENERAL QUESTION NOT TO BE INCLUDED IN THE FILE
-- Display the employee name and salary for employee with 4th highest salary 

select salary from ( select salary, rank() over (order by salary DESC) as SalaryRank from employee) where SalaryRank = 4;

-- to print other values
select name,salary from ( select salary,name, rank() over (order by salary DESC) as SalaryRank from employee) where SalaryRank = 4;




select * from ( select salary,name, rank() over (order by salary DESC) as SalaryRank from employee) where SalaryRank >= 4;


-- Print all the details

SELECT *
FROM EMPLOYEE
WHERE Salary = (
    SELECT MIN(Salary)
    FROM (
        SELECT Salary
        FROM EMPLOYEE
        ORDER BY Salary DESC
    )
    WHERE ROWNUM <= 4
);


-- Single line command (only 1 select) Display the employee name and salary for employee with 4th highest salary 
-- Two instances
select distinct e1.E_ID, e1.salary from employee e1, employee e2 where e1.salary=e2.salary and e1.E_ID <> e2.e_id;