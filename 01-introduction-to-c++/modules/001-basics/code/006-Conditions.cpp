#include<iostream>
using namespace std;

/**
 *  Check if number is even or odd.
 */
void checkEvenOdd(){
    int n;
    cout << "Enter the number : "<< endl;
    cin >> n;

    if(n%2 == 0){
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
}

/**
 *  What is the output
 *  Ans : Hello Hi
 */
void problem1(){
    int x = 5; 
    if (x < 6)
        cout <<  "Hello ";
    if(x == 5){
        cout << "Hi ";
    }
    else { 
        cout << "Hey ";
    } 
    cout<<endl;
}

/**
 *  What is the output
 *  Ans : Inside if 15
 */
void problem2(){
    int x = 15;
    if(x <= 15) {
        cout << "Inside if ";
    } else if(x == 15) {
        cout << "Inside else if ";
    }
    cout << x << endl;
}

/**
 *  What is the output
 *  Ans : 2
 */
void problem3(){
    int var1 = 5; 
    int var2 = 6;
    if ((var2 = 1) == var1)
        cout << var2;
    else 
        cout  << (var2 + 1); 
    cout << endl;
}

/**
 *  What is the output
 *  Ans : hello
 */
void problem4(){
    int a = 10, b = 20, c = 100;
    if(a <= b || c <= b) {
        cout << "hello" << endl;
    }
    else if(a <= b || a <= c) {
        cout << "hi" << endl;
    }
    else {
        cout << "hey" << endl;
    }
}

/**
 *  What is the output
 *  Ans : hi
 */
void problem5(){
    int a = 10, b = 20, c = 30;
    // here !b condition will be evaluated as false because b is non-zero.
    if(a <= b && !b) {
        cout << "hello";
    }
    else if(c >= a && c >= b) {
        cout << "hi";
    }
    else {
        cout << "hey";
    }
    cout<<endl;
}

/**
 *  Check Case:
 *  -   Write a program that takes a character as input and prints either 
 *      1, 0 or -1 according to the following rules.
 *  -   1, if the character is an uppercase alphabet (A - Z)
 *      0, if the character is a lowercase alphabet (a - z)
 *      -1, if the character is not an alphabet
 * 
 *  Input format :
 *      Single Character
 *  Output format :
 *      1 or 0 or -1
 *  Constraints :
 *      Input can be any character  
 * 
 *  Sample Input 1 :
 *      v
 *  Sample Output 1 :
 *      0
 *  
 *  Sample Input 2 :
 *      V
 *  Sample Output 2 :
 *      1
 *  
 *  Sample Input 3 :
 *      #
 *  Sample Output 3 :
 *      -1
 */
void checkCase()
{
    char ch;
    cin>>ch;
    
    if(ch >= 65 && ch <= 90){
        cout << 1;
    } else if( ch >= 97 && ch <= 122) {
        cout << 0;
    } else {
        cout << -1;
    } 
    cout<< endl;
}
void assignment1(){
    checkCase();
}

int main(){
    //checkEvenOdd();

    // int i = 20;
    // cout<<!i<<endl;

    // problem1();

    // problem2();

    // problem3();

    // problem4();

    // problem5();

    assignment1();
    
    return 0;
}