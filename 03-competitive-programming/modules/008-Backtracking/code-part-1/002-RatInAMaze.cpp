#include<bits/stdc++.h>

using namespace std;

/**
 *  Rat In A Maze Problem
 *  -   You are given a N*N maze with a rat placed at maze[0][0]. Find and print 
 *      all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. 
 *      Rat can move in any direc­tion ( left, right, up and down).
 *  -   Value of every cell in the maze can either be 0 or 1. Cells with value 0 
 *      are blocked means rat can­not enter into those cells and those with value 1 
 *      are open.
 *  
 *  Input Format
 *      The first line of input contains an integer 'N' representing 
 *      the dimension of the maze.
 *      The next N lines of input contain N space-separated 
 *      integers representing the type of the cell.
 *  Output Format :
 *      For each test case, print the path from start position to destination 
 *      position and only cells that are part of the solution path should be 1, rest 
 *      all cells should be 0.
 *      Output for every test case will be printed in a separate line.
 *  
 *  Constraints:
 *      0 < N < 11 0 <= Maze[i][j] <=1
 * 
 *  Time Limit: 1sec
 *  
 *  Sample Input 1 :
 *      3
 *      1 0 1
 *      1 0 1
 *      1 1 1
 *  Sample Output 1 :
 *      1 0 0 1 0 0 1 1 1 
 *  Sample Output 1 Explanation :
 *      Only 1 path is possible
 *      1 0 0
 *      1 0 0
 *      1 1 1
 *      Which is printed from left to right and then top to bottom in one line.
 *  
 *  Sample Input 2 :
 *      3
 *      1 0 1
 *      1 1 1
 *      1 1 1
 *  Sample Output 2 :
 *      1 0 0 1 1 1 1 1 1 
 *      1 0 0 1 0 0 1 1 1 
 *      1 0 0 1 1 0 0 1 1 
 *      1 0 0 1 1 1 0 0 1 
 *  Sample Output 2 Explanation :
 *      4 paths are possible which are printed in the required format.
 */

void printMatrix(int** arr , int n){
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
    }    
    cout << endl;
}

void ratInAMaze(int maze[][20] , int** sol , int r, int c, int n){
    if(r == n-1 && c == n-1){
        sol[r][c] = 1;
        printMatrix(sol, n);
        sol[r][c] = 0;
        return;
    }
    if(r < 0 || r >= n || c < 0 || c >= n || sol[r][c] == 1 || maze[r][c] == 0){
        return;
    }
    sol[r][c] = 1;
    ratInAMaze(maze, sol, r-1, c, n);
    ratInAMaze(maze, sol, r+1, c, n);
    ratInAMaze(maze, sol, r, c-1, n);
    ratInAMaze(maze, sol, r, c+1, n);
    sol[r][c] = 0;
}

void ratInAMaze(int maze[][20], int n){
	int** sol = new int*[n];
    for(int i=0; i<n; i++){
        sol[i] = new int[n];
        for(int j=0; j<n; j++){
            sol[i][j] = 0;
        }
    }
    ratInAMaze(maze, sol, 0, 0, n);
}


int main() {
    int n; 
    cin >> n ;
    int maze[20][20];
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }		
    }
    ratInAMaze(maze, n);
}