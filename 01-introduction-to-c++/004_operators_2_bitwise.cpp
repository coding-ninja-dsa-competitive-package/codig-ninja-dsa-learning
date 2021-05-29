#include<iostream>
using namespace std;

/**
 *  Bitwise Operators:
 *  1.  | - bitwise OR
 *  2.  & - bitwise AND
 *  3.  ~ - bitwise NOT
 *  4.  ^ - bitwise XOR
 *  5.  <<  - bitwise left shift
 *  6.  >>  - bitwise right shift
 */

int main(){
    /**
     *      00001111
     *      00011110
     *      --------
     *      00011111  => 31
     */
    int ror = 15 | 30;
    /**
     *      00001111
     *      00011110
     *      --------
     *      00001110  => 14
     */
    int rand = 15 & 30;
    /**
     *      00001111
     *      --------
     *      11110000  => 
     *     Since the number is negative , take 2's compliment.
     *      00001111
     *      +      1
     *      --------
     *      00010000  => -16
     */
    int rnot = ~15;
    /**
     *      00001111
     *      00011110
     *      --------
     *      00010001  => 17
     */
    int rxor = 15 ^ 30;
    /**
     *      00001111
     *      --------
     *      00111100  => 60
     */
    int rls = 15 << 2;
    /**
     *      00001111
     *      --------
     *      00000011  => 3
     */
    int rrs = 15 >> 2;

    cout << ror << endl;
    cout << rand << endl;
    cout << rnot << endl;
    cout << rxor << endl;
    cout << rls << endl;
    cout << rrs << endl;

    return 0;
}