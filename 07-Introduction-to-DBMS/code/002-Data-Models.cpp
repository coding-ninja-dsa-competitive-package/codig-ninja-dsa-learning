/**
 *  MCQ - 1 (Conceptual Model)
 *  -   Which of the following is true for conceptual model:
 *  Options
 *      a.  It is independent of hardware
 *      b.  It is independent of software
 *      c.  It is dependent on both hardware and software
 *      d.  It is independent of both hardware and software
 *  Ans:    d
 *      -   Conceptual model is the high level data model which does not depend on the 
 *          hardware and the software.
 */

/**
 *  MCQ -2
 *  -   When asked to design a high level conceptual data model, the very first step 
 *      is _______.
 *  Options
 *      a.  Functional requirement analysis
 *      b.  Logical design analysis
 *      c.  Requirement analysis
 *      d.  Conceptual design analysis
 *  Ans:    c
 *      -   Before we start with the designing of a conceptual data model , we should be 
 *          clear of the requirements of the system. Hence, requirement analysis is the 
 *          first step that needs to be taken. 
 *      -   Let’s take an example to understand this. You have been asked to create a 
 *          data model for a BANK. So the very first step  will be collecting the 
 *          necessities and functionalities that the BANK database must have . Some 
 *          examples can be it should  be able to store: current balance, type of account, 
 *          customer name , account numbers etc. 
 */

/**
 *  MCQ -3
 *  -   Which one of the following is an example of the object-based logical model?
 *  Options
 *      a.  entity relationship model
 *      b.  document model
 *      c.  relational model
 *      d.  network model
 *  Ans:    a
 *      -   The Entity Relationship  model is the example of an object-based logical model 
 *          as it uses the notions of entities or objects and relationships among them 
 *          instead of using implementation-based concepts, such as records, used in the 
 *          record-based models. This delivers flexible structuring abilities and permits 
 *          data limitations to be specified explicitly.
 */

/**
 *  MCQ -4
 *  -   According to a certain given database schema, manager’s salary is hidden from 
 *      employees, which level of abstraction is it.    
 *  Options
 *      a.  Physical level
 *      b.  Conceptual level
 *      c.  External level
 *      d.  Internal level
 *  Ans:    c
 *      -   External level abstraction provides a powerful and flexible abstraction by 
 *          hiding certain parts of a database from certain users according to the 
 *          requirements. Also, in this abstraction, the user is not aware of any missing 
 *          attributes from the view. It also allows users to access data in a customized 
 *          way according to their needs, and due to this functionality, different users 
 *          see the same data in different ways simultaneously.
 */

/**
 *  MCQ -5
 *  -   Which of the following model tells how data will be stored: 
 *  Options
 *      a.  Physical data model 
 *      b.  Creational data model
 *      c.  Conceptual data model
 *      d.  Representational data model
 *  Ans:    a
 *      -    Physical Data model represents   the physical structure of the database which 
 *          includes planning of how the data will be organised,  stored on the disk and 
 *          various access methods available for it.
 */

/**
 *  MCQ -6 (Data Modelling)
 *  -   Data modelling helps in achieving abstraction in DBMS.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 *      -   Abstraction means showing only what is required and hiding the extra information. 
 *          This is achieved through the three kind of data modelling: Conceptual, 
 *          Representational and Physical data models.
 */

/**
 *  MCQ -7
 *  -   Which of the following data models describes the database at the highest level ?
 *  Options
 *      a.  Conceptual data model
 *      b.  physical data model
 *      c.  network data model
 *      d.  hierarchical data model
 *  Ans:    a
 *      -   A conceptual data model describes and conveys high-level relationships between 
 *          concepts/entities. In simpler words, it helps an organization see their data 
 *          – and the relationships between distinct data.
 */

/**
 *  MCQ -8
 *  -   Which one of the following is a popular representational model?
 *  Options
 *      a.  ER model
 *      b.  Relational model
 *      c.  Hierarchical model
 *      d.  Network model
 *  Ans:    b
 *      -   The relational model in DBMS is used to organize and manage the data stored in 
 *          a database. It stores data in the form of tables. Each row represents an 
 *          entity, and each column represents the entity's properties. 
 */

/**
 *  MCQ -9 (Database Schema)
 *  -   Database schema is part of which design process
 *  Options
 *      a.  Conceptual design
 *      b.  Logical design
 *      c.  Physical Design
 *      d.  None of the above
 *  Ans:    b
 *      -   Going by the definition of database schema , it is the skeleton structure 
 *          that demonstrates the logical view of the complete database. It is responsible 
 *          for describing the organization of data and how the relations will be 
 *          associated among them.  It also formulates all the conditions that are to be 
 *          applied on the data.
 */

/**
 *  MCQ - 10 (3-Tier Architecture)
 *  -   In 3 tier architecture, which of the following deals with the physical storage of 
 *      data
 *  Options
 *      a.  External schema
 *      b.  Internal schema
 *      c.  Conceptual schema
 *      d.  All of the above
 *  Ans:    b
 *      -   The internal schema  describes the physical storage structure of the database. It 
 *          is a very low-level representation of the complete database.
 */

/**
 *  MCQ -11
 *  -   Which of the following shows only the relevant data to users and hides the rest
 *  Options
 *      a.  Physical Schema
 *      b.  External Schema
 *      c.  Conceptual Schema
 *      d.  None of the above
 *  Ans:    b
 *      -   External schema shows only the data a user requires, in the form of views. 
 *          Other unnecessary data is kept hidden from the users.
 */

/**
 *  MCQ -12
 *  -   Which of the following describes the design of a database and the relationship 
 *      between data ?
 *  Options
 *      a.  Conceptual Schema
 *      b.  Physical Schema
 *      c.  External Schema 
 *      d.  None of the above
 *  Ans:    a
 *      -   The conceptual schema defines the structure of the database for a group of 
 *          users. It abstracts information about the physical storage structures and 
 *          defines data types, entities, relationships, etc. 
 */

/**
 *  MCQ -13
 *  -   Which of the following changes whenever we modify any data
 *  Options
 *      a.  Database schema
 *      b.  Database instance
 *      c.  None of the above
 *  Ans:    b
 *      -   Database instance refers to the data stored in the database at a particular         
 *          moment. On the other hand database schema is the structure of the database 
 *          and does not change if we are modifying only the data. So, if we're adding, 
 *          removing, changing the data it will only change the database instance. 
 */

/**
 *  MCQ -14
 *  -   Which of the following is/are true with reference to ‘view’ in DBMS?
 *  1.  A ‘view’ is a special stored procedure executed when a certain event occurs.
 *  2.  A ‘view’ is a virtual table, which occurs after executing a pre-compiled query.
 *  Options
 *      a.  Only 1 is true.
 *      b.  Only 2 is true
 *      c.  None
 *      d.  Both are true.
 *  Ans:    b
 *  -   A view is a subset of a database generated from a query and stored as a permanent 
 *      object. Definition of view is permanent, but the data included therein is dynamic 
 *      depending on the point at which the view is accessed. Views represent a subset of 
 *      the data contained in a table.
 */

/**
 *  MCQ -15
 *  -   Match the following:
 *      1.  Physical Level Abstraction      p)  what data is stored in Database
 *      2.  Instance                        q)  design of the database
 *      3.  Logical Level Abstraction       r)  information stored in database in particular
 *      4.  Schema                          s)  how data is stored in database
 *  Options
 *      a.  1-s,2-r,3-p,4-q
 *      b.  1-p,2-q,3-r,4-s
 *      c.  1-s,2-p,3-q,4-r
 *      d.  1-s,2-q,3-p,4-r
 *  Ans:    a
 *      -   1. Physical level abstraction is one of the lowest levels of abstraction. It    
 *          provides us with the details of complex data structures. It tells us how the 
 *          data is stored in the database.
 *          2. The instance, also known as the current state or database state, provides 
 *          us with information about what data is stored in a database at a particular 
 *          moment. 
 *          3. Logical level abstraction is the second last level of abstraction 
 *          architecture. It provides us with information about what data is stored in the 
 *          database.
 *          4. A database schema provides a logical view of the database. It is like a 
 *          skeleton structure for the database. It is also known as the design of the 
 *          database.
 */