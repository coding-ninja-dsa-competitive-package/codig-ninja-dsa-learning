/**
 *  MCQ - 1
 *  -   An index helps to speed up which operation?
 *  Options
 *      a.  SELECT queries
 *      b.  WHERE clauses
 *      c.  Both A and B    
 *      d.  UPDATE Query
 *  Ans:    c
 *  -   Indexing is a method that helps us to locate a record or data present in the 
 *      memory faster. Indexing boosts the efficiency by minimising the number of disk 
 *      accesses required when we process a query. This will help to speed up operations 
 *      with READ operations like- SELECT queries, WHERE clause etc.
 */

/**
 *  MCQ - 2
 *  -   The index consists of
 *  Options
 *      a. list of keys
 *      b. pointers to the key in the table
 *      c. both (a) and (b) 
 *      d. none
 *  Ans:    c
 *  -   The index is a data structure that we use to perform indexing. Indexes contain a 
 *      few database columns: 
 *      1.  The first column consists of a search key, which contains the copy of the 
 *          primary key of the table so that the data access time could be reduced which 
 *          means data can be accessed quickly. The order of the key may or may not be 
 *          sorted.
 *      2.  The second column is the data reference. It contains pointers holding the 
 *          address of the disk block where the value corresponding to the key is stored. 
 */

/**
 *  MCQ - 3
 *  -   Which of the following is true.
 *      1.  Sparse indices can be used only if the relation is stored in sorted order of 
 *          the search key.
 *      2.  It is generally faster to locate a record if we have a dense index rather than 
 *          a sparse index.
 *  Options
 *      a.  Only 1
 *      b.  Only 2
 *      c.  None
 *      d.  Both 1 and 2 
 *  Ans:    d
 *  -   Indexing is a method that helps us to locate the data present in the memory 
 *      efficiently.  There are two types of primary indexing:
 *      1. Sparse indexing 
 *      2. Dense indexing
 *  -   In the above question, the main focus is on the sparse indexing technique, a 
 *      variety of index columns stores an equivalent block address. When data is 
 *      retrieved, the block address is going to be fetched. That is why sparse indices 
 *      are smaller in size in comparison to dense Indices. That is why it is generally 
 *      faster to locate a record if we have a dense index rather than a sparse index. 
 *      Sparse indices can be used only if the relation is stored in the sorted order of 
 *      the search key.
 */

/**
 *  MCQ - 4 
 *  -   Primary index is further divided into dense index and sparse index. Which of the 
 *      following is true about both.
 *  Options
 *      a.  Dense index is not space friendly. 
 *      b.  Sparse index is not space friendly. 
 *      c.  Sparse index is faster than Dense index.
 *      d.  a and c
 *  Ans:    a
 */

/**
 *  MCQ - 5
 *  -   A block can hold either 6 records or 12 key pointers. A database contains 48 
 *      records, then how many blocks is required to hold the data file and the dense 
 *      index?
 *  Ans:    12
 *  -   Explanation: We know, the database contains 48 records and a block can hold 6 
 *      records or hold 12 key pointers.
 *      Therefore, how many blocks can hold 48 records?
 *          48/6 = 8
 *      Similarly, how many blocks for 12 key pointers?
 *          48/12 = 4
 *      Hence, total blocks = 8+4=12.
 */

/**
 *  MCQ - 6
 *  -   Suppose a block can hold either 5 records or 10 (key, pointer) pairs. If there 
 *      are x number of records and dense indexing is used then how many blocks do we need 
 *      to hold a data file and dense index?
 *  Ans : 3*x/10
 *  -   Explanation: Total no. of records given = x.
 *      A block can hold 5 records.
 *  -   We know in dense indexing the number of rows in the index table is the same as  
 *      those in the main table.
 *      So,How many blocks to hold x records?
 *              x/5
 *  -   Similarly, a block can hold 10 key pointers. So,
 *      How many blocks to hold x key pointers?
 *          x/10
 *      Therefore, Total blocks = x/5 + x/10 = 3*x/10  
 */

/**
 *  MCQ - 7
 *  -   Which of the following indexes is defined on an ordered data file and created on 
 *      a non-key field?
 *  Options
 *      a.  Primary index
 *      b.  Secondary index     
 *      c.  B-trees 
 *      d.  Clustering index 
 *  Ans:    d
 *  -   Clustering Index is the index that is created and ordered on the basis of the 
 *      non-primary key attributes of the table.These attributes are not unique for each 
 *      record. In Clustering index, to fetch a record we group two or more attributes 
 *      together to get the unique values and create an index out of them. Clustering 
 *      index is an ordered data file which is created on a non-key field.
 */

/**
 *  MCQ - 8
 *  -   Which of the following will be considered as multi level indexing?
 *  Options
 *      a.  Clustering indexing
 *      b.  Secondary indexing 
 *      c.  Primary Indexing
 *      d.  All of them
 *  Ans:    c
 *  -   Secondary index is taken into consideration when the size of datafile increases 
 *      i.e. when the size of the table increases, sparse indexing starts to slow down. 
 *      To overcome this we introduce another level of indexing that is known as secondary 
 *      indexing. In this, we select a huge chunk of columns initially and put it up at 
 *      the first level of indexing which is known as primary level indexing. The data of 
 *      primary level indexing is stored in primary memory. After this, each chunk is 
 *      divided into smaller ranges. This is known as the second level of indexing, this 
 *      is stored in the secondary memory along with the actual data file. Secondary 
 *      indexing is also known as multilevel indexing. 
 */

/**
 *  MCQ - 9
 *  -   Which of the following operations does indexing slows down.
 *      1. DELETE
 *      2. INSERT
 *      3. SELECT
 *      4. READ
 *  Options
 *      a.  Only 1,3
 *      b.  Only 2,4
 *      c.  Only 1,2    
 *      d.  Only 1,2,4
 *  Ans:    c
 *  -   Indexing results in the reduction of the speed of execution of write operations 
 *      in the memory. Major Write operations are INSERT, UPDATE and DELETE operations.
 */

/**
 *  MCQ - 10
 *  -   When the records of the main table are sorted on the basis of search key which is 
 *      also the primary key, and so is the order of the index table, it’s called :
 *  Options
 *      a.  Primary Indexing 
 *      b.  Secondary Indexing with key 
 *      c.  Clustered Indexing
 *      d.  Secondary Indexing with non-key
 *  Ans:    a
 *  -   When the indexing is done on the basis of the primary key of the data file it is 
 *      known as the primary indexing. During the primary indexing, the data file is 
 *      already ordered to support the primary key. Primary Index is an ordered file 
 *      whose records are of fixed length with two fields. The primary field of the index 
 *      replicates the primary key of the information entered in an ordered manner, and 
 *      therefore the second field of the ordered file contains a pointer that points to 
 *      the data block where a record containing the keys is available.
 */