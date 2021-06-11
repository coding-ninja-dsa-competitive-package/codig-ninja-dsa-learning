# OOPS - Object Oriented Programming

>   ```Object Oriented Programming (OOP)``` is a programming paradigm where the complete software operates as a bunch of objects talking to each other. An ```object``` is a collection of ```data``` and ```methods``` that operate on its data. 

---

## Concepts:

### Classes:
-   The building block of C++ that leads to **Object-Oriented programming** is a ```Class```. 
-   It is a **user-defined data type**, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class.
-   ```Data members``` are the data variables and ```member functions``` are the functions used to manipulate these variables and together these data members and member functions define the properties and behaviour of the objects in a ```Class```.
>   Example : Vehicle - Every vehicle has some propertiesa and functions.

### Objects:
-   An Object is an identifiable entity with some characteristics and behaviour. An ```Object``` is an ```instance of a Class```. 
-   When a class is defined, no memory is allocated but **when it is instantiated (i.e. an object is created) memory is allocated**.


### Encapsulation
-   In normal terms, ```Encapsulation``` is defined as **wrapping up of data and information under a single unit**. 
-   In ```Object-Oriented Programming```, ```Encapsulation``` is defined as **binding together the data and the functions** that manipulate them.
>   Exmaple : Class - which encapsulates data and functions.

### Abstraction
-   ```Abstraction``` means displaying only essential information and **hiding the details**. 
-   Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
>   Example : ATM - hides the implementation of logic for withdrawl function.

### Polymorphism
-   The word ```polymorphism``` means having **many forms**. In simple words, we can define ```polymorphism``` as the ability of a message to be displayed in more than one form.
-   Two types of ```Polymorphism```:
    1.  ```Compile-Time Polymorphism``` : 
        -   Behaviour is identified at compile time.
        -   It includes : 
            -   ```Operator Overloading```: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
            -   ```Function Overloading```: Function overloading is using a single function name to perform different types of tasks.
    2.  ```Run-Time Polymorphism```:
        -   Behaviour is identified at run time.
        -   It includes :
            -   ```Method Overriding```
-   ```Polymorphism``` is extensively used in implementing ```inheritance```

### Inheritance
-    The capability of a class to derive properties and characteristics from another class is called Inheritance. ```Inheritance``` is one of the most important features of ```Object-Oriented Programming.```
>   Example: Dog, Cat, Cow can be Derived Class of Animal Base Class.
-   Types:
    1.  ```Single Inheritance```
    2.  ```MultiLevel Inheritance```
    3.  ```Hierarchichal Inheritance```
    4.  ```Multiple Inheritance```
    5.  ```Hybrid Inheritance```

---

## Notes From Coding Ninja:
-   [Classes, Members, Objects, Constructors](./assets/OOPS-1-Classes-Members-Constructor-this.pdf)<br>
-   [Exception Handling](./assets/OOPS-3-Exception-Handling.pdf)

---

## Problems - Code In Action
[001 - Class , Object Creation, Class Members](./code-part-1/001-Play-With-Classes-Assignments.cpp)<br>
[002 - Fraction Class](./code-part-1/002-Fraction-Class.cpp)<br>
[003 - Complex Number Class](./code-part-1/003-Complex-Number.cpp)<br>
[004 - Constructors - Types](./code-part-2/001-Play-With-Constructors.cpp)<br>
[005 - Deep, Shallow Copy](./code-part-2/002-Deep-Shallow-Copy.cpp)<br>
[006 - Const, Static Members](./code-part-2/003-Const-Static-Members.cpp)<br>
[007 - Assignments - Constructors, Static, Conse](./code-part-2/004-Assignments-Constructor-Static-Const.cpp)<br>
[008 - Operator Overloading - Fraction Class](./code-part-2/005-Operator-Overloading-Fraction-Class.cpp)<br>
[009 - Polynomial Class](./code-part-2/006-Polynomial-Class.cpp)<br>
[010 - Inheritance - Explained with Types](./code-part-3/001-Inheritance.cpp)<br>
[011 - Polymorphism - Explained with Types](./code-part-3/002-Polymorphism.cpp)<br>
[012 - Virtual, Abstract, Friend Functions & Classes](./code-part-3/003-Virtual-Abstract-Friend.cpp)<br>
