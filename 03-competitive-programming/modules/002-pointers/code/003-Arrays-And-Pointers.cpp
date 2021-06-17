#include<iostream>

using namespace std;

/**
 *  What is the output
 *  -   Assume integer takes 4 bytes and integer pointer 8 bytes.
 *  Ans : 20 8
 */
void problem1(){
    int a[5];
    int *c;
    cout << sizeof(a) << " " << sizeof(c);
}

/**
 *  Fill the output
 *  Ans : 1 2
 */
void problem2(){
    int a[] = {1, 2, 3, 4};
    cout << *(a) << " " << *(a+1);  
}

/**
 *  Fill the output
 *  -   Assume that address of 0th index of array ‘a’ is : 200.
 *  -   What is the output -
 *  Ans :   200 200
 */
void problem3(){
    int a[6] = {1, 2, 3};
    cout << a << " " << &a;
}

/**
 *  Fill the output 
 *  -   Assume that address of 0th index of array ‘a’ is : 200. 
 *  What is the output -
 *  Ans : 208
 */
void problem4(){
    int a[6] = {1, 2, 3};
    cout << (a + 2);
}

/**
 *  What is the output
 *  -   Assume address of 0th index of array 'a' is 200.
 *  What is the output -
 *  Ans :   3
 */
void problem5(){
    int a[6] = {1, 2, 3};
    int *b = a;
    cout << b[2];
}

/**
 *  What is the output
 *  -   Assume address of 0th index of array 'a' is 200.
 *  What is the output -
 *  Ans : 1 5
 */
void problem6(){
    int a[] = {1, 2, 3, 4, 5};
    cout << *(a) << " " << *(a + 4);
}

/**
 *  What is the output
 *  Ans : Error
 */
void problem7(){
    int a[] = {1, 2, 3, 4};
    //int *p = a++; 
    //cout << *p << endl;
}

int main() {
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    problem6();
    problem7();

    return 0;
}