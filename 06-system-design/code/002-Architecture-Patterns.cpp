/**
 *  Monolithic architecture:
 *  =======================
 *  -   Useful in below scenarios :
 *      1.  When we want to develop something quickly. Example for any POC.
 *      2.  When we have latency sensitive application.
 *      3.  It is comparatively easy to secure monolithic system.
 *      4.  Integration Testing is comparatively easy.
 *      5.  It leads to less confused developers.
 * 
 *  Distributed architecture:
 *  ========================
 *  -   Different components /different systems are connected over a netwrok.
 *  -   Principal on which it is built upon:
 *      -   Always use [comodity hardware] - cheap.
 *      -   Each machine should be connected over a network/internet.
 */

/**
 *  -   Website : static content / read only content
 *      -   Example : Newspaper Websites, Wikipedia, Bloging Websites
 *  -   Web Application: Read + Action(write)
 *      -   Facebook : we can read info from others, update status, upload image.
 *      -   It comprises of 3 layers:
 *          1.  Frontend / UI : represntation layer
 *          2.  Backend / business layer : logic that is needed to express data in FE.
 *          3.  Data Storage layer
 * 
 *  Monolithic Architure Pattern:
 *  -   Single/ one unit of all three layers above.
 *  -   Code should be written together.
 *  -   They should be deployed all together.
 */

/**
 *  Choose the correct option
 *  -   If a user needs to do online bank transactions which of the following should 
 *      be developed:
 *  Options
 *      a.  Web sites
 *      b.  Web applications
 *  Ans:    b 
 *      -   Online bank transactions require many user inputs like : login, fill 
 *          details, perform action, enter otp, etc additionally dynamic data is 
 *          generated after each transaction, hence a web application is required.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true:
 *  Options
 *      a.  Web site can only contain static information in the form of text
 *      b.  Web application allows user to read as well as write
 *      c.  'Web application’ and ‘Web sites’ should be used interchangeably
 *      d.  Web site does not have a logic layer
 *  Ans:    b
 *      -   The web application allows a user to read information as well as write. 
 *          It is dynamic and hence the user can interact with it.   
 */

/**
 *  Choose the correct option
 *  -   Which of the following layers of a web application is closest to the user?
 *  Options
 *      a.  Business layer
 *      b.  Front end
 *      c.  Data storage layer  
 *      d.  Back end
 *  Ans:    b
 *      -   Front end or User interface is what a user sees on the screen while 
 *          using a web application.
 */

/**
 *  Choose the correct option.
 *  -   Which layer contains the logic of a web application:
 *  Options
 *      a.  Data storage layer
 *      b.  Front end
 *      c.  User Interface layer
 *      d.  Business layer
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for monolithic architecture?
 *  Options
 *      a.  Front end, back end and data storage layer of a web application are 
 *          present on the same system
 *      b.  Only front end and back end of a web application are present on the 
 *          same system
 *      c.  Front end and business layer has to be written using different languages 
 *          and different technology.
 *      d.  All of the above
 *  Ans:    a
 *      -   In a monolithic architecture pattern, all the three layers of a web 
 *          application (Front end, back end and data storage layer) are present 
 *          on a single system in a single base code.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for monolithic architecture:
 *  Options 
 *      a.  Any error or bug in a module can break the complete system
 *      b.  For each update, the complete code has to be deployed again
 *      c.  Any change in programming language or framework will affect the entire 
 *          system
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Practice Question
 *  -   What are the challenges of having the entire application code (Front end, 
 *      back end and data storage layer) as a single codebase?
 *  Ans:    If all the layers are present as a single codebase, then it would be 
 *          difficult to modify the code as it would be tightly coupled. A lot of 
 *          time and effort would be required after every minor change, as the 
 *          whole  application code would be deployed again. Thorough testing would 
 *          be required  as a change in one layer may lead to changes in other 
 *          layers. Plus, when the code will increase with time, it would become 
 *          difficult to manage. Using different technologies would be difficult 
 *          due to compatibility issues of a single codebase.
 */

/** 
 *  Choose the correct option
 *  -   Monolithic systems are also known as:
 *  Options
 *      a.  Simple system
 *      b.  Centralised system
 *      c.  Common system
 *      d.  Web application
 *  Ans:    b
 */

/** 
 *  Choose the correct option
 *  -   In which of the following situations, monolithic architecture should be 
 *      preferred:
 *  Options
 *      a.  When resources are limited
 *      b.  Developers have little to no experience
 *      c.  The application has limited number of users
 *      d.  The application has exponentially high clients
 *  Ans:    a,b,c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for monolithic system:
 *  Options
 *      a.  Difficult to secure as components are present in single system
 *      b.  Same codebase is used for development
 *      c.  Integration testing is difficult
 *      d.  All of the above
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Monolithics requires less network calls.
 *  Options
 *      a.  true
 *      b.  false
 *  Ans:    True
 */

/**
 *  Choose the correct option
 *  -   Out of the two, which web application should definitely have less latency:
 *  Options
 *      a.  Online banking application
 *      b.  Online blogging applications
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which systems should be designed as distributed:
 *  Options
 *      a.  Data intensive systems
 *      b.  High computational power systems
 *      c.  Systems having exponentially high number of clients
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Distributed systems are the same as horizontal scaling.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    b
 *      -   Distributed systems have different components running on different  
 *          machines, but in horizontal scaling, the same components are  
 *          instantiated and run on different machines. In distributed systems, 
 *          the components need to communicate through network calls but in 
 *          horizontal scaling a machine can complete the whole task without 
 *          any need to communicate with others. 
 */

/**
 *  Choose the correct option
 *  -   Which among the following is an application of Distributed Systems?
 *  Options 
 *      a.  Both B and C
 *      b.  Telephone/Cellular Network
 *      c.  Multiplayer online games
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for distributed systems:
 *  Options
 *      a.  The nodes are not connected via network calls
 *      b.  Commodity hardware should never be used
 *      c.  For user it appears as a single system
 *      d.  For user it should appear as different systems
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Network issues and Commodity Hardware were responsible for the failure of:
 *  Options
 *      a.  Monolithic systems
 *      b.  Distributed systems
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Redundancy and replication were introduced as solution for which of the 
 *      following:
 *  Options 
 *      a.  Monolithic systems
 *      b.  Distributed systems
 *  Ans:    b
 */

/**
 *  Practice Question
 *  -   How replication can help in avoiding data loss in the distributed systems?
 *  Ans:    In a distributed system environment since nodes can be geographically 
 *      distributed, a node can crash due to any reason such as natural disasters, 
 *      power failures or scalability issues. Since the data is replicated on 
 *      multiple servers , these replicas provide the backup and can take over 
 *      avoiding the single point of failure for data.)
 */

/**
 *  Assignment
 *  -   Suppose you have to build an e-commerce application that takes orders from 
 *      the customers, verifies inventory and ships the products to them. It must 
 *      also support different clients such as desktop browsers, mobile browsers 
 *      and mobile applications.
 * 
 *  Part A
 *  -   Think of the different layers and components it should have?
 *  Ans:    User interface showing products available in store, a business logic 
 *          layer which has components like, catalogue, order, payment, shipping 
 *      etc. and the data access layer containing all the data.
 * 
 *  Part B
 *  -   If you have a team of new developers who should be made productive at the 
 *      earliest,which kind of architectural pattern would you prefer? Why?
 *  Ans:    Monolithic. Since it's the beginning of development, the code would be 
 *          simple and easy to modify.
 *  
 *  Part C
 *  -   Suppose after some time, the application becomes larger, with more clients 
 *      and a larger team size. Will the current approach have any drawbacks?
 *  Ans:    Yes, large code will make it difficult to manage and  perform testing 
 *          due to high coupling. A huge number of clients lead to overloaded 
 *      servers and hence the need for scalability. 
 *  
 *  Part D
 *  -   Which components should be scaled to run the application smoothly?
 *  Ans:    Web server should be scaled to handle incoming requests of clients, 
 *          systems would inc computational power to handle large number of 
 *      operations, database servers should also be accessed
 * 
 *  Part E
 *  -   Is there any drawback of scaling the existing monolithic application?
 *  Ans:    With a monolithic architecture, we cannot scale each component 
 *          independently, also scalability is possible only up to a certain limit.
 *  
 *  Part F
 *  -   Can you think of the benefit of using distributed architecture for this 
 *      scenario?
 *  Ans:    Distributed systems will help in scaling the components independently,
 *          heterogeneous technologies can be used for  faster operations,  large 
 *      teams can work independently on the  individual components of the   
 *      application, easy management of complex code , easy testing of components 
 *      etc.
 */