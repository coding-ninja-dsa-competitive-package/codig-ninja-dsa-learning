/**
 *  Choose the correct option
 *  -   A Bank’s database has two tables: savings and current. Ram(Customer ID: 10233276) 
 *      wants to move Rs. 20,000 from the current account to a savings account. Choose 
 *      the correct SQL for this transaction.
 *  Options
 *      a.  Option 1: 
 *          SELECT balance FROM checking WHERE customer_id = 10233276; 
 *          UPDATE current SET balance = balance - 200.00 WHERE customer_id = 10233276; 
 *          UPDATE savings SET balance = balance + 200.00 WHERE customer_id = 10233276; 
 *          START TRANSACTION;
 *      b.  Option 2: 
 *          START TRANSACTION; 
 *          SELECT balance FROM checking WHERE customer_id = 10233276; 
 *          UPDATE current SET balance = balance - 200.00 WHERE customer_id = 10233276; 
 *          UPDATE savings SET balance = balance + 200.00 WHERE customer_id = 10233276; 
 *          COMMIT;
 *      c.  Option 3: 
 *          START TRANSACTION; 
 *          SELECT balance FROM checking WHERE customer_id = 10233276; 
 *          UPDATE current SET balance = balance + 200.00 WHERE customer_id = 10233276; 
 *          UPDATE savings SET balance = balance - 200.00 WHERE customer_id = 10233276; 
 *          COMMIT;
 *      d.  Option 4: 
 *          START TRANSACTION; 
 *          UPDATE current SET balance = balance + 200.00 WHERE customer_id = 10233276; 
 *          SELECT balance FROM checking WHERE customer_id = 10233276; 
 *          UPDATE savings SET balance = balance - 200.00 WHERE customer_id = 10233276; 
 *          COMMIT;
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Choose the correct SQL statement to select all columns from the table named 
 *      CodingNinjas for rows where “LastName” column value is “David”.
 *  Options
 *      a.  SELECT * FROM CodingNinjas FOR Last_Name='Davd';
 *      b.  SELECT * FROM CodingNinjas FOR Last_Name='David';
 *      c.  CHOOSE * FROM CodingNinjas WHERE Last_Name='David';
 *      d.  SELECT * FROM CodingNinjas WHERE Last_Name='David';
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which database would you select for multi-row transactions?
 *  Options
 *      a.  Cloud Database
 *      b.  Relational Database
 *      c.  Hierarchical Database
 *      d.  NoSQL Database
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following databases would be better for semi-structured or 
 *      unstructured data like JSON or documents.
 *  Options
 *      a.  Distributed database
 *      b.  Network database
 *      c.  NoSQL database
 *      d.  Relational database
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Suppose there is a table(Students) with the SELECT Query given below. Which column 
 *      can be considered for indexing in reference to the query?
 *          SELECT student_id, class FROM Students WHERE first_name='Vishwa' 
 *  Options
 *      a.  student_id
 *      b.  Vishwa
 *      c.  class
 *      d.  first_name
 *  Ans:    d
 *  -   student_id and class are referenced in the SELECT portion and MySQL will not use 
 *      them to limit the chosen rows. Therefore, indexing them will make no difference. 
 *      first_name is referenced in the WHERE clause and it will be used to search the 
 *      particular record. So, first_name should be indexed for query optimization and 
 *      faster searching. 
 */

/**
 *  Choose the correct option
 *  -   A table named student has the following columns : “studentid, lname, fname, age, 
 *      phone, EmailId, DepartmentId”. EmailId is the candidate key and the DepartmentId 
 *      is the foreign key. The studentid is the primary key column and is often used to 
 *      lookup rows. Which column would be suitable for indexing in the student table.
 *  Options
 *      a.  Email_Id
 *      b.  Department_Id
 *      c.  Student_id
 *      d.  age
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   If 5 million entries are stored in a table and all the columns of the table take 4 
 *      bytes size on the disk. What should be the size of the index of the table?
 *  Options
 *      a.  16 bytes
 *      b.  36.5 MB
 *      c.  1.24 MB
 *      d.  20 MB
 *  Ans:    d
 *  -   Indexes will be created using unique database columns.
 *      Number of entries: 5,000,000
 *      Size of one column entry: 4 bytes
 *      The total size of indexing column: 5000000 * 4 =20000000 bytes = 20 MB 
 */

/**
 *  Choose the correct option
 *  -   A table named students consists of columns including “id, name, class, address, 
 *      phone_number”. The teacher wishes that all the students of class 8th and class 9th 
 *      are separated into different tables. Which partitioning criteria will you use?
 *  Options
 *      a.  Range partitioning
 *      b.  Hash Based partitioning
 *      c.  List partitioning
 *      d.  Round-robin partitioning
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   The SQL for a table named exam with three columns consisting of id, subject and 
 *      date is shown below:
 *          CREATE TABLE exam (col1 INT, col2 CHAR(5), col3 DATE)
 *          PARTITION BY HASH( YEAR(col3) )
 *          PARTITIONS 5;
 *      You want to insert a record to the table exam with the given column 3 value as 
 *      “2021-01-09”. The record is stored in which partition?
 *  Options
 *      a.  1   b.  2   c.  3   d.  4
 *  Ans:    a
 *  -   A record is stored in a partition from the predetermined partitions which is:
 *      partition number = MOD(expression, Number of partitions)
 *      Here,   => MOD(YEAR('2021-01-09),5)
 *              => MOD(2021,5)
 *              => 1
 */

/**
 *  Choose the correct option
 *  -   Two servers are communicating with each other in real-time. Server A sends MX types 
 *      of messages and server B sends MY types of messages. The processing time of MX is 
 *      10ms and MY is 4ms. The network round trip time is 2ms. The sending of MX types 
 *      and MY types are executed serially. A and B are single-threaded. What will be the 
 *      best case overall latency of sending and acknowledging 10 MX and 10 MY messages 
 *      from A to B?
 *  Options
 *      a.  100ms
 *      b.  160ms       
 *      c.  200ms
 *      d.  180ms
 *  Ans:    d
 *  -   Latency = Processing time + Network latency
 *          Here, Network latency = 2ms. 
 *          Processing time of MX = 10ms.
 *          Processing time of MY = 4ms.
 *          Total time = (count of MX)(latency of MX) + (count of MY)(latency of MY) 
 *          = 10*(10+2) + 10*(4+2) 
 *          = 120 + 60 = 180ms
 */

/**
 *  Choose the correct option
 *  -   Suppose both A and B are multi-threaded. What will be the best case latency then?
 *  Options
 *      a.  100ms
 *      b.  120ms
 *      c.  140ms
 *      d.  160ms
 *  Ans;    b
 *  -   Asynchronous communication is possible here since the asynchronous model allows 
 *      multiple calls to be executed at the same time. The latency would therefore be the 
 *      maximum of the latency of MX and latency of MY because first calls can execute on 
 *      separate threads while second calls are pending execution.
 *          Latency = 10*(10+2) = 120ms
 */

/**
 *  Choose the correct option
 *  -   You want to develop a note-taking application like Google Docs where multiple 
 *      people can write, read and update simultaneously without worrying about the     
 *      access of the notes or passing the updated document in a group. Which type of 
 *      communication would you use?
 *  Options
 *      a.  Synchronous Communication
 *      b.  Asynchronous Communication  
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Suppose you are sitting in your classroom and the professor is teaching system 
 *      design. You were not paying attention in the class and the professor noticed it. 
 *      He asked you to stand up and answer a few questions. What kind of communication 
 *      is this?
 *  Options
 *      a.  Synchronous Communication
 *      b.  Asynchronous Communication
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   An online gaming application uses inbuilt functionalities like GPS service of the 
 *      device. Which architectural style is suitable for this application:
 *      Options
 *          a.  Pooled architecture
 *          b.  Converged architecture
 *          c.  Service Oriented Architecture
 *          d.  Integrated Architecture
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Which of the following are not the principles of Service-Oriented Architecture?
 *  Options
 *      a.  Reusability
 *      b.  Strict coupling
 *      c.  Abstraction
 *      d.  Autonomy
 *  Ans:    b
 */

/**
 *  Practice Question
 *  -   Ram wants to build an online shopping application that supports XML and JSON using 
 *      the REST API. Which HTTP request method should be used for:
 *      Request to /user/ returns a list of registered users on a system
 *      Specify the answer in capital letters
 *  Ans:    GET
 */

/**
 *  Practice Question
 *  -   Ram wants to build an online shopping application that supports XML and JSON using 
 *      the REST API. Which HTTP request method should be used for:
 *      Request to /user/123 creates a user with the ID 123 using the body data(JSON 
 *      encoded data string)
 *      Specify the answer in capital letters.
 *  Ans:    POST
 */

/**
 *  Practice Question
 *  -   Ram wants to build an online shopping application that supports XML and JSON using 
 *      the REST API. Which HTTP request method should be used for:
 *      Request to /user/123 updates user 123 with the body data(JSON encoded data string)
 *      Specify the answer in capital letters   
 *  Ans:    PUT
 */

/**
 *  Practice Question
 *  -   Ram wants to build an online shopping application that supports XML and JSON using 
 *      the REST API. Which HTTP request method should be used for:
 *      Request to /user/123 returns the details of user 123
 *      Specify the answer in capital letters
 *  Ans:    GET
 */

/**
 *  Practice Question
 *  -   Ram wants to build an online shopping application that supports XML and JSON using 
 *      the REST API. Which HTTP request method should be used for:
 *      Request to /user/123 deletes user 123
 *      Specify the answer in capital letters
 *  Ans:    DELETE
 */

/**
 *  Choose the correct option
 *  -   Which of the following is the most common HTTP Status Code for successful requests?
 *      Options
 *      a.  200
 *      b.  404
 *      c.  412
 *      d.  303
 *  Ans:    200
 */

/**
 *  Practice Question
 *  -   While designing an online shopping application, identify the main services provided 
 *      for shopping.
 *  Ans:    The main services for online shopping applications are shopping, discount and 
 *          payment mode. 
 *      1.  Shopping/Cart: Shopping is the primary service provided by online shopping 
 *          websites. They offer a variety of online shopping options via which we may 
 *          purchase anything. There can be different varieties of products linked in 
 *          the inventory. The other services included in this service are cart, inventory 
 *          etc.
 *      2.  Discounts: Many internet businesses also provide discounts. During the festive 
 *          and wedding seasons, different discounts can be offered.
 *      3.  Payment method: The payment mode would depend on the user and should be handled 
 *          for both pay on delivery and credit card payments. 
 *      4.  Confirmation service: The payment method can be linked to the confirmation 
 *          service where users would be notified by message or mail on successful payment 
 *          or order.
 */

/**
 *  Practice Question
 *  -   We want to design an authentication system which is an online shopping application. 
 *      How would the basic authentication work for the system?
 *  Ans:    Basic authentication is the simplest type of authentication. It would consist 
 *          of the following steps:
 *      1.  Fetch the user credentials including username and password from the user.
 *      2.  Encode it using base64 encoding schemes.
 *      3.  Send it along with the HTTP request by attaching it with the authorization 
 *          header. 
 */

/**
 *  Practice Question
 *  -   What will be the challenges with the above-mentioned authentication technique?
 *  Ans:    Since the credentials are encoded using base64 encoding scheme, it is easy to 
 *      decode it and therefore poses huge security issues. It is also not safe to send 
 *      confidential information like password over the HTTP request.
 */

/**
 *  Practice Question
 *  -   How would the session/cookie-based authentication work for this system?
 *  Ans:    Session/cookie authentication is the most commonly used type of authentication. 
 *          It would consist of the following steps:
 *      1.  Fetch the user credentials including username and password from the user.
 *      2.  Using form parameters, it is sent to the server.
 *      3.  Validation takes place on the server using the credentials received from step2.
 *      4.  If the validation is successful, the server creates a cookie that is sent as a 
 *          response.
 *      5.  The cookie/session is used for all requests in future then.
 */

/**
 *  Practice Question
 *  -   What will be the challenges with the above-mentioned authentication technique?
 *  Ans:    It is suitable for only a single domain system. If the online shopping 
 *      application is both web and app based, this won't be a suitable authentication 
 *      solution. This technique has security issues because the cookie can be misused. 
 */

/**
 *  Practice Question
 *  -   How would token-based authentication work for this system?
 *  Ans:    Token authentication is the stateless type of authentication. It would consist 
 *      of the following steps:
 *      1.  Fetch the user credentials including username and password from the user.
 *      2.  Using form parameters, it is sent to the server.
 *      3.  Authorization takes place on the server using the credentials received from 
 *          step2.
 *      4.  If the validation is successful, the server creates a signed token(can be used 
 *          by the user to verify identity without entering credentials) JWT(JSON Web Token) 
 *          which is sent as a response.
 *      5.  The Token is used for all requests in future then.
 */

/**
 *  Practice Question
 *  -   What will be the challenges with the above mentioned authentication technique?
 *  Ans:    If once validated, the access of the user cannot be revoked. It is important 
 *      to safely handle the token and can be prone to security issues.
 */

/**
 *  Practice Question
 *  -   How would the OAuth work for this system?
 *  Ans:    
 *      OAuth is the extension of the token-based type of authentication. It would consist 
 *      of the following steps:
 *      1.  The authentication request is sent by the user.
 *      2.  The server validates the user by checking for an existing account and returning 
 *          back with an authorization grant.
 *      3.  The application requesting authentication then uses the grant for accessing 
 *          information.
 *      4.  On authorization, a token is generated for the access.
 *      5.  The resource can then be accessed using this token.
 */

/**
 *  Practice Question
 *  -   Which one would be the best choice for authentication method for your online 
 *      shopping application from all the above-mentioned techniques.
 *  Ans:    OAuth would be the most secure and reliable technique for authentication and 
 *      identification of personal accounts and giving user permissions.
 */
