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
 *  K-sorted Array
 *  -   If it takes only less than k moves to place element in its correct position.
 *  -   i.e. element can move k-1 in left or in right for its correct position.
 * 
 *  Sort the k-sorted array in decreasing order. 
 *  Input :     12 15 7 4 9 
 *  Output :    15 12 9 7 4
 * 
 *  Time Complexity : 
 *      T(n)  =  klogk + 2(n-k)logk + klogk
 *            =  2nlogk 
 *            =  O(n)  , if k is very small.
 */
void kSortedArray(int arr[], int n, int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k ; i<n; i++){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }
    while (!pq.empty()){
        arr[j++] = pq.top();
        pq.pop();
    }
}

int main(){
    int n;
    cin >> n;
    int arr[1000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    kSortedArray(arr, n, k);
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}