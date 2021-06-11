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
 *  Sudoku Solver:
 *  -   Coding Ninjas has provided you a 9*9 sudoku board. The board contains 
 *      non zero and zero values. Non zero values lie in the range: [1, 9]. 
 *      Cells with zero value indicate that the particular cell is empty and 
 *      can be replaced by non zero values.
 *  -   You need to find out whether the sudoku board can be solved. If the 
 *      sudoku board can be solved, then print true, otherwise print false.
 * 
 *  Input Format:
 *      There are nine lines in input. Each of the nine lines contain nine 
 *      space separated integers. These nine lines represent the sudoku board.
 *  Output Format:
 *      The first and only line of output contains boolean value, either true 
 *      or false, as described in problem statement.
 * 
 *  Constraints:
 *      The cell values lie in the range: [0, 9]
 * 
 *  Time Limit: 1 second 
 * 
 *  Note:
 *      Input are given in a way that backtracking solution will work in the 
 *      provided time limit.
 * 
 *  Sample Input 1:
 *      9 0 0 0 2 0 7 5 0 
 *      6 0 0 0 5 0 0 4 0 
 *      0 2 0 4 0 0 0 1 0 
 *      2 0 8 0 0 0 0 0 0 
 *      0 7 0 5 0 9 0 6 0 
 *      0 0 0 0 0 0 4 0 1 
 *      0 1 0 0 0 5 0 8 0 
 *      0 9 0 0 7 0 0 0 4 
 *      0 8 2 0 4 0 0 0 6
 *  Sample Output 1:
 *      true
 */
bool findEmptyCell(int board[][9],int &row,int &col){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isValidCell(int board[][9], int row, int col, int val){
    // check row
    for(int i=0; i<9; i++){
        if(board[row][i] == val){
            return false;
        }
    }
    // check col
    for(int j=0; j<9; j++){
        if(board[j][col] == val){
            return false;
        }
    }
    // check grid
    row = row-(row%3);
    col = col-(col%3);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i+row][j+col] == val){
                return false;
            }
        }
    }
    return true;
}
bool sudokuSolver(int board[9][9]){
    int row = 0, col = 0;
    // find empty cell and the coordinates of cell
    bool emptyCell = findEmptyCell(board, row, col);
    if(!emptyCell){
        return true;
    }
    // check for all possible values from 1-9
    for(int i=1; i<=9; i++){
        if(isValidCell(board, row, col, i)){
            board[row][col] = i;
            bool ans = sudokuSolver(board);
            if(ans){
                return true;
            } else {
                board[row][col] = 0;
            }
        }
    }
    return false;
}
int main(){
    int board[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
        }
    }
    sudokuSolver(board) ? cout << "true" : cout << "false";

    return 0;
}