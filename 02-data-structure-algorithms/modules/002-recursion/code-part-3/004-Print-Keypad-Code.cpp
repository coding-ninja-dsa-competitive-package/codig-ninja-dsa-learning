#include<iostream>

using namespace std;

/**
 *  Print Keypad Combinations Code
 *  -   Given an integer n, using phone keypad find out and print all the 
 *      possible strings that can be made using digits of input n.
 *  -   Note : The order of strings are not important. Just print different 
 *      strings in new lines.
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
void print_keypad(int num, string output){
    if(num == 0){
        cout << output << endl;
        return;
    }
    string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str = arr[num%10];
    for(int i=0; i<str.size(); i++){
        print_keypad(num/10, str[i]+output);
    }
}
void printKeypad(int num){
	string out;
    print_keypad(num, out);
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
}