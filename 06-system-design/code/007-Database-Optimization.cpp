/**
 *  Choose the correct option
 *  -   If we index a column in a table then a lookup table is created with a column 
 *      and ______ to the memory location where the row with this column is actually 
 *      stored.
 *  Options 
 *      a.  Pointer 
 *      b.  Key
 *      c.  Table
 *      d.  Array
 *  Ans:    a
 *  -   Indexing creates a lookup table with the column and the pointer to the memory 
 *      location of the row, containing this column.
 */

/**
 *  Choose the correct option
 *  -   Which data structure is most commonly used for indexing?
 *  Options
 *      a.  Linked List
 *      b.  B Trees
 *      c.  Arrays
 *      d.  Stack
 *  Ans:    b
 *  -   B-trees data structure  is used to store the indexing
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  Index can be created on one or more columns 
 *      b.  Indexing helps to speed up query execution 
 *      c.  Indexing should be created on columns which are frequently updated
 *      d.  All of the above
 *  Ans:    a, b
 *  -   Indexing helps small, fast, and optimized quick lookups. The columns generally 
 *      used for lookup rows like Primary key columns can be indexed. Columns that are 
 *      frequently updated and manipulated should not be indexed as it would require 
 *      excessive maintenance. 
 */

/**
 *  Choose the correct option
 *  -   Indexing should not be used when :
 *  Options
 *      a.  When the tables are small and write intensive 
 *      b.  When the tables are huge and read intensive
 *      c.  When the tables are huge and write intensive 
 *  Ans:    a, c
 *  -   Indexing small tables may not be optimal because it can take the query optimizer 
 *      longer to traverse the index searching for data than to perform a simple table 
 *      scan. Indexing should only be used if the data is huge and the application is 
 *      read-intensive.If an application is write intensive indexing might lower the 
 *      performance of write operations.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  Indexing slows down the performance of the Insert and Update statements
 *      b.  Indexing speeds up the Select statement
 *      c.  It avoids full table scan hence retrieval of data is fast
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   When should partitioning be done?
 *  Options
 *      a.  When data is huge and single server cannot hold all the data
 *      b.  When there are large number of concurrent users leading to high response time
 *      c.  Both A and B
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Partitioning of a Database into multiple machines usually leads to:
 *  Options
 *      a.  Increase the availability of data
 *      b.  Reduce the scalability of application
 *      c.  Improve the manageability of data
 *      d.  Load balancing of an application
 *      e.  Speed up query response time
 *  Ans:    a, c, d, e
 */

/**
 *  Choose the correct option
 *  -   Horizontal partitioning is also known as:
 *  Options
 *      a.  Range-based partitioning
 *      b.  Physical partitioning
 *      c.  Horizontal sharding
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true?
 *  Options
 *      a.  A shard is a vertical partition of the database
 *      b.  Database shards are autonomous and do not share any computing resources
 *      c.  Range based partition may lead to unbalanced partitioning of database
 *      d.  Sharding may add complexity to the system as they are located on different machines
 *      e.  Benefits of replication are achieved through sharding a database
 *  Ans:    b,c ,d
 */

/**
 *  Choose the correct option
 *  -   Each shard has the same schema as the original database in horizontal partitioning. 
 *      State whether the following statement is true or false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for vertical partitioning?
 *  Options
 *      a.  It may lead to slow join queries    
 *      b.  Further partitioning may be required as the partitions grows in size 
 *      c.  Referential Integrity may become issue
 *      d.  Each shard has the same schema as the original database
 *  Ans:    JOIN operations are required to get data from different shards which may lead 
 *      to slower join queries. Further partitioning is required when one of the parts 
 *      again goes larger than it has to be partitioned again.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true for directory-based partitioning?
 *  Options
 *      a.  It leads to loosely coupled application
 *      b.  It leads to horizontally scalable application   
 *      c.  It leads to tightly coupled application
 *      d.  It leads to vertically scalable application 
 *  Ans:    a, b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true?
 *  Options
 *      a.  Directory server can act as Single point of failure
 *      b.  It is very easy in implementation
 *      c.  Directory server has the mapping of each record with their corresponding servers
 *      d.  Slower join operation
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which function is used to perform hash based partitioning?
 *  Options
 *      a.  key /number of servers
 *      b.  key %number of servers  
 *      c.  key *number of servers
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true for key-based partitioning?
 *  Options
 *      a.  Dynamic adding or removing of servers becomes difficult
 *      b.  Whenever servers are added or removed, the hash function remains the same
 *      c.  After a server is added or removed, data migration might not be required
 *      d.  When the migration of data isin process, neither the new or the old hash 
 *          function is fully valid    
 *      e.  An application may suffer down time when the migration of data is in process
 *  Ans:    a, d, e
 */

/**
 *  Choose the correct option
 *  -   Which of the following partitioning criteria ensures the even distribution of data ?
 *  Options
 *      a.  List partitioning
 *      b.  Key partitioning
 *      c.  Round robin partitioning
 *  Ans;    c
 */

/**
 *  Practice Question
 *  -   Out of key-based, range-based and directory-based which partitioning is more 
 *      flexible and why? (Answer in lower case with a hyphen in between words)
 *  Ans:    directory-based
 *  -   Directory-based is more flexible than the other two as in key-based partitioning 
 *      we need to use a hash function that cannot be modified frequently. In range-based 
 *      partitioning, the values of ranges are decided which cannot be modified. But, in 
 *      directory-based partitioning we can use any algorithm to assign data in the 
 *      shards,  it is a more dynamic approach and hence more flexible.
 */

/** 
 *  Choose the correct option
 *  -   Which of the following is/are true for consistent hashing?
 *  Options
 *      a.  Works particularly well when the number of machines storing data may change
 *      b.  Redistribution of data on all the servers is required when a server is added or removed
 *      c.  Minimum amount of data is moved when a server is added or removed       
 *      d.  Availability of the application is higher in comparison to traditional hashing
 *  Ans:    a, c, d
 */

/**
 *  Practice Question
 *  -   What partitioning strategy should be used if a large amount of details is to be 
 *      stored of the car models manufactured by a company?
 *  Ans:    The details of cars can be stored by using range based/horizontal partitioning 
 *      on the database and the range for each shard can be decided on the first letter of 
 *      the name of the car model, such as A-F, G-L, M-R, S-Z.
 */

/**
 *  Practice Question
 *  -   What partitioning strategy should be used if data has to be stored for a social 
 *      media application that has user profiles, posts uploaded, number of comments on 
 *      posts etc? And how?
 *  Ans:    Vertical partitioning can be used for such data as different attributes of an 
 *      entity can be split into different shards over multiple machines. Eg: user 
 *      profiles can be stored in one shard, posts uploaded in another, comments on     
 *      another etc.This helps in handling critical (user information) and non critical 
 *      data(posts, comments) independently. 
 */