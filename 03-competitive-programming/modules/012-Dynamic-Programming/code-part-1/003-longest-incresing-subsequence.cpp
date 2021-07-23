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
 *  Longest Increasing Subsequence
 *  -   Given an array with N elements, you need to find the length of the 
 *      longest subsequence in the given array such that all elements of the 
 *      subsequence are sorted in strictly increasing order.
 * 
 *  Input Format
 *      The first line of input contains an integer N. The following line 
 *      contains N space separated integers, that denote the value of elements 
 *      of array.
 *  Output Format
 *      The first and only line of output contains the length of longest subsequence.
 *  
 *  Constraints
 *      1 <= N <= 10^3
 * 
 *  Time Limit: 1 second
 * 
 *  Sample Input 1 :
 *      6
 *      5 4 11 1 16 8
 *  Sample Output 1 :
 *      3
 * 
 *  Sample Output Explanation
 *      Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
 * 
 *  Sample Input 2 :
 *      3
 *      1 2 2
 *  Sample Output 2 :
 *      2
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
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << longestIncreasingSubsequence(arr, n);

    return 0;
}