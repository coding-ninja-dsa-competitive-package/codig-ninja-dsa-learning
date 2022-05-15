/**
 *  Maximum Subarray Sum
 *  -   This problem was asked by Amazon.
 *  -   Given an array of numbers, find the maximum sum of any contiguous subarray of 
 *      the array.
 *  -   For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would 
 *      be 137, since we would take elements 42, 14, -5, and 86.
 *  -   Given the array [-5, -1, -8, -9], the maximum sum would be -1.
 *  -   Follow up: Do this in O(N) time.
 *          
 *  Input Format:
 *  -   The first line of input contains size of array, which is denoted by N and 
 *      second line of input contains N space separated integers.
 *  Output Format:
 *  -   The first and only line of output should print the maximum subarray sum, as 
 *      described in the description.
 */

#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // solution
    int sum = 0, maxSum = INT_MIN;
	for(int i=0; i<n; i++){
        int curr_sum = sum + arr[i];
        if(curr_sum > arr[i]){
            sum = curr_sum;
        } else {
            sum = arr[i];
        }
        maxSum = max(maxSum , sum);
    }
    cout << maxSum << endl;
}