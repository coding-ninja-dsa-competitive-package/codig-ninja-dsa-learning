#include<iostream>

using namespace std;

/**
 *  Spiral Print
 *  -   For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. 
 *      That is, you need to print in the order followed for every iteration:
 *      -   First row(left to right)
 *      -   Last column(top to bottom)
 *      -   Last row(right to left)
 *      -   First column(bottom to top)
 *  -   Mind that every element will be printed only once.
 * 
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      First line of each test case or query contains two integer values, 'N' 
 *      and 'M', separated by a single space. They represent the 'rows' and 'columns' 
 *      respectively, for the two-dimensional array/list.
 *      Second line onwards, the next 'N' lines or rows represent the ith row values.   
 *      Each of the ith row constitutes 'M' column values separated by a single space.
 *  Output format :
 *      For each test case, print the elements of the two-dimensional array/list in 
 *      the spiral form in a single line, separated by a single space.
 *      Output for every test case will be printed in a seperate line.
 *      
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= N <= 10^3  
 *      0 <= M <= 10^3
 *  Time Limit: 1sec
 *      
 *  Sample Input 1:
 *      1
 *      4 4 
 *      1 2 3 4 
 *      5 6 7 8 
 *      9 10 11 12  
 *      13 14 15 16
 *  Sample Output 1:
 *      1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
 *  
 *  Sample Input 2:
 *      2
 *      3 3 
 *      1 2 3 
 *      4 5 6 
 *      7 8 9
 *      3 1 
 *      10
 *      20
 *      30
 *  Sample Output 2:
 *      1 2 3 6 9 8 7 4 5 
 *      10 20 30 
 */
void spiralPrint(int **input, int nRows, int nCols)
{
    int total = nRows*nCols;
    int i=0;
    int col_start = 0, col_end = nCols-1, row_start = 0, row_end = nRows-1;
	while(i < total){
        for(int a=col_start; a <= col_end; a++){
            cout << input[row_start][a] << " ";
            i++;
        }
        row_start++;
        for(int b=row_start; b <= row_end; b++){
            cout << input[b][col_end] << " ";
            i++;
        }
        col_end--;
        for(int c=col_end; c >= col_start; c--){
            cout << input[row_end][c] << " ";
            i++;
        }
        row_end--;
        for(int d=row_end; d >= row_start; d--){
            cout << input[d][col_start] << " ";
            i++;
        }
        col_start++;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];
        for (int i = 0; i < row; i++){
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);
        for (int i = 0; i < row; ++i){
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << endl;
    }
}