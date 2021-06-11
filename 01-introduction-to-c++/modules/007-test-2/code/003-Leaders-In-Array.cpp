#include<iostream>

using namespace std;

/**
 *  Leaders in array
 *  -   Given an integer array A of size n. Find and print all the leaders 
 *      present in the input array. An array element A[i] is called Leader, 
 *      if all the elements following it (i.e. present at its right) are 
 *      less than or equal to A[i].
 *  -   Print all the leader elements separated by space and in the same 
 *      order they are present in the input array.
 * 
 *  Input Format :
 *      Line 1 : Integer n, size of array
 *      Line 2 : Array A elements (separated by space)
 *  Output Format :
 *      leaders of array (separated by space)
 *  Constraints :   
 *      1 <= n <= 10^6
 *  
 *  Sample Input 1 :
 *      6
 *      3 12 34 2 0 -1
 *  Sample Output 1 :
 *      34 2 0 -1
 * 
 *  Sample Input 2 :
 *      5
 *      13 17 5 4 6
 *  Sample Output 2 :
 *      17 6
 */
void Leaders(int* arr,int len){
    for(int i=0; i<len; i++){
        for(int j=len-1;j>=i; j--){
            if(arr[j] > arr[i]){
                break;
            }
            if(j == i){
                cout << arr[i] << " ";
            }
        }
    }
}

int main(){
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}
	Leaders(arr,len);
}