#include<bits/stdc++.h>

using namespace std;

/**
 *  DP with bitmasking
 */

// Recursive with memoization
int minCost(int cost[4][4], int n, int person, int mask, int* dp){
    if(person >= n){
        return 0;
    }
    if(dp[mask] != INT_MAX){
        return dp[mask];
    }
    int minimum = INT_MAX;
    for(int j=0; j<n; j++){
        if(!(mask & (1<<j))){
            int ans = minCost(cost, n, person+1, mask|(1<<j), dp) + cost[person][j];
            if(ans < minimum){
                minimum = ans;
            }
        }
    }
    dp[mask] = minimum;
    return minimum;
}

// Iterative
int minCostIterative(int cost[4][4], int n){
    int* dp = new int[1<<n];
    for(int i=0; i<(1<<n); i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int mask=0; mask<(1<<n)-1; mask++){
        int temp = mask;
        // count number of set bits
        int k=0; 
        while(temp > 0){
            if((temp % 2) == 1){
                k++;
            }
            temp = temp/2;
        }
        for(int j=0; j<n; j++){
            if(!(mask & (1<<j))){
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+cost[k][j]);
            }
        }
    }
    return dp[(1<<n) - 1];
}

int main() {
    int cost[4][4] = {{10, 2, 6, 5}, {1, 15, 12 , 8}, {7, 8, 9 , 3}, {15, 13 , 4 , 10}};
    int* dp = new int[1<<4];
    for(int i=0; i<(1<<4); i++){
        dp[i] = INT_MAX;
    }

    cout << minCost(cost, 4, 0, 0, dp) << endl;
    cout << dp[0] << endl;

    cout << minCostIterative(cost, 4) << endl;

    return 0;
}