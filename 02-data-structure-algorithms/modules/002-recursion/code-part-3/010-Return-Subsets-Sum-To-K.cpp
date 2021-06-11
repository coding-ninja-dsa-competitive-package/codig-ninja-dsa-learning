#include<iostream>

using namespace std;

/**
 *  Return subsets sum to K
 *  -   Given an array A of size n and an integer K, return all subsets of A 
 *      which sum to K.
 *  -   Subsets are of length varying from 0 to n, that contain elements of 
 *      the array. But the order of elements should remain same as in the input array.
 *  Note : The order of subsets are not important.
 * 
 *  Input format :
 *      Line 1 : Integer n, Size of input array
 *      Line 2 : Array elements separated by space
 *      Line 3 : K 
 *  Constraints :
 *      1 <= n <= 20
 *  
 *  Sample Input :
 *      9 
 *      5 12 3 17 1 18 15 3 17 
 *      6
 *  Sample Output :
 *      3 3
 *      5 1
 */
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        if(k==0) {
            output[0][0] = 0;
            return 1;
        } else{
            return 0;
        }
    }
    int out1[10000][50] , out2[10000][50];
    int ans1 = subsetSumToK(input+1, n-1, out1, k);
    int ans2 = subsetSumToK(input+1, n-1, out2, k-input[0]);
    int i=0;
    for(int j=0; j<ans1; j++){
        for(int k=0; k<=out1[j][0]; k++){
            output[i][k] = out1[j][k];
        }
        i++;
    }
    for(int j=0; j<ans2; j++){
        output[i][0]=out2[j][0]+1;
        for(int k=output[i][0]; k>1; k--){
            output[i][k] = out2[j][k-1];
        }
        output[i][1]=input[0];
        i++;
    }
    return i;
}

int main() {
    int input[20],length, output[10000][50], k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];

    cin >> k;
    
    int size = subsetSumToK(input, length, output, k);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}