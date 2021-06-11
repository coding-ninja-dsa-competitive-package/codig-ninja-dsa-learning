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
 *  Coding Ninjas
 *  -   Given a NxM matrix containing Uppercase English Alphabets only. Your 
 *      task is to tell if there is a path in the given matrix which makes the 
 *      sentence “CODINGNINJA” .
 *  -   There is a path from any cell to all its neighbouring cells. For a 
 *      particular cell, neighbouring cells are those cells that share an 
 *      edge or a corner with the cell.
 * 
 *  Input Format :
 *      The first line of input contains two space separated integers N and M, 
 *      where N is number of rows and M is the number of columns in the matrix. 
 *      Each of the following N lines contain M characters. Please note that 
 *      characters are not space separated.
 *  Output Format :
 *      Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
 * 
 *  Constraints :
 *      1 <= N <= 1000
 *      1 <= M <= 1000
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      2 11
 *      CXDXNXNXNXA 
 *      XOXIXGXIXJX
 *  Sample Output 1:
 *      1
 */
bool hasPath(vector<vector<char> > &board, int n, int m,int i, int j, string str, vector<vector<bool> > & visited) {
	if(str.length() == 0){
        return true;
    }
    int rows[]={i-1, i, i+1};
    int cols[]={j-1, j, j+1};
    for(int x=0; x<=2; x++){
        for(int y=0; y<=2; y++){
            int row = rows[x];
            int col = cols[y];
            if(row<0 || col<0 || row>=n || col>=m){
                continue;
            }
            if(board[row][col] == str[0] && !visited[row][col]){
                visited[row][col] = true;
                bool found = hasPath(board, n, m, row, col, str.substr(1), visited);
                if(found){
                    return true;
                } else {
                    visited[row][col] = false;
                }
            }
        }
    }
    return false;
}
bool hasPath(vector<vector<char> > &board, int n, int m, vector<vector<bool> > & visited){
    string str = "CODINGNINJA";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == str[0]){
                bool ans = hasPath(board, n, m, i, j, str.substr(1), visited);
                if(ans){
                    return true;
                }
            }
        }
    }
    return false;
}
bool hasPath(vector<vector<char> > &board, int n, int m) {
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    return hasPath(board, n, m, visited);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);

    return 0;
}