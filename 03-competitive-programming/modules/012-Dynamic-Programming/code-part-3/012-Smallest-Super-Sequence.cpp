#include<bits/stdc++.h>

using namespace std;

/**
 *  Smallest Super-Sequence
 *  -   Given two strings S and T with lengths M and N. Find and return the length of 
 *      their shortest 'Super Sequence'.
 *  -   The shortest 'Super Sequence' of two strings is defined as the smallest string 
 *      possible that will have both the given strings as its subsequences.
 *  
 *  Note :
 *      If the two strings do not have any common characters, then return the sum of the 
 *      lengths of the two strings. 
 *  
 *  Input Format:
 *      The first only line of input contains a string, that denotes the value of string 
 *      S. The following line contains a string, that denotes the value of string T.
 *  Output Format:
 *      Length of the smallest super-sequence of given two strings. 
 *  
 *  Constraints :
 *      0 <= M <= 10 ^ 3
 *      0 <= N <= 10 ^ 3
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      ab
 *      ac
 *  Sample Output 1 :
 *      3
 *  Explanation of Sample Output 1 :
 *      Their smallest super sequence can be "abc" which has length = 3.
 *  
 *  Sample Input 2 :
 *      pqqrpt
 *      qerepct
 *  Sample Output 2 :
 *      9
 */

int smallestSuperSequence(string s1, string s2, int n, int m, int** dp){
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}

int smallestSuperSequence(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
    }
    
    int count=0;
    for(int j=m; j>=0; j--){
        dp[n][j]=count++;
    }
    count=0;
    for(int i=n; i>=0; i--){
        dp[i][m]=count++;
    }
    
    return smallestSuperSequence(str1, str2, n, m, dp);
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}