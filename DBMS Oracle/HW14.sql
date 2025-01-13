CREATE TABLE Trainees (
    Trainee_ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Program_ID INT
);

CREATE TABLE Programs (
    Program_ID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE Instructors (
    Instructor_ID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE Courses (
    Course_Code INT PRIMARY KEY,
    Title VARCHAR(50),
    Instructor_ID INT,
    FOREIGN KEY (Instructor_ID) REFERENCES Instructors(Instructor_ID)
);

CREATE TABLE TeachingAssistants (
    TA_ID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE EnrolledIn (
    Trainee_ID INT,
    Course_Code INT,
    Time_Spent INT,
    PRIMARY KEY (Trainee_ID, Course_Code),
    FOREIGN KEY (Trainee_ID) REFERENCES Trainees(Trainee_ID),
    FOREIGN KEY (Course_Code) REFERENCES Courses(Course_Code)
);

CREATE TABLE EnrolledIn (
    Trainee_ID INT,
    Course_Code INT,
    PRIMARY KEY (Trainee_ID, Course_Code),
    FOREIGN KEY (Trainee_ID) REFERENCES Trainees(Trainee_ID),
    FOREIGN KEY (Course_Code) REFERENCES Courses(Course_Code)
);

CREATE TABLE ProgramCourses (
    Program_ID INT,
    Course_Code INT,
    PRIMARY KEY (Program_ID, Course_Code),
    FOREIGN KEY (Program_ID) REFERENCES Programs(Program_ID),
    FOREIGN KEY (Course_Code) REFERENCES Courses(Course_Code)
);

CREATE TABLE AssistedBy (
    Course_Code INT,
    TA_ID INT,
    PRIMARY KEY (Course_Code, TA_ID),
    FOREIGN KEY (Course_Code) REFERENCES Courses(Course_Code),
    FOREIGN KEY (TA_ID) REFERENCES TeachingAssistants(TA_ID)
);

CREATE TABLE CoursePrerequisites (
    Course_Code INT,
    Prerequisite_Code INT,
    PRIMARY KEY (Course_Code, Prerequisite_Code),
    FOREIGN KEY (Course_Code) REFERENCES Courses(Course_Code),
    FOREIGN KEY (Prerequisite_Code) REFERENCES Courses(Course_Code)
);



INSERT ALL
    INTO Programs (Program_ID, Name) VALUES (1, 'Java Developer')
    INTO Programs (Program_ID, Name) VALUES (2, 'Full Stack Developer')
    INTO Programs (Program_ID, Name) VALUES (3, 'Data Scientist')
SELECT * FROM DUAL;


INSERT ALL
    INTO Trainees (Trainee_ID, Name, Program_ID) VALUES (101, 'Alice', 1)
    INTO Trainees (Trainee_ID, Name, Program_ID) VALUES (102, 'Bob', 2)
    INTO Trainees (Trainee_ID, Name, Program_ID) VALUES (103, 'Charlie', 3)
SELECT * FROM DUAL;

INSERT ALL
    INTO Instructors (Instructor_ID, Name) VALUES (1, 'Dr. Smith')
    INTO Instructors (Instructor_ID, Name) VALUES (2, 'Dr. Jones')
    INTO Instructors (Instructor_ID, Name) VALUES (3, 'Dr. Taylor')
SELECT * FROM DUAL;

INSERT ALL
    INTO Courses (Course_Code, Title, Instructor_ID) VALUES (201, 'Java Basics', 1)
    INTO Courses (Course_Code, Title, Instructor_ID) VALUES (202, 'Frontend Development', 2)
    INTO Courses (Course_Code, Title, Instructor_ID) VALUES (203, 'Machine Learning', 3)
SELECT * FROM DUAL;

INSERT ALL
    INTO TeachingAssistants (TA_ID, Name) VALUES (301, 'John')
    INTO TeachingAssistants (TA_ID, Name) VALUES (302, 'Emma')
    INTO TeachingAssistants (TA_ID, Name) VALUES (303, 'Sophia')
SELECT * FROM DUAL;

INSERT ALL
    INTO ProgramCourses (Program_ID, Course_Code) VALUES (1, 201)
    INTO ProgramCourses (Program_ID, Course_Code) VALUES (2, 202)
    INTO ProgramCourses (Program_ID, Course_Code) VALUES (3, 203)
SELECT * FROM DUAL;
-- ALSO ADD TIME SPENT
INSERT ALL
    INTO EnrolledIn (Trainee_ID, Course_Code,Time_Spent) VALUES (101, 201, 3)
    INTO EnrolledIn (Trainee_ID, Course_Code,Time_Spent) VALUES (102, 202, 10)
    INTO EnrolledIn (Trainee_ID, Course_Code,Time_Spent) VALUES (103, 203, 5)
SELECT * FROM DUAL;

INSERT ALL
    INTO AssistedBy (Course_Code, TA_ID) VALUES (201, 301)
    INTO AssistedBy (Course_Code, TA_ID) VALUES (202, 302)
    INTO AssistedBy (Course_Code, TA_ID) VALUES (203, 303)
SELECT * FROM DUAL;

INSERT INTO CoursePrerequisites (Course_Code, Prerequisite_Code)
VALUES 
(203, 201);


-- Q1 Write an SQL query to show the names and IDs of trainees who have completed all the required courses for their program.
SELECT T.Trainee_ID, T.Name
FROM Trainees T
WHERE NOT EXISTS (
    SELECT PC.Course_Code
    FROM ProgramCourses PC
    WHERE PC.Program_ID = T.Program_ID
    AND NOT EXISTS (
        SELECT E.Course_Code
        FROM EnrolledIn E
        WHERE E.Trainee_ID = T.Trainee_ID
        AND E.Course_Code = PC.Course_Code
    )
);

-- Q2 Write an SQL query to get the names of instructors and the courses they teach, including any courses that have prerequisites.
SELECT I.Name AS Instructor_Name, C.Title AS Course_Title, CP.Prerequisite_Code
FROM Instructors I
JOIN Courses C ON I.Instructor_ID = C.Instructor_ID
LEFT JOIN CoursePrerequisites CP ON C.Course_Code = CP.Course_Code;


-- Q3 Write an SQL query to find the average grade for each course and list the courses where the average grade is below than 70%.
SELECT C.Title AS Course_Title, AVG(E.Grade) AS Average_Grade
FROM Courses C
JOIN EnrolledIn E ON C.Course_Code = E.Course_Code
GROUP BY C.Course_Code, C.Title
HAVING AVG(E.Grade) < 70;

-- Q4 Write an SQL query to find the trainees who have signed up for the most courses, no matter which program they are in.
SELECT T.Trainee_ID, T.Name, COUNT(E.Course_Code) AS Total_Courses
FROM Trainees T
JOIN EnrolledIn E ON T.Trainee_ID = E.Trainee_ID
GROUP BY T.Trainee_ID, T.Name
HAVING COUNT(E.Course_Code) = (
    SELECT MAX(Total_Courses)
    FROM (
        SELECT COUNT(E.Course_Code) AS Total_Courses
        FROM EnrolledIn E
        GROUP BY E.Trainee_ID
    ) Subquery
);


-- Q5 Write an SQL query to list all courses and the total hours all trainees have spent on each course.
