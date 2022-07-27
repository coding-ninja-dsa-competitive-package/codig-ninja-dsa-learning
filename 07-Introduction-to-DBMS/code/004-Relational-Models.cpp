/**
 *  MCQ-1
 *  -   Match the ER diagram components to their representation in the relational model
 *          a.  Entity                              1.  Foreign Key
 *          b.  Attribute                           2.  Relation
 *          c.  Relationship between entities       3.  Columns
 *  Options:
 *  -   This problem has only one correct answer
 *      a.  a1 b2 c3
 *      b.  a2 b3 c1 
 *      c.  a2 b1 c3
 *      d.  a3 b1 c2
 *  Ans:    b
 *  -   An entity in ER diagram is represented by a relation or a table in relational 
 *      model, similarly attributes of an entity are denoted by columns or fields of the 
 *      table. Relationships between entities are shown by using foreign keys in relational 
 *      models
 */

/**
 *  MCQ-2 (Relational Model)
 *  -   In a relational model, which of the following indicates the cardinality:
 *  Options:
 *      a.  Number of attributes
 *      b.  Number of keys
 *      c.  Number of tuples 
 *      d.  Number of relations
 *  Ans:    c
 *  -   In relational model, cardinality refers to the number of tuples present
 *      in a relation or table
 */

/**
 *  MCQ-3
 *  -   Which of the following is true:
 *  Options
 *      a.  A relation and table are the same.
 *      b.  An attribute and a column in relation means the same.
 *      c.  None of the above
 *      d.  A and B both 
 *  Ans:    d
 *  -   For design purpose, table and relation means the same. Although, technically a 
 *      relation does not have duplicate value but a table can contain duplicate. 
 *      Similarly, the attributes and the column are the same.
 */

/**
 *  MCQ-4
 *  -   For the given relation Book, what is the degree:
 *          Book_Name       Book_Code       Book_Price      Author_Name     Publish_Date
 *          Physics-1         011             180           Dr. Raj Nag       21-03-1996  
 *          Chemistry-1       021             200           Dr. Kiran Sethi   25-2-2001
 *          Maths-1           031             175           Vipul Sen         1-6-2006
 *  Options
 *      a.  3  b.   5   c.  15      d.  10
 *  Ans:    b
 *  -   In relational model, degree refers to the number of attributes present in the 
 *      relation
 */

/**
 *  MCQ-5   
 *  -   Which of the following is not a property of the table:
 *  Options
 *      a.  Every column should have unique name
 *      b.  An attribute can have multiple values for a row 
 *      c.  Column values should be of same type
 *      d.  Sequence of rows is insignificant
 *  Ans:    b
 *  -   A relation should contain atomic values, so multiple values 
 *      for an attribute should be avoided
 */

/**
 *  MCQ-6
 *  -   Match the components of relational model which are same:
 *          a.  Tuples          1.  Relation    
 *          b.  Column          2.  Field
 *          c.  Table           3.  Rows/Record
 *  Options
 *      a.  a2 b1 c3
 *      b.  a3 b2 c1 
 *      c.  a1 b3 c2
 *      d.  a3 b1 c2
 *  Ans:    A Tuples in the Relational model is represented by a row, also known as 
 *      records. Similarly, columns are denoted by fields of the table also called 
 *      attributes. The table is similar  to relation in the relational model.
 */

/**
 *  MCQ-7
 *  -   There is a set of permitted values for each attribute of a relation. These are 
 *      known as:
 *  Options
 *      a.  Schema
 *      b.  Instance
 *      c.  Domain 
 *      d.  Relation
 *  Ans:    c
 *  -   Domain is a set of permitted values, The value of attributes should be in the domain.
 */

/**
 *  MCQ-8
 *  -   A null value of an attribute indicates which of the following:
 *  Options
 *      a.  Zero
 *      b.  Infinite
 *      c.  Error
 *      d.  Unknown 
 *  Ans:    d
 *  -   NULL value implies that the value for that particular attribute is unknown, 
 *      this is not same as 0 or error.
 */

/**
 *  MCQ-9
 *  -   Which of the following is true:
 *  Options
 *      a.  A candidate key is a minimal super key.
 *      b.  Candidate keys which do not become primary keys are called alternate keys.
 *      c.  Any candidate key can become a Primary key.
 *      d.  All of the above 
 *  Ans:    d
 *  -   A candidate key is a minimal subset of super keys. It contains no redundant 
 *      attribute. Hence, it is selected from the set of super keys given that those 
 *      selected keys DO NOT have any redundant attributes. Candidate Key value should 
 *      not be null. Any candidate key can be selected to be a primary key according to 
 *      preference. The candidate keys that are not selected as the primary key are called 
 *      the alternate keys. 
 */

/**
 *  MCQ-10 (Primary Key)
 *  -   A primary key should be:
 *  Options
 *      a.  Null
 *      b.  Not null
 *      c.  Unique
 *      d.  Unique and not Null 
 *  Ans:    d
 *  -   A primary key is a unique identifier that helps us to identify each and every 
 *      tuple uniquely. 
 *  -   No two rows have the same value for the primary key Attribute and the primary key 
 *      cannot be null. 
 *  -   The primary key in the table cannot be changed. 
 *  -   It is selected out of all the candidate keys by the database admin. 
 */

/**
 *  MCQ-11
 *  -   Which of the following is true:
 *  Options
 *  a.  We can have multiple candidate keys 
 *  b.  We can have multiple primary keys
 *  c.  The value of primary key can be same for 2 tuples
 *  d.  Alternate key and primary key are the same.
 *  Ans:    a
 *  -   A relation can have multiple candidate keys, out of which ,one is selected as a 
 *      primary key and the remaining ones are called alternate keys
 */

/**
 *  MCQ-12
 *  -   A primary key with the help of foreign key creates a parent child relationship 
 *      between the tables that connect them.
 *  Options
 *      a.  True 
 *      b.  False
 *  Ans:    a
 *  -   A primary key is of a relation is linked  with the foreign key, so that the 
 *      referential constraint is set up between the two relations; hence it creates a 
 *      parent-child relationship between the tables that connects them.
 */

/**
 *  MCQ-13(CRUD Operations)
 *  -   What does R refers to in CRUD operations:
 *  Options
 *      a.  Replicate
 *      b.  Read 
 *      c.  Redundant
 *      d.  Replace
 *  Ans:    b
 *  -   For the persistent storage in DBMS, four basic operations that are known as CRUD 
 *      operations are as follows: 
 *      1. 'C' in CRUD stands for Create. It is accomplished using INSERT statement in SQL.
 *      2. 'R' in CRUD stands for Read. It is accomplished using the SELECT statement in SQL.
 *      3. 'U' in CRUD stands for Update. It is accomplished using UPDATE statements in SQL.
 *      4. 'D' in CRUD stands for Delete. It is accomplished using the DELETE statement in SQL.
 */

/**
 *  MCQ-14
 *  -   Entity integrity states that primary key should be:
 *  Options
 *      a.  Null
 *      b.  Not null 
 *      c.  Null and Not null
 *      d.  zero
 *  Ans:    b
 *  -   Entity Integrity Constraint  puts constraints on Primary key i.e. primary should    
 *      be unique and does not have NULL value. 
 */

/**
 *  MCQ-15
 *  -   Referential integrity constraint states that foreign key should have a matching 
 *      primary key or it must be not Null.
 *  Options
 *      a.  True
 *      b.  False 
 *  Ans:    b
 *  -   A foreign key should have the matching primary key for its each value in the 
 *      parent table or it should be NULL.
 */

/**
 *  MCQ-16
 *  -   In following table which integrity constraint is being violated:
 *         Book_Name       Book_Code       Book_Price      Author_Name     Publish_Date
 *          Physics-1         011             180           Dr. Raj Nag       21-03-1996  
 *          Chemistry-1       021             200           Dr. Kiran Sethi   25-2-2001
 *          Maths-1           031             175           Vipul Sen         1-6-2006
 *          Grammer-1         021             150           Dr. Jay           11-5-2020
 *  Options
 *      a.  Referential Integrity constraint
 *      b.  Key constraint  
 *      c.  Domain constraint
 *      d.  Entity Integrity constraint
 *  Ans:    c
 */

/**
 *  MCQ-17
 *  -   For an attribute “Adhaar Number” which is defined as integer type, which 
 *      constraint would be violated if we enter the PAN (has numbers and alphabets) in it
 *  Options
 *      a.  Entity Integrity constraint
 *      b.  Key constraint
 *      c.  Domain constraint 
 *      d.  Referential Integrity constraint
 *  Ans:    c
 *  -   The domain integrity constraints restrict the value in the particular attributes. 
 *      It defines which values should be considered valid for a particular attribute and   
 *      which values would be invalid. Therefore, if we want to take email as input in an 
 *      attribute, then we can use domain constraints to ensure that email is valid. In 
 *      this question, a similar situation is present as the Aadhar number is defined as 
 *      an integer, which means the values entered in this attribute should contain digits 
 *      only.  On the other hand, the PAN number contains both digits and alphabets. This 
 *      will result in the violation of domain integrity constraints and show Invalid 
 *      status to the user.
 */

/**
 *  MCQ-18
 *  -   Which of the following is not a key constraint:
 *  Options
 *      a.  Check
 *      b.  Not Null
 *      c.  Unique
 *      d.  None of the above 
 *  Ans:    b
 *  -   The six types of key constraints present in the Database management system are:- 
 *      1. NOT NULL:  This constraint will restrict the user from not having a NULL value. 
 *          It ensures that every element in the database has a value.
 *      2. UNIQUE: It helps us to ensure that all the values consisting in a column are 
 *          different from each other. Is is a part of the primary constraint
 *      3. DEFAULT: it is used to set the default value to the column. The default value 
 *          is added to the columns if no value is specified for them. 
 *      4. CHECK: It is one of the integrity constraints in DBMS. It keeps the check that 
 *          integrity of data is maintained before and after the completion of the process
 *      5. PRIMARY KEY: This is an attribute or set of attributes that can uniquely 
 *          identify each entity in the entity set. The primary key must contain unique 
 *          as well as not null values.
 *      6. FOREIGN KEY: Whenever there is some relationship between two entities there 
 *          must be some common attribute between them. This common attribute must be the 
 *          primary key of an entity set and will become the foreign key of another entity 
 *          set. This key will prevent every action which can result in loss of connection 
 *          between tables.
 */

/**
 *  MCQ-19
 *  -   Which of the following relational database schemas is a correct representation 
 *      for the following ER diagram:
 *          Name        phone no.       Course      House No
 *               \          |           /           /
 *            Roll No.--Student--------------Address--City
 *  Options
 *      a.  Student(Name, Phone no., Course, Roll No., House no., City)
 *      b.  Student(Name, Phone no., Course, Roll No.) Address(House no., City, Roll no.) 
 *      c.  Student(Name, Phone no., Course, Roll No., Address, House no., City, Roll no.)
 *      d.  All of the above
 *  Ans:    b
 *  -   In the following ER diagram, The rectangle in the ER diagram represents entity 
 *      sets, whereas the ellipse represents attributes. Double ellipses represent  
 *      multi-valued attributes. The rules for conversion of ER diagram to the relational 
 *      schema are:
 *      1. Every strong entity set can be converted into a relational schema by having 
 *          the entity set name as the relation schema name.
 *      2. Attributes of the entity sets are attributes in the relational schema.
 *      3. For each multi-valued attribute, we have to create a separate table, and we  
 *          should include the primary key of the strong entity set (parent entity set) 
 *          as a foreign key attribute.
 * -    By Applying the information given above, we can say that the Entity student has 
 *      five attributes, i.e. Name, Roll No., Phone No., Course and Address. Out of these 
 *      five attributes, address is a multi-valued attribute and Name, Roll No. , 
 *      Phone No., and Course is single-valued attributes. 
 *  -   So, the relation ‘Student’ will have the fields: Nam, Phone No., Course, RollNo.  
 *      The address is further divided into two single-valued attributes, i.e. House No. 
 *      and City. 
 *  -   So, a new relation ‘Address’ would be created having fileds:House No. and City 
 *      and a Foreign Key RollNo. To connect to “Students” relation.
 */

/**
 *  MCQ-20 (Relational Algebra)
 *  -   Relational algebra is :
 *  Options
 *      a.  Non procedural query language
 *      b.  High level language
 *      c.  Procedural query language 
 *      d.  None of the above
 *  Ans:    c
 *  -   Relational Algebra is a procedural query language in which the user specifies the 
 *      set of operations to be performed sequentially to get the desired output.
 */

/**
 *  MCQ-21
 *  -   Which of the following is true for selection operator:
 *  Options
 *      a.  It displays the specified columns
 *      b.  It selects the specified columns    
 *      c.  It modifies the specified columns
 *      d.  It deletes the specified columns
 *  Ans:    b
 *  -   Selection operator is used to select some attributes or some tuples from the 
 *      table. Example σ Cust_Name="Indu" (Customer) It will select a customer whose 
 *      name is Indu but it’ll not display. Note: This Select is DIFFERENT from MySQL 
 *      SELECT. 
 */

/**
 *  MCQ-22
 *  -   Which of the following should be used to list down all the names of the Book whose 
 *      Book_price is less than 100 from the relation ‘Book’:
 *  Options
 *      a.  σBook_name, Book_price<100(Book))
 *      b.  ΠBook_name(σBook_price<100(Book)) 
 *      c.  σBook_name(σBook_price<100(Book))
 *      d.  ΠBook_price<100(Book))
 *  Ans:    b
 *  -   To list down all the names of the Book whose Book_price is less than 100 from the 
 *      relation ‘Book’, we can use the projection operator(π) on the book_name attribute 
 *      which is used to display the output. Then use the Selection operator(σ) on the 
 *      book price attribute to fulfill the condition present in the question. The 
 *      selection operator will get the desired data.
 */

/**
 *  MCQ-23
 *  -   What will be the result if set difference operator is applied as B-A on relations 
 *      A and B
 *  Options
 *      a.  All rows of relation B
 *      b.  All rows of relation B which are present in relation A
 *      c.  All rows of relation B which are not present in relation A 
 *      d.  All rows common to relation B and relation A
 *  Ans:    c
 *  -   The set difference operator is an operator which takes the two sets as an input 
 *      and returns the values that are present in the first set but absent in the second 
 *      set. When the set difference operator is applied as B-A on relations A and B, the 
 *      result will contain all rows of relation B which are not present in relation A.
 */

/**
 *  MCQ-24
 *  -   What would be the result from cartesian product of Relation A and B (A X B)
 *          Relation A
 *          SNo         Author_Name
 *          1           A
 *          2           B
 *          3           C
 *      
 *          Relation B 
 *          Id          City            State
 *          4           Agra            UP
 *          5           Bhopal          MP   
 *          6           Imphal          Manipur
 *  Options
 *      a.  The relation having 2 attributes and 6 tuples
 *      b.  The relation having 5 attributes and 6 tuples
 *      c.  The relation having 5 attributes and 9 tuples 
 *      d.  The relation having 2 attributes and 9 tuples
 *  Ans:    c
 *  -   The cartesian product is an operation used to combine each row in a given table 
 *      with each row of another table. It is also known as the cross product. It means 
 *      the product of the number of rows and the sum of the number of columns. So the 
 *      Solution will be the cross product of A and B. As A has three rows and two columns, 
 *      B has three rows and three columns. So Solution must be nine rows, and five columns 
 *      as Columns and rows represent attributes and tuples. The answer must be ‘c’.
 */

/**
 *  MCQ-25
 *  -   Which of the following would rename the “class” attribute to “course” in a 
 *      relation called University
 *          a.  ρ class -> course (University)
 *          b.  σ class = course (University)
 *          c.  ∏ class , course (University)
 *  Options
 *      a.  a 
 *      b.  b
 *      c.  c
 *      d.  None of the above
 *  Ans:    a
 *  -   A rename operator, denoted by ‘ρ’,  will be used to rename the “class” attribute 
 *      to “course” in a relation called University. 
 */