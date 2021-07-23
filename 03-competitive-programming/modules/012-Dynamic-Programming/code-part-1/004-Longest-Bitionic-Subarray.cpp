#include<bits/stdc++.h>
using namespace std;

/**
 *  Largest Bitonic Subarray
 *  -   You are given an array of positive integers as input. Write a code to return 
 *      the length of the largest such subsequence in which the values are arranged 
 *      first in strictly ascending order and then in strictly descending order.
 *  -   Such a subsequence is known as bitonic subsequence. A purely increasing or 
 *      purely decreasing subsequence will also be considered as a bitonic sequence 
 *      with the other part empty.
 *  -   Note that the elements in bitonic subsequence need not be consecutive in the 
 *      given array but the order should remain same.
 *  
 *  Input Format:
 *      Line 1 : A positive Integer N, i.e., the size of array
 *      Line 2 : N space-separated integers as elements of the array 
 *  Output Format:
 *      Length of Largest Bitonic subsequence
 *  Input Constraints:
 *      1<= N <= 10000
 *  
 *  Sample Input 1: 
 *      6
 *      15 20 20 6 4 2
 *  Sample Output 1:
 *      5
 *  Sample Output 1 Explanation:
 *      Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
 *  
 *  Sample Input 2:
 *      2
 *      1 5
 *  Sample Output 2:
 *      2
 *  
 *  Sample Input 3:
 *      2
 *      5 1
 *  Sample Output 3:
 *      2
 */

int* lis(int* arr, int n){
    int* out = new int[n];
    out[0] = 1;
    for(int i=1; i<n; i++){
        int curr_max = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                curr_max = max(curr_max , out[j]);
            }
            out[i] = curr_max+1;
        }
    }
    return out;
}

int* lis_reverse(int* arr, int n){
    int* out = new int[n];
    out[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        int curr_max = 0;
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                curr_max = max(curr_max , out[j]);
            }
            out[i] = curr_max+1;
        }
    }
    return out;
}

int longestBitonicSubarray(int *input, int n) {
	int* lis_front = lis(input, n);
    int* lis_back = lis_reverse(input, n);
    int maximum = 2;
    for(int i=0; i<n; i++){
        maximum = max(maximum, lis_front[i] + lis_back[i] - 1);
    }
    return maximum;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}
