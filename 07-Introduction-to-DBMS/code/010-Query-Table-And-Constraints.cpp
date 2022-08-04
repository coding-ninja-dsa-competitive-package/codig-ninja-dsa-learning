/**
 *  SQL Query - 1 
 *  -   Problem Statement :
 *      -   Write a query for creating a table named People, which contains information 
 *          given in the table below:
 *                      Attribute       |       Data Type
 *                          PID         |       INT (Primary Key)
 *                       LastName       |       VARCHAR
 *                       FirstName      |       VARCHAR
 *                       Address        |       VARCHAR
 *                       City           |       VARCHAR
 *      -   Print the Table schema once created as follows:
 *                  SELECT table_name, column_name, data_type
 *                  FROM information_schema.columns
 *                  WHERE table_name =<TABLE_NAME>
 *                  ORDER BY column_name;
 *          Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    CREATE TABLE People (
 *              PID INT, 
 *              LastName VARCHAR(255),
 *              FirstName VARCHAR(255),
 *              Address VARCHAR(255),
 *              City VARCHAR(255)
 *          );
 *          
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'People'
 *          ORDER BY column_name;
 */

/**
 *  SQL Query - 2
 *  -   Problem Statement :
 *      -   Write a query for creating a table named Patients, which contains the attribute 
 *          given in the table below:
 *                      Attribute          |       Data Type
 *                      Patient_id         |       INT (Primary Key)
 *                       Patient_title     |       CHAR (NOT NULL)
 *                       Patient_name      |       CHAR (NOT NULL)
 *                       admit_date        |       DATE
 *      -   Print the Table schema once created as follows:
 *                  SELECT table_name, column_name, data_type
 *                  FROM information_schema.columns
 *                  WHERE table_name =<TABLE_NAME>
 *                  ORDER BY column_name;
 *          Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    CREATE TABLE Patients (
 *              Patient_id INT, 
 *              Patient_title CHAR NOT NULL,
 *              Patient_name CHAR NOT NULL,
 *              admit_date DATE
 *          );
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'Patients'
 *          ORDER BY column_name;
 */

/**
 *  MCQ - 1
 *  -   Which of the following can accept NULL values?
 *  Options
 *      a.  Primary Key
 *      b.  Unique Key 
 *      c.  Both
 *      d.  None of the above
 *  Ans:    b
 *  -   A primary key defines the columns that uniquely identify rows in a table. When 
 *      you create a primary key constraint, none of the columns included in the primary 
 *      key can have NULL constraints; so Primary Key does not permit NULL values.
 *  -   However, You can insert NULL values into columns with the UNIQUE constraint 
 *      because NULL is there due to the absence of a value, so actually, it is never 
 *      equal to other NULL values and hence not considered a duplicate value
 */

/**
 *  MCQ - 2
 *  -   Which of the following is not a Key in MySQL?   
 *  Options
 *      a.  Primary
 *      b.  Secondary 
 *      c.  Alternate
 *      d.  Foreign
 *  Ans:    b
 *  -   There is no “secondary” key type in SQL, instead, there is an “Alternate” key type.
 */


/**
 *  MCQ - 3
 *  -   Which of the following statements regarding Foreign Key is Incorrect.
 *          Statement - 1 : Foreign key is used to link two tables together.
 *          Statement - 2 : Foreign key allows inserting NULL values.   
 *          Statement - 3 : Foreign key doesn’t allow inserting NULL values.
 *          Statement - 4 : Foreign key uniquely identifies tuples of a relation.
 *  Options
 *      a.  3 & 4 
 *      b.  2 & 4
 *      c.  2, 3 & 4
 *      d.  1, 3 & 4
 *  Ans:    The foreign key is used to link two tables, via adjoining common column. 
 *  -   The foreign key is the primary key of another table, and it is possible to have 
 *      more than one foreign key in a particular table. 
 *  -   Though NULL values are not allowed in the case of the primary key, it is allowed 
 *      in the case of the foreign key.
 *  -   The Primary key uniquely identifies tuples of a relation. If there is another key 
 *      uniquely identifying the tuples of relation, than that key will be called the 
 *      Candidate key.
 */

/**
 *  SQL Query - 3
 *  -   Problem Statement:
 *      Consider the tables given below:
 *      1.  The table users contains features like id, full_name, enabled, last_login. 
 *          The attribute id here will be the primary key.
 *              Attribute List(s): 
 *      2.  The table addresses contains features like user_id, street, city, state. The 
 *          user_id here will be the primary key as well as foreign key that refers to 
 *          id(users table). The attributes street, city and state should be declared 
 *          NOT NULL.
 *              Attribute List(s):
 *  -   Formulate a SQL query to create these tables with all the constraints given 
 *      along with the table. Also, add constraints to correlate these tables.
 *  -   Print the Table Schema for each table created as follows:
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = <TABLE_NAME>; 
 *  Note - 1: First print table users and then addresses. Position the above command just 
 *          after the CREATE TABLE command for each table.
 *  Note - 2: Write keywords of syntax in uppercase alphabets.
 *  
 *  Ans:    
 *      CREATE TABLE users (
 *          id INT PRIMARY KEY,
 *          full_name VARCHAR,
 *          enabled CHAR,
 *          last_login DATE
 *      );
 *      SELECT table_name, column_name, data_type
 *      FROM information_schema.columns
 *      WHERE table_name = 'users'; 
 *      
 *      CREATE TABLE addresses (
 *          user_id INT PRIMARY KEY,
 *          street VARCHAR NOT NULL,
 *          city VARCHAR NOT NULL,
 *          state VARCHAR NOT NULL,
 *          FOREIGN KEY (user_id) REFERENCES users(id)
 *      );
 *      SELECT table_name, column_name, data_type
 *      FROM information_schema.columns
 *      WHERE table_name = 'addresses'; 
 */

/**
 *  SQL Query - 4
 *  -   Problem Statement:
 *      -   Consider the tables given below and formulate a SQL query to create these 
 *          tables with all the constraints.
 *      1.  The table books contain features like id, title, author, publish_date, isbn. 
 *          The id should be declared as PRIMARY KEY. The isbn should be declared UNIQUE. 
 *          The attributes title, author and publish_date should be declared NOT NULL.
 *      2.  The Table reviews contains features like id, book_id, reviewer_name, content, 
 *          rating, published_date . The id should be declared PRIMARY KEY . The bookid 
 *          should be declared FOREIGN KEY referred to id (table book). The attribute 
 *          bookid should be declared NOT NULL .
 *  -   Print the Table Schema for each table created as follows:
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = <TABLE_NAME>;
 *  Note - 1: First print table books and then reviews. Position the above command just 
 *          after the CREATE TABLE command for each table.
 *  Note - 2: Write keywords of syntax in uppercase alphabets.
 *  
 *  Ans:    CREATE TABLE books(
 *              id INT PRIMARY KEY,
 *              title VARCHAR(100) NOT NULL,
 *              author VARCHAR(100) NOT NULL,
 *              published_date TIMESTAMP NOT NULL,
 *              isbn CHAR(12) UNIQUE
 *          );
 *      SELECT table_name, column_name, data_type
 *      FROM information_schema.columns
 *      WHERE table_name = 'books';
 *          
 *      CREATE TABLE reviews (
 *          id INT PRIMARY KEY,
 *          book_id INT NOT NULL,
 *          reviewer_name VARCHAR(255),
 *          content VARCHAR(255),
 *          rating INT,
 *          published_date TIMESTAMP,
 *          FOREIGN KEY (book_id) REFERENCES books(id)
 *      );
 *      SELECT table_name, column_name, data_type
 *      FROM information_schema.columns
 *      WHERE table_name = 'reviews';
 */

/**
 *  SQL Query - 5
 *  -   Problem Statement:
 *      -   Write multiple queries to create two tables named customer and contacts:
 *      1.  The table customer contains features like ID, Name, City where all columns are 
 *          never NULL. The ID here will be the primary key.
 *      2.  The Table contacts contain features like ID, Customer_Id, Customer_info, Type. 
 *          Customer_ id being a foreign key that refers to ID(customer table). Also 
 *          Customer_info and Type are never NULL.
 *  Note: Describe both the tables as well. The syntax for describe is given below. 
 *      Describe the Customer table first and then Contacts Table.
 *              DESC <TABLE_NAME>;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    CREATE TABLE customer (
 *              ID INT,
 *              Name VARCHAR(50) NOT NULL,
 *              City VARCHAR(50) NOT NULL,
 *              PRIMARY KEY (ID)
 *          );
 *          
 *          DESC customer;
 *          
 *          CREATE TABLE contacts (
 *              ID INT,
 *              Customer_id INT,
 *              Customer_info VARCHAR(50) NOT NULL,
 *              Type VARCHAR(50) NOT NULL,
 *              FOREIGN KEY (Customer_id) REFERENCES customer(ID)
 *          );
 *          
 *          DESC contacts;
 *  
 */

/**
 *  SQL Query - 6
 *  -   Problem Statement :
 *      -   Given a table named members, write a query to add a column named cc_number 
 *          (Datatype - VARCHAR).
 *  Note : Print the Table Schema once created as follows:
 *              SELECT table_name, column_name, data_type
 *              FROM information_schema.columns
 *              WHERE table_name = <TABLE_NAME>
 *              ORDER BY column_name;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    ALTER TABLE members ADD cc_number VARCHAR(255);
 *  
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'members'    
 *          ORDER BY column_name;
 */

/**
 *  SQL Query - 7
 *  -   Problem Statement :
 *      -   Given a table named Bank, write a query to change the existing column 
 *          person_id to Pid VARCHAR(50).
 *      -   table Bank
 *              person_id(INT), full_name(VARCHAR(30)), acc_no(INT), last_trans(VARCHAR(200)),
 *              phone_no(VARCHAR(200))
 *      -   Syntax to describe the above table.
 *              DESC <TABLE_NAME>;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    ALTER TABLE Bank CHANGE COLUMN person_id Pid VARCHAR(50);
 *          DESC Bank;
 */

/**
 *  MCQ - 4
 *  -   Which statement is used to delete all rows in a table without logging the 
 *      individual row deletions? 
 *  Options
 *      a.  DELETE
 *      b.  REMOVE
 *      c.  DROP
 *      d.  TRUNCATE
 *  Ans:    d
 *  -   TRUNCATE Command removes all rows from a table or specified partitions of a 
 *      table without logging the individual row deletions.
 */

/**
 *  SQL Query - 8
 *  -   Problem Statement :
 *      -   Given a table named members, write a query to remove a column named member_dob.
 *      -   Print the Table Schema once created as follows:
 *              SELECT table_name, column_name, data_type
 *              FROM information_schema.columns
 *              WHERE table_name = <TABLE_NAME>
 *              ORDER BY column_name;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    ALTER TABLE members DROP COLUMN member_dob;
 *          
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'members'
 *          ORDER BY column_name;
 */

/**
 *  SQL Query - 9
 *  -   Problem Statement :
 *      -   Write a query to rename the Table consumers to Consumer_Data.
 *      -   Print the Table Schema once created as follows:
 *              SELECT table_name, column_name, data_type
 *              FROM information_schema.columns
 *              WHERE table_name = <TABLE_NAME>
 *              ORDER BY column_name;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    ALTER TABLE consumers RENAME TO Consumer_Data;
 *      
 *          SELECT table_name, column_name, data_type
 *          FROM information_schema.columns
 *          WHERE table_name = 'Consumer_Data'
 *          ORDER BY column_name;
 */

/**
 *  SQL Query - 10
 *  -   Problem Statement :
 *      -   Write a SQL query to remove the attribute 'last_login' and rename the 
 *          'full_name' to 'customer_name' in the customer table.
 *      -   Table customer
 *              id(INT) - Primary Key, full_name VARCHAR(30), totalOrders INT, 
 *              last_login DATE, phone_no VARCHAR(200)
 *  -   Syntax to describe the table.
 *          DESC <TABLE_NAME>;
 *  Note: Write keywords of syntax in uppercase alphabets.
 *  Ans:    ALTER TABLE customer DROP COLUMN last_login;
 *          ALTER TABLE customer CHANGE COLUMN full_name customer_name VARCHAR(30);
 *          DESC customer;
 */