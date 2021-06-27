#include<bits/stdc++.h>

using namespace std;

/**
 *  Merge Sort Code
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
 *  Sample Input 2 :
 *      5   
 *      2 1 5 2 3
 *  Sample Output 2 :
 *      1 2 2 3 5 
 */

void merge(int input[], int start, int end, int mid){
	int temp[end-start+1];
    int is=start, ie=mid, js=mid+1, je=end, k=0;
    while(is<=ie && js<=je){
        if(input[is] <= input[js]){
            temp[k++] = input[is++];
        } else {
            temp[k++] = input[js++];
        }
    }
    while(is <= ie){
        temp[k++] = input[is++];
    }
    while(js <= je){
        temp[k++] = input[js++];
    }
    for(int i=start, k=0; i<= end; i++, k++){
        input[i] = temp[k];
    }
}

void mergeSort(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    merge(input, start, end, mid);
}

void mergeSort(int input[], int size){
	mergeSort(input, 0, size-1);    
}

int main() {
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++){
        cin >> input[i];
    }
    mergeSort(input, length);
    for (int i = 0; i < length; i++){
        cout << input[i] << " ";
    }

    return 0;
}