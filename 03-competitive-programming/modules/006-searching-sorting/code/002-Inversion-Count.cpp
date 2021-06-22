#include<bits/stdc++.h>

using namespace std;

/**
 *  Inversion Count
 *  -   For a given integer array/list of size N, find the total number of 
 *      'Inversions' that may exist.
 *  -   An inversion is defined for a pair of integers in the array/list when 
 *      the following two conditions are met.
 *  -   A pair (arr[i], arr[j]) is said to be an inversion when,
 *      1. arr[i] > arr[j]      
 *      2. i < j
 *  -   Where 'arr' is the input array/list, 'i' and 'j' denote the indices 
 *      ranging from [0, N).
 *  
 *  Input format :
 *      The first line of input contains an integer N, denoting the size of the array.
 *      The second line of input contains N integers separated by a single 
 *      space, denoting the elements of the array.
 *  Output format :
 *      The only line of output prints the total count of inversions in the array.
 *  Note:
 *      You are not required to print anything. Return the total number of 
 *      inversion count.
 *  
 *  Constraints :
 *      1 <= N <= 10^5 
 *      1 <= arr[i] <= 10^9
 *  Time Limit: 1sec
 *  
 *  Sample Input 1 :
 *      3
 *      3 2 1
 *  Sample Output 1 :
 *      3
 *  Explanation of Sample Input 1:  
 *      We have a total of three pairs which satisfy the condition of inversion. 
 *      (3, 2), (2, 1) and (3, 1).  
 *  
 *  Sample Input 2 :
 *      5
 *      2 5 1 3 4
 *  Sample Output 2 :
 *      4
 */
long long merge(long long *arr, int start, int end, int mid){
    long long count = 0;
    long long temp[end-start+1];
    int is=start, ie=mid, js=mid+1, je=end, k=0;
    while(is <= ie && js <= je){
        if(arr[is] <= arr[js]){
            temp[k++] = arr[is++];
        } else{
            temp[k++] = arr[js++];
        	count += (ie+1) - is;
        }
    }
    while(is <= ie){
        temp[k++] = arr[is++];
    }
    while(js <= je){
        temp[k++] = arr[js++];
    }
    for(int i=start, k=0; i<=end; i++,k++){
        arr[i] = temp[k];
    }
    return count;
}

long long mergeSort(long long *arr, int start, int end){
    long long inv_count = 0;
    if(start >= end){
        return inv_count;
    }
    int mid = start + (end-start)/2;
    inv_count += mergeSort(arr, start, mid);
    inv_count += mergeSort(arr, mid+1, end);
    inv_count += merge(arr, start, end , mid);
    return inv_count;
}

long long getInversions(long long *arr, int n){
	return mergeSort(arr, 0, n-1);
}

int main() {
    int n;
    cin >> n;
    long long* arr = new long long[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << getInversions(arr, n);
    delete [] arr;

    return 0;
}