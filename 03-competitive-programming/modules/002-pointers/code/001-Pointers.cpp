#include<bits/stdc++.h>
using namespace std;

/**
 *  Address of variable
 *  -   Which of the following gives the memory address of variable 'b' pointed by 
 *      pointer 'a' i.e.
 *  Ans :   a
 */
void problem1(){
    int b = 10;
    int *a = &b;
}

/**
 *  Pointers Output
 *  -   What will happen in this code?
 *  Ans : p now points to b 
 */
void problem2(){
    int a = 100, b = 200;
    int *p = &a, *q = &b;   
    p = q;
}

/**
 *  What will be the output ?
 *  Ans : 7 7
 */
void problem3(){
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7;
    cout  << a << "  " << b << endl;
}

/**
 *  What will be the output ?
 *  Ans : 51
 */
void problem4(){
     int a = 50;
    int *ptr = &a;
    int *q = ptr;
    (*q)++;
    cout << a  << endl;
}

/**
 *  What will be the output ?
 *  Ans : 50 51
 */
void problem5(){
     int a = 50;
    int *ptr = &a;
    cout << (*ptr)++ << " ";
    cout << a << endl;
}

/**
 *  What will be the output ?
 *  Ans : Error
 *      Segmentation Fault. As the pointer is referring to null pointer.
 */
void problem6(){
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout << *ptr << endl;
}

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans : 17 18
 */
void problem7(){
    int a = 7;
    int b = 17;
    int *c = &b; 
    a = *c;
    *c = *c + 1;
    cout  << a << "  " << b << endl;
}

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans : 2.5 2.5 2.5
 */
void problem8(){
    float f = 10.5;
    float p = 2.5;
    float* ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p;
}

int main() {
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    problem6();
    problem7();
    problem8();

    return 0;
}