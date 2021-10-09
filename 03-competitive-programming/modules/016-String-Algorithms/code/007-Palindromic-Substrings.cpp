#include<bits/stdc++.h>

using namespace std;

/**
 *  Palindromic Substrings
 *  -   Given a string S, count and return the number of substrings of S that are 
 *      palindrome.
 *  -   Single length substrings are also palindromes. You just need to calculate 
 *      the count, not the substrings.
 *  
 *  Input Format :
 *      String S
 *  Output Format :
 *      count of palindrome substrings
 *  Constraints :
 *      1 <= Length of S <= 1000
 *  
 *  Sample Input :
 *      aba
 *  Sample Output :
 *      4   
 *  Note : Here 4 corresponds to ("a","b","a","aba").
 */


int countPalindromeSubstrings(char s[]) {
    int count=0;
	string str = s;
    int n = str.length();
    for(int i=0; i<n; i++){
        int left=i, right=i;
        while(left>=0 && right<n && str[left]==str[right]){
            count++;
            left--;
            right++;
        }

        left=i, right=i+1;
        while(left>=0 && right<n && str[left]==str[right]){
            count++;
            left--;
            right++;
        }
    }
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
