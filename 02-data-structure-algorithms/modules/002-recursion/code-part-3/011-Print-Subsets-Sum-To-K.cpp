#include<iostream>

using namespace std;

/**
 *  Print Subset Sum to K
 *  -   Given an array A and an integer K, print all subsets of A which sum to K.
 *  -   Subsets are of length varying from 0 to n, that contain elements of 
 *      the array. But the order of elements should remain same as in the input array.
 *  Note : The order of subsets are not important. Just print them in different lines.
 * 
 *  Input format :
 *      Line 1 : Size of input array
 *      Line 2 : Array elements separated by space
 *      Line 3 : K 
 *      
 *  Sample Input:
 *      9 
 *      5 12 3 17 1 18 15 3 17 
 *      6   
 *  Sample Output:
 *      3 3 
 *      5 1
 */
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void subsetSumToK(int input[], int n, int output[], int m, int k){
    if(n==0){
        if(k==0){
            printArray(output, m);
        }
        return;
    }
    subsetSumToK(input+1, n-1, output, m, k);
    int i;
    int out[10000];
    for(i=0; i<m; i++){
        out[i] = output[i];
    }
    out[i] = input[0];
    subsetSumToK(input+1, n-1, out, m+1, k-input[0]);
}
void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    subsetSumToK(input, size, output, 0, k);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}