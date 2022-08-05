/**
 *  SQL Query - 1
 *  -   Problem Statement:
 *      -   Enlist all the employees ID's, names along with the Project allocated to them.
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  EmpID, EmpFName, EmpLName, ProjectID, ProjectName
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT e.EmpID, e.EmpFName, e.EmpLName, p.ProjectID, p.ProjectName 
 *          FROM Employee e
 *          INNER JOIN Project p ON p.EmpID = e.EmpID;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement:
 *      -   Fetch out all the employee ID’s and their contact detail who have been working 
 *          from Delhi with the clients name working in Kolkata.
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  EmpID, EmailID, PhoneNo, ClientFName, ClientLName
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT e.EmpID, e.EmailID, e.PhoneNo, c.ClientFName, c.ClientLName 
 *          FROM Employee e
 *          INNER JOIN Client_d c ON c.EmpID = e.EmpID
 *          WHERE e.City = 'Delhi' OR c.City = 'Kolkata'
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      -   List out all the project names with corresponding client’s email id, for all 
 *          the projects that were allocated after April 2021 and order them in descending 
 *          order of the age of clients.
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  ProjectName, ClientEmailID
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT p.ProjectName, c.ClientEmailID FROM Project p
 *          INNER JOIN Client_d c ON p.ClientID = c.ClientID
 *          WHERE p.ProjectStartDate >= '2021-05-01'
 *          ORDER BY c.Age DESC;
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   Fetch out each project allocated to which employee.
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  EmpFName, EmpLName, ProjectID, ProjectName
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT e.EmpFname, e.EmpLname, p.ProjectID, p.ProjectName 
 *          FROM Employee e
 *          LEFT JOIN Project p ON e.EmpID = p.EmpID;
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   List out all the projects along with the employee's name and their respective 
 *          allocated email ID.
 *       -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  ProjectID, ProjectName, EmpFname, EmpLname, EmailID
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT p.ProjectID, p.ProjectName, e.EmpFname, e.EmpLname, e.EmailID
 *          FROM Employee e
 *          RIGHT JOIN Project p ON p.EmpID = e.EmpID
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement:
 *      -   List out all the client details email address, whose age is between 25 to 35, 
 *          along with the projects assigned to them in ascending order of their age and 
 *          project ID. Also, use c for client_d and p for project, as alias name of tables.
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  CliendID, ClientFname, ClientLname, ClientEmailID, ProjectID, ProjectName
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT c.ClientID, c.ClientFname, c.ClientLname, c.ClientEmailID, p.ProjectID, 
 *                  p.ProjectName
 *          FROM Project p 
 *          RIGHT JOIN Client_d c ON c.ClientID = p.ClientID
 *          WHERE c.Age BETWEEN 25 AND 35
 *          ORDER BY c.Age , p.ProjectID;
 */

/**
 *  SQL Query - 7
 *  -   Problem Statement:
 *      -   List out all the combinations possible for the employee’s name and projects 
 *          that can exist(NULL included).
 *      -   Table Employee:
 *              EmpID, EmpFName, EmpLName, Age, EmailID, PhoneNo, City
 *      -   Table Project:
 *              ProjectID, EmpID, ProjectName, ProjectStartDate, ClientID
 *      -   Table Client_d:
 *              ClientID, ClientFNane, ClientLName, Age, ClientEmailID, PhoneNo, City, EmpID 
 *      -   Output Table Structure:
 *                  EmpFname, EmpLname, ProjectID
 *  Note-1: Write keywords of syntax in uppercase alphabets.
 *  Note-2: Use employee ID to link the two tables.
 *  Ans:    SELECT e.EmpFname, e.EmpLname, p.ProjectID FROM Employee e
 *          CROSS JOIN Project p;
 */