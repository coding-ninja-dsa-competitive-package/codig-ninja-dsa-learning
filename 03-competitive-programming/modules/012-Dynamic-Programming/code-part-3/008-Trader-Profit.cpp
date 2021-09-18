#include<bits/stdc++.h>

using namespace std;

/**
 *  Trader Profit
 *  -   Mike is a stock trader and makes a profit by buying and selling stocks. He 
 *      buys a stock at a lower price and sells it at a higher price to book a profit. 
 *      He has come to know the stock prices of a particular stock for n upcoming days 
 *      in future and wants to calculate the maximum profit by doing the right 
 *      transactions (single transaction = buying + selling). Can you help him maximize 
 *      his profit?
 *  
 *  Note: A transaction starts after the previous transaction has ended. Two transactions 
 *      can't overlap or run in parallel.
 *  -   The stock prices are given in the form of an array A for n days.
 *  -   Given the stock prices and a positive integer k, find and print the maximum 
 *      profit Mike can make in at most k transactions.
 *  
 *  Input Format
 *      The first line of input contains an integer q denoting the number of queries.
 *      The first line of each test case contains a positive integer k, denoting the 
 *      number of transactions. 
 *      The second line of each test case contains a positive integer n, denoting the 
 *      length of the array A.
 *      The third line of each test case contains n space-separated positive integers, 
 *      denoting the prices of each day in the array A.
 *  
 *  Constraints
 *      1<=q<=100
 *      0<k<10
 *      2<=n<=30
 *      0<=elements of array A<=1000
 *  
 *  Output Format
 *      For each query print the maximum profit earned by Mike on a new line.   
 * 
 *  Sample Input
 *      3
 *      2   
 *      6
 *      10 22 5 75 65 80
 *      3
 *      4
 *      20 580 420 900
 *      1
 *      5
 *      100 90 80 50 25
 *  Sample Output
 *      87
 *      1040        
 *      0
 */

int maxProfit(int* trx, int n, int k, int ongoingFlag, int*** dp){
	if(n==0 || k==0){
        return 0;
    }
    if(dp[n][k][ongoingFlag] > -1){
        return dp[n][k][ongoingFlag];
    }
    
    int ans1 = maxProfit(trx+1, n-1, k, ongoingFlag, dp);
    int ans2;
    if(ongoingFlag == 1){
        ans2 = maxProfit(trx+1, n-1, k-1, 0, dp) + trx[0];
    } else{
        if(k > 0){
            ans2 = maxProfit(trx+1, n-1, k, 1, dp) - trx[0];
        }
    }
    dp[n][k][ongoingFlag] = max(ans1, ans2);
    return dp[n][k][ongoingFlag];
}

int maxProfit(int* trx, int n, int k){
    int*** dp = new int**[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int*[k+1];
        for(int j=0; j<=k; j++){
            dp[i][j] = new int[2];
            for(int l=0; l<=1; l++){
                dp[i][j][l] = -1;
            }
        }
    }
    
    int ans = maxProfit(trx, n , k, 0, dp);
	for(int i=0; i<n+1; i++){
        for(int j=0; j<k+1; j++){
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;    
	return ans;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int k, n;
        cin >> k >> n;
        int* transaction = new int[n];
        for(int i=0; i<n; i++){
            cin >> transaction[i];
        }
        cout << maxProfit(transaction, n, k) << endl;
        
    }
    return 0;
}
