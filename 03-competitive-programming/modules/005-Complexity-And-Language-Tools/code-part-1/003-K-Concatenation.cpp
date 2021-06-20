#include<bits/stdc++.h>

using namespace std;

/**
 *  k-concatenation:
 *  -   You are given an array A with size N (indexed from 0) and an 
 *      integer K. Let's define another array B with size N · K as the 
 *      array that's formed by concatenating K copies of array A.
 *  -   For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.
 *  -   You have to find the maximum subarray sum of the array B. Fomally, 
 *      you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, 
 *      where 0 ≤ i ≤ j < N · K.
 *  
 *  Input
 *      The first line of the input contains a single integer T denoting the 
 *      number of test cases. The description of T test cases follows.
 *      The first line of each test case contains two space-separated integers 
 *      N and K.
 *      The second line contains N space-separated integers A0, A1, ..., AN-1.
 *  Output
 *      For each test case, print a single line containing the maximum subarray 
 *      sum of B.
 *      
 *  Constraints
 *      1 ≤ T ≤ 10
 *      1 ≤ N ≤ 105
 *      1 ≤ K ≤ 105
 *      -106 ≤ Ai ≤ 106 for each valid i
 *  Subtasks    
 *      Subtask #1 (18 points): N · K ≤ 105
 *      Subtask #2 (82 points): original constraints
 *  
 *  Example
 *  Input:
 *      2
 *      2 3
 *      1 2
 *      3 2
 *      1 -2 1
 *  Output:
 *      9
 *      2
 *  Explanation
 *      Example case 1: B = {1, 2, 1, 2, 1, 2} and the subarray with 
 *      maximum sum is the whole {1, 2, 1, 2, 1, 2}. Hence, the answer is 9.
 *      Example case 2: B = {1, -2, 1, 1, -2, 1} and the subarray with 
 *      maximum sum is {1, 1}. Hence, the answer is 2.
 */
typedef long long ll;

ll kadane(int* arr, int n){
    ll curr_sum=0;
    ll max_sum = INT_MIN;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(max_sum < curr_sum){
            max_sum = curr_sum;
        }
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_sum;
}

ll maxSubarraySum(int* arr, int n, int k){
    ll kadane_sum = kadane(arr, n);
    if(k == 1){
        return kadane_sum;
    }
    ll curr_prefix_sum=0, curr_suffix_sum=0, total_sum=0;
    ll max_prefix_sum=INT_MIN, max_suffix_sum=INT_MIN;
    // max prefix sum
    for(int i=0; i<n; i++){
        curr_prefix_sum += arr[i];
        max_prefix_sum = max(max_prefix_sum, curr_prefix_sum);
    }
    // total sum
    total_sum = curr_prefix_sum;
    // max suffix sum
    for(int i=n-1; i>=0; i--){
        curr_suffix_sum += arr[i];
        max_suffix_sum = max(max_suffix_sum, curr_suffix_sum);
    }

    int ans;
    if(total_sum < 0){
        ans = max(max_prefix_sum + max_suffix_sum , kadane_sum);
    } else {
        ans = max((max_prefix_sum + max_suffix_sum + total_sum*(k-2)), kadane_sum);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int* arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << maxSubarraySum(arr, n, k) << endl;
    }

    return 0;
}