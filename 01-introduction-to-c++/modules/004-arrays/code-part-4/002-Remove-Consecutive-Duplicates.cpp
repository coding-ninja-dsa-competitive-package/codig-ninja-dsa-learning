#include<iostream>

using namespace std;

/**
 *  Remove Consecutive Duplicates
 *  -   For a given string(str), remove all the consecutive duplicate characters.
 *  
 *  Example:
 *      Input String: "aaaa"
 *      Expected Output: "a"
 *  
 *      Input String: "aabbbcc"
 *      Expected Output: "abc"
 *      
 *  Input Format:
 *      The first and only line of input contains a string without any leading and 
 *      trailing spaces. All the characters in the string would be in lower case.
 *  Output Format:
 *      The only line of output prints the updated string.
 * 
 *  Constraints:
 *      0 <= N <= 10^6
 *      Where N is the length of the input string.
 * 
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      aabccbaa
 *  Sample Output 1:    
 *      abcb
 *  
 *  Sample Input 2:
 *      xxyyzxx
 *  Sample Output 2:
 *      xyzx
 */

void removeConsecutiveDuplicates(char input[]) {
	int i=0, j=i+1; 
    while(input[j] != '\0'){
        while(input[j] == input[i]){
            j++;
        }
        input[i+1] = input[j];
        j++;
        i++;
    }
    input[i+1] = '\0';
}

int main(){
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}