#include<iostream>

using namespace std;

// Macro - Replaces the value before compilation
#define PI 3.14

// Global variable
int global = 20;

void basics(){
    int r = 10;
    double area = PI*r*r;
    cout << area << endl;

    global++;
    cout << global << endl;
}

/**
 *  What is the output
 *  -   What is the output of the following program?
 *  Ans : 3
 */
int x = 1;
void print(){
    int x = 2;
    {
        int x = 3;
        cout << x << endl;
    }
}
void problem1(){
    print();
}

/**
 *  Fill the output
 *  -   What is the output of the following program?
 *  Ans : 16    
 *  Solution Description:
 *      "MULTIPLY(a, b)" will be replaced by "a*b" in code.
 *      So, MULTIPLY(2+3, 3+5) will be replaced by 2+3*3+5. And according to operator 
 *      precedence, multiply operator (*) has higher precedence than plus operator (+). 
 *      So, 3*3 will be evaluated first. Hence expression will become :
 *      2+9+5 = 16
 */
#define MULTIPLY(a, b) a*b

void problem2(){
    cout << MULTIPLY(2+3, 3+5);
}

/**
 *  Fill the output
 *  -   What is the output of the following program?
 *  Ans : 36
 */
#define SQUARE(x) x*x

void problem3(){
    int x = 36 / SQUARE(6);
    cout << x;
}

int main() {
    basics();

    problem1();
    problem2();
    problem3();

    return 0;
}