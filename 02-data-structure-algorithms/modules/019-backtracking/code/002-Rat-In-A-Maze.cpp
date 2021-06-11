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
 *  Rat In A Maze Problem
 *  -   You are given an integer N and a binary 2D array of size N*N. The 
 *      given binary matrix represents a maze and a rat starts from the top 
 *      left cell and has to reach to the bottom right cell of the maze. The 
 *      rat can move in all the four directions: up, down, left and right.
 *  -   In the given binary matrix, 0 signifies the cell is a dead end and 1 
 *      signifies the cell can be used to move from source to destination cell.
 *  -   You have to print all the paths, following which rat can move from the 
 *      top left cell to the bottom right cell of the given binary matrix.
 * 
 *  Input Format
 *      The first line of input contains an integer, that denotes the value of N.
 *      Each of the following N lines denote rows of the binary matrix and contains 
 *      either 0 or 1. Each row of the binary matrix contains N elements. 
 * Output Format :
 *      Every possible solution has to be printed on a separate line. Each of the 
 *      possible solution will have N*N elements, printed row wise and separated 
 *      by space. The cells that are part of the path should be 1 and remaining 
 *      all cells should be 0. Please refer to sample test cases for more clarity.   
 * 
 *  Constraints
 *      1 <= N <= 18
 *      0 <= Number of cells with value 1 <= 15
 * 
 *  Time Limit: 1 second
 *  
 *  Sample Input 1 :
 *      3
 *      1 0 1
 *      1 0 1
 *      1 1 1
 * Sample Output 1 :
 *      1 0 0 1 0 0 1 1 1 
 *  Explanation :
 * 
 * Sample Input 2 :
 *      3
 *      1 0 1
 *      1 1 1
 *      1 1 1
 * Sample Output 2 :
 *      1 0 0 1 1 1 1 1 1 
 *      1 0 0 1 0 0 1 1 1 
 *      1 0 0 1 1 0 0 1 1 
 *      1 0 0 1 1 1 0 0 1 
 * 
 * Explanation:
 *      As described in the Sample Output 2, four paths are possible.
 */ 
void printMtrx(int** arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}
void ratInAMaze(int** arr, int n, int** sol, int r, int c){
    if(r == n-1 && c == n-1){
        sol[r][c] = 1;
        printMtrx(sol, n);
        sol[r][c] = 0;
        return;
    }
    if(r < 0 || r >= n || c < 0 || c >= n || sol[r][c] == 1 || arr[r][c] == 0){
        return;
    }
    sol[r][c] = 1;
    ratInAMaze(arr, n, sol, r-1, c);
    ratInAMaze(arr, n, sol, r+1, c);
    ratInAMaze(arr, n, sol, r, c-1);
    ratInAMaze(arr, n, sol, r, c+1);
    sol[r][c] = 0;
}
int main(){
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
    for(int i=0; i<n; i++){
        delete [] arr[i];
        delete [] sol[i];
    }
    delete [] arr;
    delete [] sol;

    return 0;
}