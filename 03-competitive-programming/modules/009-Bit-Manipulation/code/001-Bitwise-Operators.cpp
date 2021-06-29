#include<bits/stdc++.h>

using namespace std;

/**
 *  1.  Left Shift Operator (<<)
 *      -   We basically move the bits to the left. 
 *      -   It results in doubling the number. 
 *      -       n << i  ==>  N * 2^i
 *  2.  Right Shift Operator (>>)
 *      -   We basically move the bits to the right. 
 *      -   It results in half the number. 
 *      -       n >> i  ==>  floor(N / 2^i)
 *  3.  AND operator (&)
 *      -   General form : 
 *              x & 1 = x
 *              x & 0 = 0
 *      -   Example :   3 & 4
 *                  0011 & 0100 = 0000
 *  4.  OR operator (|)
 *      -   General Form :
 *              x | 1 = 1
 *              x | 0 = x
 *      -   Example :   4 | 5 => 0100 | 0101 => 0101 => 5
 *  5.  NOT operator (~)
 *      -   Flips the bit.
 *      -   General form : 
 *              ~0 = 1
 *              ~1 = 0
 *  6.  XOR operator (^)
 *      -   General Form:
 *              x ^ 1 = ~x
 *              x ^ 0 = x
 */


/**
 *  Predict The Output
 *  Ans : 4  i.e. 2 * 2^1
 */
void problem1(){
    int x = 2;
    x = x << 1;
    cout << x;
}

/**
 *  Predict The Output
 *  Ans : -1  i.e. -2 / 2^1
 */
void problem2(){
    int x = -2;
    x = x >> 1;
    cout << x;
}

/**
 *  Predict The Output
 *  Ans : no
 */
void problem3(){
    if(~0 == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}

/**
 *  Predict The Output
 *  Ans : y is 1
 */
void problem4(){
    int y = 0;
    if(1 | (y = 1)) {
        cout << "y is " << y;
    }
    else {
        cout << y;
    }
}

/**
 *  Predict The Output
 *  Ans : true
 */
void problem5(){
    int y = 1;
    if(y & (y = 2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
}

/**
 *  Turn Off The Bit
 *  -   Which bitwise operator is suitable for turning off a particular bit in a number?
 *  Ans : & operator
 */

/**
 *  Turn On The Bit
 *  -   Which bitwise operator is suitable for turning on a particular bit in a number?
 *  Ans : | operator
 */

/**
 *  Check ith bit
 *  -   Which bitwise operator is suitable for checking whether a particular bit 
 *      is on or off?
 *  Ans :  & | ^
 * 
 *  AND (&) => (x >> i) & 1  => shift i bits and check the ith bit as X&1
 *  XOR (^) => x ^ (1 << i) => prepare mask with 2^i and take XOR
 *  OR (|) => (x >> i) | 0  =>  shift i bits and check the ith bit as X|0
 */

int main() {
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();

    return 0;
}