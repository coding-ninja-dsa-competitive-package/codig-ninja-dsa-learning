/**
 *  Choose the correct options
 *  -   Which of the following is true for client-server architecture?
 *  Options
 *      a.  World Wide Web is an example of client server architecture.
 *      b.  It works on request-response model
 *      c.  Web applications are built on this architecture but not the web sites
 *      d.  Servers running web applications are known as application servers
 *  Ans:    a, b, d
 */

/**
 *  Choose the correct option
 *  -   Some of the examples of clients can be:
 *  Options
 *      a.  Mobile apps
 *      b.  Web based consoles
 *      c.  Desktop, laptop and Ipads.
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for client-server architecture?
 *  Options
 *      a.  A web server can also act as a client when requesting information
 *      b.  Server can initiate the communication
 *      c.  Both server and client can initiate the communication
 *  Ans:    a
 */

/**
 *  Assignment
 *  -   Let's suppose you want to create an online bookstore. The application can be used 
 *      to browse the books, get book details and order books.
 *  
 *  Part A
 *  -   What can be the possible issues if client-server architecture is not used?
 *  Ans:    Here, the online bookstore application can be considered a single piece of 
 *      software that needs to be downloaded from the internet. This monolithic application 
 *      will contain all the required details of books and orders. So whenever a new book 
 *      has to  be added or deleted, or any other details are modified, the entire 
 *      application needs to be re-distributed again to the users. Since, the books 
 *      catalogue will change frequently, this will lead to repeated distribution of the 
 *      application. 
 * 
 *  Part B
 *  -   How can client server architecture help?
 *  Ans:    The client-server architecture can be used to split the application into 2 
 *      parts. The client will have an interface that will display all the information 
 *      and the server will have all the data related to the book, details , orders etc. 
 *      The changes can be made to the server and will reflect on the client-side. 
 */

/**
 *  Choose the correct options
 *  -   Which of the following is true ?
 *  Options
 *      a.  To communicate using REST API, the client needs the backend endpoints
 *      b.  REST API acts as a multi-entry point into the system
 *      c.  The backend endpoints is the URL of the service
 *  Ans:    a, c    
 *  -   REST API is a single entry point into the system.
 */

/**
 *  Choose the correct option
 *  -   The client-server communication model is based on HTTP protocol.State whether 
 *      the following statement is true/false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a   
 */

/**
 *  Choose the correct option
 *  -   Service-oriented architecture defines a service as a unit of software designed to 
 *      complete a specific task. State whether the following statement is true/false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following are advantages of using SOA?
 *  Options
 *      a.  It helps to create reusable code
 *      b.  Different components and services are tightly coupled with each other
 *      c.  Allows using multiple coding languages
 *      d.  It is used for creating scalable applications as services run on different 
 *          serves
 *  Ans:    a, c, d
 */

/**
 *  Practice Question
 *  -   Consider an online banking system and list some of the services it would have.
 *  Ans:    Authentication, fund transfer, user profile, onboarding, account statement, 
 *      wallet to bank transfer etc.
 */

/**
 *  Choose the correct option
 *  -   What are the disadvantages of a microservice-based architecture ?
 *  Options
 *      a.  Complicated testing as distributed environment
 *      b.  Requires load balancing so that network latency can be decreased
 *      c.  Creating lot of services for complex applications can lead to confusion 
 *          between developers
 *      d.  Higher operational cost than monolithic architecture
 *      e.  All of the above
 *  Ans:    e
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for microservice-based architecture? 
 *  Options
 *      a.  As the services are independent of each other, different teams can 
 *          independently develop, test and put the code into production
 *      b.  Flexibility to try new languages and technologies
 *      c.  SOA has evolved from Microservice based architecture
 *      d.  Prone to single point of failure
 *      e.  Microservices connect to each other through APIs
 *  Ans:    a, b, e
 */

/**
 *  Choose the correct option
 *  -   When should microservices architecture be preferred?
 *  Options
 *      a.  When an application needs to be rebuild due to change in functionalities, 
 *          addition of new features
 *      b.  Big data applications which require dedicated services for tasks such as 
 *          data collection, processing, delivery etc
 *      c.  Applications requiring real time data and executing different operations to 
 *          delivery output immediately such a s traffic control system
 *      d.  All of the above
 *  Ans:        
 */

/**
 *  Choose the correct option
 *  -   What of the following statement is true?
 *  Options
 *      a.  A tier is the storage space used to save code for different components of an 
 *          application
 *      b.  A tier is a logical separation of different components of an application
 *      c.  A tier is the logical separation at code level for different features of an 
 *          application
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  1 Tier architecture has minimum network latency
 *      b.  1 Tier architecture should be used when the application should look uniform 
 *          with respect to designing of UI
 *      c.  In 2 tier architecture, all the three layers are stored in the single machine.
 *      d.  In 2 Tier architecture, the first tier stores the User Interface and the
 *          second tier stores the Business logic and data storage layer
 *  Ans:    a, d
 */

/**
 *  Choose the correct option
 *  -   What are the benefits of using tier architecture?
 *  Options
 *      a.  It makes modifications and updation of different components easy
 *      b.  It makes different components tightly coupled
 *      c.  It helps in assigning dedicated task and roles to each component
 *      d.  It leads to complicated testing of the complete system
 *  Ans:    a, c
 */

/**
 *  Practice Question
 *  -   For a banking application, which would provide better performance: client-server 
 *      architecture or 3 tier architecture?
 *  Ans:    3 tier architecture . In client-server architecture the data and the service 
 *      layers are closer to each other, leading to low latency and high performance, but 
 *      if the load is larger then it will perform poorly due to bottlenecks of data calls 
 *      and business logic happening simultaneously. 3 tier architecture avoids this. Also, 
 *      3 tier architecture takes less space at the client-side (Mobile apps, ATMs, 
 *      website) as the logic and data is stored at separate servers. Hence, light apps 
 *      will lead to more users willing to use the app. 
 */