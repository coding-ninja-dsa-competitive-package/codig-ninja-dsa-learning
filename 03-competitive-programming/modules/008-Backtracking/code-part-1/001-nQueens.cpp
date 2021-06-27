#include<bits/stdc++.h>

using namespace std;

/**
 *  N-Queen Problem:
 *  -   You are given N, and for a given N x N chessboard, find a way to place 
 *      N queens such that no queen can attack any other queen on the chess board. 
 *      A queen can be killed when it lies in the same row, or same column, or 
 *      the same diagonal of any of the other queens. You have to print all such 
 *      configurations.
 *  
 *  Input Format :
 *      Line 1 : Integer N
 *  Output Format : 
 *      One Line for every board configuration. 
 *      Every line will have N*N board elements printed row wise and are separated 
 *      by space
 *  Note : Don't print anything if there isn't any valid configuration.
 *  
 *  Constraints :
 *      1<=N<=10
 *  Sample Input 1:
 *      4
 *  Sample Output 1 :
 *      0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
 *      0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
 */

void printMatrix(int** board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
    }
    cout << endl;
}

bool canBePlaced(int** board, int n, int row, int col){
    // check column
    for(int i=row-1; i>=0; i--){
        if(board[i][col] == 1){
            return false;
        }
    }
    // check left diagonal
    for(int i=row-1, j=col-1; i>=0 && j >=0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // check right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    return true;
}

void nQueens(int** board, int n, int row){
    if(row == n){
        printMatrix(board, n);
        return;
    }
    for(int i=0; i<n; i++){
        if(canBePlaced(board, n, row, i)){
            board[row][i] = 1;
            nQueens(board, n, row+1);
            board[row][i] = 0;
        }
    }
    
}

void placeNQueens(int n){
    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
	nQueens(board, n, 0);
}

int main() {
    int n; 
    cin >> n ;
    placeNQueens(n);

    return 0;
}