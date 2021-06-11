#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  N-Queen Problem
 *  -   You are given N, and for a given N x N chessboard, find a way to place N 
 *      queens such that no queen can attack any other queen on the chess board. 
 *      A queen can be killed when it lies in the same row, or same column, or the 
 *      same diagonal of any of the other queens. You have to print all such 
 *      configurations.
 *  Note: Don't print anything if there isn't any valid configuration.
 * 
 *  Input Format:       
 *      The first line of input contains an integer, that denotes the value of N.     
 *  
 *  Output Format :
 *      In the output, you have to print every board configuration in a new line. 
 *      Every configuration will have N*N board elements printed row wise and are 
 *      separated by space. The cells where queens are safe and placed, are denoted 
 *      by value 1 and remaining all cells are denoted by value 0. Please refer to 
 *      sample test cases for more clarity.
 * 
 *  Constraints :
 *      1 <= N <= 10
 *      Time Limit: 1 second
 * 
 *  Sample Input 1:
 *      4
 *  Sample Output 1 :
 *      0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
 *      0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
 */
void printMatrix(int** arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}
bool isValidPosition(int** arr, int n, int row, int col){
    // check upper column
    for(int i = row-1; i >= 0; i--){
        if(arr[i][col] == 1){
            return false;
        }
    }
    // check upper left diagonal
    for(int i = row-1, j= col-1; i >=0  && j >= 0 ; i--, j--){
        if(arr[i][j] == 1){
            return false;
        }
    }
    // check upper right diagonal
    for(int i = row-1, j = col+1; i >=0  && j < n; i--, j++){
        if(arr[i][j] == 1){
            return false;
        }
    }
    return true;
}
void nQueens(int** arr, int row, int n){
    if(row == n){
        printMatrix(arr, n);
        return;
    }
    for(int j=0; j<n; j++){
        if(isValidPosition(arr, n, row, j)){
            // place the queen
            arr[row][j] = 1;
            // move to next row
            nQueens(arr, row+1, n);
            // backtrack
            arr[row][j] = 0;
        } 
    }
}

int main(){
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }
    nQueens(arr, 0, n);
    return 0;
}