/**
 *  Factors Impacting Consistency:
 *  -----------------------------
 *  -   We need to stop the read, while all the replica are getting updated.
 *  -   By improving the network bandwidth, This will help us to quickly 
 *      synchronize the replica.
 *  -   Replica should be chosen based on distance aware strategies.
 *  
 *  CAP Theorem:
 *  -----------
 *  -   C : Consistency , A : Availability, P : Partition Tolerance
 */

/**
 *  Choose the correct option   
 *  -   What do you mean by consistency?
 *  Options
 *      a.  When the application is never down
 *      b.  When there is no lag in the response
 *      c.  When each client gets the same data 
 *      d.  When the data is always available to the client
 *  Ans:    c
 */

/**
 *  Choose the correct option   
 *  -   What leads to dirty read?
 *  Options
 *      a.  Slow processing of data
 *      b.  Reading old data 
 *      c.  Reading latest data
 *      d.  Writing old data 
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Why do you think Monolithic systems are natively consistent?
 *  Options
 *      a.  Less clients can read data
 *      b.  Data is present on a single machine
 *      c.  Code is comparatively simple
 *      d.  Less network calls
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true about improving consistency?
 *  Options
 *      a.  In distributed systems, we should stop the write operation while the 
 *          replica systems are getting updated.
 *      b.  In distributed systems, we should stop the read operation while the 
 *          replica systems are getting updated.
 *      c.  Reducing the network bandwidth.
 *      d.  Data centres should not be situated near to each other.
 *  Ans:    b
 */

/**
 *  Practice Question
 *  -   Can you think of the implications if the online banking applications are 
 *      not consistent?
 *  Ans:    Let us consider a case to understand it. Suppose a person withdraws all 
 *          the money from his bank account. The bank should update this transaction 
 *          into its database and all the other branches of the bank so that 
 *          everyone gets the same accurate information and does not allow any more 
 *          withdrawal from the same account.
 */

/**
 *  Choose the correct option
 *  -   Locking down of nodes, till all are updated with latest data is done in:
 *  Options
 *      a.  Strong consistency
 *      b.  Eventual consistency
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   In eventual consistency, some of the systems might hold old data for a brief 
 *      amount of time.State whether the statement is true or false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following can have eventual consistency?
 *  Options
 *      a.  Social media applications
 *      b.  Flight ticket booking applications
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true about distributed systems :
 *  Options
 *      a.  Partition tolerance is very important, hence we must choose one from 
 *          consistency or availability.
 *      b.  Consistency, availability and partition tolerance all can be high for a 
 *          system.
 *      c.  It only helps in designing the monolithic systems.
 *      d.  Consistency cannot be compromised on, so we must choose one from 
 *          availability and partition tolerance.
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for network partition?
 *  Options
 *      a.  It happens when the network is divided on the basis of speed.
 *      b.  It means decomposition of the network into LAN, WAN MAN.
 *      c.  It means dividing the network into groups of nodes having same function.
 *      d.  It happens when a node goes down or get disconnected from the network.
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Strong consistency may lead to low availability. State whether the following 
 *      statement is true or false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 *  -   Since to achieve strong consistency the nodes are locked or shut down, so 
 *      that data cannot be read from it, which may lead to low availability of the 
 *      application.
 */

/**
 *  Match the correct options
 *  -   Match the characteristic which should be preferred for the following 
 *      applications:
 *      a. Blogs website                             1. Availability 
 *      b. Multiplayer online games                  2. Consistency
 *      c. Stock trading platforms
 *      d. Video streaming sites
 *      e. Flight ticket booking system
 *      f. Video chat applications
 *  Options
 *      a.  a.1 b.1. c.2 d.1 e.2 f.1 
 *      b.  a.2 b.1. c.2 d.1 e.1 f.1
 *      c.  a.1 b.2. c.2 d.1 e.2 f.2    
 *      d.  a.1 b.2. c.1. d.1 e.2 f.1
 *  Ans: a
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  Time helps us to identify which event occurred first.
 *      b.  Physical clocks can be easily trusted for distributed systems.
 *      c.  Logical time plays an important role as different nodes can be placed 
 *          in different geographical locations.
 *      d.  Monolithic systems do not always need logical time.
 *  Ans:    a, c, d
 */

/**
 *  Choose the correct option
 *  -   What are the challenges of using physical time?
 *  Options
 *      a.  Physical clocks may not be helpful to identify sequence of events in 
 *          distributed systems.
 *      b.  Nodes in different geographical location might follow different time 
 *          zones
 *      c.  Network delay can change the original sequence of events.
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Logical time is divided into
 *  Options
 *      a.  Logical global time 
 *      b.  Logical physical time
 *      c.  Logical local time 
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  Local event happen within the machine.
 *      b.  Process mark its own event when running on the machine, this time is    
 *          known as logical local time.
 *      c.  Lamport clock is one of the algorithm to implement logical time.
 *      d.  All of the above
 *  Ans: d
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true regarding Lamport clock?
 *  Options
 *      a.  Each process uses a global counter.
 *      b.  As the event happens, process increments the counter
 *      c.  Events can be categorized as ‘send’ events or ‘receive’ events.
 *      d.  Send events carries its own timestamp + 1 .
 *  Ans:    b, c
 */

/**
 *  Assignment
 *  -   Let's suppose we have the task to synchronise the order and the customer        
 *      between two systems such as an ERP and an online shopping application, 
 *      wherein:
 *      -   The customer can log into the app, select products and place orders.
 *  -   Every order will have the reference of its customer so that the order cannot 
 *      be created before the customer in ERP.
 *  -   So two separate paralleling running integration processes are created :
 *      -   Process P1 to synchronise the customer
 *      -   Process P1 to synchronise the order
 *  -   Since these two processes are running parallel, there could be a situation 
 *      when the order arrives before the corresponding data of the customer.
 *  -   This situation would prevent the order from being created in the ERP system 
 *      and may lead to blocking the system not allowing any further processing.
 *  -   What can be the solution for this case, knowing that we still need to 
 *      maintain the consistency of the system and strong consistency is not 
 *      preferred?
 *  Ans:    While trying to synchronise the order in the ERP when the customer 
 *      detail for that order has not been received, we can simply postpone the 
 *      processing of the order for a short while. Due to this, the parallel process 
 *      will get the time to synchronise the customer and the corresponding customer 
 *      details will eventually be synched with the ERP. This is where eventual 
 *      consistency helps the system.
 */