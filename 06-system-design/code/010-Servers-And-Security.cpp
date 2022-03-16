/**
 *  Choose the correct option
 *  -   Which of the following is true for the PULL method?
 *  Options
 *      a.  It is the default mode of HTTP communication
 *      b.  The server can send the data without the request from the client
 *      c.  Multiple request from the client may waste network bandwidth and increases 
 *          the load on the server  
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for the PUSH method?
 *  Options
 *      a.  The client sends multiple requests for the same information until it receives it    
 *      b.  The server keeps pushing the new updates whenever available to the client
 *      c.  Push notifications on the mobile is an example of this method
 *      d.  This method reduces the load of requests on the servers
 *  Ans:    b, c, d
 */

/**
 *  Choose the correct option
 *  -   Which of the following are challenges of long polling?
 *  Options
 *      a.  Ordering of the message cannot be guaranteed when multiple connection are 
 *          established
 *      b.  Message delivery cannot be guaranteed, which may lead to message loss
 *      c.  Both A and B    
 *  Ans:    c
 */

/**
 *  Choose the correct option
 *  -   Which of the following statement is/are true?
 *  Options
 *      a.  Web socket should be preferred when we have bi-directional data flow between 
 *          client and server
 *      b.  Web socket keep the client-server connection for as long as required
 *      c.  Web sockets should not be used when we need a dedicated connection
 *      d.  All of the above
 *  Ans:    a, b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are applications of web sockets?
 *  Options
 *      a.  Messaging applications
 *      b.  Real time video streaming
 *      c.  Complex browser based multiplayer games
 *      d.  All of the above
 *  Ans:    d
 *  -   All these applications need a dedicated connection that remains open so that the 
 *      data can flow in proper order securely and immediately from both sides.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true for server-side events?
 *  Options
 *      a.  The server can initiate the connection with the client
 *      b.  The server automatically pushes the data whenever updates are required
 *      c.  The incoming messages from the server are treated as events
 *      d.  Displaying stock prices on the UI can be one of the application of SSE
 *  Ans:    b, c, d
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true regarding polling?
 *  Options     
 *      a.  Long polling connections get closed faster than the polling connection
 *      b.  In long polling instead of sending an empty response, the server holds the 
 *          response till it has some update for the client
 *      c.  The server closes the connection once it receives a request from the client.
 *      d.  All of the above
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   A proxy server is a hardware or a piece of software that is placed between a 
 *      client and an application to provide intermediary services in the communication.
 *      State whether the following statement is True/False.
 *  Options
 *      a.  True    
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which of the following can be the functions of forward proxy?
 *  Options
 *      a.  To provide protection to the client by filtering the outgoing requests and 
 *          incoming responses
 *      b.  To give access to malicious websites
 *      c.  Enforcing “terms of use” of a network
 *      d.  Caching external site contents for better user experience
 *  Ans:    a, c, d
 */

/**
 *  Choose the correct option
 *  -   Which of the following can be the functions of reverse proxy?
 *  Options
 *      a.  Provide load balancing for the server
 *      b.  Prevention from malicious attacks such as Denial of Services
 *      c.  Allows administrators to swap the backend servers without disturbing the traffic
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   Which of the following handling requests is used by the content delivery network 
 *      (CDN)?
 *  Options
 *      a.  Forward proxy
 *      b.  Reverse proxy
 *  Ans:    b
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true for API gateway?
 *  Options
 *      a.  It can authenticate an incoming API call
 *      b.  It can act as a load balancer and keep track of requests sent to different 
 *          nodes of the network
 *      c.  Acts as a single entry point into the system
 *      d.  All of the above
 *  Ans:    d
 */

/**
 *  Choose the correct option
 *  -   For the clients, an API gateway can hide the details of how the application is 
 *      divided into microservices. State whether the following statement is true/false.
 *  Options
 *      a.  True
 *      b.  False
 *  Ans:    a
 */

/**
 *  Choose the correct option
 *  -   Which type of proxy should be used when an organisation wants to avoid phishing 
 *      attacks on its network by blocking malicious domains which of the following should      
 *      be used?
 *  Options
 *      a.  Reverse Proxy
 *      b.  Forward Proxy
 *  Ans:    b
 *  -   Forward proxy is used to prevent accessing of malicious websites.
 */

/**
 *  Choose the correct option
 *  -   Which type of proxy should be used for a large organisation having multiple 
 *      servers where an administrator has to onboard a new user on the network and 
 *      this user should have appropriate access rights for each server?
 *  Options
 *      a.  Reverse Proxy
 *      b.  Forward Proxy
 *  Ans:    a
 *  -   Reverse proxy. The administrator would have to configure each server for which the 
 *      access has to be given but since the organisation had multiple servers, it would 
 *      become very time taking and may sometimes lead to errors. Instead, the admin can    
 *      configure access rights using the Reverse proxy which can route all the traffic 
 *      through it. The backend server would now only communicate with the proxy.
 */

/**
 *  Choose the correct option
 *  -   Which type of proxy should be used if a company wants to expose an API to allow 
 *      querying of data but not to allow any modifications of data?
 *  Options
 *      a.  Reverse Proxy
 *      b.  Forward Proxy
 *  Ans:    a
 *  -   Reverse proxy. The company needs to filter out all the received requests other 
 *      than HTTP GET before passing it to the servers to process and provide the response.
 */

/**
 *  Choose the correct option
 *  -   Which of the following is true?
 *  Options
 *      a.  HTTP Basic Authentication is a standardized way to request client           
 *          authentication credentials
 *      b.  Multi factor authentication of the user is possible with Basic Authentication
 *      c.  Basic authentication does not require cookies and session IDs.
 *  Ans:    a, c
 */

/**
 *  Choose the correct option
 *  -   Which of the following is/are true?
 *  Options
 *      a.  OAuth is the most preferred option to identify personal user accounts
 *      b.  Multi factor authentication can be used
 *      c.  OAuth shares the password data of the user
 *      d.  OAuth does not share the password data of the user , instead uses authorization 
 *          token to establish the identity of the user
 *  Ans:    a, b, d
 */