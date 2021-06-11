#include<iostream>

using namespace std;

/**
 *  Return Keypad Code
 *  -   Given an integer n, using phone keypad find out all the possible 
 *      strings that can be made using digits of input n. Return empty string 
 *      for numbers 0 and 1.
 *  Note : 
 *      1. The order of strings are not important.
 *      2. Input and output has already been managed for you. 
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
int keypad(int num, string output[]){
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = keypad(num/10, output);
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str = arr[num%10];
    for(int i=0; i<smallerOutputSize ; i++){
        string out = output[i];
        for(int j=0; j<str.size(); j++){
            output[i + (j*smallerOutputSize)] =  out+str[j]; 
        }
    }
    return smallerOutputSize*str.size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << " ";
    }
}