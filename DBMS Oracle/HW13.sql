CREATE TABLE Department (
    Department_ID NUMBER PRIMARY KEY,
    Department_Name VARCHAR2(15) NOT NULL,
    Manager_ID NUMBER,
    Location VARCHAR2(15)
    );


CREATE TABLE Employee (
    Employee_ID NUMBER PRIMARY KEY,
    Name VARCHAR2(10) NOT NULL,
    Birth_Date DATE,
    Address VARCHAR2(15),
    Gender VARCHAR2(6),
    Salary NUMBER(10, 2),
    Department_ID NUMBER,
    Supervisor_ID NUMBER,
    FOREIGN KEY (Department_ID) REFERENCES Department(Department_ID) on delete cascade,
    FOREIGN KEY (Supervisor_ID) REFERENCES Employee(Employee_ID)on delete cascade
);

CREATE TABLE Project (
    Project_ID NUMBER PRIMARY KEY,
    Project_Name VARCHAR2(15) NOT NULL,
    Location VARCHAR2(15),
    Department_ID NUMBER,
    FOREIGN KEY (Department_ID) REFERENCES Department(Department_ID) on delete cascade
);


CREATE TABLE Works_On (
    Employee_ID NUMBER,
    Project_ID NUMBER,
    Hours_Spent NUMBER(10, 2),
    PRIMARY KEY (Employee_ID, Project_ID),
    FOREIGN KEY (Employee_ID) REFERENCES Employee(Employee_ID),
    FOREIGN KEY (Project_ID) REFERENCES Project(Project_ID)
);



INSERT INTO Department (Department_ID, Department_Name, Manager_ID, Location) VALUES (1, 'IT', 101, 'New York');
INSERT INTO Department (Department_ID, Department_Name, Manager_ID, Location) VALUES (2, 'HR', 102, 'Chicago');
INSERT INTO Department (Department_ID, Department_Name, Manager_ID, Location) VALUES (3, 'Finance', 103, 'San Francisco');
INSERT INTO Department (Department_ID, Department_Name, Manager_ID, Location) VALUES (4, 'Marketing', 104, 'Los Angeles');

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (101, 'Alice', TO_DATE('1985-05-20', 'YYYY-MM-DD'), 'New York', 'Female', 75000, 1, NULL);

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (102, 'Bob', TO_DATE('1990-03-15', 'YYYY-MM-DD'), 'Chicago', 'Male', 65000, 2, 101);

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (103, 'Charlie', TO_DATE('1980-07-10', 'YYYY-MM-DD'), 'San Francisco', 'Male', 80000, 3, NULL);

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (104, 'Diana', TO_DATE('1992-01-25', 'YYYY-MM-DD'), 'Los Angeles', 'Female', 55000, 4, 101);

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (105, 'Eve', TO_DATE('1988-09-15', 'YYYY-MM-DD'), 'Chicago', 'Female', 60000, 2, 102);

INSERT INTO Employee (Employee_ID, Name, Birth_Date, Address, Gender, Salary, Department_ID, Supervisor_ID) 
VALUES (106, 'Frank', TO_DATE('1985-12-10', 'YYYY-MM-DD'), 'San Francisco', 'Male', 70000, 3, 103);

INSERT INTO Project (Project_ID, Project_Name, Location, Department_ID) VALUES (201, 'AI Development', 'New York', 1);
INSERT INTO Project (Project_ID, Project_Name, Location, Department_ID) VALUES (202, 'Portal', 'Chicago', 2);
INSERT INTO Project (Project_ID, Project_Name, Location, Department_ID) VALUES (203, 'Budget Analysis', 'San Francisco', 3);
INSERT INTO Project (Project_ID, Project_Name, Location, Department_ID) VALUES (204, 'Ad Campaign', 'Los Angeles', 4);


INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (101, 201, 50);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (102, 202, 40);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (103, 203, 60);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (104, 204, 45);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (105, 202, 20);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (106, 203, 30);
INSERT INTO Works_On (Employee_ID, Project_ID, Hours_Spent) VALUES (106, 201, 35);



-- a. Identify the department(s) with the highest average salary among its employees.

SELECT Department_ID, AVG(Salary) AS Avg_Salary
FROM Employee
GROUP BY Department_ID
HAVING AVG(Salary) = (
    SELECT MAX(AVG_Salary)
    FROM (
        SELECT Department_ID, AVG(Salary) AS AVG_Salary
        FROM Employee
        GROUP BY Department_ID
    )
);

-- b. List all employees who are directly supervised by more than one manager.

SELECT E.Employee_ID, E.Name, COUNT(DISTINCT S.Supervisor_ID) AS Num_Supervisors
FROM Employee E
JOIN Employee S ON E.Employee_ID = S.Supervisor_ID
GROUP BY E.Employee_ID, E.Name
HAVING COUNT(DISTINCT S.Supervisor_ID) > 1;

-- c. Find the project(s) with the highest total hours spent by employees.

SELECT Project_ID, SUM(Hours_Spent) AS Total_Hours
FROM Works_On
GROUP BY Project_ID
HAVING SUM(Hours_Spent) = (
    SELECT MAX(Total_Hours)
    FROM (
        SELECT SUM(Hours_Spent) AS Total_Hours
        FROM Works_On
        GROUP BY Project_ID
    )
);

-- d. Find all employees who have never been assigned to any project.

SELECT E.Employee_ID, E.Name
FROM Employee E
WHERE NOT EXISTS (
    SELECT 1
    FROM Works_On W
    WHERE E.Employee_ID = W.Employee_ID
);

-- e. List each department along with the total number of projects managed by the department and the total number of employees assigned to it.

SELECT D.Department_ID, 
       D.Department_Name, 
       COUNT(DISTINCT P.Project_ID) AS Total_Projects, 
       COUNT(DISTINCT E.Employee_ID) AS Total_Employees
FROM Department D
LEFT JOIN Project P ON D.Department_ID = P.Department_ID
LEFT JOIN Employee E ON D.Department_ID = E.Department_ID
GROUP BY D.Department_ID, D.Department_Name;
