#include<iostream>
#include<cstring>

using namespace std;

/**
 *  Print Subsets of Array
 *  -   Given an integer array (of length n), find and print all the subsets 
 *      of input array.
 *  -   Subsets are of length varying from 0 to n, that contain elements of 
 *      the array. But the order of elements should remain same as in the input array.
 *  Note : The order of subsets are not important. Just print the subsets in different lines.
 * 
 *  Input format :  
 *      Line 1 : Integer n, Size of array
 *      Line 2 : Array elements (separated by space)
 *  Constraints :
 *      1 <= n <= 15
 *  
 *  Sample Input:   
 *      3
 *      15 20 12
 *  Sample Output:
 *      [] (this just represents an empty array, don't worry about the square brackets)
 *      12 
 *      20 
 *      20 12 
 *      15 
 *      15 12       
 *      15 20   
 *      15 20 12 
 */
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void subsetsOfArray(int input[], int n, int output[] , int m){
    if(n==0){
        printArray(output, m);
        return;
    }
    subsetsOfArray(input+1, n-1, output, m);
    int i;
    int out[m+1];
    for(i=0; i<m; i++){
        out[i] = output[i];
    }
    out[i] = input[0]; 
    subsetsOfArray(input+1, n-1, out, m+1);
}
void printSubsetsOfArray(int input[], int size) {
    int output[35000];
    subsetsOfArray(input, size, output, 0);
}

int main() {
    int input[1000],length;
    cin >> length;
    for(int i=0; i < length; i++)
  	    cin >> input[i];
    printSubsetsOfArray(input, length);
}