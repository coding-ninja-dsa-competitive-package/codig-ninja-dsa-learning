#include<iostream>

using namespace std;

/**
 *  Pointers Output
 *  -   Figure out the correct output of the following code.
 *  Ans : -10
 */
void changeSign(int *p){
    *p = (*p)  *  -1;
}
void problem1(){
    int a = 10;
    changeSign(&a);
    cout << a << endl;
}

/**
 *  Fill the output
 *  Ans :  2 1
 */
void fun(int a[]) {
    cout << a[0] << " ";
}
void problem2() {
    int a[] = {1, 2, 3, 4};
    fun(a + 1);
    cout << a[0];
} 

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans : 10
 */
void square(int *p){
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
}
void problem3(){
    int a = 10;
    square(&a);
    cout << a << endl;
}

int main() {
    
    problem1();
    problem2();
    problem3();

    return 0;
}