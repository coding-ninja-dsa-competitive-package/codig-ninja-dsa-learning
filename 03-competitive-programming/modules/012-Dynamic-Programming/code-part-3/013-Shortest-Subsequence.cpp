#include<bits/stdc++.h>

using namespace std;

/**
 *  Shortest Subsequence
 *  -   Gary has two string S and V. Now, Gary wants to know the length shortest 
 *      subsequence in S, which is not a subsequence in V.
 *  -   Note: The input data will be such that there will always be a solution.
 *  
 *  Input Format :
 *      The first line of input contains a string, that denotes the value of S. The 
 *      following line contains a string, that denotes the value of V.
 *  Output Format :
 *      Length of shortest subsequence in S such that it is not a subsequence in V
 *  
 *  Constraints:
 *      1 <= N <= 1000
 *      1 <= M <= 1000  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1: 
 *      babab
 *      babba
 *  Sample Output 1:
 *      3
 *  Explanation:
 *      "aab" is the shortest subsequence which is present in S and absent in V.
 */

int shortestSubsequence(string s, string v, int n , int m, int** dp){
    if(n==0) {
        return 1001;
    }
    if(m<=0){
        return 1;
    }
    if(dp[n][m] > -1){
        return dp[n][m];
    }
    // if the char is not included
    int ans1 = shortestSubsequence(s.substr(1), v, n-1, m, dp);
    int i=0; 
    for(; i<m; i++){
        if(s[0] == v[i]){
            break;
        }
    }
    if(i==m){
        return 1;
    }
    // if the char is included
    int ans2 = 1 + shortestSubsequence(s.substr(1), v.substr(i+1), n-1, m-i-1, dp);
    dp[n][m] = min(ans1, ans2);
    return dp[n][m];
}

int solve(string s, string v) {
	int n = s.length();
    int m = v.length();
    
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
        for(int j=0; j<=m; j++){
            dp[i][j] = -1;
        }
    }
    
    int ans = shortestSubsequence(s, v, n , m, dp);
    
    for(int i=0; i<=n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    
    return ans;
}


int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
    return 0;
}