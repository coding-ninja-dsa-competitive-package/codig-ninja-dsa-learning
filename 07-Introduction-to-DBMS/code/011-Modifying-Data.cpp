/**
 *  SQL Query - 1
 *  -   Problem statement :
 *      -   Formulate a query to add records to table tutorials.
 *  Note: Print the table after adding the values.
 *  Ans:    INSERT INTO tutorials (tutorial_title, tutorial_author, submission_date) 
 *              VALUES ('Learn MySQL', 'Balachandra Raju', '01-09-2021');
 *          SELECT * FROM tutorials;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement
 *      -   Formulate a query to add a record, where you only fill in columns Roll_no, 
 *          std_name, Age with the given data:
 *              ( 7, Shantnu, 21 )
 *      -   Information about the table:
 *          Attribute lists of table Students : Roll_no (INT), std_name CHAR(200), 
 *              Address CHAR(200), Phone CHAR(200), Age INT
 *  Note: Print the complete table after adding the values.
 *  Ans:    INSERT INTO Students (Roll_no, std_name, Age) VALUES (7, 'Shantnu', 21);
 *          SELECT * FROM Students;
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:  
 *      -   Given a table named stud_data, formulate a query to change the Fname and 
 *          Age of the already entered record to ( Neelabh, 22 ) of roll number 17.
 *  Note: Print the complete table after updating the data.
 *  Ans:    UPDATE stud_data SET Fname='Neelabh', Age=22 WHERE roll_no=17;
 *          SELECT * FROM stud_data;
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   Consider a table named products, formulate a query deleting the record where 
 *          product_id = 596 or 700.
 *  Note: Print the complete table after deleting the data.
 *  Ans:    DELETE FROM products WHERE product_id IN (596, 700);
 *          SELECT * FROM products;
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement
 *      -   Given the table cities, form a query using REPLACE, to update/add the given data:
 *  Note: Print the table afterwards.   
 *  Ans:    REPLACE INTO cities SET id=4, cname='Phoenix', population=1768980;
 *          SELECT * FROM cities;
 */