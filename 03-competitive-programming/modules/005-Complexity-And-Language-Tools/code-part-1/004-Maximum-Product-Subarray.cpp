#include<bits/stdc++.h>

using namespace std;

/**
 *  Maximum Product Subarray
 *  -   Given an array that contains both positive and negative integers. Find and
 *      return the product of maximum product subarray.
 *  -   Assumption : There is always a postive product possible i.e. no array of
 *      this form (0, -20 , 0) or (-20)
 * 
 *  Input Format :
 *      Line 1 : Integer n, size of array
 *      Line 2 : Array elements (separated by space)
 *  Output Format :
 *      Maximum product
 * 
 *  Constraints :
 *      1 <= N <= 9
 * 
 *  Sample Input 1:
 *      5
 *      6 -3 -10 0 2
 *  Sample Output 1:
 *      180
 * 
 *  Sample Input 2;
 *      6
 *      2 3 4 5 -1 0
 *  Sample Output 2:
 *      120
 */
int maxProductSubarray(int arr[], int n){
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            max_ending_here *= arr[i];
            min_ending_here = min(min_ending_here*arr[i], 1);
        } else if(arr[i]==0){
            max_ending_here = 1;
            min_ending_here = 1;
        } else {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here*arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << maxProductSubarray(arr, n) << endl;

    return 0;
}