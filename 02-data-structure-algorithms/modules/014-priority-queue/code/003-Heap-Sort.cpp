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
 *  Heap Sort
 *  -   Given an integer array of size N. Sort this array (in decreasing 
 *      order) using heap sort.
 *  -   Note: Space complexity should be O(1).
 * 
 *  Input Format:
 *      The first line of input contains an integer, that denotes the value 
 *      of the size of the array or N.
 *      The following line contains N space separated integers, that denote 
 *      the value of the elements of the array.
 *  Output Format :
 *      The first and only line of output contains array elements after sorting. 
 *      The elements of the array in the output are separated by single space.
 * 
 *  Constraints :
 *      1 <= n <= 10^6
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      6   
 *      2 6 8 5 4 3
 *  Sample Output 1:    
 *      8 6 5 4 3 2
 */
void buildHeap(int arr[], int n){
    for(int i = 1; i < n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }
}
void removeMin(int arr[], int n){
    int size = n;
    while(size > 1){
        int min = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = min;
        size--;
        
        int parentIndex = 0;
        while(parentIndex < size){
            int leftChildIdx = 2*parentIndex+1;
            int rightChildIdx = 2*parentIndex+2;
            int minIndex = -1;
            if(leftChildIdx < size && rightChildIdx < size){
                if(arr[leftChildIdx] < arr[rightChildIdx]){
                    minIndex = leftChildIdx;
                } else {
                    minIndex = rightChildIdx;
                }
            } else if(leftChildIdx < size){
                minIndex = leftChildIdx;
            } else if(rightChildIdx < size){
                minIndex = rightChildIdx;
            }
            if(minIndex != -1 && arr[parentIndex] > arr[minIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[minIndex];
                arr[minIndex] = temp;
                
                parentIndex = minIndex;
            } else {
                break;
            }
        }
    }
}
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    removeMin(arr, n);
}

int main(){
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 
    heapSort(input, size);
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 
    delete[] input;

    return 0;
}