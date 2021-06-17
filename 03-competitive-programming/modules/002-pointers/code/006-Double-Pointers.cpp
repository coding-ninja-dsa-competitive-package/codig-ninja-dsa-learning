#include<iostream>

using namespace std;

/**
 *  What will be the output ?
 *  Ans : 10 21
 */
void problem1(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout << a << " " << b << endl;
}

/**
 *  What will be the output ?
 *  Ans : 101 104
 */
void problem2(){
    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++ + 4;
    cout << a << " " << b << endl;
}

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans : 102 100
 */
void problem3(){
    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = (**q)++;
    int *r = *q;
    (*r)++;
    cout << a << " " << b << endl;
}

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans :   11
 */
void increment(int **p){
    (**p)++;
}
void problem4(){
    int num = 10;
    int *ptr = &num;
    increment(&ptr);
    cout << num << endl;
}

int main() {
    problem1();
    problem2();
    problem3();
    problem4();

    return 0;
}