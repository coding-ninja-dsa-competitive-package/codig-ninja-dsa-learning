#include<bits/stdc++.h>

using namespace std;

/**
 *  LCS - Problem
 *  -   Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of 
 *      the 'Longest Common Subsequence'.
 *  -   For a string 'str'(per se) of length K, the subsequences are the strings 
 *      containing characters in the same relative order as they are present in 
 *      'str,' but not necessarily contiguous. Subsequences contain all the strings 
 *      of length varying from 0 to K.
 *  Example :
 *      Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
 *      
 *  Input format :
 *      The first line of input contains the string 'S' of length 'M'.
 *      The second line of the input contains the string 'T' of length 'N'.
 *  Output format :
 *      Return the length of the Longest Common Subsequence.
 *  
 *  Constraints :
 *      0 <= M <= 10 ^ 3
 *      0 <= N <= 10 ^ 3
 *  
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1 :
 *      adebc
 *      dcadb
 *  Sample Output 1 :
 *      3
 *  Explanation of the Sample Output 1 :
 *      Both the strings contain a common subsequence 'adb', which is the longest 
 *      common subsequence with length 3. 
 *  
 *  Sample Input 2 :
 *      ab  
 *      defg
 *  Sample Output 2 :
 *      0
 *  Explanation of the Sample Output 2 :
 *      The only subsequence that is common to both the given strings is an empty 
 *      string("") of length 0.
 */

//  Approach 1 - Recursive
int lcs(char* s1, char* s2){
    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }
    if(s1[0] == s2[0]){
        return 1 + lcs(s1+1, s2+1);
    } else {
        int ans1 = lcs(s1, s2+1);
        int ans2 = lcs(s1+1, s2);
        return max(ans1, ans2);
    }
}

//  Approach 2 - Recursive
int lcsHelper(char* s1, char* s2, int n, int m, int** arr){
    if(n==0 || m==0){
        return 0;
    }
    if(arr[n][m] > -1){
        return arr[n][m];
    }
    int ans;
    if(s1[0] == s2[0]){
        ans = 1 + lcsHelper(s1+1, s2+1, n-1, m-1, arr);
    } else {
        int ans1 = lcsHelper(s1, s2+1, n, m-1, arr);
        int ans2 = lcsHelper(s1+1, s2, n-1, m, arr);
        ans = max(ans1, ans2);
    }
    arr[n][m] = ans;
    return ans;
}

int lcs_memoization(char* s1, char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
        for(int j=0; j<=m; j++){
            dp[i][j] = -1;
        }
    }
    int ans = lcsHelper(s1, s2, n, m , dp);
    for(int i=0; i<n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

//  Approach 3 - DP

int lcs_dp(char* s1, char* s2){
    int n = strlen(s1);
    int m = strlen(s2);
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[n-i] == s2[m-j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ans = dp[n][m];
    for(int i=0; i<n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main() {
    char a[100], b[100];
    cin >> a >> b;
    cout << lcs(a, b) << endl;

    cout << lcs_memoization(a, b) << endl;

    cout << lcs_dp(a, b) << endl;

    return 0;
}