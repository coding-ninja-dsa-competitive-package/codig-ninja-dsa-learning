#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Loot Houses
 *  -   A thief wants to loot houses. He knows the amount of money in each house. 
 *      He cannot loot two consecutive houses. Find the maximum amount of money 
 *      he can loot.
 */
// Approach 1 - Brute Force - O(2^n)
int maxMoneyLooted(int *arr, int n){
	if(n <= 0){
        return 0;
    }
    int ans1 = arr[0] + maxMoneyLooted(arr+2, n-2);
    int ans2 = maxMoneyLooted(arr+1, n-1);
    return max(ans1 , ans2);
}
// Approach 2 - Memoization
int maxMoneyLootedRec(int *arr, int n, int* out){
	if(n <= 0){
        return 0;
    }
    if(out[n] != -1){
        return out[n];
    }
    int ans1 = arr[0] + maxMoneyLootedRec(arr+2, n-2, out);
    int ans2 = maxMoneyLootedRec(arr+1, n-1, out);
    out[n] = max(ans1 , ans2);
    return out[n];
}
int maxMoneyLooted2(int *arr, int n){
    int* out = new int[n+1];
    for(int i=0; i<=n; i++){
        out[i] = -1;
    }
    return maxMoneyLootedRec(arr, n, out);
}
// Approach 3 - DP
int maxMoneyLooted3(int *arr, int n){
    int* out = new int[n+1];
    out[0] = 0;
    out[1] = arr[0];
    for(int i=2; i<=n; i++){
        out[i] = max(out[i-1], arr[i-1]+out[i-2]);
    }
    return out[n];
}
void problem1(){
    int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxMoneyLooted(arr, n);
    cout << maxMoneyLooted2(arr, n);
    cout << maxMoneyLooted3(arr, n);
	delete[] arr;
}

/**
 *  Longest Increasing Subsequence
 *  -   Given an array with N elements, you need to find the length of the 
 *      longest subsequence in the given array such that all elements of the 
 *      subsequence are sorted in strictly increasing order.
 */
// DP - O(n^2)
int longestIncreasingSubsequence(int* arr, int n) {
    int* out = new int[n];
    out[0] = 1;
    for (int i = 1; i < n; i++){
        out[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && out[i] < out[j] + 1){
                out[i] = out[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (max < out[i]){
            max = out[i];
        }
    }
    return max;
}
void problem2(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestIncreasingSubsequence(arr, n);
}
/**
 *  All possible ways  
 *  -   Given two integers a and b. You need to find and return the count of 
 *      possible ways in which we can represent the number a as the sum of 
 *      unique integers raise to the power b.
 *  -   For example: if a = 10 and b = 2, only way to represent 10 as sum of 
 *      unique integers raised to power 2 is - 10 = 1^2 + 3^2 
 *      Hence, answer is 1. 
 *  Note : x^y represents x raise to the power y
 */
int getWays(int a, int b, int i, int sum){
    int count = 0;
    int p = pow(i, b);
    while(p+sum < a){
        int res = getWays(a, b, i+1, sum+p);
        count += res;
        i++;
        p = pow(i, b);
    }
    if(p+sum == a){
        count++; 
    }
    return count;
}
int getAllWays(int a, int b) {
	return getWays(a, b, 1, 0);
}
void problem3(){
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}

/**
 *  Ways To Make Coin Change
 *  -   For the given infinite supply of coins of each of denominations,
 *      D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total 
 *      number of ways W, in which you can make the change for Value V using 
 *      coins of denominations D.
 *  -   Return 0 if the change isn't possible.
 */
// Approach 1 - Brute Force - O(2^n)
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }
    if(numDenominations<=0 && value>0){
        return 0;
    }
    int ans1 = countWaysToMakeChange(denominations, numDenominations-1, value);
    int ans2 = countWaysToMakeChange(denominations, numDenominations, value-denominations[numDenominations-1]);
    return ans1+ans2;
}
// Approach 2 - Memoization - O(n^2)
int countWaysToMakeChangeRec(int denominations[], int numDenominations, int value, int** arr){
	if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }
    if(numDenominations<=0 && value>0){
        return 0;
    }
    if(arr[numDenominations][value] != -1){
        return arr[numDenominations][value];
    }
    int ans1 = countWaysToMakeChangeRec(denominations, numDenominations-1, value, arr);
    int ans2 = countWaysToMakeChangeRec(denominations, numDenominations, value-denominations[numDenominations-1], arr);
    arr[numDenominations][value] = ans1+ans2;
    return arr[numDenominations][value];
}
int countWaysToMakeChange2(int denominations[], int numDenominations, int value){
    int** arr = new int*[numDenominations+1];
    for(int i=0; i<=numDenominations; i++){
        arr[i] = new int[value+1];
        for(int j=0; j<=value; j++){
            arr[i][j] = -1;
        }
    }
    return countWaysToMakeChangeRec(denominations, numDenominations, value, arr);
}
// Approach 3 - DP - O(n^2)
int countWaysToMakeChange3(int denominations[], int numDenominations, int value){
    int arr[numDenominations+1][value+1];
    for(int i=0; i<=numDenominations; i++){
        for(int j=0; j<=value; j++){
            if(i == 0){
                arr[i][j] = 0;  
            }
            if(j == 0){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=1; i<=numDenominations; i++){
        for(int j=1; j<=value; j++){
            if(denominations[i-1] > j){
                arr[i][j] = arr[i-1][j];
            } else {
                arr[i][j] = arr[i-1][j] + arr[i][j-denominations[i-1]];
            }
        }
    }
    return arr[numDenominations][value];
}
void problem4(){
    int numDenominations;
	cin >> numDenominations;
	int *denominations = new int[numDenominations];
	for (int i = 0; i < numDenominations; i++){
		cin >> denominations[i];
	}
	int value;
	cin >> value;
	cout << countWaysToMakeChange(denominations, numDenominations, value);
    cout << countWaysToMakeChange2(denominations, numDenominations, value);
    cout << countWaysToMakeChange3(denominations, numDenominations, value);
	delete[] denominations;
}


/**
 *  Matrix Chain Multiplication
 *  -   Given a chain of matrices A1, A2, A3,.....An, you have to figure out 
 *      the most efficient way to multiply these matrices. In other words, 
 *      determine where to place parentheses to minimize the number of multiplications.
 *  -   You will be given an array p[] of size n + 1. Dimension of matrix Ai 
 *      is p[i - 1]*p[i]. You need to find minimum number of multiplications 
 *      needed to multiply the chain.
 */
// Approach 1 - Brute Force - O(n^n)
int matrixMultiplication(int* arr , int start, int end){
    if(start >= end-1){
        return 0;
    }
    int minimum = INT_MAX;
    for(int i=start+1; i<end; i++){
        int ans1 = matrixMultiplication(arr, start, i);
        int ans2 = matrixMultiplication(arr, i, end);
        int ans3 = arr[start] * arr[i] * arr[end];
        int ans = ans1 + ans2 + ans3;
        minimum = min(minimum, ans);
    }
    return minimum;
}
int matrixChainMultiplication(int* arr, int n) {
    return matrixMultiplication(arr, 0, n);
}
// Approach 2 - Memoization
int matrixMultiplicationRec(int* arr , int start, int end, int** out){
    if(start >= end-1){
        return 0;
    }
    if(out[start][end] != -1){
        return out[start][end];
    }
    int minimum = INT_MAX;
    for(int i=start+1; i<end; i++){
        int ans1 = matrixMultiplicationRec(arr, start, i, out);
        int ans2 = matrixMultiplicationRec(arr, i, end, out);
        int ans3 = arr[start] * arr[i] * arr[end];
        int ans = ans1 + ans2 + ans3;
        minimum = min(minimum, ans);
    }
    out[start][end] = minimum;
    return  out[start][end];
}
int matrixChainMultiplication2(int* arr, int n) {
    int** out = new int*[n+1];
    for(int i=0; i<=n; i++){
        out[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            out[i][j] = -1;
        }
    }
    return matrixMultiplicationRec(arr, 0, n, out);
}
// Approach 3 - DP
int matrixChainMultiplication3(int* arr, int n) {
    n++;
    int** out = new int*[n];
    for(int i=0; i<n; i++){
        out[i] = new int[n];
    }
    for(int i=1; i<n; i++){
        out[i][i] = 0;
    }
    for(int loop=2; loop<n; loop++){
        for(int i=1; i<n-loop+1; i++){
            int j = i+loop-1;
            out[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int ans = out[i][k] + out[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                if(ans < out[i][j]){
                    out[i][j] = ans;
                }
            }
        }
    }
    return out[1][n-1];
}
void problem5(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }
    cout << matrixChainMultiplication(arr, n);
    cout << matrixChainMultiplication2(arr, n);
    cout << matrixChainMultiplication3(arr, n);
}

/**
 *  Coin Tower
 *  -   Whis and Beerus are playing a new game today. They form a tower of N coins 
 *      and make a move in alternate turns. Beerus plays first. In one step, the 
 *      player can remove either 1, X, or Y coins from the tower. The person to 
 *      make the last move wins the game. Can you find out who wins the game?
 */
// Approach 1 - Brute Force - O(3^n)
int findGameWinner(int n, int x, int y){
    if(n<=0){
        return 0;
    }
    int ans1 = 1 ^ findGameWinner(n-1, x, y);
    int ans2 = 0;
    if(n >= x){
        ans2 = 1 ^ findGameWinner(n-x, x, y);
    }
    int ans3 = 0;
    if(n >= y){
        ans3 = 1 ^ findGameWinner(n-y, x, y);
    }
    if(ans1+ans2+ans3 > 0){
        return 1;
    }
    return 0;
}
string findWinner(int n, int x, int y, int index = 0){
	if(findGameWinner(n, x, y) == 1){
        return "Beerus";
    }
    return "Whis";
}

// Approach 2 - Memoization = O(n)
int findGameWinnerRec(int n, int x, int y, int* arr){
    if(n<=0){
        return 0;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int ans1 = 1 ^ findGameWinnerRec(n-1, x, y, arr);
    int ans2 = 0;
    if(n >= x){
        ans2 = 1 ^ findGameWinnerRec(n-x, x, y, arr);
    }
    int ans3 = 0;
    if(n >= y){
        ans3 = 1 ^ findGameWinnerRec(n-y, x, y, arr);
    }
    if(ans1+ans2+ans3 > 0){
        arr[n] = 1;
    } else {
        arr[n] = 0;
    }
    return arr[n];
}
string findWinner2(int n, int x, int y, int index = 0){
    int* arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
	if(findGameWinnerRec(n, x, y, arr) == 1){
        return "Beerus";
    }
    return "Whis";
}
// Approach 3 - DP - O(n)
string findWinner3(int n, int x, int y, int index = 0){
    int* arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        int ans1 = 1^arr[i-1];
        int ans2=0, ans3=0;
        if(i >= x){
            ans2 = 1^arr[i-x];
        }
        if(i >= y){
            ans3 = 1^arr[i-y];
        }
        if(ans1 + ans2 + ans3 > 0){
        	arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
	if(arr[n] == 1){
        return "Beerus";
    }
    return "Whis";
}
void problem6(){
    int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
    cout << findWinner2(n, x, y);
    cout << findWinner3(n, x, y);
}

/**
 *  Maximum Square Matrix With All Zeros
 *  -   Given an NxM matrix that contains only 0s and 1s, find out the size 
 *      of the maximum square sub-matrix with all 0s. You need to return the 
 *      size of the square matrix with all 0s.
 */
int findMaxSquareWithAllZeros(int **arr, int n, int m){
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if((i==0 || j==0) && arr[i][j] == 0){
                dp[i][j] = 1;
            } else if(i==0 || j==0) {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
    	for(int j=1; j<n; j++){
            if(arr[i][j] == 0){
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            } else {
                dp[i][j] = 0;
            }
        }  
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
	return ans;
}
void problem7(){
    int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	for (i = 0; i < n; i++){
		arr[i] = new int[m];
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
	delete[] arr;
}

/**
 *  Shortest Subsequence
 *  -   Gary has two string S and V. Now, Gary wants to know the length shortest 
 *      subsequence in S, which is not a subsequence in V.
 *  Note: The input data will be such that there will always be a solution.
 */
// Approach 1 - Brute Force - O(2^n)
int solveHelper(string s, string v, int n, int m) {
    if(n==0){
        return 1001;
    }
    if(m<=0){
        return 1;
    }
    int ans1 = solveHelper(s.substr(1), v, n-1, m);
    int i=0;
    for(; i<m; i++){
        if(v[i] == s[0]){
            break;
        }
    }
    if(i == m){
        return 1;
    }
    int ans2 = 1+solveHelper(s.substr(1), v.substr(i+1), n-1, m-i-1); 
    return min(ans1, ans2);
}

int solve(string s, string v){
    int n = s.length();
    int m = v.length();
    return solveHelper(s, v, n, m);
}
//	Approach 2 - Memoization
int solveHelperRec(string s, string v, int n, int m, int **dp){
    if (n == 0){
		return 1001;
	}
	if (m <= 0){
		return 1;
	}
    if(dp[n][m]>=0){
        return dp[n][m];
    }
    int ans1=solveHelperRec(s.substr(1), v, n-1, m, dp);
	int i = 0;
	for (; i < m; i++){
		if (s[0] == v[i]){
			break;
		}
	}
	if (i == m){
		return 1;
	}
    int ans2= 1 + solveHelperRec(s.substr(1), v.substr(i+1), n-1, m-i-1, dp);
    dp[n][m] = min(ans1, ans2);
    return dp[n][m];
}
int solve2(string s, string v){
    int n=s.length();
    int m=v.length();
	int **dp=new int* [n+1];
    for(int i=0; i<n+1; i++){
        dp[i]=new int [m+1];
        for(int j=0; j<m+1; j++){
            dp[i][j]=-1;
        }
    }
    return solveHelperRec(s, v, n, m, dp);
    for(int i=0; i<s.length()+1; i++){
        delete[]dp[i];
    }
    delete[]dp;
}
void problem8(){
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
    cout << solve2(s, v);
}

int main() {
    // Loot Houses
    // problem1();

    // Longest Increasing Subsequence
    // problem2();

    // All possible ways
    // problem3();

    // Ways To Make Coin Change
    // problem4();

    // Matrix Chain Multiplication
    // problem5();

    // Coin Tower
    // problem6();

    // Maximum Square Matrix With All Zeros
    // problem7();

    // Shortest Subsequence
    problem8();

    return 0;
}