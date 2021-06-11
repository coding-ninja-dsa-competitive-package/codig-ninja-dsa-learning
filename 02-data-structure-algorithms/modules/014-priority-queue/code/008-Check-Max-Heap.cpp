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
 *  Check Max-Heap
 *  -   Given an array of integers, check whether it represents max-heap 
 *      or not. Return true if the given array represents max-heap, else 
 *      return false.
 * 
 *  Input Format:
 *      The first line of input contains an integer, that denotes the value 
 *      of the size of the array. Let us denote it with the symbol N.
 *      The following line contains N space separated integers, that denote 
 *      the value of the elements of the array.
 *  Output Format :
 *      The first and only line of output contains true if it represents max-heap 
 *      and false if it is not a max-heap.
 *  
 *  Constraints:
 *      1 <= N <= 10^5
 *      1 <= Ai <= 10^5
 * 
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1:
 *      8
 *      42 20 18 6 14 11 9 4
 *  Sample Output 1:
 *      true
 */
bool isMaxHeap(int arr[], int n) {
    for(int i=1; i<n; i++){
        int child = arr[i];
        int parent = arr[(i-1)/2];
        if(parent<child){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");
    delete[] arr;

    return 0;
}