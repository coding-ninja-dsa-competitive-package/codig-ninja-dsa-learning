#include<bits/stdc++.h>

using namespace std;

/**
 *  Maximum Sum Rectangle
 *  -   Given a 2D array, find the maximum sum rectangle in it. In other words 
 *      find maximum sum over all rectangles in the matrix.
 *  
 *  Input
 *      First line contains 2 numbers n and m denoting number of rows and number 
 *      of columns. Next n lines contain m space separated integers denoting 
 *      elements of matrix nxm.
 *  Output
 *      Output a single integer, maximum sum rectangle.
 * 
 *  Constraints
 *      1<=n,m<=100
 *  
 *  Sample Input
 *      4 5
 *      1    2   -1   -4   -20   
 *     -8   -3    4    2    1
 *      3    8    10   1    3
 *     -4   -1    1    7   -6
 *  Sample Output
 *      29
 */

int kadane(int* arr, int n){
    int curr_sum=0, max_so_far=INT_MIN;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum > max_so_far){
            max_so_far = curr_sum;
        }
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return max_so_far;
}

int maxSumRectangle(int** arr, int n, int m){
    int sum = INT_MIN;
    // starting column (i)
    for(int i=0; i<m; i++){
        int* temp = new int[n]();
        // loop from starting column to last column
        for(int j=i; j<m; j++){
            // loop from 0th row to last row
            for(int k=0; k<n; k++){
                temp[k] += arr[k][j];
            }
            sum = max(sum, kadane(temp, n));
        }
    }
    return sum;
}

int main(){
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int result = maxSumRectangle(arr, n, m);
    cout << result;
    return 0;
}
