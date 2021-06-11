# string

>   **C++** has in its definition a way to represent sequence of characters as an object of class. This class is called **std::string**

>   **String** class stores the characters as a sequence of bytes with a functionality of allowing access to single byte character. 

---

### string vs char array
  
-   A **character array** is simply an array of characters can terminated by a **null character**. A string is a class which defines objects that be represented as **stream of characters**.
-   Size of the character array has to allocated **statically**, more memory cannot be allocated at run time if required. Unused allocated memory is wasted in case of character array. In case of strings, memory is allocated **dynamically**. More memory can be allocated at run time on demand. As no memory is preallocated, no memory is wasted.
-   **Character array** do not offer much inbuilt functions to manipulate strings. **String** class defines a number of functionalities which allow manifold operations on strings.

---

### Problem - Code In Action

[001 - String Basic](./code/001-Basics.cpp)<br>
[002 - Print All Substrings](./code/002-Print-All-Substrings.cpp)<br>

---
