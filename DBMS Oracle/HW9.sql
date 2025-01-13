-- 1

create table student (roll_no number primary key,student_name varchar2(10) not null,city varchar2(10));
create table program (program_id number primary key,program_name varchar2(10) not null,program_fees number ,check(program_fees >=10000) ,department varchar2(10));
create table register (program_id number references program(program_id),roll_no number references student(roll_no),primary key(program_id,roll_no));

-- Insert sample data into the Student table
INSERT ALL 
INTO Student VALUES (1, 'Sanchit', 'Kotdwar')
INTO Student VALUES (2, 'Pokhriyal', 'Kotdwar')
INTO Student VALUES (3, 'Tomar', 'Dehradun')
INTO Student VALUES (4, 'Harshit', 'Tanakpur')
INTO Student VALUES (5, 'Shukla', 'Kanpur')
INTO Student VALUES (6, 'Rahul', 'Mizoram')
INTO Student VALUES (7, 'Sam', 'Delhi')
SELECT * FROM DUAL;
-- Insert sample data into the Program table
INSERT ALL
INTO Program VALUES (101, 'MCA', 60000, 'CS')
INTO Program VALUES (102, 'BBA', 28000, 'Business')
INTO Program VALUES (103, 'BCA', 50000, 'IT')
INTO Program VALUES (104, 'BTech', 100000, 'Engineer')
INTO Program VALUES (105, 'Math_Hons', 25000, 'Maths')
SELECT * FROM DUAL;
-- Insert sample data into the Register table
INSERT ALL
INTO Register VALUES (104, 1)  
INTO Register VALUES (104, 2)  
INTO Register VALUES (103, 3)  
INTO Register VALUES (101, 4)  
INTO Register VALUES (102, 5)  
SELECT * FROM DUAL;


-- 2 Display the details of students who are registered in the "MCA" program. 
SELECT s.roll_no,s.student_name,s.city FROM student s 
JOIN Register r ON s.roll_no = r.roll_no
JOIN Program p ON r.program_id = p.program_id 
WHERE program_name='MCA'

-- 3 Display the list of all students, who are registered in at least one program. 
SELECT s.student_name FROM student s 
RIGHT JOIN Register r ON s.roll_no = r.roll_no;


-- 4 Display the details of programs that have fees greater than the average fee. 
SELECT * from program WHERE program_fees>(SELECT AVG(program_fees) as av from program);


-- Question 5: 
-- Display the names of students who are registered in a program having fees less than 30000. 
SELECT s.student_name FROM student s WHERE s.roll_no 
IN(SELECT r.roll_no FROM register r WHERE r.program_id 
IN(SELECT program_id FROM program p 
WHERE p.program_fees<30000));



-- Question 6: 
-- Display the details of students who have not registered in any course. 
SELECT s.student_name FROM student s 
LEFT JOIN Register r ON s.roll_no = r.roll_no
WHERE r.program_id is NULL;

-- Question 7: ------------------------------------------------------------------------------
-- Display the names of programs in which a maximum number of students are registered.
SELECT p.program_name FROM Register r 
LEFT JOIN Program p ON r.program_id = p.program_id 
group by program_name having COUNT(*)
IN
    (SELECT MAX(student_count) FROM
        (SELECT COUNT(roll_no) AS student_count
            FROM register
            GROUP BY program_id
        )
    );

-- Question 8: 
-- Display the names of programs in which a minimum number of students are registered.
SELECT p.program_name FROM Register r 
LEFT JOIN Program p ON r.program_id = p.program_id 
group by program_name having COUNT(*)
IN
    ( SELECT MIN(student_count) FROM
        (SELECT COUNT(roll_no) AS student_count
                    FROM register
                    GROUP BY program_id
        )
    );
