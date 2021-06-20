#include<bits/stdc++.h>

using namespace std;

/**
 *  Kadane’s Algorithm:
 *  -   Initialize:
 *          max_so_far = INT_MIN
 *          max_ending_here = 0
 *      Loop for each element of the array
 *          (a) max_ending_here = max_ending_here + a[i]
 *          (b) if(max_so_far < max_ending_here)
 *              max_so_far = max_ending_here
 *          (c) if(max_ending_here < 0)
 *              max_ending_here = 0
 *      return max_so_far
 * 
 *  Sample Input:
 *      8
 *      -2 -3 4 -1 -2 1 5 -3
 *  Sample Output:
 *      7
 *      Explanation : Max Sum Contiguous array : 4 -1 -2 1 5
 */

int largestSumContiguousArrayKadane(int* arr,int n){
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i=0; i<n; i++){
        max_ending_here += arr[i];
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << largestSumContiguousArrayKadane(arr, n);

    return 0;
}