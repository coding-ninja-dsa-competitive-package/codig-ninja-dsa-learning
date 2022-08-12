/**
 *  MCQ - 1
 *  -   A transaction can proceed only after the concurrency control manager ________ the   
 *      lock to the transaction.
 *  Options
 *      a.  Acquires
 *      b.  Allocates
 *      c.  Grants 
 *      d.  None
 *  Ans:    c
 *  -   A transaction can proceed only after the concurrency control manager grants the lock 
 *      to the transaction. 
 */ 

/**
 *  MCQ - 2
 *  -   Which of the following concurrency control protocols ensure both conflict 
 *      serializability and free from deadlock?
 *  Options
 *      a. Timestamp ordering
 *      b. 2 Phase locking
 *      c. Both (a) and (b)
 *      d. None
 *  Ans:    a
 *  -   2-phase locking is a concurrency control method that ensures conflict 
 *      serializability. The protocol utilizes locks, applied by a transaction to data, 
 *      which may block other transactions from accessing the same data during the 
 *      transaction’s life. The timestamp-based concurrency control algorithm is a 
 *      non-lock concurrency control method. This method also ensures conflict 
 *      serializability.
 *  -   We know that deadlock is a situation where the transactions try to access lock 
 *      on already locked data items. So, 2 phase locking may lead to deadlock states 
 *      that can result in the mutual blocking of two or more transactions.
 *  -   But in timestamp, each transaction is allocated with the time slot. Hence it 
 *      can’t enter a deadlock. So Timestamp ordering ensures both the conflict 
 *      serializability and is free from deadlocks
 */ 

/**
 *  MCQ - 3
 *  -   Concurrency control in RDBMS is important for which of the following reasons ?
 *  Options
 *      a.  To ensure data integrity when updates occur to the database in a single -user environment.
 *      b.  To ensure data integrity when reads occur to the database in a single-user environment.
 *      c.  To ensure data integrity when updates occur to the database in a multi-user environment.
 *      d.  To ensure data integrity when reads occur to the database in a multi-user environment.
 *  Ans:    c
 *  -   Concurrency control is the management procedure that controls concurrent execution 
 *      of the multiple operations done by multiple users at the same time on the same 
 *      database. We need concurrency control to manage these concurrent executions of 
 *      the operations and help maintain consistency in the database
 */ 

/**
 *  MCQ - 4
 *  -   Consider the transactions:
 *          T1, T2, T3
 *          Read(X), Read(Z), Read(X)
 *          Write(Y), Write(W), Write(P)
 *          Write(Z), Read(X)
 *      Which of these is are in conflict?
 *  Options
 *      a.  T1 and T2, T1 and T3
 *      b.  T1, T2 and T3
 *      c.  T1 and T3, T2 and T3
 *      d.  T1 and T2
 *  Ans:    d
 *  -   Two operations are said to be conflicting if all conditions satisfy: 
 *      1. They belong to different transactions.
 *      2. They operate on the same data item.
 *      3. At Least one of them is a write operation.
 *  -   We can see that T1 is reading X and writing on Y and Z . Similarly T2 is 
 *      reading Z and X plus writing on W. We can notice that both the transactions have 
 *      Z in common, which can lead to conflict. While X is also common for both the 
 *      transactions, it would not lead to conflict as both T1 and T2 are only performing 
 *      read on it
 */ 

/**
 *  MCQ - 5
 *  -   Which of the following Concurrency controls is prone to deadlocks.
 *  Options
 *      a. Timestamp Based Concurrency Control
 *      b. Lock Based Concurrency Control   
 *      c. Both (a) and (b)
 *      d. None
 *  Ans;    b
 *  -   Explaination: Deadlock, a situation where the transactions try to access lock on 
 *      already locked data items. Whereas in timestamp, each transaction is allocated  
 *      with the time slot. Hence it can’t enter a deadlock.
 */ 

/**
 *  MCQ - 6
 *  -   Which of the following is not an advantage of database clustering?
 *  Options
 *      a.  Load Balancing
 *      b.  Data Redundancy
 *      c.  Increased Availability
 *      d.  Decreased Availability 
 *  Ans:    d
 *  -   Clustering is the process of combining more than one server or instance holding 
 *      the same database. We can say a cluster is a set of replicated servers.     
 *  -   Clustering helps us with a lot of features like
 *      1.  Data Redundancy: Clustering databases helps with data redundancy, as we store 
 *          the same data at multiple servers. The redundancy that clustering offers is 
 *          required and is quite certain due to the synchronization. 
 *      2.  Load Balancing: Clustering of databases also helps the servers with the load 
 *          balancing i.e., if there’s only one server and there are a lot of requests 
 *          coming in to access the database then it may become difficult for a server 
 *          to handle all the requests. Clustering helps to reduce load balancing.
 *      3.  Increased Availability: An availability of a database is defined as the time 
 *          when we can access the database. Now as we have clusters of servers available, 
 *          even if one of the databases is going through a transaction, now the other 
 *          servers can be used to access the database with the help of a load balancer. 
 *          Also, even if a server fails, the database will be available. Hence, due to 
 *          clustering, the databases have high availability.
 */ 

/**
 *  MCQ - 7
 *  -   Database uses _________ to support deployments with very large data sets by 
 *      dividing the data over multiple servers.
 *  Options
 *      a. Replication
 *      b. Sharding
 *      c. Both (a) and (b)
 *      d. None
 *  Ans:    b
 *  -   Sharding is a method of partitioning and storing a single logical set of data in 
 *      multiple databases which is stored on multiple servers. It is an extension of 
 *      horizontal partitioning. Databases use sharding to support deployments with very 
 *      large data sets by dividing the data over multiple servers.
 */ 

/**
 *  MCQ - 8
 *  -   Partitioning of the database is usually committed when:
 *  Options
 *      a. Dealing with huge dataset, which one server alone cannot handle.
 *      b. The requests to database access are taking longer time to be accepted i.e. 
 *          long response time.
 *      c. Both (a) and (b)
 *      d. None of the Above
 *  Ans:    c
 *  -   Partitioning is a technique that is used to divide stored database objects into 
 *      separate servers. Due to this, there is an increase in performance as well as 
 *      the increase in controllability of the data. We can manage huge chunks of data 
 *      optimally. Partitioning is committed when we are dealing with a huge dataset or 
 *      the request are taking more time than expected.
 */ 

/**
 *  MCQ - 9
 *  -   Some of the columns of a relation are at different sites in which of the following 
 *      techniques?
 *  Options
 *      a.  Data Replication
 *      b.  Horizontal Partitioning
 *      c.  Vertical Partitioning   
 *      d.  Horizontal and Vertical Partitioning
 *  Ans:    c
 *  -   To partition the data they are two techniques: 
 *      1.  Vertical Partitioning: In this, we partition the given data vertically i.e 
 *          column-wise. So, if we are provided with table students with attributes 
 *          student id, name, courseid, address, we can store this data by distributing 
 *          it among servers where we store studentid, name is one server, courseid in 
 *          another and address in the third one. 
 *      2.  Horizontal Partitioning: In this, we partition the given data horizontally 
 *          i.e. row-wise. So, have chunks of a certain size of data stored at different 
 *          servers. 
 */ 

/**
 *  MCQ - 10
 *  -   A distributed database is which of the following?
 *  Options
 *      a.  A loose collection of file that is spread to multiple locations and is 
 *          interconnected by a network.
 *      b.  A loose collection of file that is limited to one location.
 *      c.  A single logical database that is limited to one location.
 *      d.  A single logical database that is spread to multiple locations and is 
 *          interconnected by a network.
 *  Ans:    d
 *  -   A distributed database is not limited to at least one system, it covers different 
 *      sites, i.e, on multiple computers or over a network of computers. A distributed 
 *      database system is found on various sites that don’t share physical components. 
 *      This might be required when a specific database must be accessed by various users 
 *      globally. It must be managed in such a way that for the users it's like one single 
 *      database.
 */ 

/**
 *  MCQ - 11
 *  -   Which of the following is true about the process of sharding?
 *  Options
 *      a. RDBMS locking method
 *      b. Extension of Horizontal Partition
 *      c. Technique for partitioning the data
 *      d. both (b) and (c)
 *  Ans:    d
 *  -   Sharding is a method of partitioning and storing a single logical set of data in 
 *      multiple databases which is stored on multiple servers. It is an extension of 
 *      Horizontal partitioning. The smaller chunks of the data that are created after 
 *      shrading are called Shards.
 */ 
