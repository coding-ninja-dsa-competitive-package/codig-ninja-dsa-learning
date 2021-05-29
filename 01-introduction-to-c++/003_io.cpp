/**
 *  ->  Printing/Providing output:
 *      ==========================
 *      -   For printing statements in C++ programs, we use the cout statement.
 *          For example: If you want to print “Hello World!” (without parenthesis) in your code, 
 *              we will write it in following way:
 *                  cout << “Hello World!”;
 *      -   A full view of the basic C++ program is given below for the above example:
 *              #include <iostream>
 *              using namespace std;
 *              int main() {
 *                  cout<<”Hello World!”;
 *              }
 *          Output: Hello World!
 *  ->  Line separator:
 *      -   For separating different lines in C++, we use endl or ‘\n’ .
 *  ->  Taking input from the user:
 *      -   To take input from the user, we use the cin statement.
 *          For example: If you want to input a number from the user:
 *                  int n;
 *                  cin >> n;
 * 
 */

#include <iostream>
using namespace std;

void problem1(){
    int a, b; 
    cin >> a;
    cin >> b;
    cout << (a+b) << endl;
    cout<<"========================"<<endl;

    double d;
    char c;
    cin >> d >> c;
    cout << a << d << c << endl;
    cout<<"========================"<<endl;
}

/**
 *  Write a program to count and print the total number of characters (lowercase english alphabets only), 
 *  digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
 *  That is, input will be a stream of characters and you need to consider all the characters which are 
 *  entered till '$'.
 *  Print count of characters, count of digits and count of white spaces respectively (separated by space).
 *  ->  Sample input , output
 *          abc def4 5$ , 6 2 2
 */
void countAndPrintNumberOfChars(){
    char ch;
    ch = cin.get();

    int sumOfChars = 0, sumOfDigits = 0, sumOfSpaces=0;
    while(ch != '$'){
        if(ch >= 97 && ch <= 122){
            sumOfChars++;
        } else if(ch >= 48 && ch <= 57){
            sumOfDigits++;
        } else if(ch == '\n' || ch == ' ' || ch =='\t'){
            sumOfSpaces++;
        }
        ch = cin.get();
    }
    cout << sumOfChars << " " << sumOfDigits << " " << sumOfSpaces ;
}
void assignment1(){
    countAndPrintNumberOfChars();
}

int main() {
    //basics
    problem1();
    
    //count and print number of characters
    //assignment1();
}