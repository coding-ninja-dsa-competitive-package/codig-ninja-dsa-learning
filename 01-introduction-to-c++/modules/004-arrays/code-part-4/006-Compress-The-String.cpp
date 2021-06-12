#include<iostream>

using namespace std;

/**
 *  Compress the String
 *  -   Write a program to do basic string compression. For a character which is 
 *      consecutively repeated more than once, replace consecutive duplicate 
 *      occurrences with the count of repetitions.
 *  -   Consecutive count of every character in the input string is less than or    
 *      equal to 9.
 * 
 *  Exmple:
 *      If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".
 *      The string is compressed only when the repeated character count is more than 1.
 *  Note :
 *      Consecutive count of every character in the input string is less than or equal to 9.
 *  
 *  Input Format:
 *      The first and only line of input contains a string without any leading and 
 *      trailing spaces.
 *  Output Format:
 *      The only line of output prints the updated string.
 *  
 *  Constraints:
 *      0 <= N <= 10^6
 *      Where N is the length of the input string.
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      aaabbccdsa
 *  Sample Output 1:
 *      a3b2c2dsa
 *  
 *  Sample Input 2:
 *      aaabbcddeeeee
 *  Sample Output 2:
 *      a3b2cd2e5
 */
void stringCompression(char input[]){
    int i=0 , j=0, count;  
    while(input[j] != '\0'){
        count=0;
        while(input[j] == input[i]){
            count++;
            j++;
        }
        if(count > 1){
            i++;
            input[i] = count+48;
        }
        i++;
        input[i] = input[j];
    }
    input[i] ='\0';
}

int main(){
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str;
}   