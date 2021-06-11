#include<iostream>

using namespace std;

#include<iostream>
#include<cmath>
using namespace std;

/**
 *  Selection Sort:
 *  1.  From all elements, go in loop and find the min.
 *  2.  Put a pointer at start , and swap the min element with start index.
 *  3.  increment the index . 
 *  4.  Repeat steps 1-3.
 */
void selectionSort(int* arr, int n){
    for(int start=0; start<n-1; start++){
        int min=arr[start], min_idx=start;
        for(int j=min_idx+1; j<n; j++){
            if(arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
        }
        int temp = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		selectionSort(input, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
}