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
 *  Subset Sum
 *  -   You are given an array of integers and a target K. You have to find 
 *      the count of subsets of the given array that sum up to K.
 *  Note:
 *      1. Subset can have duplicate values.
 *      2. Empty subset is a valid subset and has sum equal to zero.
 * 
 *  Input Format:
 *      The first line of input will contain an integer T, that denotes the 
 *      value of number of test cases. Each test case contains two lines. 
 *      The first line of each test case will contain two space-separated integers 
 *      N and K, where N is the size of the given array and K is the target value. 
 *      The second line of each test case will contain N space separated integers 
 *      denoting the elements of the input array.
 *  Output Format ;
 *      For each test case, print the number of subsets that sum upto K in a 
 *      separate line.
 * 
 *  Constraints
 *      1 <= T <= 50
 *      2 <= N <= 15
 *      0 <= array[i] <= 10^9
 *      0 <= K <= 10^9
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      1
 *      5 6
 *      2 4 4 3 1
 *  Sample Output 1:
 *      3
 *  
 *  Explanation:
 *      Following are the three subsets, that sum upto K=6:
 *      1. [2, 4], Element 4 in this subset is the one at index 1
 *      2. [2, 4], Element 4 in this subset is the one at index 2
 *      3. [2, 3, 1]  
 *  Sample Input 2:
 *      2
 *      8 8
 *      1 4 1 3 1 1 2 3 
 *      8 2
 *      4 1 4 4 2 4 1 1
 *  Sample Output 2:
 *      30
 *      4
 */
#include<vector>
// Approach 1 - Recursion - Brute Force  
int countSubsetSumToK(int* arr,int n,int sum){
    int count =0;
    if(n==0){
        if(sum==0){
            count++;
        }
        return count;
    }
    if(arr[n-1] > sum){
        count += countSubsetSumToK(arr, n-1, sum);
    } else {
        count += countSubsetSumToK(arr, n-1, sum);
        count += countSubsetSumToK(arr, n-1, sum-arr[n-1]);
    }
    return count;
}
// Approach 2 - Memoization
int countSubsetSumToKRec(int* arr,int n,int sum, int** out){
    int count =0;
    if(n==0){
        if(sum==0){
            count++;
        }
        return count;
    }
    if(out[n][sum] != -1){
        return out[n][sum];
    }
    if(arr[n-1] > sum){
        count += countSubsetSumToKRec(arr, n-1, sum, out);
    } else {
        count += countSubsetSumToKRec(arr, n-1, sum, out);
        count += countSubsetSumToKRec(arr, n-1, sum-arr[n-1], out);
    }
    out[n][sum] = count;
    return count;
}
// Approach 3 - DP
int countSubsetSumToKDP(int* arr,int n,int sum, int** out){
    for(int i=0; i<=n; i++){
        out[i][0] = 1;
    }
    for(int j=1; j<=sum; j++){
        out[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] > j){
                out[i][j] = out[i-1][j];
            } else {
                out[i][j] = out[i-1][j] + out[i-1][j - arr[i-1]];
            }
        }
    }
    return out[n][sum];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n >> sum;
        int* arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int** out = new int*[n+1];
        for(int i=0; i<=n; i++){
            out[i] = new int[sum+1];
            for(int j=0; j<=sum; j++){
                out[i][j] = -1;
            }
        }
        cout << countSubsetSumToK(arr, n, sum) << endl;
        cout << countSubsetSumToKRec(arr, n, sum, out) << endl;
        cout << countSubsetSumToKDP(arr, n, sum, out) << endl;
        for(int i=0; i<n; i++){
            delete [] out[i];
        }
        delete [] arr;
        delete [] out;
    }

    return 0;
}