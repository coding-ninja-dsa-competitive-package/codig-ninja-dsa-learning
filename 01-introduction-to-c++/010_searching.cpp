#include<iostream>
using namespace std;

/**
 *  Binary Search:
 *  find X in array arr,
 *  1.  Take start , end element from arr and calculate mid element.
 *  2.  if X == mid , return index;
 *  3.  if X>mid , start = mid+1 else , end = mid-1;
 *  4.  Repeat step 2-3 till we find the element or arr is completed.
 */
int binarySearch(int *input, int n, int val){
    int start = 0, end = n-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(input[mid] == val){
            return mid;
        }
        if(val < input[mid]){
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    if(start > end){
        return -1;
    }
}
void problem1(){
    int size;
	cin >> size;
	int *input = new int[size];
	for(int i = 0; i < size; ++i){
		cin >> input[i];
	}
	int t;
	cin >> t;
	while (t--){
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	delete [] input;
}

int main(){
    
    // Binary Search
    problem1();
    
    return 0;
}