#include<bits/stdc++.h>

using namespace std;

/**
 *  Miser Man
 *  -   Jack is a wise and miser man. Always tries to save his money.
 *  -   One day, he wants to go from city A to city B. Between A and B, there are N 
 *      number of cities(including B and excluding A) and in each city there are M 
 *      buses numbered from 1 to M. And the fare of each bus is different. Means for 
 *      all N*M busses, fare (K) may be different or same. Now Jack has to go from 
 *      city A to city B following these conditions:
 *      1.  At every city, he has to change the bus.
 *      2.  And he can switch to only those buses which have number either equal or 1 
 *          less or 1 greater to the previous
 *  -   You are to help Jack to go from A to B by spending the minimum amount of money.
 *          N, M, K <= 100.
 *  
 *  Input
 *      Line 1:    N M
 *      Line 2:    NxM Grid
 * 
 *      Each row lists the fares the M busses to go form the current city to the next city.
 *  Output
 *      Single Line containing the minimum amount of fare that Jack has to give.
 *  
 *  Sample Input
 *      5 5
 *      1  3  1  2  6
 *      10 2  5  4  15
 *      10 9  6  7  1
 *      2  7  1  5  3
 *      8  2  6  1  9
 *  Sample Output
 *      10
 *  Explanation:
 *      1 -> 4 -> 1 -> 3 -> 1: 10
 */

int calculateMinFare(int** arr, int n, int m, int i, int j, int** dp){
    if(i==n){
        return 0;
    }
    if(dp[i][j] > -1){
        return dp[i][j];
    }
    
    int ans1 = arr[i][j] + calculateMinFare(arr, n, m, i+1, j, dp);
    int ans2 = INT_MAX;
    if(j+1 < m){
        ans2 = arr[i][j] + calculateMinFare(arr, n, m, i+1, j+1, dp);
    }
    int ans3 = INT_MAX;
    if(j-1 > 0){
        ans3 = arr[i][j] + calculateMinFare(arr, n, m, i+1, j-1, dp);
    }
    
    dp[i][j] = min(ans1, min(ans2, ans3));
    return dp[i][j];
}

int main(){
    int n,m;
    cin >> n >> m;
    
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[m+1];
    }
    
    int minFare = INT_MAX;
    for(int k=0; k<m; k++){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = -1;
            }
        }
        minFare = min(minFare, calculateMinFare(arr, n, m, 0, k, dp));
    }
    
    for(int i=0; i<=n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    
    cout << minFare << endl;
    
    return 0;
}
