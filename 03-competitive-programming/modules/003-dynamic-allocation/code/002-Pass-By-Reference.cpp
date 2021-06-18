#include<iostream>

using namespace std;

void increment(int &i){
    i++;
}
void basics(){
    int i=10;
    int &j = i;   // reference variable

    i++;
    cout << j << endl;

    increment(i); // pass by reference
    cout << i << endl;
}

/**
 *  What is the output
 *  Ans : 10 11
 */
void func(int p){
    cout << p << " ";
}
void problem1(){
    int i = 10;
    int &p = i;
    func(p++);
    cout << i;
}

/**
 * What is the output
 *  Ans : 10 7 10
 */
void func(int i, int& j, int p){
    i++;
    j++;
    p++;
}
void problem2(){
    int i = 10;
    int j = 6;
    int &p = i;
    func(i, j, p);
    cout << i << " " << j << " " << p;
}

int main() {
    basics();
    problem1();
    problem2();

    return 0;
}