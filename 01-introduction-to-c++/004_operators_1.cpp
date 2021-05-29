/**
 *  Operators in C++
 *  =================
 *  1.  Arithmetic operators:
 *      --------------------
 *      ->  These are used in mathematical operations in the same way as that in algebra.
 *      ->      OPERATOR    -   DESCRIPTION
 *                  +       -   Add two operands
 *                  -       -   Subtracts second operand from the first
 *                  *       -   Multiplies two operands
 *                  /       -   Divides numerator by denominator
 *                  %       -   Calculates Remainder of division
 *  2.  Relational operators:
 *      --------------------
 *      ->  C++ relational operators specify the relation between two variables by comparing them.
 *      ->  Following table shows the relational operators that are supported by C++.
 *              OPERATOR    -   DESCRIPTION
 *                  ==      -   Checks if two operands are equal
 *                  !=      -   Checks if two operands are not equal
 *                  >       -   Checks if operand on the left is greater than operand on the right
 *                  <       -   Checks if operand on the left is lesser than operand on the right
 *                  >=      -   Checks if operand on the left is greater than or equal to operand on the right
 *                  <=      -   Checks if operand on the left is less than or equal to operand on the right
 *  3.  Logical operators:
 *      -----------------
 *      ->  C++ supports 3 types of logical operators. The result of these operators is a boolean value i.e., 
 *          True(BITWISE ‘1’) or False(BITWISE ‘0’). Refer the visual representation below:
 *              OPERATOR    -   DESCRIPTION
 *                  &&      -   Logical AND
 *                  ||      -   Logical OR
 *                  !       -   Logical NOT
 */
#include <iostream>
using namespace std;   

void problem1(){
    int x, y = 1;
    x = 10;
    if (x != 10 && x / 1 == 0)
        cout << y;
    else
        cout << ++y;
    cout <<endl;
}

void problem2(){
    int x = 15;
    int y = x++;
    int z = ++x;
    cout << y << " " << z << endl;
}

void problem3(){
    int x = 10;
    int y = 20;
    if(x++ > 10 && ++y > 20 ){
    cout << "Inside if ";
    } else{
    cout << "Inside else ";
    }
    cout << x << " " << y << endl;
}

void problem4(){
    int x = 10;
    int y = 20;
    if(x++ > 10 || ++y > 20 ){
    cout << "Inside if ";
    } else{
    cout << "Inside else ";
    }
    cout << x << " " << y << endl;
}

int main()
{
    double a = 6 / 4; // in/int will output as int so here it will be 1.
    int b  = 6 / 4;
    double c = a + b; // since a=1, c = 1+1 = 2.
    cout << c << endl; // will print 2.
    cout<<"========================"<<endl;

    double a1 = 55.5;
    //a1 = a1 % b;  // syntax error as % is not a valid operator with double.
    cout<<"========================"<<endl;

    int var1 = 5;
    int var2 = 6;
    cout << (var1 > var2) << endl; // it will print 0 as condition evaluates to false.
    cout<<"========================"<<endl;

    problem1();  // 2
    cout<<"========================"<<endl;

    problem2();  // 15 17
    cout<<"========================"<<endl;

    int g = 3;
    cout << (++g * 8) << endl; // 32 - as per precendence table ++ operator will be evaluated first
    cout<<"========================"<<endl;

    problem3(); //Inside else 11 20
    cout<<"========================"<<endl;

    problem4(); // Inside if 11 21
    cout<<"========================"<<endl;
}