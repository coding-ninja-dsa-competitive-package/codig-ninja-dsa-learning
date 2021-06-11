#include<iostream>

using namespace std;

/**
 *  Print all Codes - String
 *  -   Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are 
 *      given a numeric string S. 
 *  -   Write a program to print the list of all possible codes that can be 
 *      generated from the given string.
 * 
 *  Input format :
 *      A numeric string S
 *  Output Format :
 *      All possible codes in different lines
 *  Constraints :
 *      1 <= Length of String S <= 10
 *  
 *  Sample Input:
 *      1123
 *  Sample Output:
 *      aabc
 *      kbc
 *      alc     
 *      aaw 
 *      kw
 */
#include <string.h>
using namespace std;

void possibleCodes(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    char ch1 = ( input[0] - '0' ) + 'a' - 1;
    possibleCodes(input.substr(1), output+ch1);
    if(input.length() >= 2){
        int number = (input[0] - '0')*10 + (input[1] - '0');
        if(number >= 10 && number <= 26){
         	char ch2 = number + 'a' - 1;
    		possibleCodes(input.substr(2), output+ch2);     
        } 
    }
}
void printAllPossibleCodes(string input) {
    string output="";
    possibleCodes(input, output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
}