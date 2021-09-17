#include<bits/stdc++.h>

using namespace std;

/**
 *  Knapsnack - Problem
 *  -   A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
 *      There are N items and ith item weighs wi and is of value vi. Considering the 
 *      constraints of maximum weight that knapsack can carry, you have to find and 
 *      return the maximum value that thief can generate by stealing items.
 *  Note
 *      Space complexity should be O(W).
 *  
 *  Input Format :
 *      The first line contains an integers, that denote the value of N. The following 
 *      line contains N space separated integers, that denote the values of weight of 
 *      items. The following line contains N space separated integers, that denote the 
 *      values associated with the items. The following line contains an integer that 
 *      denote the value of W. W denotes maximum weight that thief can carry.
 *  
 *  Output Format :
 *      The first and only line of output contains the maximum value that thief can 
 *      generate, as described in the task.     
 *  
 *  Constraints
 *      1 <= N <= 10^4
 *      1<= wi <= 100
 *      1 <= vi <= 100
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1 :
 *      4
 *      1 2 4 5
 *      5 4 8 6
 *      5
 *  
 *  Sample Output 1 :
 *      13
 */

// Approach 1 - Memoization
int knapsack(int* weight, int* value, int n, int maxWeight, int** dp) {
	if(n==0 || maxWeight==0){
        return 0;
    }	
    if(dp[n][maxWeight] > -1){
        return dp[n][maxWeight];
    }
    if(weight[0] > maxWeight){
        return knapsack(weight+1, value+1, n-1, maxWeight, dp);
    }
    int ans1 = value[0] + knapsack(weight+1, value+1, n-1, maxWeight-weight[0], dp);
    int ans2 = knapsack(weight+1, value+1, n-1, maxWeight, dp);
    dp[n][maxWeight] = max(ans1, ans2);
    return dp[n][maxWeight];
}

int knapsack(int *weight, int *value, int n, int maxWeight){
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[maxWeight+1];
        for(int j=0; j<=maxWeight; j++){
            arr[i][j] = -1;
        }
    }
    return knapsack(weight, value, n, maxWeight, arr);
}

//  Approach 2 - DP iterative
int knapsack_dp(int *weight, int *value, int n, int maxWeight){
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[maxWeight+1];
        for(int j=0; j<=maxWeight; j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            } else {
                arr[i][j] = -1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxWeight; j++){
            if(weight[i-1] > j){
                arr[i][j] = arr[i-1][j];
            } else {
                int ans1 = value[i-1] + arr[i-1][j-weight[i-1]];
                int ans2 = arr[i-1][j];
                arr[i][j] = max(ans1 , ans2);
            }
        }
    }
    return arr[n][maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}