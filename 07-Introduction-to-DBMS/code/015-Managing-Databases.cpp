/**
 *  MCQ - 1
 *  -   Choose the query which should be used to create a Database while also being 
 *      careful of duplication.
 *  Options
 *      a.  CREATE DATABASE Market;
 *      b.  CREATE DATABASE IF NOT EXISTS Market; 
 *      c.  CREATE DATABASE UNIQUE Market;
 *      d.  CREATE DATABASE IF EXISTS Market;
 *  Ans:    b
 *  -   To create a database, we always use the CREATE keyword in SQL. If we want to 
 *      create a database that will be careful of duplication, we should use the IF NOT 
 *      EXIST keyword. If we try to create a database that already exists and does not 
 *      mention IF NOT EXISTS, then an error would be thrown. 
 */

/**
 *  MCQ - 2
 *  -   Which DDL command is used to permanently delete the database.
 *  Options
 *      a.  DELETE
 *      b.  TRUNCATE
 *      c.  DROP 
 *      d.  REMOVE
 *  Ans:    c
 *  -   When the user has to delete a whole database or just a table DROP keyword is used 
 *      to accomplish that. The DROP statement is used to destroy objects like an existing 
 *      database, table, index, or view. 
 */

/**
 *  MCQ - 3
 *  -   What does The DROP DATABASE statement return?
 *  Options
 *      a.  Total number Rows deleted
 *      b.  Total number Data points deleted
 *      c.  Total number of columns deleted
 *      d.  Total number of tables deleted. 
 *  Ans:    DROP DATABASE returns the total number of tables deleted. The DROP statement 
 *      is used when the user has to delete a whole database or just a table. The DROP 
 *      statement is used to destroy objects like an existing database, table, index, 
 *      or view.
 */