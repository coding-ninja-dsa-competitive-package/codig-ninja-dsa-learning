#include<bits/stdc++.h>

using namespace std;

/**
 *  Return SubSequences of String
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

int subsequences(string input, string* output){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int size = subsequences(input.substr(1), output);
    for(int i=0; i<size; i++){
        output[i+size] = input[0] + output[i];
    }
    return 2*size;
}

int main() {
    string str;
    cin >> str;

    string* output = new string[10000];
    int size = subsequences(str, output);
    for(int i=0; i<size; i++){
        cout << output[i] << endl;
    }

    return 0;
}