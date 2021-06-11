#include<iostream>

using namespace std;

/**
 *  Merge Sort
 *  -   Sort an array A using Merge Sort.
 *  -   Change in the input array itself. So no need to return or print anything.
 * 
 *  Input format :
 *      Line 1 : Integer n i.e. Array size
 *      Line 2 : Array elements (separated by space)
 *  Output format :
 *      Array elements in increasing order (separated by space)
 *  Constraints :
 *      1 <= n <= 10^3
 *  
 *  Sample Input 1 :
 *      6 
 *      2 6 8 5 4 3
 *  Sample Output 1 :
 *      2 3 4 5 6 8
 *  
 *  Sample Input 2:
 *      5   
 *      2 1 5 2 3
 *  Sample Output 2 :
 *      1 2 2 3 5 
 */
void merge(int arr[], int start, int mid, int end){
    int *temp = new int[end-start+1];
    int k=0;
    int s1 = start, e1=mid, s2=mid+1, e2 = end;
    while(s1 <= e1 && s2 <= e2){
        if(arr[s1] < arr[s2]){
            temp[k++] = arr[s1++];
        } else {
            temp[k++] = arr[s2++];
        }
    }
    while(s1<=e1){
        temp[k++] = arr[s1++];
    }
    while(s2<=e2){
        temp[k++] = arr[s2++];
    }
    int index = start;
    for(int i=0; i<k;  i++){
        arr[index++] = temp[i];
    }
    delete [] temp;
}
void mergeSortFun(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSortFun(arr, start, mid);
    mergeSortFun(arr, mid+1, end);
    merge(arr, start, mid, end);
}
void mergeSort(int input[], int size){
	mergeSortFun(input, 0, size-1);        
}

int main(){
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}