/**
 *  Declaring a variable:
 *  ====================
 *  ->  To declare a variable, we should always know what type of value it should hold, whether it’s
 *      an integer (int), decimal number (float, double), character value (char). In general, the 
 *      variable is declared as follows:
 *              Datatype variableName = VALUE;
 *      Note: Datatype is the type of variable:
 *      -   int : Integer value
 *      -   float, double : Decimal number
 *      -   char : Character values (including special characters)
 *      -   bool : Boolean values (true or false)
 *      -   long : Contains integer values but with larger size
 *      -   short : Contains integer values but with smaller size
 *  ->  Table for datatype and its size in C++: (This can vary from compiler to compiler and system
 *      to system depending on the version you are using):
 *              Datatype    |   Default size
 *                bool      |      1 byte
 *                char      |      1 byte
 *                short     |      2 bytes
 *                int       |      4 bytes
 *                long      |      8 bytes
 *                float     |      4 bytes
 *                double    |      8 bytes
 *      For example: To declare an integer variable ‘a’ with a value of 5, the structure looks like:
 *              int a = 5;
 *      Similarly, this way other types of variables can also be declared. There is one more type of
 *      variable known as string variables which store combinations of characters.
 * 
 *  ->  Rules for variable names:
 *      ========================
 *      -   Can’t begin with a number.
 *      -   Spaces and special characters except underscore(_) are not allowed.
 *      -   C++ keywords (reserved words) must not be used as a variable name.
 *      -   C++ is case-sensitive, meaning a variable with name ‘A’ is different from variable with
 *          name ‘a’. (Difference in the upper-case and lower-case holds true).
 *  
 *  How is data Stored ?
 *  ==================
 *  1.  For integers:   
 *      ------------
 *      ->  The most commonly used is a signed 32-bit integer type. When you store an integer,
 *          its corresponding binary value is stored. There is a separate way of storing positive
 *          and negative numbers. For positive numbers the integral value is simply converted
 *          into binary value while for negative numbers their 2’s complement form is stored.
 *          -   For negative numbers:
 *              ->  Computers use 2’s complement in representing signed integers because:
 *                  -   There is only one representation for the number zero in 2’s complement,
 *                      instead of two representations in sign-magnitude and 1’s complement.
 *                  -   Positive and negative integers can be treated together in addition and
 *                      subtraction. Subtraction can be carried out using the addition logic.
 * 
 *          For example: int i = -4;
 *          Steps to calculate Two’s Complement of -4 are as follows:
 *              Step1: Take Binary Equivalent of the positive value (4 in this case)
 *                          0000 0000 0000 0000 0000 0000 0000 0100
 *              Step2: Write 1’s complement of binary representation by inverting the bits
 *                          1111 1111 1111 1111 1111 1111 1111 1011
 *              Step3: Find 2’s complement by adding 1 to the corresponding 1’s complement
 *                          1111 1111 1111 1111 1111 1111 1111 1011
 *                         +0000 0000 0000 0000 0000 0000 0000 0001
 *                          ----------------------------------------
 *                          1111 1111 1111 1111 1111 1111 1111 1100
 *          Thus, integer -4 is represented by the above binary sequence in C++.
 *  2.  For float and double values:
 *      ---------------------------
 *      ->  In C++, any value declared with a decimal point is by-default of type double (which is
 *          generally of 8-bytes). If we want to assign a float value (which is generally of 4-bytes),
 *          then we must use ‘f’ or ‘F’ literal to specify that the current value is “float”.
 *          For example:
 *              float var = 10.4f // float value
 *              Double val = 10.4 // double value
 *  3.  For character values:
 *      --------------------
 *      ->  Every character has a unique integer value, which is called ASCII value. As we know,
 *          systems only understand binary language and thus everything has to be stored in
 *          the form of binaries. So, for every character there is a corresponding integer code-ASCII 
 *          code and the binary equivalent of this code is actually stored in memory when we try to 
 *          store a character.
 *          -   For ASCII values, refer the link : https://ascii.cl/
 *  #   Adding int to char:
 *      ------------------
 *      ->  When we add int to char, we are basically adding two numbers i.e., one corresponding to 
 *          the int and the other corresponding to the ASCII code for the character.
 *          For ex, 'a'+1 will result into 98 because the ASCII value of 'a' is 97 , so it printed 97+1 = 98.
 * 
 *  #   Compiler assigns a garbage value to an uninitialised local variable in C++ Programming.
 */
#include<iostream>
using namespace std;

int main(){
    bool a = true;
    cout << a<<endl; //will print 1.
    cout<<"========================"<<endl;

    cout << ('a' + 1)<<endl; //will print 98
    cout<<"========================"<<endl;

    int i = 'c';
    cout << i << endl; //will print 99
    cout<<"========================"<<endl;

    char c = 74;
    cout << c <<endl;
    cout<<"========================"<<endl;

    int a1 = 10;
    char ch = 'a';
    ch = ch + a1;
    cout << ch << endl; // will print k which is 107
    cout<<"========================"<<endl;

    return 0;
}