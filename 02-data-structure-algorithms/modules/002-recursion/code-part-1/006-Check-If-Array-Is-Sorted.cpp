#include<iostream>

using namespace std;

/**
 *  Check if array is sorted or not
 */
bool isArraySorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return isArraySorted(arr+1, size-1);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << isArraySorted(arr, n) << endl;
}