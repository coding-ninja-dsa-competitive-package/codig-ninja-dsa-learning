#include<bits/stdc++.h>

using namespace std;

/**
 *  Square Brackets
 *  -   You are given:  a positive integer n, an integer k, 1<=k<=n, an increasing sequence 
 *      of k integers 0 < s1 < s2 < ... < sk <= 2n.
 *  -   What is the number of proper bracket expressions of length 2n with opening brackets 
 *      appearing in positions s1, s2,...,sk?
 *  -   Illustration
 *          Several proper bracket expressions:
 *          [[]][[[]][]] 
 *          [[[][]]][][[]]
 *          An improper bracket expression: 
 *          [[[][]]][]][[]]
 *  -   There is exactly one proper expression of length 8 with opening brackets in 
 *      positions 2, 5 and 7.
 *  
 *  Task
 *  -   Write a program which for each data set from a sequence of several data sets:
 *      1.  Reads integers n, k and an increasing sequence of k integers from input,
 *      2.  Computes the number of proper bracket expressions of length 2n with opening 
 *          brackets appearing at positions s1,s2,...,sk,
 *      3.  Writes the result to output.
 *  
 *  Input
 *      The first line of the input file contains one integer d, 1 <= d <= 10, which is 
 *      the number of data sets. The data sets follow. Each data set occupies two lines 
 *      of the input file. The first line contains two integers n and k separated by 
 *      single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing 
 *      sequence of k integers from the interval [1;2n] separated by single spaces.
 *  Output
 *      The i-th line of output should contain one integer - the number of proper bracket 
 *      expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
 *  
 *  Sample Input
 *      5 
 *      1 1 
 *      1 
 *      1 1
 *      2 
 *      2 1 
 *      1 
 *      3 1 
 *      2 
 *      4 2 
 *      5 7 
 *  Sample Output
 *      1 
 *      0 
 *      2 
 *      3 
 *      2 
 */

int calculateBrackets(bool* pos_open, int n, int currOpen, int currClosed, int** dp){
    if(pos_open[0]){
        return 0;
    }
    if(dp[currOpen][currClosed] > -1){
        return dp[currOpen][currClosed];
    }
    if(currOpen>n || currClosed>n){
        return 0;
    }
    if(currOpen==n && currClosed==n){
        return 1;
    }
    
    int ans;
    if(currOpen == currClosed || pos_open[currOpen+currClosed+1]){
        ans = calculateBrackets(pos_open, n, currOpen+1, currClosed, dp);
    } else if(currOpen == n){
        ans = calculateBrackets(pos_open, n, currOpen, currClosed+1, dp);
    } else {
        int ans1 = calculateBrackets(pos_open, n, currOpen+1, currClosed, dp);
        int ans2 = calculateBrackets(pos_open, n, currOpen, currClosed+1, dp);
        ans = ans1+ans2;
    }
    dp[currOpen][currClosed] = ans;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        bool* pos_open = new bool[2*n + 1];
        for(int i=0; i<=2*n; i++){
            pos_open[i] = false;
        }
        for(int i=0; i<k; i++){
            int idx;
            cin >> idx;
            pos_open[idx] = true;
        }
        
        int** dp = new int*[21];
        for(int i=0; i<=20; i++){
            dp[i] = new int[21];
            for(int j=0; j<21; j++){
                dp[i][j] = -1;
            }
        }
        
        cout << calculateBrackets(pos_open, n, 0, 0, dp) << endl;
    }
    return 0;
}
