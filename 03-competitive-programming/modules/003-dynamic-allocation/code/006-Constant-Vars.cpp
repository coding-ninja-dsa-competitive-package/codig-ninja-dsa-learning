#include<iostream>

using namespace std;


void basics(){
    // constant int 
    const int i = 10;
    int const i2 = 20;

    //constant reference
    int j= 12;
    const int &k = j;
    j++;
    // k++; // we can't increment the const path

    cout << k << endl;

    // constant reference from a const int
    int const j2 = 12;
    int const &k2 = j2;
    // j2++;        // we can't change it as const path
    // k2++;        // we can't change it as const path

    // reference from const int
    int const j3 = 123;
    // int &k3 = j3;       // we can't drop const binding
}

void basics_pointers(){
    int const i=10;
    int const *p = &i;
    cout << *p << endl;

    int j=12;
    int const *p2 = &j;
    cout << *p2 << endl; // 12
    j++;
    cout << *p2 << endl;  // 13

    int i2 = 10;
    int j2= 21;
    int const *p1 = &i2; // pointer pointing to the const int i.e. p itself can be changed
    p1 = &j2;
    // (*p1)++;
    int * const p3 = &i2; // const pointer pointing to the int i.e. p can't be changed
    // p3 = &j2;
    (*p3)++;
    int const * const p4 = &i2; // pointer & value both are const i.e. we can't change any. 
}

/**
 *  What is the output
 *  -   What is the output of the following program ?
 *  Ans : Error
 */
void problem1(){
    int  const  p = 5;
    // cout << ++p; //uncomment
}

/**
 *  What is the output
 *  Ans : 6
 */
void problem2(){
    int p = 5;
    int const *q = &p;
    p++;
    cout << p << endl;
}

/**
 *  Which statement(s) will give an error for the following code
 *  -   p++;
 *  -   q++;
 *  -   (*q)++;
 *  Ans :   (*q)++  // pointer pointing to const int
 */
void problem3(){
    int p = 5;
    int const *q = &p;
}

/**
 *  Which statement(s) will give an error for the following code -
 *  -   p++;
 *  -   q++;
 *  -   (*q)++;
 *  Ans : q++  // const pointer pointing to int
 */
void problem4(){
    int p = 5;
    int * const q = &p;
}

/**
 *  Which statement(s) will give an error for the following code -
 *  -   p++;
 *  -   (*q)++;
 *  -   q++;
 *  Ans :  q++ , (*q)++  // const pointer pointing to const int
 */ 
void problem5(){
    int p = 5;
    int const * const q = &p;
}

/**
 *  Which statement(s) will give an error for the following code -
 *  -   p++;
 *  -   q++
 *  -   (*q)++;
 *  Ans : p++ , (*q)++  // pointer pointing to const int
 */
void problem6(){
    const int p = 5;
    int const *q = &p;
}

int main() {
    basics();
    basics_pointers();

    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    problem6();

    return 0;
}