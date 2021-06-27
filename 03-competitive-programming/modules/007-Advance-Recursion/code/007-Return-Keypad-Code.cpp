#include<bits/stdc++.h>

using namespace std;

/**
 *  Return Keypad Code
 *  -   Given an integer n, using phone keypad find out all the possible strings 
 *      that can be made using digits of input n.
 *  -   Return empty string for numbers 0 and 1.
 *      Note : 1. The order of strings are not important.
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
#include <string>

int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size = keypad(num/10, output);
    string key = keys[num%10];
    for(int i=0; i<size; i++){
        string str = output[i];
        for(int j=0; j<key.length(); j++){
        	output[j*size + i] = str + key[j];
        }
    }
    return key.length() * size;
}


int main() {
    int num;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }

    return 0;
}