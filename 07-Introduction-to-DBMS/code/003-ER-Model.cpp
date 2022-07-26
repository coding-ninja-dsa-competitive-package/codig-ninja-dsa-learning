/**
 *  MCQ - 1
 *  -   ER diagram represents which of the following data models:
 *  Options
 *      a.  Conceptual 
 *      b.  Physical
 *      c.  Logical
 *      d.  Minimised
 *  Ans:    a
 *  -   ER diagram creation is part of the conceptual design process wherein we identify 
 *      entities, relationships, attributes, types of entities, etc. They come under the 
 *      category of conceptual data models
 */

/**
 *  MCQ - 2
 *  -   ER diagrams are usually created after we design the databases
 *  Options
 *      a.  True
 *      b.  False 
 *  Ans:    b
 *  -   ER diagram creation is part of the conceptual design process wherein we identify 
 *      entities, relationships, attributes,types of entities, types of attributes etc; 
 *      which is then followed by creation of the schemas and databases.
 */

/**
 *  MCQ - 3
 *  -   Why do we use ER diagrams?
 *  Options
 *      a.  It acts as a blueprint for designing the database
 *      b.  It helps in the identification of entities, attributes, relationships between 
 *          various entities
 *      c.  It can be translated into relational models
 *      d.  All of the above.
 *  Ans:    d
 *  -   The main purpose of using ER diagrams are
 *      1.  Modelling how the data is stored in the database is important. ER diagrams 
 *          help to design the database hence it also acts as a Blueprint of the database. 
 *      2.  It tells the user about the different entities, attributes, etc., that are 
 *          used in the database. Apart from that, It also helps users define the 
 *          relationship between different entities of the databases. Users can identify 
 *          all the entities, attributes, and relationships by seeing the ER diagram.
 *      3.  We can create a relational model of a database with the help of ER diagram. 
 *          ER diagram represents data graphically that helps create a relational model.
 */

/**
 *  MCQ - 4
 *  -   Entities, attributes and relationships are the three important components of ER 
 *      Diagram.
 *  Options
 *      a.  True
 *      b.  False 
 *  Ans: a
 *  -   The three main components of ER diagram are: 
 *      1.  Entity: An entity is an object that stores data in the database. An entity 
 *          consisting of one or more attributes and a unique key.
 *      2.  Attributes:  It is a single-valued property of either an entity-type or a 
 *          relationship type.
 *      3.  Relationships: A relationship is an association between 2 or more entities. 
 */

/**
 *  MCQ - 5 (Primary Key)
 *  -   For an entity Book, which attribute can be made the primary key
 *  Options
 *      a.  Book_price
 *      b.  Book_name
 *      c.  Book_code 
 *      d.  Publish_date    
 *  Ans:    c
 *  -   Book_price, Book_name and Publish_date can be the same for different books. 
 *      Book_code is the only attribute which would be unique for each book and hence 
 *      can be made the Primary key.
 */

/**
 *  MCQ - 6
 *  -   Which of the following is true for entity
 *  Options
 *      a.  It can be related to another entity
 *      b.  It has a key attribute
 *      c.  It can have one or many attributes
 *      d.  All of the above 
 *  Ans:    d
 *  -   An entity is an object that stores data in the database. An entity consisting of 
 *      one or more attributes and a unique key.
 *  -   An entity can be represented by the following points below.
 *      1.  Entities take part in relationships. We can see different entities having a 
 *          relationship with each other.
 *      2.  An entity consists of a Key attribute which is known as a Unique key.
 *      3.  An Entity can have more than one attribute.
 */

/**
 *  MCQ - 7
 *  -   Any entity which does not has its own primary key is known as
 *  Options
 *      a.  Unknown entity
 *      b.  Strong entity
 *      c.  Hard entity
 *      d.  Weak entity 
 *  Ans:    d
 *  -   Weak entity does not have its own primary key and hence depends on some other 
 *      entity called Strong entity.
 */

/**
 *  MCQ - 8 (Weak Entity)
 *  -   How is a weak entity represented: -
 *  Options:
 *      a.  double-square
 *      b.  double-circle
 *      c.  double-diamond
 *      d.  dashed-circle
 *  Ans:    a
 *  -   A weak entity set is usually dependent on a strong entity set to ensure its 
 *      existence and it does not have any primary key rather contains a discriminator 
 *      or a partial key to differentiate between the records present in the weak entity 
 *      set table. It is represented with a double rectangle. It needs to have 
 *      participation
 */

/**
 *  MCQ - 9 (Entity)
 *  -   An entity can be
 *  Options
 *      a.  related to only one other entity
 *      b.  related to itself
 *      c.  related to only two other entities
 *      d.  related to many other entities 
 *  Ans:    d
 *  -   An entity can be related to many different entities , including itself. 
 *      For an University ER diagram, the entity Course can be related to entities such as:
 *      Students. Professor, Fees, Workshops etc.
 */

/**
 *  MCQ - 10 (Attributes)
 *  -   For library management system, the Bookcode, Bookname, Authorname, Bookprice are 
 *      all an examples of
 *  Options:
 *      a.  Entities
 *      b.  Attributes 
 *      c.  Relationships
 *      d.  Descriptions
 *  Ans:    b
 *  -    An attribute is a single-valued property of either an entity-type or a 
 *      relationship type. In the case of the library management system, the bookcode, 
 *      Bookname, Authorname and Bookprice all are single-valued properties that are a 
 *      part of an entity book.
 */

/**
 *  MCQ - 11
 *  -   In a library management system a student can borrow maximum of 3 books in a 
 *      semester, so in ER diagram the “Book_name” attribute should be represented as :
 *  Options:
 *      a.  double-square
 *      b.  dashed-circle
 *      c.  double-circle
 *      d.  none of these
 *  Ans:    c
 *  -   Here, Book_name is a multivalued attribute as more than 1 book can be borrowed. 
 *      Multivalued attributes are represented with double ovals
 */

/**
 *  MCQ - 13
 *  -   A student can book a maximum of three books but each book can be booked by only 
 *      one student, so the relationship between student and book is
 *  Options
 *      a.  Many-to-many
 *      b.  One-to-many 
 *      c.  Many-to-none    
 *      d.  One-to-one
 *  Ans:    b
 *  -   A student can borrow a maximum of 3 books. This means that a student instance can 
 *      be related to any books i. So, One student can have many books. Also, we know a 
 *      book can be borrowed only by a single student. So the relationship between them 
 *      must be described as one to many.
 *  -   It will not be many-to-many as one book cannot be borrowed by multiple students 
 */

/**
 *  MCQ - 14 (Relationship)
 *  -   Which of the following is used to represent the relationship in an E-R diagram
 *  Options
 *      a.  circles
 *      b.  rectangles
 *      c.  diamond 
 *      d.  ellipse
 *  Ans:    A diamond symbol is used to represent a relationship between different entities 
 *          in an ER diagram.
 */

/**
 *  MCQ - 15 (Relationship)
 *  -   Each student gets only one login ID for the online library system. So, the 
 *      relationship between student and login ID is
 *  Options
 *      a.  M:N
 *      b.  1:N
 *      c.  N:1
 *      d.  1:1 
 *  Ans: d
 *  -   According to the statement, A student is getting only one login ID. This means 
 *      that  a single  student will be related to a single  Login id. are. So the answer 
 *      must be 1:1.
 */

/**
 *  MCQ - 16 (ER Diagram)
 *  -   Which of the following is considered best-practices for creating ER Diagram
 *  Options
 *      a.  Naming every entity , attribute and relationship    
 *      b.  Connecting relationships to each other
 *      c.  Same Entities are drawn multiple times
 *      d.  All of the above    
 *  Ans:    a
 *  -   Relationships should not be connected to each other, they should connect entities.      
 *      Similarly, every entity should bed drawn only once in the diagram.
 */

/**
 *  MCQ - 17 (ER Diagram)
 *  -   Which of the following is not true for ER Diagram
 *  Options
 *      a.  ER Diagram is a visual representation for ER model
 *      b.  ER diagrams has three components: entities, relationships and attributes
 *      c.  ER diagram is not a high level data model diagram 
 *      d.  All of the above
 *  Ans:    c
 *  -   ER Diagram is a high level data model diagram, which helps in visualising  and 
 *      designing the database components.
 */

/**
 *  MCQ - 18 
 *  -   Which of the following is a type of abstraction in which entities with relationships 
 *      come together to form higher level entity
 *  Options
 *      a.  Generalization
 *      b.  Specialization
 *      c.  Aggregation 
 *      d.  None of the above
 *  Ans:    c
 *  -   Aggregation is used when we need to express a relationship among relationships. It 
 *      is like abstraction through which relationships are treated as higher-level 
 *      entities. In this multiple entities are considered as a single entity and again 
 *      this single entity has a relationship with another entity. 
 */

/**
 *  MCQ - 19
 *  -   If textbook, magazine, journal, encyclopedia entities are derived from the Book 
 *      entity , then it is an example of
 *  Options
 *      a.  Specialization 
 *      b.  Generalization
 *      c.  Aggregation
 *      d.  None of the above
 *  Ans:    a
 *  -   In Specialization, based on distinguishing properties an entity is broken down 
 *      into multiple sub-entities.
 */

/**
 *  MCQ - 20 (Generalisation)
 *  -   Which is true for Generalisation:
 *  Options
 *      a.  It is a top down approach
 *      b.  It is a bottom up approach 
 *      c.  both a. and b.
 *  Ans:    b
 *  -   In generalisation, the sub entities are combined together resulting in the 
 *      formation of a parent entity set on the basis of some common features.   The new 
 *      entity thus formed contains all the features of the sub entities. Generalisation 
 *      is a process which follows a Bottom-to-Up approach.
 */

/**
 *  MCQ - 21
 *  -   The process of designating sub groupings within the entity set is called as _______.
 *  Options
 *      a.  Specialization
 *      b.  Division
 *      c.  Aggregation
 *      d.  Finalization
 *  Ans:    a
 *  -   With Respect to ER Model, specialisation is the procedure to split up the entities 
 *      into further sub entities on the basis of their functionalities, specialities and 
 *      features. These sub-designation of entities are distinctive from other entities 
 *      in the set. 
 */

/**
 *  MCQ - 22
 *  -   An abstraction concept for building a composite object from their individual 
 *      component object is?   
 *  Options
 *      a.  generalization
 *      b.  aggregation 
 *      c.  association
 *      d.  specialization
 *  Ans:    b
 *  -   In Aggregation multiple entities are considered as a single entity and again this
 *      single entity can have relationship with another entity. It treats relationships 
 *      as an abstract entity.
 */