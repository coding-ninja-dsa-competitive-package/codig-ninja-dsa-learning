/**
 *  SQL Query - 1
 *  -   Problem Statement:
 *      -   List down the student id along with their complete names.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT stud_id, fname, lname FROM Student;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement:
 *      -   List down the student id along with their names and contact info like email 
 *          and phone number who joined the institute in 2018.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT stud_id, fname, lname, email, ph_no FROM Student WHERE joining_Year = 2018;
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      -   List down all the information about the students who are enrolled in the 
 *          CS400 course.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no   |   joining_Year 
 *          |   course  |   DOB
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT stud_id, fname, lname, email, ph_no, joining_Year, course, DOB 
 *          FROM Student WHERE course = 'CS400';
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   List down all the student's personal details like student id, name and 
 *          contact information like email, phone number who joined the institute after 
 *          2000 and have the surname Daga.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT stud_id, fname, lname, email, ph_no 
 *          FROM Student 
 *          WHERE lname = 'Daga'
 *          AND joining_Year > 2000;
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   List out all the student id’s who have either joined the institute in the 
 *          year 2016 or were enrolled for CS101.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id 
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT stud_id FROM Student
 *          WHERE joining_Year = 2016 
 *          OR course = 'CS101';
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement:
 *      -   Enlist all the students who joined the institute between the year 2009 and 2011.
 *       -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no   |   joining_Year 
 *          |   course  |   DOB
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT stud_id, fname, lname, email, ph_no, joining_Year, course, DOB 
 *          FROM Student WHERE joining_Year BETWEEN 2009 AND 2011;
 */

/**
 *  SQL Query - 7
 *  -   Problem Statement:
 *      -   List out all the students' names (fname and lname) with their joining year 
 *          and phone number who were born on and after 2nd November 1998.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          fname   |   lname   |   joining_Year    |   ph_no
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT fname, lname, joining_Year, ph_no FROM Student
 *          WHERE DOB >= '1998-11-02'
 */

/**
 *  SQL Query - 8
 *  -   Problem Statement:
 *      -   Enlist the email ids of all the interns along with their names.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_name, email
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Emp_name, Email FROM Emp_data WHERE Contract = 'Intern';
 */

/**
 *  SQL Query - 9
 *  -   Problem Statement:
 *      -   Fetch the records of all employees of Department D3 with the FTE offer
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name, dept, contract, email, hometown
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    Select Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *          FROM Emp_data WHERE Dept = 'D3' AND Contract = 'FTE';
 */

/**
 *  SQL Query - 10
 *  -   Problem Statement:
 *      -   Fetch all the records of the employees working for department D1 or D3.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name, dept, contract, email, hometown
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    Select Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *          FROM Emp_data WHERE Dept = 'D3' OR Dept = 'D1';
 */

/**
 *  SQL Query - 11
 *  -   Problem Statement:
 *      -   List out all the students' names (fname and lname) and their course whose ids 
 *          are 423,667,645,321,776.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          fname   |   lname   |   course
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT fname, lname, course FROM Student 
 *          WHERE stud_id IN (423, 667, 645, 321, 776);
 */

/**
 *  SQL Query - 12
 *  -   Problem Statement:
 *      -   List down the complete names of the students from batch 2019 (who joined 
 *          in 2019) and the second letter of their first name is “s”.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          fname   |   lname
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT fname, lname FROM Student 
 *          WHERE joining_Year = 2019 AND fname like '_s%';
 */

/**
 *  SQL Query - 13
 *  -   Problem Statement:
 *      -   List down all the student information who use Yahoo as their emails.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no   |   joining_Year 
 *          |   course  |   DOB
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT stud_id, fname, lname, email, ph_no, joining_Year, course, DOB
 *          FROM Student WHERE email LIKE '%yahoo%';
 */

/**
 *  SQL Query - 14
 *  -   Problem Statement:
 *      -   Fetch all the records of the employees working for department D1 or D3 
 *          using the IN clause.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name, dept, contract, email, hometown
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *          FROM Emp_data WHERE Dept IN ('D1', 'D3');
 */

/**
 *  SQL Query - 15
 *  -   Problem Statement:
 *      -   Fetch all the records of employees that neither work for department D1 nor for D2.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name, dept, contract, email, hometown
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *          FROM Emp_data WHERE Dept NOT IN ('D1', 'D2');
 */

/**
 *  SQL Query - 16
 *  -   Problem Statement:
 *      -   List down the employee name and department that are either from Mumbai or 
 *          Jalandhar and hold an employee Id numbered less than 900.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_name, dept
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Emp_name, Dept FROM Emp_data
 *          WHERE Emp_ID < 900 AND HomeTown IN ('Mumbai', 'Jalandhar');
 */

/**
 *  SQL Query - 17
 *  -   Problem Statement:
 *      -   Fetch all the records with Email ID’s starting from ‘fab’.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name, dept, contract, email, hometown
 *      Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *          FROM Emp_data WHERE Email LIKE 'fab%';
 */

/**
 *  SQL Query - 18
 *  -   Problem Statement:
 *      -   List down all the employee id’s and names whose Email contains ‘bcd’ and 
 *          belongs to department D3 or D4 but aren’t from Himachal, Guwahati.
 *      -   Table Emp_data:
 *              Emp_ID, Emp_name, Dept, Contract, Email, HomeTown
 *  -   Output Table Structure:
 *          emp_id, emp_name
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT Emp_ID, Emp_name FROM Emp_data 
 *          WHERE Email LIKE '%bcd%'
 *          AND Dept IN ('D3', 'D4')
 *          AND HomeTown NOT IN ('Himachal', 'Guwahati');
 */

/**
 *  SQL Query - 19
 *  -   Problem Statement:
 *      -   List down all the details of students sorted in ascending order w.r.t their 
 *          surname.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no   |   joining_Year 
 *          |   course  |   DOB
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT * FROM Student ORDER BY lname ASC;
 */

/**
 *  SQL Query - 20
 *  -   Problem Statement:
 *      -   List out all the details of the students where they are listed in ascending 
 *          order w.r.t the fname and then listed in descending order w.r.t the lname.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          stud_id     |   fname   |   lname   |   email   |   ph_no   |   joining_Year 
 *          |   course  |   DOB
 *      Note: Write keywords of syntax in uppercase alphabets.      
 *  Ans:    SELECT * FROM Student ORDER BY fname ASC , lname DESC;
 */

/**
 *  SQL Query - 21
 *  -   Problem Statement:
 *      -   Fetch out the email ids of all students who joined in 2005 and sort them in 
 *          descending order wrt date of birth of the students.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          email
 *      Note: Write keywords of syntax in uppercase alphabets.      
 *  Ans:    SELECT email FROM Student WHERE joining_Year = 2005 ORDER BY DOB DESC;
 */

/**
 *  SQL Query - 22
 *  -   Problem Statement:
 *      -   List out the complete name of all the students who enrolled in CS206 batch 
 *          2019 and sort them in ascending order according to their date of birth 
 *          and lname.
 *      -   Information about the table:
 *              Table Student:
 *          stud_id, fname, lname, email, ph_no, joining_year, course, DOB
 *  -   Output Table Structure:
 *          fname   |   lname
 *      Note: Write keywords of syntax in uppercase alphabets.     
 *  Ans:    SELECT fname,lname FROM Student WHERE course = 'CS206' 
 *          AND joining_Year = '2019' ORDER BY DOB ASC;
 */

/**
 *  SQL Query - 23
 *  -   Problem Statement:
 *      -   List down the Order ID’s and their respective Ordering time, arranged in 
 *          Ascending order by ordering time.
 *      -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   ordered_time
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT order_id, ordered_time FROM e_transactions ORDER BY ordered_time ASC;
 */

/**
 *  SQL Query - 24
 *  -   Problem Statement:          
 *      -   Arrange the above-given data in descending order by Shipping time.
 *      -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   ordered_time |   shipping_time   |   cost    |   cust_id
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT * FROM e_transactions ORDER BY shipping_time DESC;
 */

/**
 *  SQL Query - 25
 *  -   Problem Statement:
 *      -   Fetch out all the records but in descending order by ordering time and in 
 *          case of similar order times sort in ascending order w.r.t. shipping time.
 *      -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   ordered_time |   shipping_time   |   cost    |   cust_id
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT * FROM e_transactions ORDER BY ordered_time DESC, shipping_time ASC;
 */

/**
 *  SQL Query - 26
 *  -   Problem Statement:
 *      -   List down all the order details in ascending order by cost and whose cost 
 *          is less than 5000.
 *      -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   ordered_time |   shipping_time   |   cost    |   cust_id
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT * FROM e_transactions WHERE cost < 5000 ORDER BY cost ASC;
 */

/**
 *  SQL Query - 27
 *  -   Problem Statement:      
 *      -   List down the orders ids with their shipping time which were ordered before 
 *          30th June 2021 sort them in ascending order w.r.t. cost and in descending 
 *          order w.r.t. time the purchase was made.
 *      -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   shipping_time
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT order_id, shipping_time FROM e_transactions 
 *          WHERE ordered_time < '2021-06-30' ORDER BY cost ASC, ordered_time DESC;
 */

/**
 *  SQL Query - 28
 *  -   Problem Statement:
 *      -   List down all the details of the orders made in February 2021 or July 2021, 
 *          also sort them in ascending order by their price.
 *       -   Information about the table:
 *              Table e_transactions:
 *          order_id, ordered_time, shipping_time, cost, cust_id
 *  -   Output Table Structure:
 *          order_id   |   ordered_time |   shipping_time   |   cost    |   cust_id
 *      Note: Write keywords of syntax in uppercase alphabets.  
 *  Ans:    SELECT * FROM e_transactions WHERE ordered_time LIKE '2021-02-%' OR 
 *          ordered_time LIKE '2021-07-%' ORDER BY cost ASC;
 */