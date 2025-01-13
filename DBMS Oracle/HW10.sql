create table employee (id number primary key,name varchar2(10),age number ,department varchar2(10),salary number);
INSERT ALL
INTO employee  VALUES (1, 'Sanchit',22, 'IT',100000)
INTO employee  VALUES (2, 'Pokhriyal', 21, 'CSE',200000)
INTO employee  VALUES (3, 'Harshit', 25, 'Finance',110000)
INTO employee  VALUES (4, 'Tomar', 30, 'CSE',80000)
INTO employee  VALUES (5, 'Shukla', 21, 'IT',50000)
INTO employee  VALUES (6, 'Archit', 20, 'CSE',100000)
INTO employee  VALUES (7, 'Arpit', 19, 'HR',140000)
INTO employee  VALUES (8, 'Rishab', 30, 'R and D',300000)
select * from dual;


-- Find out the second minimum salary of an employee.  
SELECT distinct salary AS second_min_salary
FROM 
(
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary ASC) AS rnk
    FROM employee
)
WHERE rnk = 2;

-- Find out the second minimum salary of an employee without using limit, dense range, and order by clause. 
SELECT MIN(salary) AS second_min_salary
FROM employee
WHERE salary > (SELECT MIN(salary) FROM employee);


-- Find out the third maximum salary of an employee.  
SELECT distinct salary AS second_min_salary
FROM 
(
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM employee
)
WHERE rnk = 3;



--  Find out the third maximum salary of an employee without using limit, dense range, and order by clause.  
SELECT MAX(salary) AS Third_Max_Salary FROM employee 
WHERE salary < (SELECT MAX(salary) FROM employee 
WHERE salary < (SELECT MAX(salary) FROM employee));


-- Display the names and salaries of employees who earn more than the average salary of their department.  
SELECT name, salary FROM employee e1
WHERE salary > (
    SELECT AVG(salary)
    FROM employee e2
    WHERE e1.department = e2.department
);


-- Fetch the list of the employee who belongs to the same department but earns less than the second highest employee. 

SELECT e1.NAME, e1.DEPARTMENT, e1.SALARY
FROM employee e1
WHERE e1.SALARY < (
    SELECT MAX(e2.SALARY)
    FROM employee e2
    WHERE e2.DEPARTMENT = e1.DEPARTMENT
    AND e2.SALARY < (
        SELECT MAX(e3.SALARY)
        FROM employee e3
        WHERE e3.DEPARTMENT = e1.DEPARTMENT
    )
);


--Display the names of employees who are older than their colleagues in the same department. 
SELECT name
FROM employee e1
WHERE age > (
    SELECT MAX(age)
    FROM employee e2
    WHERE e1.department = e2.department AND e1.name != e2.name
);



SELECT e1.Department, e1.EmpFirstNm, e1.Salary
FROM TBLEmployee e1
WHERE e1.Salary < 
(
    SELECT MAX(e2.SALARY)
    FROM TBLEmployee e2
    WHERE e2.Department = e1.Department
);


USE doselect;
SELECT e1.EmployeeId
FROM Employee e1
JOIN Employee e2
ON e1.ReportsTo = e2.EmployeeId
WHERE e1.BirthDate < e2.BirthDate
ORDER BY e1.EmployeeId;


SELECT 
    (unique) t.technology AS Technology,
    COUNT(t.traineeid) AS TraineeCount,
    AVG(t.cgpa) AS AvgCGPA,
    COUNT(DISTINCT pa.projectid) AS ProjectCount
FROM 
    trainee t
LEFT JOIN 
    projectallocation pa ON t.traineeid = pa.traineeid
LEFT JOIN 
    projectdetails pd ON pa.projectid = pd.projectid
GROUP BY 
    t.technology
ORDER BY 
    TraineeCount DESC, AvgCGPA DESC;
