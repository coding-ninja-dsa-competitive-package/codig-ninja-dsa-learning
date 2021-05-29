/**
 *  ->  C++ code begins with the inclusion of header files . There are many header files available 
 *      in the C++ programming language. So, what are these header files?
 *  ->  The names of program elements such as variables, functions, classes, and so on must be 
 *      declared before they can be used. For example, you can’t just write x = 42 without first
 *      declaring variable ‘x’ as:
 *              int x=42;
 *  ->  The declaration tells the compiler whether the element is an int, a double, a float, a
 *      function or a class. Similarly, header files allow us to put declarations in one location and
 *      then import them wherever we need them. This can save a lot of typing in multi-file programs. 
 *      To declare a header file, we use #include directive in every .cpp file. This #include is used 
 *      to ensure that they are not inserted multiple times into a single .cpp file.
 *      Note: # operator is known as Macros.
 *  ->  The following are not allowed, or are considered as bad practices while putting header files 
 *      into the code:
 *      -   Built-in-type definitions at namespace or global scope
 *      -   non-inline function definitions
 *      -   Non-const variable definitions
 *      -   Aggregate definitions
 *      -   Unnamed namespaces
 *      -   Using directives
 *  ->  Now, moving forward to the code:
 *              #include <iostream>
 *              using namespace std;
 *  ->  iostream stands for Input/Output stream, meaning this header file is necessary if you want 
 *      to take input through the user or print output to the screen. This header file contains the
 *      definitions for the functions:
 *      -   cin : used to take input
 *      -   cout : used to print output
 *  ->  namespace defines which input/output form is to be used.
 *      
 *      Note: semicolon (;) is used for terminating a C++ statement. ie. different statements in a
 *            C++ program are separated by semicolon.
 *  ->  main() function:
 *      Look at the following piece of code:
 *          int main() {
 *              Statement 1;
 *              Statement 2;
 *              ...
 *          }
 *      Starting with the line:  int main()
 *      -   int : This is the return-type of the function. You will get this thing clear once you
 *                reach the Functions topic.    
 *      -   main() : This is the portion of any C++ code inside which all the commands are written 
 *                   and gets executed.
 *          ->  This is the line at which the program will begin executing. This statement is similar 
 *              to the start block of flowcharts.
 *      -   {} : all the code written inside the curly braces is said to be in one block, also known
 *               as scope of a particular function.
 */

#include <iostream>
using namespace std;

int main(){
    //cout << code ;  //error - code was not declared in scope
    cout << "career" << "labs"; // will print careerlabs
}