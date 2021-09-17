#include<bits/stdc++.h>

using namespace std;

/**
 *  Subset Sum - Problem
 *  -   You are given a set of N integers. You have to return true if there exists 
 *      a subset that sum up to K, otherwise return false.
 *  
 *  Input Format
 *      The first line of the test case contains an integer 'N' representing the 
 *      total elements in the set.
 *      The second line of the input contains N integers separated by a single space.    
 *      The third line of the input contains a single integer, denoting the value of K.
 *  Output Format
 *      Output Yes if there exists a subset whose sum is k, else output No.
 *  
 *  Constraints :   
 *      1 <= N <= 10^3
 *      1 <= a[i] <= 10^3, where a[i] denotes an element of the set 
 *      1 <= K <= 10^3
 *  
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1 :
 *      4
 *      4 3 5 2
 *      13
 *  Sample Output 1 :
 *      No
 * 
 *  Sample Input 2 :
 *      5
 *      4 2 5 6 7
 *      14
 *  Sample Output 2 :
 *      Yes
 */

bool isSubsetPresent(int *arr, int n, int sum){
	bool** dp = new bool*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new bool[sum+1];
        for(int j=0; j<=sum; j++){
            if(i==0){
                dp[i][j] = false;
            } else if(j==0){
                dp[i][j] = true;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> sum;
    if (isSubsetPresent(arr, n, sum)){
        cout << "Yes";
    } else {
        cout << "No";
    }

    delete[] arr;
    return 0;
}