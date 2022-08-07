/**
 *  MCQ - 1
 *  -   Which of the following is a sequence of SQL operations which are treated as a   
 *      single unit of work:
 *  Options
 *      a.  Database
 *      b.  Transaction 
 *      c.  Session
 *      d.  SQL workbench
 *  Ans:    b
 *  -   A transaction is a sequential group of queries, statements, or operations such as 
 *      update, select, insert or delete to perform as a one single work unit that can be 
 *      committed or rolled back. 
 */

/**
 *  MCQ - 2
 *  -   Which command performs the end of a successful transaction.
 *  Options
 *      a.  COMMIT TRANSACTION 
 *      b.  ROLLBACK TRANSACTION
 *      c.  COMMIT WORK
 *      d.  All of the mentioned
 *  Ans:    b
 *  -   There is mainly four types of TCL Command:  
 *      1.  BEGIN TRANSACTION: This TCL command basically starts the transaction.
 *      2.  COMMIT TRANSACTION: This TCL command makes changes done to the transaction 
 *          permanent. It saves all the changes done to a transaction.
 *      3.  ROLLBACK TRANSACTION: This TCL commands uncommit or cancels all the changes 
 *          done to a transaction and restores the current state to any previously saved 
 *          state.
 *      4.  SAVEPOINT TRANSACTION: This TCL command saves the current state into a saving 
 *          point. That savepoint can later be accessed. 
 */

/**
 *  MCQ - 3
 *  -   You can roll back after performing the commit in MySQL.
 *  Options
 *      a.  True
 *      b.  False
 *      c.  Depends on the Transaction
 *  Ans:    b
 *  -   DBMS transactions have many queries, but there are no queries that will 'undo' 
 *      the committed changes done to the transaction. Unless the user has a  backup of a 
 *      database, the user cannot Rollback after performing a Commit on SQL.
 */

/**
 *  MCQ - 4
 *  -   Suppose we have created a savepoint named Spt1, which of the following commands 
 *      can be used to rollback the transactions executed after creating the savepoint :
 *  Options
 *      a.  RELEASE SAVEPOINT Spt1
 *      b.  COMMIT Spt1
 *      c.  ROLLBACK TO Spt1 
 *      d.  ROLLBACK
 *  Ans:    c   
 *  -   ROLLBACK transaction - This TCL commands undo all the changes or restore the 
 *      current state to any previously saved state. 
 *  -   General form: 
 *          ROLLBACK:  This rollback the previously committed command to its initial state
 *          ROLLBACK TO savepoint: This undoes the current state and restores it to the 
 *              savepoint
 */

/**
 *  MCQ - 5
 *  -   Which of the following is the query to apply Read Lock on table Employees.
 *  Options
 *      a.  LOCK TABLE Employees READ; 
 *      b.  LOCK TABLE Employees READ|WRITE;
 *      c.  LOCK TABLE Employees PRIORITY READ;
 *      d.  LOCK TABLE Employees READ ONLY;
 *  Ans:    a
 *  -   READ LOCK allows a user to only read the data from a table. 
 *      The syntax for READ LOCK is  LOCK TABLES T_name READ
 */

/**
 *  MCQ - 6
 *  -   Choose the correct command to view the operations currently being performed by MySQL.
 *  Options
 *      a.  SHOW WAITLIST;
 *      b.  SHOW PROCESSLIST; 
 *      c.  SHOW OPERATIONS;
 *      d.  None
 *  Ans:    b
 *  -   The 'SHOW PROCESSLIST' command in MySQL displays all the running threads or 
 *      processes information associated with the current user account. This command is 
 *      extremely useful when the MySQL server returns too many connection error messages.
 */

/**
 *  MCQ - 7
 *  -   Which of the following written queries will produce error when working in the 
 *      same session.
 *      Table: cricket(Id integer, Name varchar, Position varchar, Status integer)
 *  Options
 *      a.  LOCK TABLE cricket READ; INSERT INTO cricket(‘score’) VALUES('200’); 
 *      b.  LOCK TABLE cricket WRITE; INSERT INTO cricket(‘score’) VALUES('200’);       
 *      c.  LOCK TABLE cricket READ; SELECT * FROM cricket;
 *      d.  None
 *  Ans:    a
 *  -   READ LOCK: This lock allows a user to only read the data from a table. 
 *      WRITE LOCK: This lock allows a user to do both reading and writing on a table.
 *  -   In the query, LOCK TABLE cricket READ; INSERT INTO cricket(‘score’) VALUES('200’):  
 *      we applied READ LOCK on the cricket table and in the next query the INSERT 
 *      operation is done which is basically a write operation. This will result in an 
 *      error as when we READ LOCK, we can only do READ operation 
 *  -   In other options, B, C, D, ee have done READ operation after READ LOCK, and 
 *      WRITE operation after WRITE LOCK, hence they would not have error.
 */