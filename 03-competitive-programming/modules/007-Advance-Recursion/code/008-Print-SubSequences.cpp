#include<bits/stdc++.h>

using namespace std;

/**
 *  Print all the subsequences of String 
 * 
 *  Sample Input1:
 *      abc
 *  Sample Output1:
 *      
 *      a
 *      b
 *      c
 *      ab
 *      bc
 *      ac
 *      abc
 */

void printSubsequences(string input, string output){
    if(input.empty()){
        cout << output << endl;
        return;
    }
    printSubsequences(input.substr(1), output);
    printSubsequences(input.substr(1), output + input[0]);
}

int main() {
    string str;
    cin >> str;

    string out;
    printSubsequences(str, out);

    return 0;
}