/**
 *  SQL Query - 1
 *  -   Problem Statement:
 *      -   List out the unique values for the gender attribute using Group by clause.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output Table Structure:
 *              Gender
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Gender FROM Customer GROUP BY Gender;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement:
 *      -   List the number of customers from each city.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the city name and its corresponding 
 *              number of customers.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT City, COUNT(cust_id) FROM Customer GROUP BY City ORDER BY City;
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      -   List out the total number of orders made to each address.
 *       -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the address and its corresponding sum of 
 *              total orders made to that address.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Address , SUM(TotalOrdersYet) FROM Customer GROUP BY Address;
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:  
 *      -   List out the maximum number of orders made from a particular Pincode.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the pincode and the maximum number of orders 
 *              made from a particular pincode.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Pincode, MAX(TotalOrdersYet) FROM Customer GROUP BY Pincode;
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   List out the minimum number of orders made from a particular Gender.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the Gender and its corresponding 
 *              minimum number of orders.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Gender, MIN(TotalOrdersYet) FROM Customer GROUP BY Gender;
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement:
 *      -   List out the Average number of orders made from each City.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the city name and its corresponding 
 *              average number of orders.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT City, AVG(TotalOrdersYet) FROM Customer GROUP BY City;
 */

/**
 *  SQL Query - 7
 *  -   Problem Statement:
 *      -   List the cities in descending order of the number of customers residing 
 *          in them.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the city name and its corresponding 
 *              number of customers in descending order.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT City , COUNT(cust_id) FROM Customer GROUP BY City 
 *          ORDER BY COUNT(cust_id) DESC;
 */

/**
 *  SQL Query - 8
 *  -   Problem Statement:
 *      -   List down all the duplicate addresses from Jalandhar city with the number of 
 *          times the address appears.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output : The result set should have the address and its corresponding number 
 *              of duplicate addresses present.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Address, COUNT(Address) FROM Customer WHERE City = 'Jalandhar' 
 *          GROUP BY Address;
 */

/**
 *  SQL Query - 9
 *  -   Problem Statement:
 *      -   Fetch the Number of employees for each role/Job.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name and its corresponding 
 *              number of employees.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, COUNT(Job) FROM Employee_data GROUP BY Job;
 */

/**
 *  SQL Query - 10
 *  -   Problem Statement:
 *      -   List out the number of employees for each distinct role corresponding with 
 *          their department code.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name, its department code and 
 *              its corresponding number of employees.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, DeptCode, COUNT(*) FROM Employee_data GROUP BY Job, DeptCode;
 */

/**
 *  SQL Query - 11
 *  -   Problem Statement:
 *      -   List down the maximum salaries for each Job role
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name and its corresponding 
 *              maximum salary.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, MAX(Salary) FROM Employee_data GROUP BY Job;
 */

/**
 *  SQL Query - 12
 *  -   Problem Statement:
 *      -   List down the average salary given out for each department for specific 
 *          job roles.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name, its department code and its 
 *              corresponding average salary.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, DeptCode, AVG(Salary) FROM Employee_data GROUP BY Job, DeptCode;
 */

/**
 *  SQL Query - 13
 *  -   Problem Statement:
 *      -   List down the minimum salaries offered for each job role in each department, 
 *          although list them in descending order based on the max salaries being offered 
 *          for that role.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name, its department code and its 
 *              corresponding minimum salary.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, DeptCode, MIN(Salary) FROM Employee_data GROUP BY Job, DeptCode 
 *          ORDER BY MAX(SALARY) DESC;
 */

/**
 *  SQL Query - 14
 *  -   Problem Statement:
 *      -   List down the addresses with the city and the pincode which appear more than 
 *          twice in the table.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output Table Structure:
 *              Address     |   City    |   Pincode
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Address, City, Pincode FROM Customer GROUP BY Address, City, Pincode 
 *          HAVING COUNT(*) > 2;
 */

/**
 *  SQL Query - 15
 *  -   Problem Statement:
 *      -   List down all the addresses which belong to Guwahati and have made more than 7 
 *          orders in total.
 *      -   Information about the table:
 *              Table Customer:
 *              cust_id, cname, Address, Gender, City, PinCode, TotalOrderYet
 *      -   Output Table Structure:
 *              Address
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Address FROM Customer WHERE City = 'Guwahati' GROUP BY Address 
 *          HAVING SUM(TotalOrdersYet) > 7;
 */

/**
 *  SQL Query - 16
 *  -   Problem Statement:
 *      -   List down the jobs having an average salary more than 3000 USD.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : Job
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job FROM Employee_data GROUP BY Job HAVING AVG(Salary) > 3000;
 */

/**
 *  SQL Query - 17
 *  -   Problem Statement:
 *      -   List down the department's codes that pay their employees (combined) more 
 *          than 5000 USD and list them in ascending order of the minimum salary offered 
 *          by each department.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : DeptCode
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT DeptCode FROM Employee_data GROUP BY DeptCode 
 *          HAVING SUM(Salary) > 5000 ORDER BY MIN(Salary) ASC;
 */

/**
 *  SQL Query - 18
 *  -   Problem Statement:
 *      -   List down the managers handling more than 2 employees, and make sure those 
 *          employees don’t belong to departments 10 and 20.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the manager's name and its corresponding 
 *              number of employees.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Manager, COUNT(Manager) FROM Employee_data 
 *          WHERE DeptCode NOT IN (10, 20) 
 *          GROUP BY Manager HAVING COUNT(Manager) > 2;
 */

/**
 *  SQL Query - 19
 *  -   Problem Statement:
 *      -   For All the Analyst jobs list down the maximum salaries offered to them in 
 *          different departments and under different managers, list all the details in 
 *          ascending order based on the combined salary given out by that department.
 *      -   Information about the table:
 *              Table Employee_data:
 *              EmpCode, EmpFName, EmpLName, Job, Manager, HireDate, Salary, DeptCode
 *      -   Output : The result set should have the job name, its department code, its 
 *              corresponding manager name and its corresponding maximum salary.
 *          Note: Write keywords and aggregate functions in uppercase alphabets.
 *  Ans:    SELECT Job, DeptCode, Manager, MAX(Salary) FROM Employee_data
 *          WHERE Job = 'ANALYST'
 *          GROUP BY Job, DeptCode, Manager 
 *          ORDER BY SUM(Salary) ASC;
 */