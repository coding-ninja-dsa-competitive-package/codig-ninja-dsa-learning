/**
 *  Latency:
 *  -------
 *  -   Time to complete a requent. 
 *
 *  Factors which impacts latency :
 *  ----------------------------
 *  -   N/w delays (improve n/w bandwidth)
 *  -   Computational delays    (concurrent/parallel processing)
 * 
 *  CDN (Content Delivery Network):
 *  -   Caches the static data.
 * 
 *  Throughput:
 *  ----------
 *  -   Rate of doing things like 50 request/minute.
 *  -   How can we imporove throughput:
 *      -   improving machine resources
 *      -   improving performance:
 *          -   Caching
 *          -   CDN
 *      -   Proper monitoring and fixing all the performance bottlenecks.
 *      -   Distributed computation using Load Balancers.
 * 
 *  Fault Tolerance:
 *  ---------------
 *  -   If any failure happens, system should handle it gracefully
 */

/**
 *  Choose the correct option
 *  -   Latency is measured in which of the following units:
 *  Options
 *      a.  Milliseconds
 *      b.  Mbps
 *      c.  Byte
 *      d.  Volts
 *  Ans:    a
 *      -   Latency is the delay or the time taken to get back a response. It is 
 *          hence measured in the unit of time
 */

/**
 *  Choose the correct option
 *  -   Which of the following is not an example of latency ?
 *  Options
 *      a.  Time taken to retrieve data from a database
 *      b.  Time taken to display a message on screen
 *      c.  Amount of data saved in the database
 *      d.  Time taken for a form to get saved online
 *  Ans:    c
 *  
 */

/**
 *  Choose the correct option
 *  -   Which of the following is not true for latency?
 *  Options
 *      a.  It is caused by network congestion
 *      b.  High latency is good for applications
 *      c.  Low configuration of the system can cause higher latency
 *      d.  It is measured in the unit of time.
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Distributed systems always have lower latency than monolithic systems.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    b
 *      -   Latency in Distributed systems considers network as well as 
 *          computational time.
 */

/**
 *  Choose the correct option
 *  -   CDN Stands for:
 *  Options
 *      a.  Content distribution network
 *      b.  Cache delivery network
 *      c.  Content delivery network
 *      d.  Content delivery node
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Content delivery network is the cause of high latency.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    b
 *      -   Content delivery network reduce the delay and make the delivery of 
 *          content more efficient, hence lowers the latency of a system.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is not true?
 *  Options 
 *      a.  Low latency can lead to high throughput.
 *      b.  Time taken to complete a request is throughput
 *  Ans:    b
 */

/**
 *  Assignment
 *  -   Can you think of some applications for which it is necessary to have high 
 *      throughput?
 *  Ans:    Since high throughput also means a high amount of data being processed 
 *          per unit of time some of the examples are :
 *      1.  Simulation applications  testing the functionality of aeroplane parts, 
 *          cars.
 *      2.  Cryptocurrency mining applications.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for throughput?
 *  Options 
 *      a.  Estimation of the throughput of an application plays an important role 
 *          in designing the system.
 *      b.  Distributed systems with load balancers can increase the throughput.
 *      c.  Monolithic systems have better throughput than distributed systems
 *      d.  Resources available on a machine can affect the throughput of a system
 *  Ans:    a, b, d
 */

/**
 *  Choose the correct option
 *  -   Number of instructions processed by a system in certain amount of time is 
 *      an example of:
 *  Options
 *      a.  Latency
 *      b.  Throughput
 *  Ans:    b
 */

/**
 *  Practice Question
 *  -   An assembly line is manufacturing chairs. It takes 4hours to manufacture a 
 *      chair and in a day 168 chairs are produced. Can you identify the latency 
 *      and throughput using the above information? (Specify Latency in hours and 
 *      Throughput in chairs/hour.)
 *  -   Answer should contain two integers separated by a comma.
 *  Ans:    4,7
 *      -   Latency: Latency is the amount of time in milliseconds (ms) it takes 
 *          a single message to be delivered. 
 *      -   Here, Time taken for manufacturing a chair: 4 hours
 *          Therefore, Latency = 4 hours
 *      -   Throughput: Throughput is the amount of data that is successfully 
 *          transmitted through a system in a certain amount of time, measured in 
 *          bits per second (bps). Throughput is a measurement of how much is 
 *          actually transmitted, and it is not the theoretical capacity (bandwidth) 
 *          of the system. 
 *      -   Here, Number of chairs produced in 1 day : 168 chairs
 *          Throughput =  Number of requests / Total time taken
 *              = 168 chairs / 1 day
 *              = 168 chairs / 24 hours
 *              = 7 chairs/hour
 */

/**
 *  Choose the correct option
 *  -   Which of the following can improve the throughput of the system?
 *  Options
 *      a.  Using Content Delivery Network
 *      b.  Resolving performance bottlenecks
 *      c.  Caching
 *      d.  All of the above    
 *  Ans:    d
 */

/**
 *  Practice Question
 *  -   Let us consider an e-commerce website that gets 200 HTTP requests on 
 *      average. In normal settings, a browser is able to generate 4 simultaneous 
 *      requests. Also, consider that the average network round trip time is about 
 *      150ms. Using this information calculate the overall latency, i.e. the 
 *      overall page load time for an e-commerce website.
 *      Specify answer in seconds.
 *  Ans:    Given the above 3 pieces of information, we can easily calculate the 
 *          overall website latency. The following formula can be used:
 *          (Http request/ Simultaneous browser request)* network latency (in ms) = 
 *                  Page load time (in ms)
 *          = (200/4)*150 =7500ms or 7.5sec
 */

/**
 *  Choose the correct option
 *  -   Which of the following can cause low availability ?
 *  Options
 *      a.  Hardware failure
 *      b.  Software bugs
 *      c.  Servers crashing due to high load of requests
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following statement is false?
 *  Options
 *      a.  Monolithic systems have higher availability than distributed systems.
 *      b.  Monolithic systems have lower availability than distributed systems.
 *      c.  Distributed systems can increase the availability by using redundancy 
 *          and replication
 *      d.  Single point of failure usually leads to low availability.
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   How are fault tolerance and availability related?
 *  Options
 *      a.  High fault tolerance leads to high availability
 *      b.  High availability leads to high fault tolerance
 *      c.  They are not related
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following can help in improving the availability of an 
 *      application ?
 *  Options
 *      a.  Decreasing the down time
 *      b.  Making system more fault tolerant
 *      c.  Actively monitoring the application
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Horizontally scaling an application means that there is no single point of 
 *      failure and hence the application also becomes high available. State whether 
 *      the following statement is true or false.
 *  Options 
 *      a.  True
 *      b.  False
 *  Ans:    a
 */

/**
 *  Practice Question
 *  -   Do you think availability can impact the business done by an application? How?
 *  Ans:    Availability means that the application should be accessible and 
 *          functional for the clients. To achieve a competitive advantage high 
 *      availability is necessary as even a small downtime can result in loss of 
 *      clients and bad reputation for the application. Also, when an application   
 *      is down the productivity of employees also decreases.
 *      Eg: consider an application which iaims for 99% availability, which means 
 *      87 hours or 3.62 days for downtime per year. This can lead to significant 
 *      loss in productivity and customers especially if the downtime is at peak 
 *      hours of business. 
 *      According to a report,  a 30min outrage in 2013 for Amazon.com reportedly 
 *      cost the company nearly $2billion.
 */