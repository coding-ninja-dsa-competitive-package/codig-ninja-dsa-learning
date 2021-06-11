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
 *  Matrix Chain Multiplication
 *  -   Given a chain of matrices A1, A2, A3,.....An, you have to figure out 
 *      the most efficient way to multiply these matrices. In other words, 
 *      determine where to place parentheses to minimize the number of multiplications.
 *  -   You will be given an array p[] of size n + 1. Dimension of matrix Ai 
 *      is p[i - 1]*p[i]. You need to find minimum number of multiplications 
 *      needed to multiply the chain.
 *  
 *  Input Format:
 *      The first line of input contains an integer, that denotes the value 
 *      of n. The following line contains n+1 integers, that denote the value 
 *      of elements of array p[].
 *  Output Format:
 *      The first and only line of output prints the minimum number of 
 *      multiplication needed.
 * 
 *  Constraints :
 *      1 <= n <= 100
 *  
 *  Time limit: 1 second
 * 
 *  Sample Input 1:
 *      3
 *      10 15 20 25
 *  Sample Output 1:
 *      8000
 *  Sample Output Explanation:
 *      There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
 *      If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
 *      If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
 *      Thus minimum number of multiplications required are 8000. 
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

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }
    cout << matrixChainMultiplication(arr, n);
    cout << matrixChainMultiplication2(arr, n);
    cout << matrixChainMultiplication3(arr, n);

    return 0;
}