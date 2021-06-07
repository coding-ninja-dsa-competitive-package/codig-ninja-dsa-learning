/**
 *  Backtracking:
 *  ============
 *  -   It means basically - exploring all the paths possible to get the answer.
 *  -   It is an approach which we can use to solve our problem and how we can
 *      implement this approach is basically , we call as recursion.
 */
#include<iostream>

using namespace std;

/**
 *  N-Queen Problem
 *  -   You are given N, and for a given N x N chessboard, find a way to place N 
 *      queens such that no queen can attack any other queen on the chess board. 
 *      A queen can be killed when it lies in the same row, or same column, or the 
 *      same diagonal of any of the other queens. You have to print all such 
 *      configurations.
 *  Note: Don't print anything if there isn't any valid configuration.
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
void problem1(){
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
}

/**
 *  Rat In A Maze Problem
 *  -   You are given an integer N and a binary 2D array of size N*N. The 
 *      given binary matrix represents a maze and a rat starts from the top 
 *      left cell and has to reach to the bottom right cell of the maze. The 
 *      rat can move in all the four directions: up, down, left and right.
 *  -   In the given binary matrix, 0 signifies the cell is a dead end and 1 
 *      signifies the cell can be used to move from source to destination cell.
 *  -   You have to print all the paths, following which rat can move from the 
 *      top left cell to the bottom right cell of the given binary matrix.
 */ 
void ratInAMaze(int** arr, int n, int** sol, int r, int c){
    if(r == n-1 && c == n-1){
        sol[r][c] = 1;
        printMatrix(sol, n);
        sol[r][c] = 0;
        return;
    }
    if(r < 0 || r >= n || c < 0 || c >= n || sol[r][c] == 1 || arr[r][c] == 0){
        return;
    }
    sol[r][c] = 1;
    ratInAMaze(arr, n, sol, r-1, c);
    ratInAMaze(arr, n, sol, r, c-1);
    ratInAMaze(arr, n, sol, r+1, c);
    ratInAMaze(arr, n, sol, r, c+1);
    sol[r][c] = 0;
}
void problem2(){
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0; i <n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int** sol = new int*[n];
    for(int i=0; i<n; i++){
        sol[i] = new int[n];
        for(int j=0; j<n; j++){
            sol[i][j] = 0;
        }
    }
    ratInAMaze(arr, n, sol, 0, 0);
}

/**
 *  Crossword Problem
 *  -   Coding Ninjas has provided you a crossword of 10*10 grid. The grid 
 *      contains '+' or '-' as its cell values. Now, you are also provided 
 *      with a word list that needs to placed accurately in the grid. Cells 
 *      marked with '-' are to be filled with word list.
 *  -   For example, The following is an example for the input crossword grid 
 *      and the word list.
 *                  +-++++++++
 *                  +-++-+++++
 *                  +-------++
 *                  +-++-+++++
 *                  +-++-+++++
 *                  +-++-+++++
 *                  ++++-+++++
 *                  ++++-+++++
 *                  ++++++++++
 *                  ----------
 *                  CALIFORNIA;NIGERIA;CANADA;TELAVIV
 * 
 *      Output for the given input should be:
 *                  +C++++++++
 *                  +A++T+++++
 *                  +NIGERIA++
 *                  +A++L+++++
 *                  +D++A+++++
 *                  +A++V+++++
 *                  ++++I+++++
 *                  ++++V+++++
 *                  ++++++++++
 *                  CALIFORNIA
 *      Note: We have provided such test cases that there is only one 
 *      solution for the given input.
 */

/**
 *  Sudoku Solver:
 *  -   Coding Ninjas has provided you a 9*9 sudoku board. The board contains 
 *      non zero and zero values. Non zero values lie in the range: [1, 9]. 
 *      Cells with zero value indicate that the particular cell is empty and 
 *      can be replaced by non zero values.
 *  -   You need to find out whether the sudoku board can be solved. If the 
 *      sudoku board can be solved, then print true, otherwise print false.
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
void assignment1(){
    int board[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> board[i][j];
        }
    }
    sudokuSolver(board) ? cout << "true" : cout << "false";
}

/**
 *  Subset Sum
 *  -   You are given an array of integers and a target K. You have to find 
 *      the count of subsets of the given array that sum up to K.
 *  Note:
 *      1. Subset can have duplicate values.
 *      2. Empty subset is a valid subset and has sum equal to zero.
 */
#include<vector>
int countSubsetSumToK(int* arr,int n,int sum, vector<int> &output){
    int count =0;
    if(n==0){
        if(sum == 0){
            count++;
        }
        return count;
    }
    int ans1 = countSubsetSumToK(arr+1, n-1, sum, output);
    vector<int> res;
    for(int i=0; i<output.size(); i++){
        res.push_back(output[i]);
    }
    res.push_back(arr[0]);
    int ans2 = countSubsetSumToK(arr+1, n-1, sum-arr[0], res);
    return ans1+ans2;
}
void assignment2(){
    int t;
    cin >> t;
    while(t--){
        int n, sum;
        cin >> n >> sum;
        int* arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        vector<int> output;
        cout << countSubsetSumToK(arr, n, sum, output) << endl;
    }
}

int main() {
    // N Queens problem
    // problem1();

    // rat in a maze
    // problem2();

    // sudoku solver
    // assignment1();

    // count subsets sum to k
    assignment2();

    return 0;
}