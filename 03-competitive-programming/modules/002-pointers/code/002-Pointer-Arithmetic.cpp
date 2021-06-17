#include<bits/stdc++.h>

using namespace std;

/**
 *  What is the output
 *  Ans : 7 Garbage_value
 */
void problem1(){
    int a = 7;
    int *c = &a;
    c = c + 1;
    cout  << a << "  " << *c << endl;
}

/**
 *  Fill the output
 *  -   Assume memory address of variable ‘a’ is : 400 (and an integer takes 
 *      4 bytes), what will be the output -
 *  Ans : 412
 */
void problem2(){
    int a = 7;
    int *c = &a;
    c = c + 3;
    cout  << c << endl;
}

/**
 *  Fill the output
 *  -   Assume memory address of variable ‘a’ is : 200 and a double variable 
 *      is of size 8 bytes, what will be the output -
 *  Ans : 208
 */
void problem3(){
    double a = 10.54;
    double *d = &a;
    d = d + 1;
    cout  << d << endl;
}

int main() {
    problem1();
    problem2();
    problem3();

    return 0;
}