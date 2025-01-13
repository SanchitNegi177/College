--Q1
create table department(dep_id number primary key,name varchar2(15));
create table employee(emp_id number primary key,dep_id number , name varchar2(15) ,age number, salary number,city varchar2(15), foreign key(dep_id) references department(dep_id),check (age>18));

insert all
into department values(1,'CSE')
into department values(2,'IT')
into department values(3,'Finance')
into department values(4,'HR')
into department values(5,'Electical')
into department values(6,'Mechanical')
into department values(7,'Civil')
select * from dual;


insert all
into employee values(1,1,'Sanchit',20,100000,'Kotdwar')
into employee values(2,1,'Harshit',20,90000,'Tanakpur')
into employee values(3,2,'Tomar',19,200000,'Dehradun')
into employee values(4,3,'Rishab',32,50000,'Kotdwar')
into employee values(5,5,'Archit',22,88000,'Tanakpur')
into employee values(6,6,'Rohit',35,20000,'Najibabad')
into employee values(7,7,'Shukla',20,66000,'Kanpur')
into employee values(8,4,'Himanshu',40,66000,'Dehradun')
select * from dual;

insert into employee values(9,NULL,'Rishi',40,25000,'Kanpur');
insert into employee values(10,NULL,'Aman',60,20000,'Delhi');
insert into employee values(11,NULL,'Armaan',20,30000,'Haldwani');


--Q2  Display the details of employees along with their corresponding department names. 
SELECT e.emp_id, e.name as employee_name, e.age, e.salary, e.city, d.name  department_name
FROM employee e
LEFT JOIN department d
ON e.dep_id = d.dep_id;



--Q3 Print the names of employees who are not assigned to any department.
select name from employee where dep_id IS NULL;

--Q4 Print the employee names and department names for employees whose salary is greater than 25,000. (Using left join). 
SELECT e.name employee_name, d.name department_name
FROM employee e
JOIN department d
ON e.dep_id = d.dep_id
WHERE e.salary>25000;

--Q5 Remove this question as it is same as Q3
-- SELECT e.name employee_name, d.name department_name
-- FROM employee e
-- LEFT JOIN department d
-- ON e.dep_id = d.dep_id
-- WHERE e.dep_id is NULL;

--Q6Print the employee names and their corresponding department names for employees with a salary greater than 25,000. (Using right join). 

SELECT e.name employee_name, d.name department_name
FROM department d
RIGHT JOIN employee e
ON e.dep_id = d.dep_id
WHERE e.salary>25000;

--Q7 Display the names of departments along with the names of employees who are older than 30 years. 
SELECT e.name employee_name, d.name department_name
FROM employee e
LEFT JOIN department d
ON e.dep_id = d.dep_id
WHERE e.age>30;



--rough
    SELECT dep_id,MAX(salary) AS max_salary
    FROM employee
    GROUP BY dep_id
    ORDER BY dep_id;

select * from employee where salary in (select salary from employee group by salary having count(*) > 1);

SELECT dep_id,MAX(salary) 
    FROM employee
    GROUP BY dep_id
    ORDER BY dep_id;