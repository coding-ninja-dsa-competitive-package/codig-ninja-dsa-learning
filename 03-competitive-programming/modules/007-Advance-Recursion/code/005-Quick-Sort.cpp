#include<bits/stdc++.h>

using namespace std;

/**
 *  Quick Sort Code
 *  -   Sort an array A using Quick Sort.
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
 *      1 5 2 7 3
 *  Sample Output 2 :
 *      1 2 3 5 7 
 */


int getPartition(int input[], int start, int end){
    int partition = input[start];
    int count_min = 0;
    for(int i=start; i<=end; i++){
        if(input[i] < partition){
            count_min++;
        }
    }
    input[start] = input[start + count_min];
    input[start + count_min] = partition;
    
    int i=start, j=end; 
    while(i < start+count_min && j > start + count_min){
        if(input[i] < partition){
            i++;
        } else if(input[j] >= partition){
            j--;
        } else {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
}

void quickSort(int input[], int start, int end){
    if(start >= end){
        return;
    }
	int pivot = getPartition(input, start, end);
    quickSort(input, start, pivot-1);
    quickSort(input, pivot+1, end);
}

void quickSort(int input[], int size) {
  	quickSort(input, 0, size-1);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;

    return 0;
}