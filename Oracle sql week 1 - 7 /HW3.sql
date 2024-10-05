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
SELECT * FROM dual;

-- count number of employee
SELECT COUNT(*) from employee;

-- Display all employees of age 22
Select * from employee where age = 22;

-- Display eid and department of employee with salary >= 50000
Select emp_id, department from employee where salary >= 50000;

-- •	Print the name of the employees and label the column as "Full Name" for those employees whose department name is 'Finance' and age is 22
Select name as "Full Name" from employee where department = 'Finance' and age = 22;

-- •	Print the department names from the employee table without having the duplicates.
Select unique department from employee;




-- USEFULL
update employee set department = 'Finance' where department = 'ECE';