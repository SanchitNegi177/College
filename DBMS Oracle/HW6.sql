--Using employee table in HW 5
-- ADD NAME and DEPARTMENT to it;

insert into employee values(2011,'Haridwar',45000,'CSE','ayan');
insert into employee values(2012,'Kotdwar',20000,'IT','Rish');
insert into employee values(2013,'Kanpur',30000,'CSE','Reyansh');
insert into employee values(2014,'Rishikesh',80000,'CSE','Arya');
insert into employee values(2015,'Punjab',20000,'IT','Luv');

insert into employee values(2016,'Ram Garh',20000,'Finance','Bill');

insert into employee values(2018,'Chandigarh',20000,'IT','Ram');
insert into employee values(2017,'Pithodgarh',50000,'IT','Himanshu');
insert into employee values(2019,'Delhi',40000,'CSE','ayan');


--Q1
select * from employee where Department='CSE';


--Q2
SELECT name FROM EMPLOYEE WHERE name LIKE 'ay%';

--Q3
SELECT * FROM EMPLOYEE WHERE name LIKE '%sh';

--Q4
SELECT name,department FROM EMPLOYEE WHERE city LIKE 'D%' OR name LIKE '%h';

--Q5
SELECT * FROM EMPLOYEE WHERE salary > 15000 AND name LIKE 'H%';

--Q6
SELECT name FROM EMPLOYEE WHERE name LIKE '___';

--Q6 another way
SELECT name FROM EMPLOYEE WHERE LENGTH(name) == 3;

--Q7
SELECT name FROM EMPLOYEE WHERE LENGTH(name) >= 5;

-- Q7 another way
 SELECT name FROM EMPLOYEE WHERE name LIKE '_____%'
