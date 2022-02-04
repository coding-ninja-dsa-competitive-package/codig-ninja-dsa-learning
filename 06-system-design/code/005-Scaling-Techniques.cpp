/**
 *  Vertical Scaling:
 *  ----------------
 *  -   Vertical scaling increases the scale of a system by adding more 
 *      configuration or hardware for better computation power or storage. In 
 *      practice, this would mean adding better processors, increasing RAM, or 
 *      other power increasing adjustments.
 *  -   Scaling here is done through multi-core by spreading the load between the 
 *      CPU and RAM resources.
 *      Example: MySQL
 *  
 *  Limitation of vertical scaling :
 *  ------------------------------
 *  -   SPOF (Single point of failure)
 *  -   Vertical scaling after a point becomes very expensive.
 * 
 *  Horizontal Scaling :
 *  -------------------
 *  -   Horizontal scaling is a process of increasing the scale of a system by 
 *      adding more machines. This entails collecting and connecting multiple 
 *      devices to take on more system requests.
 *      Example: Cassandra, MongoDB
 *  -   Using small but large number of machines
 *  -   Monolithic be horizontally scaled ? YES. Load will increase , wastage of 
 *      resources.
 * 
 *  Redundancy: 
 *  ----------
 *  -    Duplicating nodes for high availability
 *  -   Types:
 *      -   Active Redundancy   :   Every node gets equals calls.
 *      -   Passive Redundancy  :   Active node will be called, passive will be backup.
 *      
 *  Replication:
 *  -----------
 *  -   Duplication of data on different machines.
 *  -   Types:
 *      -   Active Replication : each node will have data copied.
 *      -   Passive Replication : master & slave/worker model
 * 
 *  Load Balancer:
 *  -------------
 *  -   each machine is equally loaded
 *  -   healthcheck 
 *  -   high availability/scalability/throughpput
 *  -   Algorithm to decide which server will process request.
 *      -   Round Robin Method : choose server one after another in sequence when all the
 *              servers are of same capacity.
 *      -   Weighted Round Robin : when servers are of different capacity.
 *      -   IP Hash Algorithm: servers are almost same capacity and we want to do random
 *              unbiased distribution of traffic.
 *                  [has(requests) % n ] -> [0, n-1]
 *      -   Least Connection Algorithm: when we need to decide based on the availability
 *              of open connection on a server. 
 *      -   Least Response Time: 
 *  -   Challenge : SPOC i.e. if load balancer goes down, everything goes down. 
 *      -   Redundancy is done to avoid this situation (Active / Passive)
 * 
 *  Caching:
 *  -------
 *  -   Improve Read performance.
 *  -   Caching makes sense in Read Intensive Application like Blogging, Wikipedia, News.
 *  -   Where caching can be applied:
 *      -   Application Server Cache
 *      -   CDN (Content Delivery Network) is used for caching static content and then 
 *          delivering to the application.
 * 
 *  Types of Caching:
 *  ----------------
 *  -   Local/ In Memory Cache : stored inside RAM
 *      Examples:   Google Guava Cache, MemCache
 *  -   Distributed Cache
 *      Example:    Redis
 * 
 *  Different Caching Strategies:
 *  ----------------------------
 *  -   Write Through Cache:
 *      -   As soon as new data is saved , it is saved in cache as well i.e. high
 *          consistency, No stale data, consistent read.
 *      -   disadvantage : write will be slower.
 *  -   Write Around Cache:
 *      -   write is fast and not copied to cache dirrectly. cache is updated while read.
 *      -   disadvantage : read is slow
 *  -   Write Back Cache:
 *      -   Write in to cache. Actual write will happen in asynchrous way.
 *      -   Write is fast.
 *      -   disadvantage: loss of data in case cahe memory is failed.
 * 
 *  Cache Eviction Strategy:
 *  -----------------------
 *  -   FIFO : first in first out
 *  -   LIFO : Last in first out
 *  -   LRU : Least Recently Used
 *  -   MRU : Most recently used
 *  -   RR : Random Replacement
 */

/**
 *  Choose the correct option
 *  -   Which of the following is Not true regarding scalability?
 *  Options
 *      a.  Scalability leads to more clients.
 *      b.  Scalability may increase the response time for clients. 
 *      c.  If an application is scalable the response time may remain same or may 
 *          decrease as clients increase
 *      d.  None of the above
 *  Ans:    b
 */

/**
 *  Choose the correct option   
 *  -   Vertical scaling can be achieved by:
 *  Options
 *      a.  Increasing the storage/ hard disk space
 *      b.  Increasing the network bandwidth
 *      c.  Increasing the processing power
 *      d.  All of the above
 *  Ans:    d
 */

/** 
 *  Choose the correct option
 *  -   What is true for vertical scaling:
 *  Options
 *      a.  It can be increased easily by removing hardware from the system 
 *      b.  There is a limit to scaling a system vertically
 *      c.  Vertical scaling is not possible for monolithic systems
 *      d.  Vertical scaling reduces the performance of the system
 *  Ans:    b
 *  -   This is correct because vertical scaling has a limit. Vertical scaling is 
 *      limited to the capacity of one machine, scaling beyond that capacity can 
 *      involve downtime and has an upper hard limit, i.e. the scale of the hardware 
 *      on which you are currently running.
 */

/**
 *  Choose the correct option
 *  -   Why does Vertical scaling has the risk of a single point of failure:
 *  Options
 *      a.  Multiple hard disks may fail simultaneously
 *      b.  All the components of the application, code, hardware additions, are 
 *          present on a single system 
 *      c.  Additional hardware may reduce the performance
 *      d.  Many network calls may lead to failure 
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for vertical scaling:
 *  Options
 *      a.  It is prone to single point of failure
 *      b.  It might not be able to handle exponential increase in client
 *      c.  It can become very expensive after a point
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following scaling methods uses large number of machines:
 *  Options
 *      a.  Vertical scaling
 *      b.  Horizontal scaling
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which kind of scaling is possible for monolithic systems:
 *  Options
 *      a.  Vertical scaling
 *      b.  Horizontal scaling
 *      c.  Both Vertical scaling & Horizontal scaling
 *      d.  none of the above
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is not true for horizontal scaling:
 *  Options
 *      a.  Commodity hardware is used
 *      b.  There are no network calls required in this type of scaling.
 *      c.  Multiple systems are used for scaling
 *      d.  Monolithic systems can be horizontally scaled
 *  Ans:    b
 *  -   Horizontal scaling makes use of multiple commodity hardware to improve the 
 *      performance of the system.
 */

/**
 *  Choose the correct option
 *  -   Redundancy can help in improving the availability of the system. State 
 *      whether the statement is true or false.
 *  Options
 *      a.  True 
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option   
 *  -   Partition in distributed systems can be caused due to:  
 *  Options
 *      a.  Absence of network 
 *      b.  High latency
 *      c.  Node going down 
 *      d.  Low availability
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is NOT the purpose of redundancy?
 *  Options
 *      a.  Removing single point of failure
 *      b.  High availability of the system
 *      c.  Providing backup in crisis
 *      d.  None of the above 
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following statements are true?
 *  Options
 *      a.  Redundancy means having duplicate components or nodes. 
 *      b.  In passive redundancy initial nodes are active and duplicate passive 
 *          nodes are on standby, to take over in case of any failure 
 *      c.  In active redundancy there is no duplication of nodes.
 *  Ans:    a, b
 */

/**
 *  Choose the correct option
 *  -   Which of the following means keeping multiple copies of data and updating 
 *      them whenever any changes take place?
 *  Options
 *      a.  Redundancy
 *      b.  Latency
 *      c.  Replication
 *      d.  Fault Tolerance
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Active replication uses the master-slave model for replicating data within 
 *      various servers.State whether true or false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    b
 */

/**
 *  Practice Question
 *  -   Three of the classmates are copying the programming assignment from Rahul.  
 *      After every 1-2 days Rahul makes some modifications in the assignment. Now,
 *      his classmates also keep updating the assignment whenever any modification 
 *      is done. Which kind of replication is this? Can you identify the master and 
 *      slave nodes from the example?
 *  Ans:    This is an example of Passive replication because in passive replication 
 *      there is only one server that processes client requests. After processing a 
 *      request, the primary server updates the state on the other (backup) servers 
 *      and sends back the response to the client. Similarly, in this question, 
 *      Rahul is that primary server who processes requests and his classmates then 
 *      update their assignments from Rahul's assignment. Here, Rahul acts as the 
 *      master, and his classmates act as slaves nodes.
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is/are taken care by the load balancer:
 *  Options
 *      a.  To check if servers are in running condition
 *      b.  To allocate the client requests equally to different servers
 *      c.  To make sure some server is not overloaded with requests
 *      d.  Computing and storing power of the system
 *  Ans:    a, b, c
 */

/**
 *  Choose the Correct Option
 *  -   How adding Load balancer leads to high availability
 *  Options
 *      a.  It passes the messages fast to the clients
 *      b.  If a server is down, load balancer transfer the request to another healthy server
 *      c.  It adds more latency to the system
 *      d.  It does not affect the availability of the system
 *  Ans:    b
 */

/**
 *  Choose the Correct Options
 *  -   When should a load balancer not be used:
 *  Options
 *      a.  When we need to horizontally scale an application
 *      b.  When we are using centralized systems
 *      c.  When an application is vertically scaled
 *      d.  When we have multiple servers   
 *  Ans:    b, c
 */

/**
 *  Choose the Correct Option
 *  -   Load balancers can be placed between:
 *  Options
 *      a.  Client application/ user and the web server
 *      b.  Application servers and database servers
 *      c.  Web server and application server
 *      d.  All of the above    
 *  Ans:    d
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is true for load balancers:
 *  Options
 *      a.  It leads to faster response time
 *      b.  It leads to delayed response time
 *      c.  It leads to low down time
 *      d.  It can predict traffic bottlenecks
 *  Ans:    a, c, d
 */

/**
 *  Choose the Correct Option
 *  -   How is load balanced if round robin algorithm is used for equal capacity servers:
 *  Options
 *      a.  Servers are allotted requests randomly
 *      b.  Servers are allotted requests sequentially
 *  Ans:      b
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is true for IP hash algorithm:
 *  Options
 *      a.  It is used for servers having different capacities
 *      b.  Hash function is used to identify the server which would be allocated the 
 *          request
 *      c.  Hash function is applied on the IP address of the client which generated the 
 *          request
 *      d.  Hash function is applied on IP address of the servers
 *  Ans:    b, c
 */

/**
 *  Choose the Correct Option
 *  -   What are the challenges of using load balancer:
 *  Options
 *      a.  It leads to low availability
 *      b.  It can be a single point of failure
 *      c.  It decreases the scalability of the system
 *      d.  It might not be able to detect unhealthy servers 
 *  Ans:    b
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is improved by using cache:
 *  Options
 *      a.  Connectivity
 *      b.  Throughput
 *      c.  Latency
 *      d.  Availability
 *  Ans:    b, c, d
 *  -   Caching can improve data availability by providing continued service for 
 *      applications that depend only on cached tables even if the backend server is 
 *      unavailable. Caching improves the data retrieval performance because it is then 
 *      not required to access the slow storage layer, which improves latency and 
 *      throughput. 
 */

/**
 *  Choose the Correct Option
 *  -   Caching helps in reducing
 *  Options
 *      a.  Database read calls
 *      b.  External API calls
 *      c.  Network I/O calls
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is true:
 *  Options
 *      a.  CDN usually caches the static content
 *      b.  CDN stands for caching delivery network
 *      c.  CDN is a type of caching mechanism
 *  Ans:    a, c
 */

/**
 *  Choose the Correct Option
 *  -   Which of the following is true:
 *  Options
 *      a.  Data is stored in ROM in case of local memory
 *      b.  Multiple machines have common in-memory or local memory
 *      c.  Distributed cache can be used if multiple machines wants to share cache
 *  Ans:    c
 */

/**
 *  Choose the Correct Option
 *  -   For an ecommerce application saving cart details of the customers, which cache 
 *      should be used :
 *  Options
 *      a.  In memory cache
 *      b.  Distributed cache
 *      c.  Local cache 
 *  Ans:    b
 *  -   Since, an ecommerce application would involve multiple servers, distributed cache 
 *      should be used so that the information of the client's cart can be shared amongst 
 *      them.
 */

/**
 *  Choose the Correct Options
 *  -   When should caching be not used:
 *  Options
 *      a.  When the data is changing frequently
 *      b.  When the data is not changing frequently
 *      c.  If the application is read intensive
 *      d.  If the application is write intensive
 *  Ans:    a, d
 */

/**
 *  Choose the Correct Option
 *  -   Cache reduces the network call to the database, and it speeds up the performance 
 *      of the system.
 *  Options
 *      a.  True    
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is true for write through cache strategy:
 *  Options
 *      a.  Data is simultaneously written in cache and the database
 *      b.  It makes write intensive applications faster.
 *      c.  It leads to high consistency
 *  Ans:    a, c
 */

/**
 *  Fill Up
 *  -   When data is not found in the cache, it is known as ______ ?
 *  Ans:    cache miss
 */

/**
 *  Choose the Correct Options
 *  -   Which of the following is true for write around cache strategy:
 *  Options
 *      a.  For each write operation, write is only performed once directly to the database
 *      b.  Should not be used for write intensive applications
 *      c.  It leads to higher chances of cache miss
 *      d.  Read operations become faster.
 *  Ans:    a, c
 */

/**
 *  Choose the Correct Option   
 *  -   Which of the following cache eviction strategies evicts the data randomly:
 *  Options
 *      a.  LRU
 *      b.  RR
 *      c.  MRU
 *      d.  LIFO
 *  Ans:   b
 */

/**
 *  Choose the Correct Option
 *  -   Which of the following solutions can be used by e-blogging application to improve 
 *      its performance:
 *  Options
 *      a.  Using cache at Back end
 *      b.  Using CDN to provide images, videos, CSS etc.
 *      c.  Using cache in the client’s browser
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Assignment
 *  -   Answer the following questions if you have to design a cache for Twitter.
 *  
 *  Part A  
 *  -   What is the estimated amount of the data that needs to be cached?
 *  Ans:    Since it's a large-scale application used by millions of people , we can 
 *          estimate it to be in some TBs.)
 * 
 *  Part B
 *  -   Which cache eviction strategy should be used?
 *  Ans:    Since new entries might not get space in the cache until we remove some 
 *          previous entries, implementing an eviction strategy is an important part. 
 *          Eviction strategies selection mainly depend on the access pattern we want 
 *          to implement. For this example, we can choose LRU  as it will remove the 
 *          least recently used entry from the cache.
 *  
 *  Part C
 *  -   Which caching strategy should be used?
 *  Ans:    Since Twitter can be considered as a write intensive application, using write 
 *          around cache seems a good solution. Write around cache writes directly into 
 *          the database ensuring low write load on the cache and making the write request  
 *          fasts. 
 *  
 *  Part D
 *  -   What kind of QPS (query per second) we expect from the system?
 *  Ans:    A single machine might be able to handle 1M queries per second, if we go 
 *          beyond that we may face high latency as queries received may not be answered 
 *          quickly.
 *  
 *  Part E
 *  -   Out of consistency and availability,which is more important for this system?
 *  Ans:    Unavailability in the caching system means more cache miss which would again 
 *          lead to high latency as read would be done from disk, taking more time.  So, 
 *          out of both the above-mentioned metrics, we should go for availability. 
 *          Eventual consistency can be used in this scenario.
 */
