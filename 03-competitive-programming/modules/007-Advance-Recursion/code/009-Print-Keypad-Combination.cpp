#include<bits/stdc++.h>

using namespace std;

/**
 *  Print Keypad Combinations Code
 *  -   Given an integer n, using phone keypad find out and print all the 
 *      possible strings that can be made using digits of input n.
 *  Note : The order of strings are not important. Just print different strings 
 *  in new lines.
 *  
 *  Input Format :
 *      Integer n   
 *  Output Format :
 *      All possible strings in different lines
 *  Constraints :
 *      1 <= n <= 10^6
 * 
 *  Sample Input:
 *      23
 *  Sample Output:
 *      ad
 *      ae
 *      af
 *      bd
 *      be
 *      bf
 *      cd  
 *      ce
 *      cf
 */

void printKeypad(int num, string output){
    if(num == 0 || num == 1){
		cout << output << endl;
        return;
    }
    string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string key = keys[num%10];
    for(int i=0; i<key.length(); i++){
        printKeypad(num/10, key[i] + output);
    }
}

void printKeypad(int num){
    string output="";
   	printKeypad(num, output);
}

int main() {
    int num;
    cin >> num;
    printKeypad(num);

    return 0;
}