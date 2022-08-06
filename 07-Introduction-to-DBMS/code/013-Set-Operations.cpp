/**
 *  SQL Query - 1
 *  -   Problem Statement:
 *      -   Using the tables given below, list out all the employees of the company.
 *      -   Information about the table:
 *              Table Empdept1: :
 *                  EmpCode, EmpFName, EmpLName, Job        
 *              Table Empdept2:
 *                  EmpCode, EmpFName, EmpLName, Job 
 *      -   Output Table Structure:
 *                  EmpCode | EmpFName  | EmpLName  | Job 
 *  Note-1: The data should not contain duplicate rows of employees.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT * FROM Empdept1 UNION SELECT * FROM Empdept2;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement:
 *      -   List down employees (all the details) from both the departments who work as Salesman.
 *      -   Information about the table:
 *              Table Empdept1: :
 *                  EmpCode, EmpFName, EmpLName, Job        
 *              Table Empdept2:
 *                  EmpCode, EmpFName, EmpLName, Job 
 *      -   Output Table Structure:
 *                  EmpCode | EmpFName  | EmpLName  | Job 
 *  Note-1: The data should not contain duplicate rows of employees.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT * FROM Empdept1 WHERE Job = 'SALESMAN' 
 *          UNION SELECT * FROM Empdept2 WHERE Job = 'SALESMAN';
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      -   List out each employee name and employee code from both the departments 
 *          and order them in ascending order by their code.
 *      -   Information about the table:
 *              Table Empdept1: :
 *                  EmpCode, EmpFName, EmpLName, Job        
 *              Table Empdept2:
 *                  EmpCode, EmpFName, EmpLName, Job 
 *      -   Output Table Structure:
 *                  EmpCode | EmpFName  | EmpLName  | Job 
 *  Note-1: Duplicates are allowed.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT * FROM (SELECT EmpFName, EmpLName, EmpCode FROM EmpDept1
 *          UNION ALL SELECT EmpFName, EmpLName, EmpCode FROM EmpDept2) AS emp 
 *          ORDER BY emp.EmpCode ASC
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   Find out all the details of employees that work for both the departments.
 *      -   Information about the table:
 *              Table Empdept1: :
 *                  EmpCode, EmpFName, EmpLName, Job        
 *              Table Empdept2:
 *                  EmpCode, EmpFName, EmpLName, Job 
 *      -   Output Table Structure:
 *                  EmpCode | EmpFName  | EmpLName  | Job 
 *  Note-1: The data should not contain duplicate rows of employees.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT DISTINCT * FROM Empdept1
 *          INNER JOIN Empdept2 USING(EmpCode, EmpFName, EmpLName, Job);
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   List down all the details of employees working in dept1 but not in Dept2.
 *      -   Information about the table:
 *              Table Empdept1: :
 *                  EmpCode, EmpFName, EmpLName, Job        
 *              Table Empdept2:
 *                  EmpCode, EmpFName, EmpLName, Job 
 *      -   Output Table Structure:
 *                  EmpCode | EmpFName  | EmpLName  | Job 
 *  Note-1: The data should not contain duplicate rows of employees.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT * FROM Empdept1 
 *          LEFT JOIN Empdept2 USING (EmpCode, EmpFName, EmpLName, Job)
 *          WHERE Empdept2.EmpCode IS NULL;
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement:
 *      -   Formulate a MySQL query to list out all the projects(id, name) and employee's 
 *          names (first, last) along with their respective Email id’s irrespective of the 
 *          fact if that project is assigned or not and whether an employee is assigned 
 *          any project or none.
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpID, EmpFname, EmpLname, Age, EmailID, PhoneNo, City
 *              Table Project:
 *                  ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Output Table Structure:
 *                  ProjectID   |   ProjectName   | EmpFname  | EmpLname  | EmailID
 *  Hint: Use Full Join, but MySql doesn’t support the “Full Join” clause.
 *  Note-1: Use employee ID to link the two tables.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT p1.ProjectID, p1.ProjectName, e1.EmpFname, e1.EmpLname, e1.EmailID 
 *          FROM Project p1
 *          LEFT JOIN Employee e1 ON e1.EmpID = p1.EmpID 
 *          UNION
 *          SELECT p2.ProjectID, p2.ProjectName, e2.EmpFname, e2.EmpLname, e2.EmailID  
 *          FROM Project p2
 *          RIGHT JOIN Employee e2 ON e2.EmpID = p2.EmpID 
 */