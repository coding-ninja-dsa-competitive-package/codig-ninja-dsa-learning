#include<iostream>
using namespace std;

/**
 *  Pointers Output
 *  -   What will be the output ?
 *  Ans : b
 */
void problem1(){
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;
}

/**
 *  What is the output
 *  -   Assume address of 0th index of array ‘b’ is 200. What is the output -
 *  Ans : xyz
 */
void problem2(){
    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;
}

/**
 *  What is the output
 *  -   Assume address of 0th index of array ‘b’ is 200. What is the output -
 *  Ans :   yz
 */
void problem3(){
    char b[] = "xyz";
    char *c = &b[0];
    c++;
    cout << c << endl;
}

/**
 *  Fill the output
 *  Ans : h h
 */
void problem4(){
    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0];
}

int main() {
    problem1();
    problem2();
    problem3();
    problem4();

    return 0;
}