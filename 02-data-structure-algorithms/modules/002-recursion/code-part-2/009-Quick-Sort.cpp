#include<iostream>

using namespace std;

/**
 *  Quick Sort
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
int partition(int input[], int start, int end){
    int pivot = input[start], count=0;
    for(int i=start+1; i<=end; i++){
        if(input[i] <= pivot){
            count++;
        }
    }
    input[start] = input[start+count];
    input[start+count] = pivot;
    
    int i=start, j=end;
    while(i < start+count && j > start+count){
        if (input[i] <= pivot){
        	i++;
        }
        else if (input[j] > pivot){
            j--;
        }
        else{
         	int temp = input[i];
        	input[i] = input[j];
        	input[j] = temp;
        	i++;
        	j--;   
        }
    }
    return start+count;
    
}
void quickSortFun(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(input, start, end);
    quickSortFun(input , start, pivot-1);
    quickSortFun(input , pivot+1, end);
}
void quickSort(int input[], int size) {
	quickSortFun(input, 0, size-1);
}

int main(){
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
}