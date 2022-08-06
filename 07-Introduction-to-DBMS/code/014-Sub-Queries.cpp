/**
 *  MCQ - 1
 *  -   Suppose a user has 3 queries Q1, Q2 and Q3. These queries are written in a way 
 *      i.e. Q1(Q2(Q3)). Which query will be executed first?
 *  Options
 *      a.  Q1
 *      b.  Q2
 *      c.  Q3
 *      d.  All are updated at the same time
 *  Ans:    c
 *  -   Subqueries is a way of using queries within a particular query. It is accomplished 
 *      using the parenthesis. The inner query is always executed first, followed by the 
 *      execution of the outer query. Inner query results in a single value or set of 
 *      values as an output. In the above example, Q3 is the innermost query, so it should 
 *      be executed first.
 */

/**
 *  MCQ - 2
 *  -   Which of the following are the clauses in which subqueries exist?
 *  Options
 *      a.  INSERT clause
 *      b.  FROM clause
 *      c.  WHERE clause
 *  Ans:    b, c
 *  -   Subqueries exist mainly in 3 clauses
 *          1. Inside a WHERE clause
 *          2. Inside a FROM clause 
 *          3. Inside a SELECT clause
 */

/**
 *  SQL Query - 1
 *  -   Problem Statement:
 *      -   Write a SQL query to find out the quantity supplied by anjali and rachit.
 *      -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Qty
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Qty FROM SP WHERE Sno IN (SELECT Sno FROM Supplier 
 *          WHERE Sname IN ('anjali', 'rachit'));
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement:
 *      -   Write a SQL query to display the supplier name and city of the supplier who 
 *          supplies parts with Pno 1 and 5.
 *      -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Sname, City
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Sname, City FROM Supplier WHERE Sno IN (SELECT Sno FROM SP 
 *          WHERE Pno IN (1, 5));
 */

/**
 *  SQL Query - 1
 *  -   
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      -   Write a SQL Query to get the colour of parts supplied by Supplier with Sno 1,3,6
 *      -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Colour
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Colour FROM Product WHERE Pno IN (SELECT Pno FROM SP 
 *          WHERE Sno IN (1,3,6));
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   Write a SQL query to get the colour of parts supplied by all the employees 
 *          except rachit and kashish.
 *      -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Colour
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT Colour FROM Product WHERE Pno IN (SELECT Pno FROM SP 
 *          WHERE Sno NOT IN (1,6));
 */

/**
 *  MCQ - 3
 *  -   The given below relation schema is used to store information about the employees 
 *      of a company, where empId is the primary key and depttid indicates the department 
 *      of the employee.
 *  -   Emp(empId, name, gender, salary, depttid)
 *  -   Guess the output of the following Query:
 *          SELECT name, MIN(salary) FROM Emp GROUP BY depttid HAVING MIN(salary) > 
 *          (SELECT min(salary) FROM employees WHERE depttid = 20);
 *  Options
 *      a.  It gives the names and minimum salary greater than department 20 of 
 *          all employees.
 *      b.  It gives the name and salaries of the employees in department 20
 *      c.  It gives the names and minimum salaries of all the employees.
 *      d.  It throws an error.
 *  Ans:    a
 *  -   It will execute successfully. After the SELECT clause, we have written name, 
 *      min(salary) the output table will have two columns of names and the minimum 
 *      salary of every department. The table will contain the name and minimum salary 
 *      of the departments which have a minimum salary greater than the minimum salary 
 *      of department 20.
 */

/**
 *  MCQ - 4
 *  -   The given below relation schema is used to store information about the employees 
 *      of a company, where empId is the primary key and deptt_id indicates the department 
 *      of the employee.
 *  -   Emp(empId, name, gender, salary, deptt_id);
 *  -   The following query was written to get the name of Employees whose salary is 
 *      greater than the average salary but throw an error. Choose the correct reason 
 *      for the error.
 *  -   Query: SELECT name FROM Emp WHERE salary = (SELECT deptt_id, AVG(salary) FROM 
 *      employees GROUP BY deptt_id);
 *  Options
 *      a.  In the above sub-query, the GROUP BY clause is not required.    
 *      b.  In a subquery SELECT statement, we cannot use a function.
 *      c.  The single row sub-query gives multiple records
 *      d.  We should have used IN operator instead of the “=” operator as the “=” operator 
 *          is invalid here
 *  Ans:    c, d
 *  -   The GROUP BY clause gives the average salary for each department. This will result 
 *      in multiple results to the main query giving an error.
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   Write a SQL Query to get the supplier name who supply pencils with quantity 
 *          greater than 10.
 *      -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Sname
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Remember that the column values are case-sensitive.
 *  Ans:    SELECT Sname FROM Supplier WHERE Sno IN (SELECT Sno FROM SP 
 *          WHERE Pno = 2 AND Qty > 10);
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement:
 *      -   List down all the Employees whose salary is greater than that of Monica Geller.
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpCode, EmpName, Job, Manager, HireDate, Salary , DeptCode
 *      -   Output Table Structure:
 *              EmpName
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2 : You are not authorized to view the salaries of the employees.
 *  Ans:    SELECT EmpName FROM Employee 
 *          WHERE Salary > (SELECT Salary FROM Employee WHERE EmpName = 'Monica Geller');
 */

/**
 *  SQL Query - 7
 *  -   Problem Statement:
 *      -   List down all the employees whose job is the same as Phoebe Buffay.
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpCode, EmpName, Job, Manager, HireDate, Salary , DeptCode
 *      -   Output Table Structure:
 *              EmpName, Salary , DeptCode, Job
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT EmpName, Salary, DeptCOde, Job FROM Employee 
 *          WHERE Job = (SELECT Job FROM Employee WHERE EmpName = 'Phoebe Buffay');
 */

/**
 *  SQL Query - 8
 *  -   Problem Statement:
 *      -   Print out all the employees with their respective Departments even if any 
 *          employee’s salary is more than 4000.
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpCode, EmpName, Job, Manager, HireDate, Salary , DeptCode
 *      -   Output Table Structure:
 *              EmpName , DeptCode
 *  Hint: use EXISTS operator.
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT EmpName, DeptCode FROM Employee 
 *          WHERE EXISTS (SELECT EmpName, DeptCode FROM Employee WHERE Salary > 4000);
 */

/**
 *  SQL Query - 9
 *  -   Problem Statement:
 *      -   Print the name and age of all oldest sailors.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              sname, age
 *  Note-1: There can be multiple sailors of the same age. All the sailors who are the 
 *          oldest should be listed in the output.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT sname, age FROM sailors WHERE age = (SELECT MAX(age) FROM sailors);
 */

/**
 *  SQL Query - 10
 *  -   Problem Statement:
 *      -   Find the name of boats and their respective colors of the sailors with minimum 
 *          age.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              bname, color
 *  Note-1: All the sailors who are youngest should be listed in the output.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT bname, color FROM boats WHERE bid IN 
 *          (SELECT bid FROM reserves WHERE sid IN 
 *          (SELECT sid FROM sailors WHERE age = (SELECT MIN(age) FROM sailors)));
 */

/**
 *  SQL Query - 11
 *  -   Problem Statement:
 *      -   Find the IDs of sailors and their daytook for sailors with highest rating.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              sid, daytook
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT sid, daytook FROM reserves WHERE sid IN(
 *          SELECT sid FROM sailors WHERE rating = (SELECT MAX(rating) FROM sailors));
 */

/**
 *  MCQ - 5
 *  -   Consider a table bank_records given below:
 *          Customer, Bank Manager, Amount
 *              Ram, Anchit, 100000
 *              Shyam, Gopal, 50000
 *              Makhan, Anchit, 70000
 *  -   What will be the output of the following query?
 *          SELECT * FROM ( ( SELECT b.Customer, b.Bank_Manager FROM bank_records b) 
 *          JOIN ( SELECT r.Amount FROM bank_records r) ) as br;
 *  Options
 *      a.  5   
 *      b.  9
 *      c.  6
 *      d.  3
 *  Ans:    b
 *  -   default : cross join
 */

/**
 *  MCQ - 6 
 *  -   The given below relation schema is used to store information about the employees 
 *      of a company, where emp_Id is the primary key and dept_Id indicates the department 
 *      of the employee.
 *  -   Employee(emp_Id, name, gender, salary, dept_Id)
 *  -   Consider the following SQL query:
 *          SELECT emp_Id, name from (select * from Employee WHERE salary>avg(salary)) as e;
 *      What will be the output of the query:
 *  Options
 *      a.  It will provide the employee id and name of the employee whose salary is 
 *          greater than the average salary of all the employees.
 *      b.  It will provide the employee id and name of the employee whose salary is 
 *          less than the average salary of all the employees.  
 *      c.  It will provide the name of the employee whose salary is greater than the 
 *          average salary of all the employees.
 *      d.  It will provide the employee id of the employee whose salary is less than 
 *          the average salary of all the employees.
 *  Ans:    a
 *  -   After the SELECT clause, we have written emp_id and name. So, the output consists 
 *      of 2 columns emp_id and name. The table will be derived from the subquery using 
 *      FROM clause. In the subquery, we are selecting all the values from employees whose 
 *      salary is greater than the average salary of all the employees.
 */

/**
 *  MCQ - 7
 *  -   The given below relation schema is used to store information about the employees 
 *      of a company, where emp_Id is the primary key and dept_Id indicates the department 
 *      of the employee.
 *  -   Employee(emp_Id, name, gender, salary, dept_Id)
 *  -   Consider the following Query:
 *          SELECT emp_id FROM ( SELECT Employee.emp_id FROM Employee ORDER BY 
 *          Employee.dept_id DESC) as e;
 *  -   What will be the output of the Following query
 *  Options
 *      a.  It will provide the employee id of all the employees in ascending order of 
 *          department id.
 *      b.  It will provide the department id of all employees in ascending order of 
 *          employee id.
 *      c.  It will provide the employee id of all the employees in descending order of 
 *          department id.
 *      d.  It will provide the department id of all employees in descending order of 
 *          employee id.
 *  Ans:    c   
 *  -   After the SELECT clause, we have written emp_id. So, output consist of one column 
 *      i.e. emp_id.  The table will be derived from the subquery using FROM clause. In 
 *      the subquery, we are we are sorting the table in the descending order of department 
 *      id.
 */

/**
 *  SQL Query - 12
 *  -   Problem Statement:      
 *      -   Write a SQL query to display the name, 20 times the weight as w and colour of 
 *          red coloured products whose original weight is less than 10.
 *       -   Information about the table:
 *              Table Product:
 *                  Pno, Pname, Colour, Weight
 *              Table Supplier:
 *                  Sno, Sname, City, Status
 *              Table SP:
 *                  Sno, Pno, Qty
 *      -   Output Table Structure:
 *              Pname, Colour, w
 *  Ans:    SELECT Pname, Colour, 20*Weight as w FROM Product 
 *          WHERE Colour = 'red' AND Weight < 10;
 */

/**
 *  SQL Query - 13
 *  -   Problem Statement:
 *      -   List down the employee details with their annual salary, given that the 
 *          annual salary of the employees being listed should be greater than 30000
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpCode, EmpName, Job, Manager, HireDate, Salary , DeptCode
 *      -   Output Table Structure:
 *              EmpCode, EmpName, Salary , A_Sal
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT * FROM (SELECT EmpCode, EmpName, Salary, 12*Salary AS A_Sal FROM Employee) AS emp 
 *          WHERE emp.A_Sal > 30000;
 */

/**
 *  MCQ - 8 
 *  -   What is true about correlated subqueries?
 *  Options
 *      a.  The tables used in the main query are also used in a correlated subquery
 *      b.  Subqueries that necessarily use tables other than those used in the main query  
 *          are called correlated subqueries.
 *      c.  The subquery that references a column used in the main query is called a 
 *          correlated subquery
 *      d.  A subquery written without parentheses is called a correlated subquery  
 *  Ans:    c
 *  -   The correlated subquery references a column in the outer query and runs the 
 *      subquery once for each row of the outer query, while the uncorrelated subquery 
 *      runs the subquery first and passes the price value for the outer query.
 */

/**
 *  SQL Query - 14
 *  -   Problem Statement:
 *      -   Print the employee details for all employees who earn more than the average 
 *          salary and having an “e” in their name.
 *      -   Information about the table:
 *              Table Employee:
 *                  EmpCode, EmpName, Job, Manager, HireDate, Salary , DeptCode
 *      -   Output Table Structure:
 *              EmpCode, EmpName, Salary
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT EmpCode, EmpName, Salary FROM Employee
 *          WHERE EmpName LIKE '%e%'
 *          AND Salary > (SELECT AVG(Salary) FROM Employee);
 */

/**
 *  SQL Query - 15
 *  -   Problem Statement:
 *      -   Find the ids and names of sailors who have reserved at least two different boats.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              sid, sname
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT sid, sname FROM sailors 
 *          WHERE sid IN (SELECT sid FROM reserves GROUP BY sid HAVING COUNT(sid) > 1);
 */

/**
 *  SQL Query - 16
 *  -   Problem Statement:
 *      -   Fetch out the color, sailor id and boat id of the boats reserved by the Sailor 
 *          having 2nd highest rating.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              color, sid, bid
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT b.color, j.sid, j.bid FROM 
 *              (SELECT sid, bid FROM reserves WHERE sid IN (
 *                  SELECT sid FROM sailors WHERE rating = 
 *                      (SELECT MAX(rating) FROM sailors WHERE rating != 
 *                          (SELECT MAX(rating) FROM sailors)))) AS j
 *          INNER JOIN boats b ON b.bid = j.bid 
 *          ORDER BY bid DESC;
 */

/**
 *  SQL Query - 17
 *  -   Problem Statement:
 *      -   Display all the sailor id, boat id and sailor name which are reserved by 
 *          Sailors who have ratings more than the average rating in the reserves table.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              sid, bid, sname
 *  Note-1: The order of display should be same as mentioned in the question.
 *  Note-2: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT a.sid , r.bid, a.sname FROM  
 *          (SELECT sid, sname FROM sailors WHERE rating > (SELECT AVG(rating) FROM sailors)) a
 *          INNER JOIN reserves r ON r.sid = a.sid;
 */

/**
 *  SQL Query - 18
 *  -   Problem Statement:
 *      -   Display all the sailor id, boat id, sailor name and boat color which are 
 *          reserved by Sailors who have ratings less than the average rating in the 
 *          reserves table.
 *      -   Information about the table:
 *              Table sailors: :
 *                  sid, sname, rating, age
 *              Table boats:
 *                  bid, bname, color
 *              Table reserves:
 *                  sid, bid, daytook
 *      -   Output Table Structure:
 *              sid, bid, sname, color
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    SELECT r.sid , r.bid, s.sname, b.color FROM reserves AS r, boats AS b, sailors AS s
 *          WHERE s.sid = r.sid 
 *          AND r.bid = b.bid 
 *          AND s.rating < (SELECT AVG(rating) FROM reserves INNER JOIN sailors WHERE s.sid = r.sid)
 */

/**
 *  MCQ - 9
 *  -   Which of the following is the advantage of Join over Subqueries?
 *  Options
 *      a.  Joins are easier to understand than Subqueries.
 *      b.  With the help of joins, you can use the results of other queries.
 *      c.  Joins are faster in execution than Subqueries. 
 *      d.  Both A and B
 *  Ans:    c
 *  -   1. The complexity of writing a subquery is much less than writing a query for joins.
 *      2. Subqueries uses the results of another query in the outer query.
 *      3. The retrieval time of Joins is much faster th
 */