/** 
 *  NoSQL:
 *  -----
 *  -   Types of NoSQL Databases:
 *      -   Key/Value Database: stores data in pairs.
 *              Example: Redis
 *      -   Document Database:  RDBMS (relationship) + NOSQL (dynamic schema)
 *              Example : Mongo Database
 *      -   Columnar Database:  columns are stored together. 
 *             -    Aggregations are very fast like minimum salry.
 *             Example: Cassandra
 *      -   Graph Database: Combination of vertex & edges for defining relationship
 *              Example: Linkedin (1st degree, 2nd degree, 3rd degree connection).
 *              Example: Neo4J 
 */

/**
 *  Choose the correct option
 *  -   Which of the following are true for file-based storage systems?
 *  Options     
 *      a.  It has in-built high security features
 *      b.  It leads to data redundancy and inconsistency
 *      c.  It provides high data integrity
 *      d.  All of the above
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   If you are provided with a large number of confidential user details, a File-Based 
 *      storage system should be used to store it.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    b
 *  -   Since file-based storage systems do not inherently provide data security features, 
 *      confidential information should not be stored in them
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true?
 *  Options
 *      a.  DBMS is a set of programs that helps a user to create and maintain a database.
 *      b.  DBMS can be used to perform operations such as insert, update , delete and 
 *          retrieve.
 *      c.  DBMS is a hardware unit for managing tables.
 *      d.  DBMS helps a user to overcome issues of data redundancy and inconsistency.
 *  Ans:    a, b, d
 */

/**
 *  Choose the correct option
 *  -   Which of the following has a quicker response to query data?
 *  Options
 *      a.  File based storage system
 *      b.  RDBMS
 *  Ans:    b
 *  -   RDBMS provides us with query language to quickly  retrieve the data or some part 
 *      of it.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true?
 *  Options
 *      a.  DBMS stores data in files while RDBMS stores data in tables.
 *      b.  DBMS hardware and software requirements are usually higher than RDBMS 
 *          requirements.
 *      c.  DBMS is used by a single user whereas RDBMS can be used by multiple users.
 *      d.  RDBMS supports client server architecture.
 *  Ans:    a, c, d
 */

/**
 *  Choose the correct option
 *  -   Which of the following NoSQL database is usually used for caching solutions?
 *  Options
 *      a.  Columnar databases
 *      b.  Document databases
 *      c.  Key value databases 
 *      d.  Graph databases
 *  Ans:    c
 */

/**
 *  Practice Question
 *  -   Guess the type of NoSQL database that should be used for the following parts.       
 *      Please choose answer between :
 *          Key-value database
 *          Document database
 *          Columnar Database
 *          Graph database
 *      
 *  Part A  
 *  -   To store data as collections, dictionaries, associative arrays.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    a
 *  -   A key-value store, or key-value database is a simple database that uses an 
 *      associative array (think of a map or dictionary) as the fundamental data model 
 *      where each key is associated with one and only one value in a collection. This 
 *      relationship is referred to as a key-value pair.
 *  
 *  Part B
 *  -   For blogging applications.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    b
 *  -   A document database is a great choice for content management applications such as 
 *      blogs and video platforms. With a document database, each entity that the 
 *      application tracks can be stored as a single document. The document database is 
 *      more intuitive for a developer to update an application as the requirements evolve. 
 *      In addition, if the data model needs to change, only the affected documents need 
 *      to be updated. No schema update is required and no database downtime is necessary 
 *      to make the changes. 
 *  
 *  Part C
 *  -   To store web pages as documents for an e-commerce product catalogue.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    b
 *  -   The document model works well with use cases such as catalogs, user profiles, and 
 *      content management systems where each document is unique and evolves over time. 
 *      Document databases enable flexible indexing, powerful ad hoc queries, and analytics 
 *      over collections of documents.
 * 
 *  Part D
 *  -   For social networks.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    d
 *  -   Graph databases such as Neo4j offer possibilities when it comes to creating 
 *      innovative social networks or integrating current social graphs into an 
 *      enterprise application. Social media networks are already graphs, so there’s no 
 *      point converting a graph into tables and then back again. Having a data model that 
 *      directly matches your domain model helps you better understand your data, 
 *      communicate more effectively and avoid needless work.
 * 
 *  Part E
 *  -   Shopping cart content for e-commerce application.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar Database   
 *      d.  Graph Database
 *  Ans:    a
 *  -   The key-value database can be used for storing cart content. If we wanted to 
 *      store user session data, shopping cart information, and user preferences, we could 
 *      just store all of them in the same bucket with a single key and single value for 
 *      all of these objects. 
 *  
 *  Part F
 *  -   To manage a data warehouse.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar Database
 *      d.  Graph Database
 *  Ans:    c
 *  -   A columnar database stores data by columns rather than by rows, which makes it 
 *      suitable for analytical query processing, and thus for data warehouses.
 *  
 *  Part G
 *  -   Online multiplayer games.
 *  Options
 *      a.  Key-value database
 *      b.  Document database   
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    b
 *  -   Document databases have flexible schema means that you can change your data layer 
 *      just as quickly as you change your game. Document database's flexible document 
 *      data model allows you to quickly iterate on what constitutes a player in your world. 
 *  
 *  Part H
 *  -   Application like google maps , storing connections between different paces.
 *  Options
 *      a.  Key-value database
 *      b.  Document database
 *      c.  Columnar database   
 *      d.  Graph database
 *  Ans:    d
 *  -   The entire premise of Google Maps is using a big giant graph with nodes and edges 
 *      to figure out the fastest or shortest way to travel. That’s all Google Maps is–a 
 *      big graph with lots of nodes and edges. Having a data model that directly matches 
 *      your domain model helps you better understand your data, communicate more 
 *      effectively and avoid needless work
 *  
 *  Part I
 *  -   Create leaderboard for online games
 *  Options
 *      a.  Key-value database
 *      b.  Document database   
 *      c.  Columnar database
 *      d.  Graph database
 *  Ans:    a
 *  -   We can use a key-value database for creating a leaderboard for online games. For 
 *      the Leaderboard implementation, the user_id is a unique field, it makes a great 
 *      candidate in becoming the Key of the sorted set. The number of points will be the 
 *      Score(value).
 */ 


/**
 *  Assignment
 *  -   Suppose you are building a photo-sharing application like Instagram. Answer the 
 *      following questions:
 *  
 *  Part A
 *  -   Do you think such a large scale application can be built using only one kind 
 *      of database?
 *  Ans:    No, in the majority of cases multiple DBs are used for different functions 
 *          of an application.
 *  
 *  Part B
 *  -   Can we use relational and NoSQL databases in the same system?
 *  Ans:    Yes, they can be used for a single system.
 * 
 *  Practice Question 3.
 *  -   For the same photo-sharing application, select the database that should be 
 *      preferred for the following features. (Choose between a Relational or Nosql 
 *      database)
 *  
 *  Part C
 *  -   Which database should be preferred to store the photos?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    b
 *  
 *  Part D
 *  -   Which type of database should be used to store login information?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    a
 *  -   1st is the correct answer.
 *      -   A relational Database can be used here. The fundamental relationship between 
 *          a user id and the data you need to look up can usually be done with a single 
 *          table in some SQL based system without a join. If you need to do more to the 
 *          data then look it up by user id (or possibly name) and retrieve a single 
 *          record (or very small group of records) using indexing. 
 *      -   Relational databases have four important ACID properties: Atomicity, 
 *          Consistency, Isolation and Durability. Here,
 *      -   The four properties are:
 *          -   Atomic: Guarantees that all operations in a transaction are treated as a 
 *              single “unit”, which either succeeds completely or fails completely.
 *          -   Consistent: Ensures that a transaction can only bring the database from 
 *              one valid state to another by preventing data corruption.
 *          -   Isolation: Determines how and when changes made by one transaction become 
 *              visible to the other. 
 *          -   Durable: Ensures that the results of the transaction are permanently stored 
 *              in the system. The modifications must persist even in case of power loss 
 *              or system failures.
 *  
 *      -   The Benefits of ACID Transactions in storing login information:
 *          -   Absolute Data Integrity and Safety: Avoiding lost updates, dirty reads, 
 *              stale reads, and enforcing app-specific integrity constraints
 *          -   Intuitive Data Access Logic: ACID-compliant databases usually allow 
 *              complex schema modelling and native support for multi-step data 
 *              manipulation operations such as consistent secondary indexes. 
 *  
 *  Part E
 *  -   Which type of database should be used to run analytics on the huge amount of user 
 *      data generated?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    b
 *  
 *  Part F
 *  -   Which type of database should be used to implement cache to maintain low latency 
 *      for frequently accessed data?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    b
 *  
 *  Part G
 *  -   Which type of database should be used to set up a payment system within the 
 *      application?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    a
 * 
 *  Part H
 *  -   Which type of database should be used to run a recommendation system to keep 
 *      users engaged?
 *  Options
 *      a.  Relational Database
 *      b.  NoSQL Database
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   A normalised database is a starting point of the denormalization process.
 *  Options
 *      a.  True    
 *      b.  False
 *  Ans:    a
 *  -   Denormalization is the process of adding redundant data in the normalised 
 *      relational database to optimise the performance.
 */

/**
 *  Choose the correct option
 *  -   Which of the following are the benefits of denormalisation?
 *  Options
 *      a.  It can enhance query performance by reducing the number of joins
 *      b.  It can help in accelerating reporting as all the data is easily accessible
 *      c.  It can reduce the number of network calls to fetch data from multiple places
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   What can be the challenges of denormalisation?
 *  Options
 *      a.  May lead to wastage of memory
 *      b.  May lead to more number of foreign keys
 *      c.  Due to data duplication, the data might become inconsistent
 *      d.  It may lead to faster write operations, if the number of writes are high    
 *  Ans:    a, c
 */

/**
 *  Assignment
 *  -   Suppose we have an online bookstore database and it has two tables: books and 
 *      warehouse.
 *  -   Books table contains information such as BookId, Bookname, Warehouse_ID, Quantity.
 *  -   Similarly, the warehouse table contains Warehouse_ID, Address. Using this 
 *      information answer the following questions.
 * 
 *  Part A
 *  -   What if we require the information of the books and where they are stored to get    
 *      them ready for delivery. This would require the warehouse address, which is 
 *      stored in a different table.How to get this data?
 *  Ans:    We would require to join the two tables
 *  
 *  Part B
 *  -   What if the books table has a huge amount of data, millions of entries. Will join 
 *      still be an optimal solution?
 *  Ans:    The performance of the system may decrease due to performing joins on large 
 *          amounts of data.
 *  
 *  Part C
 *  -   Can denormalisation be used in this scenario?
 *  Ans:    Yes
 * 
 *  Part D
 *  -   What should be done?
 *  Ans:    If we add the address of the warehouse within the book table there would be 
 *          no need to perform huge join operations.
 */