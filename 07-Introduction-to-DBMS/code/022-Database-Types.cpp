/**
 *  MCQ - 1
 *  -   Choose the correct option to fill in the blanks.
 *      Database __________ is the logical design of the database, and the database_______
 *      ____ is a snapshot of the data in the database at a given instant in time.
 *  Options
 *      a.  Instance, Schema
 *      b.  Relation, Schema
 *      c.  Relation, Domain
 *      d.  Schema, Instance 
 *  Ans:    d
 *  -   A database schema provides a logical view of the database. It is like a skeleton 
 *      structure for the database. A database schema is also known as the design of the 
 *      database. The database instance is also known as the current state or database 
 *      state. Database instance provides us with information about what data is stored 
 *      in a database at a particular moment.
 */

/**
 *  MCQ - 2
 *  -   Which of the following is TRUE regarding Referential Integrity?
 *  Options
 *      a.  Every primary-key value must match a primary-key value in an associated table
 *      b.  Every foreign-key value must match a primary-key value in an associated table 
 *      c.  Every foreign-key value must match a foreign-key value in an associated table
 *      d.  Every primary-key value must match a foreign-key value in an associated table
 *  Ans:    b
 *  -   Referential Integrity Constraint specifies that all the values taken by the 
 *      foreign key must either be available in relation to the primary key or be null. 
 */

/**
 *  MCQ - 3
 *  -   Which of the following is true concerning an OODBMS?
 *  Options
 *      a.  They are overtaking RDBMS for all applications.
 *      b.  They have the ability to store complex data types on the Web. 
 *      c.  They are most useful for traditional, two-dimensional database table 
 *          applications.
 *      d.  None of the above
 *  Ans:    b
 *  -   Explanation: OODBMS can handle complex data relations and more variety of data 
 *      types than standard relational databases.
 */

/**
 *  MCQ - 4
 *  -   Which of these is most like a hierarchical database?
 *  Options
 *      a.  Spreadsheet
 *      b.  Family tree 
 *      c.  Book
 *      d.  All of the above
 *  Ans:    b
 *  -   In the hierarchical database, the data is stored in the form of records and 
 *      organised into a tree-like structure, in which a node can have as many sub-nodes 
 *      as it wants, connected through edges. Some examples of hierarchical databases are 
 *      IBM’s Information Management System (IMS) and the RDM Mobile. Hierarchical 
 *      Databases structurally look like a family tree.
 */

/**
 *  MCQ - 5
 *  -   What is the basic relationship in a hierarchical database?
 *  Options
 *      a.  Siblings
 *      b.  Grandparent-grandchild
 *      c.  Data is not related
 *      d.  Parent-child 
 *  Ans:    d
 *  -    The hierarchical database model mandates that every child record has just one 
 *      parent, whereas each parent record can have one or more child records. so as to 
 *      retrieve data from a hierarchical database, the entire tree must be traversed 
 *      ranging from the basis node.
 */

/**
 *  MCQ - 6
 *  -   Network models are complicated by physical keys, but the Relation model is :
 *  Options
 *      a.  faster because it uses logical keys 
 *      b.  slower because it uses physical keys
 *      c.  faster because it uses physical keys
 *      d.  slower because it uses logical keys
 *  Ans:    a
 *  -   Explanation: logical keys here refer to primary key and foreign key which 
 *      are more apt for relational models to work.
 */

/**
 *  MCQ - 7
 *  -   A network structure __________.
 *  Options
 *      a.  is conceptually simple
 *      b.  is a physical representation of the data    
 *      c.  allows a many-to-many relationship 
 *      d.  will be the dominant database of the future
 *  Ans:    c
 *  -   A network database is a modified form of hierarchical database in which a member 
 *      entity (similar to child entity in a hierarchical database) can have multiple 
 *      relations with different owner entities (similar to parent entity in hierarchical 
 *      database). Hence allowing a many-to-many relationship. 
 */