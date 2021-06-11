#include<iostream>

using namespace std;

/**
 *  Check Palindrome (recursive)
 *  -   Check whether a given String S is a palindrome using recursion. 
 *      Return true or false.
 * 
 *  Input Format :
 *      String S
 *  Output Format :
 *      'true' or 'false'
 *  Constraints :
 *      0 <= |S| <= 1000
 *      where |S| represents length of string S.
 *  
 *  Sample Input 1 :
 *      racecar
 *  Sample Output 1:
 *      true
 *      
 *  Sample Input 2 :
 *      ninja
 *  Sample Output 2:
 *      false
 */
bool isPalindrome(char input[], int start , int end){
    if(start > end){
        return true;
    }
    if(input[start] != input[end]){
        return false;
    }
    return isPalindrome(input, start+1, end-1);
}
bool checkPalindrome(char input[]) {
    int len = strlen(input);
    int start = 0, end = len-1;
	return isPalindrome(input, start, end);
}

int main(){
    char input[50];
    cin >> input;
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}