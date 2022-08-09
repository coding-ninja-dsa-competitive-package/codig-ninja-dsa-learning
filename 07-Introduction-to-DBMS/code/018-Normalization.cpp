/**
 *  MCQ - 1
 *  -   What is trivial functional dependency?
 *  Options
 *      a.  If A→B holds where B is not a subset of A.
 *      b.  If A→B holds where B is a subset of A.
 *      c.  If A→B holds where B is not an intersection of A.
 *      d.  If A→B holds where B is an intersection of A.
 *  Ans:    b
 *  -   Let there be a set of attributes A which determines a set of attributes B 
 *      (i.e. A→ B). Now if the dependent (i.e. B) is a subset of the determinant 
 *      (i.e. A). i.e. If A→ B and B⊆A. Hence, we call this a trivial functional 
 *      dependency
 */

/**
 *  MCQ - 2
 *  -   The rule which states that addition of same attributes to the right side and    
 *      left side will results in other valid dependency is classified as:
 *  Options
 *      a.  reflexive rule
 *      b.  augmentation rule
 *      c.  transitivity Rule   
 *      d.  Sigma Rule
 *  Ans:    b
 *  -   The augmentation rule states that the addition of the same attributes to the 
 *      right side and the left side will result in another valid dependency. If B can 
 *      be determined from A, then adding an attribute to this functional dependency won’t 
 *      change anything. i.e. If A→ B holds, then AM→ BM holds too. ‘M’ being a set of 
 *      attributes. 
 */

/**
 *  MCQ - 3
 *  -   A relation R has the following tuples:
 *                  A, B, C
 *                  1, 2, 3
 *                  4, 2, 3
 *                  5, 3, 3
 *                  2, 4, 4
 *      Which of the following dependencies do not hold over the relation R?
 *  Options
 *      a.  A -> B
 *      b.  AB -> C
 *      c.  C -> B
 *      d.  B -> C  
 *  Ans:    c
 *  -   Explanation: Here , if we observe carefully for C->B, we would notice that for 
 *      attribute 'C', value 3 is appearing multiples times and it is pointing to 
 *      different values of attribute 'B'.  So, if we consider value 3 of attribute 'C' , 
 *      then it can point to value 2 as well as value 3 of attribute 'B'. Hence, 'C' 
 *      cannot determine 'B' uniquely.
 *      Hence ,C->B dost NOT hold.
 */

/**
 *  MCQ - 4
 *  -   R={A, B, C, D, E} is the given schema, the FD’s for the same are as follows:
 *          A→B, A→C, CD→E, B→D, E→A
 *      Identify the illegal relation from the following.
 *  Options
 *      a.  BC→ CD
 *      b.  AC→ BC
 *      c.  EC→ AC
 *      d.  BD→ CD
 *  Ans:    d
 *  -   Using Armstrong’s axiom of Augmentation, which states that,If Y can be determined   
 *      from X, then adding an attribute to this functional dependency won’t change 
 *      anything i.e. If X→ Y holds, then XM→ YM holds too. ‘M’ being a set of attributes.
 *  -   Therefore, here all the relation stated holds but not BD→ CD. As there is no FD 
 *      stating B→ D.
 */

/**
 *  MCQ - 5
 *  -   R={A, B, C, D, E} is the given schema, the FD’s for the same are as follows:
 *          A→B, A→C, CD→E, B→D, E→A
 *      Is the relation CD→ AC legal one?
 *  Options
 *      a.  Yes
 *      b.  No
 *      c.  Cannot say
 *  Ans:    a
 *  -   We know CD→ E and E→ A . Therefore, CD→ A (using transitive rule)
 *      Also it is evident that C⊆CD therefore,  CD→ C.
 *      Hence, Combining CD→ A and  CD→ C , we can state, CD→ AC.
 */

/**
 *  MCQ - 6
 *  -   A functional dependency of the form A→B is trivial if:
 *  Option
 *      a.  A⊆A
 *      b.  A⊆B
 *      c.  B⊆A
 *      d.  A⊆B and B⊆A
 *  Ans:    c
 *  -   Let there be a set of attributes A which determines a set of attributes B
 *      (i.e. A→ B). The functional dependency will be trivial if the dependent (i.e. B) 
 *      is a subset of the determinant (i.e. A). i.e. If A→ B and B⊆A.
 */

/**
 *  MCQ - 7
 *  -   Which of the following anomalies can a relation have if it contains data 
 *      redundancies.
 *  Options
 *      a.  Insertion
 *      b.  Deletion    
 *      c.  Update
 *      d.  All of them 
 *  Ans:    Data Redundancy means having the same copies of data in a database. This 
 *      mostly happens in the database when the data is not normalised. Anomalies that 
 *      can be caused due to Data Redundancy are mostly on the WRITE anomalies that are 
 *      insertion anomaly, deletion anomaly, update anomaly, etc.
 */

/**
 *  MCQ - 8
 *  -   Consider the following table:
 *              Employee_ID, Name, Department, Clubs
 *              1, Navdeep, Content, Fitness Freaks
 *              2, Shubhangi, Marketing, Marketing Club 
 *              3, Shubhangi, Marketing, Management Club 
 *              4, Gaurav, CIS, Technology Orgs
 *              5, Gaurav, CIS, Fitness Freaks
 *  -   Answer the following question with the help of above data. Keep in mind that an 
 *      employee may be added to various clubs, but only one department.
 *  -   While creating the database, the column “Clubs” was defined so that null values 
 *      are not allowed. A new intern is hired by the company. No departments or clubs 
 *      are assigned to him beforehand. What kind of anomaly might occur due to this 
 *      restriction?
 *  Options
 *      a.  Updation Anomaly
 *      b.  Deletion Anomaly
 *      c.  Insertion Anomaly
 *      d.  None of the above
 *  Ans:    c
 *  -   A new employee without a club affiliation cannot be added into the database.
 */

/**
 *  MCQ - 9
 *  -   Consider the following table:
 *              Employee_ID, Name, Department, Clubs
 *              1, Navdeep, Content, Fitness Freaks
 *              2, Shubhangi, Marketing, Marketing Club 
 *              3, Shubhangi, Marketing, Management Club 
 *              4, Gaurav, CIS, Technology Orgs
 *              5, Gaurav, CIS, Fitness Freaks
 *  -   Answer the following question with the help of above data. Keep in mind that an 
 *      employee may be added to various clubs, but only one department.
 *  -   If the club Fitness Freak is disbanded and the data is not handled properly, what 
 *      anomaly might occur?
 *  Options
 *      a.  Updation Anomaly
 *      b.  Deletion Anomaly
 *      c.  Insertion Anomaly
 *      d.  None of the above
 *  Ans:    b
 *  -   Deletion of instances of the club Fitness Freak will lead to the complete loss of 
 *      employee information having Employee_ID as 1.
 */

/**
 *  MCQ - 10
 *  -   Consider the following table:
 *              Employee_ID, Name, Department, Clubs
 *              1, Navdeep, Content, Fitness Freaks
 *              2, Shubhangi, Marketing, Marketing Club 
 *              3, Shubhangi, Marketing, Management Club 
 *              4, Gaurav, CIS, Technology Orgs
 *              5, Gaurav, CIS, Fitness Freaks
 *  -   Answer the following question with the help of above data. Keep in mind that an 
 *      employee may be added to various clubs, but only one department.
 *  -   Gaurav has recently decided to switch to the Tech Team and has put in an official 
 *      request for department change. What anomaly might occur in the above database if 
 *      the database manager doesn’t realise the one to many relation between employee 
 *      and clubs?
 *  Options
 *      a.  Updation Anomaly
 *      b.  Deletion Anomaly
 *      c.  Insertion Anomaly
 *      d.  None of the above
 *  Ans:    a
 *  -   Updating the department may lead to the data inconsistency and partial update as 
 *      multiple entries are present for Gaurav .  All rows should be updated with a new 
 *      department for Gaurav.
 */

/**
 *  MCQ - 11
 *  -   Katherine was the assistant to the DBMS professor at her college. She was given a 
 *      simple task of converting composite attributes into individual attributes for a 
 *      table. What normalization is she performing?
 *  Options
 *      a.  First
 *      b.  Second
 *      c.  Third
 *      d.  None of the above
 *  Ans:    a
 *  -   First Normal Form (1NF) is the first step of the normalisation process. For a   
 *      relation to justifying 1NF, it needs to satisfy 4 basic conditions: 
 *      1. Each attribute should contain atomic values. (i.e. no multivalued attributes) 
 *      2. Each Value stored in an attribute should be of the same type. 
 *      3. All the attributes in a table should have unique names. 
 *      4. The order of the data stored in the table doesn’t matter.
 *  -   In the given question Katherine was given the task of converting composite 
 *      attributes to individual attributes for a table. So it is in the First normal form.
 */

/**
 *  MCQ - 12
 *  -   Which of the following is not required for a table to be in 1NF?
 *  Options
 *      a.  Attributes to have unique names
 *      b.  Free from Transitive dependencies
 *      c.  Single valued attribute
 *      d.  Each value in an attribute is of a similar type.
 *  Ans:    b
 *  -   For a relation to justifying 1NF, it needs to satisfy 4 basic conditions: 
 *      1. Each attribute should contain atomic values.
 *      2. Each Value stored in an attribute should be of the same type. 
 *      3. All the attributes in a table should have unique names. 
 *      4. The order of the data stored in the table doesn’t matter.
 */

/**
 *  MCQ - 13
 *  -   We are given a table products:
 *          cust_id, products_ordered, price    
 *              20, Mobile cover, 499
 *              27, Bag, Earphones, 1399
 *              33, Laptop, 35000
 *              35, camera, 5490
 *  -   Identify which Normal form it doesn’t satisfy, and type answer as 3NF, 2NF... 
 *      seperated by commas.
 *  Ans:    1NF
 *  -   It doesn’t satisfy 1 NF, as product_ordered attribute has multiple values in a 
 *      single record.
 *  -   A way to fix this is, Split the table into two tables one containing the cust_id 
 *      with the price paid and other one containing the cust_id and the products_ordered.
 *  -   Here, splitting the table is a better option as the customer buying the products 
 *      have certain number of products in the cart and we only know the final price. 
 *      We are not aware of the price of individual product_ordered like Bag or earphones, 
 *      so we would not be able to insert them as separate rows (one for Bag and another 
 *      for Earphone)  inside the Product table.
 *  Table Price:
 *  
 *  cust_Id   |   price
 *  ------------------
 *    20      |   499
 *    27      |  1399
 *    33      |  35000
 *    35      |  5490
 *  
 *  Table Orders:
 * 
 *  cust_Id   |   price
 *  --------------------
 *    20      |  Mobile cover
 *    27      |  Bag
 *    27      |  Earphone
 *    33      |  Laptop
 *    35      |  Camera
 */

/**
 *  MCQ - 14
 *  -   For a relation to be in 2NF it has to:
 *  Options
 *      a.  Be in 1 NF
 *      b.  Shouldn’t have transitive dependencies
 *      c.  Shouldn’t have partial dependencies
 *      d.  Both c and a 
 *      e.  Both a and b
 *  Ans:    d
 *  -   For a relation to justifying 2NF, it needs to satisfy two important rules: 
 *      1.  It should be in the First Normal Form. 
 *      2.  It should not have any partial dependencies i.e. when a nonprime attribute is        
 *          derivable from only a part of a candidate key. 
 */

/**
 *  MCQ - 15
 *  -   For a given table employee, assume an employee can work for multiple teams.
 *          Emp_Id, Team, Emp_age
 *          34324, Design, 22
 *          34324, Content, 22
 *          54355, Content, 21
 *          77445, Technical, 25
 *          77445, Design, 25
 *  -   Identify the prime attributes. Write them as comma separated.
 *  Ans:    Non-prime: Emp_age (it is dependent on Emp_id)
 *          Prime attributes: {Emp_id, Team}
 */

/**
 *  MCQ - 16
 *  -   For a given table employee, assume an employee can work for multiple teams.
 *          Emp_Id, Team, Emp_age
 *          34324, Design, 22
 *          34324, Content, 22
 *          54355, Content, 21
 *          77445, Technical, 25
 *          77445, Design, 25
 *  -   What normal form does this table violates?
 *  Ans:    Here ({Emp_id, Team}) is the key for the table. We can see that Emp_age is 
 *      dependent on Emp_id and  Emp_id is a subset of the Prime attributes ({Emp_id, Team}). Hence, it is a case of Partial dependency. Therefore, it is a violation of 2NF.
 */

/**
 *  MCQ - 17
 *  -   For a given table employee, assume an employee can work for multiple teams.
 *          Emp_Id, Team, Emp_age
 *          34324, Design, 22
 *          34324, Content, 22
 *          54355, Content, 21
 *          77445, Technical, 25
 *          77445, Design, 25   
 *  -   How will you fix the violation? Write in bullet format.
 *  Ans:    To fix this we should split the above table into two:
 *  
 *          Table Emp_detail:
 *              Emp_id   |    Emp_age
 *              --------------------
 *                34324  |  22
 *                54355  |  21
 *                77445  |  25
 *      
 *          Table Team_data:
 *              Emp_id   |   Team
 *              --------------------
 *                34324  |  Design 
 *                34324  |  Content
 *                54355  |  Content
 *                77445  |  Technical
 *                77445  |  Design 
 */

/**
 *  MCQ - 18
 *  -   Which of the following dependencies leads to violation of 3NF.
 *  Options
 *      a.  Transitive Dependency
 *      b.  Partial Dependency
 *      c.  Both a and b    
 *      d.  None of them
 *  Ans:    c
 *  -   For a table to be in third normal form, first it should be in 2NF and second no     
 *      transitive dependencies. 
 */

/**
 *  MCQ - 19
 *  -   Given a table subjects as shown below:
 *              Sub, Department, Instructor
 *              S1, Dep1, Ins1
 *              S2, Dep1, Ins2
 *              S3, Dep1, Ins1
 *              S4, Dep2, Ins3
 *              S5, Dep2, Ins4
 *  -   Identify the normal it violates. Also, give the ways to fix them.
 *  Note: Write the normal form(s) comma separated and give the ways to fix them in bullet 
 *      form from the next line.
 *  Ans:    Here, on observing we can say, 
 *      Sub--> Instructor (A subject is taught by instructor
 *      And Instructor--> Department (an instructor belongs to certain department)
 *      So we can say Sub --> Department (using transitive rule.)
 *      Hence, transitive dependency from the primary key.
 *      Hence Violating 3NF.
 * 
 *  -   Let's fix this by splitting the above table into two as below:
 *          Table Ins_dep:
 *              Instructor   |  Department 
 *              -------------------------
 *                 Ins1      |  Dep1
 *                 Ins2      |  Dep1
 *                 Ins3      |  Dep2
 *                 Ins4      |  Dep3
 *  
 *          Table Sub_Ins:
 *              Sub     |   Instructor
 *              -------------------------
 *              S1      |  Ins1
 *              S2      |  Ins1
 *              S3      |  Ins2
 *              S4      |  Ins3
 *              S5      |  Ins4
 */

/**
 *  MCQ - 20
 *  -   Which of the following is true about BCNF:
 *  Options
 *      a.  lossless join and dependency preserving
 *      b.  lossless join but not dependency preserving 
 *      c.  not lossless join but dependency preserving
 *      d.  none of these
 *  Ans: b   
 *  -   Lossless Join:
 *      A decomposition of the Relation is said to be lossless when it is decomposed into 
 *      two new relation whose FD satisfy following condition:
 *      1. Union of attributes of two relation is equal to that of the original relation. 
 *      2. Intersection of Attributes of two decomposed relations must not be NULL.
 *      3. Common attribute between the relations must be a key for at least one of them.
 *  -   Dependency Preserving:
 *      On decomposing a relation into two, All dependencies of the original relation 
 *      either must be a part of both the decomposed relation or must be derivable from 
 *      combination of dependencies of both the relation.
 */