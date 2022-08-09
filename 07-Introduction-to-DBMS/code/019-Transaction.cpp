/**
 *  MCQ - 1
 *  -   When dealing with transactions, any DBMS should be capable of ensuring:
 *  Options
 *      a.  Parts of a transaction are not lost due to a failure.
 *      b.  Transactions are free from interference from other users.
 *      c.  Transactions do not make the database inconsistent.
 *      d.  All of the above. 
 *  Ans:    d
 *  -   When dealing with transactions, any DBMS should be capable of ensuring that: 
 *      1. Transactions are free from interference from other users.
 *      2. Parts of transactions are not lost due to program failures.
 *      3. Transactions don’t make the database inconsistent.
 *      4. Incomplete transactions never occur in the database.
 */

/**
 *  MCQ - 2
 *  -   Which of the following is a part of ACID properties of transactions?
 *  Options
 *      a. Duration
 *      b. Atomicity
 *      c. Isolation    
 *      d. Only a,b
 *      e. Only b,c 
 *  Ans:    e
 *  -   ACID stands for:  
 *      1.  Atomicity : It is also known as the “All or nothing rule”. It ensures that 
 *          either the transaction occurs completely or it will not occur at all.
 *      2.  Consistency : It ensures that data remains consistent before and after the 
 *          transaction.
 *      3.  Isolation : It ensures that parallel transactions remain consistent when 
 *          they are converted into serializable form.
 *      4. Durability  : It ensures that data is not lost during the transactions.
 */

/**
 *  MCQ - 3
 *  -   If the system crashes just after the transaction is executed, we don’t lose the 
 *      changes made to the database due to:
 *  Options
 *      a.  Transactions endurance
 *      b.  Transactions are atomic, so they are saved
 *      c.  Durability property 
 *      d.  Isolation property, as the transaction is isolated it doesn’t get affected by 
 *          anything happening in the surroundings.
 *  Ans:    Durability property ensures all the changes or updates to the database have 
 *      been recorded and have been stored and will be never lost even if the system 
 *      crashes.
 *      On the other hand, Atomic property tells that a transaction will happen only 
 *      when it will be performed entirely or will not be executed at all. Isolation 
 *      ensures that the transactions are executing independently, i.e. when one 
 *      transaction is being done, it won’t be interrupted by the other one. However, 
 *      multiple transactions can happen simultaneously, given that each transaction is 
 *      unaware of the other concurrently executing transactions.
 */

/**
 *  MCQ - 4
 *  -   At which state is transaction considered permanent in the database?
 *  Options
 *      a.  Save
 *      b.  Committed
 *      c.  Rolled
 *      d.  Loaded
 *  Ans;    b
 *  -   When the updates are made permanent on the database, then the transaction is said 
 *      to be in the committed state. Whatever changes we make during the transaction, 
 *      the database saves that data in the hard disk and these changes are visible to the
 *      user.
 *  Note: Rollback can’t be done from here. At this state, a new consistent state is 
 *      achieved by the database.
 */

/**
 *  MCQ - 5
 *  -   In case of any shut down during transaction before commit, which of the following 
 *      statements is done automatically?
 *  Options
 *      a.  Flashback
 *      b.  Rollback 
 *      c.  Commit  
 *      d.  View
 *  Ans:    b
 *  -   In case of any shutdown during transaction before commit, the transaction shifts 
 *      from a partially committed state to a failed state. After a transaction reaches 
 *      the failed state, Rollback operations occur and it reaches the aborted state. 
 *      Rollback operation 'UNDO' the changes made during the transaction.
 */

/**
 *  MCQ - 6
 *  -   If the checks by the database recovery system fails, then the transaction is in 
 *      which state?
 *  Options
 *      a.  Active
 *      b.  Partially committed
 *      c.  Committed
 *      d.  Failed 
 *  Ans:    d
 *  -   Active State:- The very first state of the life cycle of the transaction, all 
 *      the read and write operations are being performed. If they execute without any 
 *      error the transaction comes to a ‘partially committed’ state, although if any 
 *      error then it leads to a ‘failed’ state. 
 *  -   Partially Committed State:- After the transaction is executed the changes are 
 *      saved in the buffer in Main Memory. If the changes made are permanent on the 
 *      database then the state will transfer to the ‘committed’ state and if there is 
 *      any kind of failure, The transaction will go to the ‘failed’ state.
 *  -   Committed State:- When the updates are made permanent on the database. Then the 
 *      transaction is said to be in the committed state. Rollback can’t be done from 
 *      committed states. At this state, a new consistent state is achieved by the database. 
 *  -   Failed State:- When a transaction is being executed and some failure occurs. Due 
 *      to these failures, it becomes impossible to continue the execution of a 
 *      transaction. This results in the entrance of transactions in the failed state. 
 *      The transaction can reach this state from an Active or Partially committed state. 
 */

/**
 *  MCQ - 7
 *  -   The state in which the transaction is, while it’s still executing is/are:
 *  Options
 *      a. Start
 *      b. Active
 *      c. Failed
 *      d. Partially Committed
 *      e. Only a,d
 *      f. Only b,d 
 *      g. Only b,c,d
 *  Ans:    f
 *  -   When the transaction is executing, it can only be in two states
 *      1.  Active State :- The very first state of the life cycle of the transaction, all 
 *          the read and write operations are being performed and if they execute without 
 *          any error the transaction comes to a ‘partially committed’ state, although 
 *          if any error then it leads to ‘failed’ state. 
 *      Note: All the changes made by the transaction now are stored in the buffer in the 
 *      main memory. 
 *      2.  Partially Committed State:- After the transaction is executed the changes are 
 *          saved in the buffer in Main Memory. If the changes made are permanent on the 
 *          database then the state will transfer to the ‘committed’ state and if there is 
 *          any kind of failure, The transaction will go to the ‘failed’ state
 */

/**
 *  MCQ - 8
 *  -   When a transaction doesn’t complete it’s execution successfully. We call it:
 *  Options
 *      a.  Terminated
 *      b.  Closed
 *      c.  Failed
 *      d.  Aborted 
 *  Ans:    d
 *  -   Aborted State: When the transaction reaches the failed state, all the changes 
 *      made in the buffer are reversed. After that the transaction rollback completely. 
 *      The transaction reaches an aborted state after that. After reaching the aborted 
 *      state, the failed transaction get removed from the database 
 */