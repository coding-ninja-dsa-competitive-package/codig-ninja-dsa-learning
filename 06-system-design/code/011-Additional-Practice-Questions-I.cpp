/**
 *  Choose the correct option
 *  -   Which of the following is part of HLD:
 *  Options
 *      a.  Pseudocode
 *      b.  Unit testing
 *      c.  Functional architecture 
 *      d.  Database design 
 *  Ans:    c, d
 */

/**
 *  Practice Question
 *  -   Suppose you are asked to design a parking lot system with the following use cases:
 *      When a user enters the parking lot, a ticket is generated. When the user exits the 
 *      parking lot, the price should be calculated.
 *  -   What information should be on the ticket?
 *  Ans:    vehicle number, time of arrival, parking spot number, ticket ID etc 
 */

/**
 *  Practice Question
 *  -   How to allocate parking spots to users?
 *  Ans:   
 *      -   different areas for different vehicles, acc to the size: small, medium, large
 *      -   which strategy is used to allocate a spot to a user
 *      -   is the price different for different kinds of vehicles acc to their size etc.
 */

/**
 *  Practice Question
 *  -   What should be the part of the high-level design for this system?
 *  Ans:    
 *      -   Scaling: for one parking lot, the number of parking slots on each floor?  The 
 *          number of floors? 
 *      -   The data size of a parking ticket? Data generated after 15 years?
 *      -   If we have to store data for 10 million parking lots in the coming years?
 *      -   Components: what would be different components of the system? 
 *          E.g servers, databases etc. How will the servers be able to handle the 
 *              request load for 10million parking lots? 
 *      -   Services: What services should be there. 
 *          Eg: parking service, slot services, ticket generation, pricing service etc.
 *      -   APIs: what APIs would be required?
 *      -   Should the system be centralized or distributed?
 */

/**
 *  Practice Question
 *  -   What should be the part of the low-level design for this system?
 *  Ans:    
 *      -   Details of classes, the interaction of various classes, data types, and 
 *          functions. 
 *          Eg of classes can be ParkingLot, ParkingSpot, Ticket, Vehicle, Payment, 
 *              ParkingRate etc.
 *      -   Class diagrams
 *      -   Use case diagram, Eg of the actors: customer, system, parking attendant, 
 *              Admin. Eg of some use cases:  add/remove/edit Parking Floor, 
 *              add/remove/edit Parking Spot, Generate ticket, Payment, Add/Modify
 *              Parking Rates etc  
 *      -   Activity diagram and event diagram
 *      -   Pseudo code/ algorithms.
 */

/**
 *  Practice Question
 *  -   Suppose you alone have been given a task to build a search engine like Google, 
 *      as a first step would you build a monolithic or a distributed application?
 *  Ans:    Since the application is being built from scratch without any team of 
 *      developers, whose growth in terms of clients we are not sure of, it would be 
 *      easy to start building it like a monolithic application.
 */


/**
 *  Practice Question
 *  -   As the application grows, the code would become complex. What can be done to use 
 *      heterogeneous tools and languages for building new features?
 *  Ans:    After a point, the application might have to be broken into multiple components 
 *      which are able to work in an autonomous fashion. Also, there might be a need to 
 *      use dedicated tools and technology for different components of the application. 
 *      To achieve this, we would have to move from monolithic to distributed systems. 
 *      Distributed architecture would help in the development of new features, testing 
 *      of components and avoiding the need to deploy the complete application code 
 *      whenever any modification or new code is added. Also, redundancy and replication 
 *      can be introduced to avoid the single point of failure and data loss.
 */

/**
 *  Practice Question
 *  -   Each machine has 5 cores each with 2 threads for concurrent requests; how many 
 *      machines would we require for 1K RPS throughput and 1sec latency.
 *  Ans:    Each machine has 5 cores with 2 threads for concurrent requests, hence 
 *          The total number of concurrent requests handled by a machine: 5*2=10 
 *          The number of requests the system will receive from clients: 1K
 *          So, the number of machines required to handle 1K RPS = 1000/10 = 100 machines. 
 */

/**
 *  Practice Question
 *  -   A network having a bandwidth of 12Mbps can pass 10,000 frames per minute. Each 
 *      frame is of size 12,000 bits. Calculate the throughput of the network?
 *  -   Specify the answer in Mbps and enter the integer part of the answer.
 *  Ans:    2
 *  -   Since 10000 frames per minute can pass and each frame is of 12,000 bits, the 
 *      number of bits passing per second is: (10000*12000)/60 =2,000,000 bps = 2Mbps
 *  -   So, the throughput is 2Mbps which is almost 1/5th of the bandwidth of the network.
 */

/**
 *  Practice Question
 *  -   What is the side effect of having more replicas in the same data centre and few 
 *      in others?
 *  Ans:    It affects the reliability of data, if we lose one Data Centre our replication 
 *      goes down significantly. To avoid this, we can replicate the sync way in the same 
 *      data centre, and in the background async way for other data centre, if we know 
 *      most of our clients would not be redirected to those other data centres at the 
 *      same time.
 */

/**
 *  Practice Question
 *  -   Suppose you alone have been given a task to build a search engine like Google. 
 *      After 2 years, the application becomes popular and starts receiving 3x the number
 *      of requests. Also, the data to be stored has increased to 100GB and might increase 
 *      more with time. What should you do in terms of scaling?
 *  Ans:    Vertical scaling of the application can be done, so that we can increase 
 *      the computational resources, storage without much change in the application.
 */

/**
 *  Practice Question
 *  -   Suppose after 5years, the application becomes really huge and starts receiving 
 *      millions of requests. The data has now grown to 100TB. What can be done now?
 *  Ans:    Since, after a point, vertical scaling might not help as we would not be able 
 *      to add endless computational resources onto a single system, it's time to move to 
 *      horizontally scale the application. Now, instead of a single system, we can 
 *      leverage the resources of multiple commodity hardware. These systems will be 
 *      able to handle the exponential increase of requests and also remove the risk of 
 *      a single point of failure.
 */

/**
 *  Practice Question
 *  -   Suppose we have 10 machines and each machine has storage of 50GB space. We want 
 *      to store 200 GB of static user data. How much replication can we achieve without 
 *      making the system use more than 80% of the space?
 *  Ans:    1 Machine has 50Gb space
 *      Only 80% of it can be used. So for each machine, 
 *      space available to store data: 80% of 50GB = 40GB
 *      Data to be stored = 200GB, hence number of machines required to store this data: 
 *          200GB / 40GB= 5 machines
 *      So, out of 10 machines provided, 5 would be used to store the static user data, 
 *      and the rest 5 mchies can be used for replication . Hence, we can achieve 2x 
 *      replication of data.
 */

/**
 *  Practice Question
 *  -   Choose the replication strategy (out of active and passive replication), which 
 *      should be preferred for the following scenarios:
 *      A. Some modification has to be made to a Wikipedia page
 *  Ans:    Since, wikipedia can be considered a read intensive site where the main purpose 
 *      is to display the articles to the user and modifications are not done frequently, 
 *      passive replication strategy should be used. One master node can perform the write 
 *      operation wherever modification is required and this can be then replicated to all 
 *      the other nodes.
 * 
 *      B. If Netflix wants to know how many people viewed a particular movie.
 *  Ans:    In this kind of scenario active replication should be preferred. Since this 
 *      computation cannot be handled by one single master mode, all the active nodes 
 *      need to do the write operation and then later sync within themselves to know 
 *      the exact number.
 */

/**
 *  Choose the correct option
 *  -   Choose the correct load balancing algorithms in which client requests are 
 *      distributed to the server with the minimum number of active connections for 
 *      different server characteristics.
 *  Options
 *      a.  Resource Based
 *      b.  Least Connection
 *      c.  IP Hash
 *      d.  Weighted least connection 
 *  Ans:    d
 *  -   Weighted Least Connection builds on the Least Connection load balancing algorithm 
 *      to account for differing application server characteristics. The administrator
 *      assigns a weight to each application server based on criteria of their choosing 
 *      to demonstrate the application server traffic-handling capability. 
 */

/**
 *  Practice Question
 *  -   Match the following Load Balancing Algorithms with their technique:
 *      1. Round-Robin
 *      2. Resource-Based
 *      3. Weighted Response Time
 *      4. Source IP Hash
 *      A. Distribution of requests to servers on the basis of how busy they are.
 *      B. Distribution of requests to servers on the basis of Server Response Time (SRT)
 *      C. Distribution of requests to servers on basis of the hashed value
 *      D. Distribution of requests to servers in rotation
 *  Options
 *      a.  1->C, 2->B, 3->A, 4->D
 *      b.  1->D, 2->A, 3->B, 4->C
 *      c.  1->A, 2->B, 3->C, 4->D
 *      d.  1->D, 2->B, 3->A, 4->C
 *  Ans;    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following caching strategies is used in most relational database 
 *      storage engines with write-heavy workloads.
 *  Options
 *      a.  Cache-Aside
 *      b.  Write-Back
 *      c.  Read-Through Cache
 *      d.  Write-Through Cache
 *  Ans:    b
 *  -   Write back is a storage method in which data is written into the cache every 
 *      time a change occurs, but is written into the corresponding location in the main 
 *      memory only at specified intervals or under certain conditions. This is sometimes 
 *      called write-behind as well. Write back caches improve the write performance and 
 *      are good for write-heavy workloads.
 */

/**
 *  Choose the correct option
 *  -   Which of the following caching strategies would be suitable for read-heavy 
 *      applications like a blog website where the same data is requested multiple times.
 *  Options
 *      a.  Write-Back
 *      b.  Write-Around
 *      c.  Read-Through
 *      d.  Write-Through
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 5 items. We add 11,2,6,5,20 to the 
 *      cache. Which element should be removed from the cache on adding 1 according to 
 *      the LRU cache eviction strategy.
 *  Options 
 *      a.  20  b.  2   c.  6   d.  11 
 *  Ans: d
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 5 items. We add 11,2,6,5,20 to the 
 *      cache. Which element should be removed from the cache on adding 1 according to 
 *      the MRU cache eviction strategy.
 *  Options
 *      a.  20  b.  2   c.  6   d.  11
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 4 elements. We add 
 *      A->B->C->D->E->C->D->B (added from left to right) to the cache. Using the MRU 
 *      Cache Eviction strategy, what would be the final sequence after adding all the 
 *      elements to the cache.
 *  Options
 *      a.  A C B D
 *      b.  A B C D
 *      c.  A B D E
 *      d.  A B C E
 *  Ans:    c
 *  -   Here, A B C D are placed in the cache as there is still space available. At the     
 *      5th access E, we see that the block which held D is now replaced with E as this 
 *      block was used most recently. Another access to C and at the next access to D, 
 *      C is replaced as it was the block accessed just before D and so on.
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 4 elements. We add 
 *      A->B->C->D->E->D->F(added from left to right) to the cache. Using the LRU Cache 
 *      Eviction strategy, what would be the final sequence after adding all the elements 
 *      to the cache.
 *  Options
 *      a.  C D E F
 *      b.  A B E F
 *      c.  E F C D
 *      d.  D C F E 
 *  Ans:    c
 *  -   In the above example once A B C D gets installed in the blocks with sequence 
 *      numbers (Increment 1 for each new Access) and when E is accessed, it is a miss  
 *      and it needs to be installed in one of the blocks. According to the LRU Algorithm,  
 *      since A has the lowest Rank(A(0)), E will replace A.
 *  -   In the second to last step, D is accessed and therefore the sequence number is 
 *      updated.
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 4 elements. We add 
 *      A->B->C->D->E->C->D->B(added from left to right) to the cache. Using the FIFO 
 *      Cache Eviction strategy, what would be the final sequence after adding all the 
 *      elements to the cache.
 *  Options
 *      a.  E C D B
 *      b.  B D E C
 *      c.  C E D B
 *      d.  E C B D
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a cache with a capacity of 4 elements. We add  
 *      A->B->C->D->E->C->D->B(added from left to right) to the cache. Using the LIFO 
 *      Cache Eviction strategy, what would be the final sequence after adding all the 
 *      elements to the cache.
 *  Options
 *      a.  A B C D
 *      b.  B A B C
 *      c.  E C D B
 *      d.  B A C D
 *  Ans:    a
 */
