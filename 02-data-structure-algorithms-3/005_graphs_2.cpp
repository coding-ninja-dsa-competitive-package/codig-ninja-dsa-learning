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
 *  Islands
 *  -   An island is a small piece of land surrounded by water . A group of     
 *      islands is said to be connected if we can reach from any given island 
 *      to any other island in the same group . Given V islands (numbered from 
 *      1 to V) and E connections or edges between islands. Can you count the 
 *      number of connected groups of islands.
 */
void dfs(vector<vector<int> > & edges, int n, int start, vector<bool> & visited){
    for(int i=0; i<n; i++){
        if(i != start && edges[start][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(edges, n, i, visited);
        }
    }
}
int countNumOfIslands(vector<vector<int> > & edges,int n, vector<bool> & visited){
    int count=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(edges, n, i, visited);
            count++;
        }
    }
    return count;
}
void assignment1() {
    int v, e;
    cin >> v >> e;
    vector<vector<int> > edges(v, vector<int>(v));
    for(int i=0; i<e; i++){
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    vector<bool> visited(v, false);
    cout << countNumOfIslands(edges, v, visited) << endl;
}

/**
 *  Coding Ninjas
 *  -   Given a NxM matrix containing Uppercase English Alphabets only. Your 
 *      task is to tell if there is a path in the given matrix which makes the 
 *      sentence “CODINGNINJA” .
 *  -   There is a path from any cell to all its neighbouring cells. For a 
 *      particular cell, neighbouring cells are those cells that share an 
 *      edge or a corner with the cell.
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
void assignment2(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);
}

/**
 *  Connecting Dots
 *  -   Gary has a board of size NxM. Each cell in the board is a coloured 
 *      dot. There exist only 26 colours denoted by uppercase Latin characters 
 *      (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. 
 *      The key of this game is to find a cycle that contain dots of same colour. 
 *      Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only 
 *      if it meets the following condition:
 *      1.  These k dots are different: if i ≠ j then di is different from dj.
 *      2.  k is at least 4.
 *      3.  All dots belong to the same colour.
 *      4.  For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 
 *          should also be adjacent. Cells x and y are called adjacent if they 
 *          share an edge.
 *  -   Since Gary is colour blind, he wants your help. Your task is to determine 
 *      if there exists a cycle on the board.
 */
// Solution 1
bool hasCycle(vector<vector<char> > &board, int n, int m, int i, int j, vector<vector<bool> > &visited, char ch) {
	int up=0, down=0, left=0, right=0;
    if(i > 0){
        up = (int)visited[i-1][j];
    }
    if(i+1 < n){
        down = (int)visited[i+1][j];
    }
    if(j>0){
        left = (int)board[i][j-1];
    }
    if(j+1 < m){
        right = (int)board[i][j+1];
    }
    if((up+down+left+right) == 2){
        return true;
    }
    
    bool found = false;
    // check up 
    if(i>0 && board[i-1][j] == ch && !visited[i-1][j]){
        visited[i-1][j] = true;
        bool ans = hasCycle(board, n, m, i-1, j, visited, ch);
        if(ans){
            found = true;
        } else {
            board[i-1][j] = false;
        }
    }
    // check left
    if(j>0 && board[i][j-1] == ch && !visited[i][j-1]){
        visited[i][j-1] = true;
        bool ans = hasCycle(board, n, m, i, j-1, visited, ch);
        if(ans){
            found = true;
        } else {
            board[i][j-1] = false;
        }
    }
    // check right
    if(i+1 < n && board[i+1][j] == ch && !visited[i+1][j]){
        visited[i+1][j] = true;
        bool ans = hasCycle(board, n, m, i+1, j, visited, ch);
        if(ans){
            found = true;
        } else {
            board[i+1][j] = false;
        }
    }
    // check down
    if(j+1 < m && board[i][j+1] == ch && !visited[i][j+1]){
        visited[i][j+1] = true;
        bool ans = hasCycle(board, n, m, i, j+1, visited, ch);
        if(ans){
            found = true;
        } else {
            board[i][j+1] = false;
        }
    }
    return found;
}
bool hasCycle(vector<vector<char> > &board, int n, int m) {
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bool ans = hasCycle(board, n, m , i , j, visited, board[i][j]);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

// Solution 2
void hasCycle2(vector<vector<char> > &board, vector<vector<bool> > &visited, int n,int m,int x, int y, int fromX, int fromY, bool &found, char ch){
    if(x<0 || x>=n || y<0 || y>=m){
        return;
    }
    if(board[x][y] != ch){
        return;
    }
    if(visited[x][y]){
        found = true;
        return;
    }
    visited[x][y] = true;
    int arrX[] = {1, -1, 0, 0};    
    int arrY[] = { 0, 0, 1, -1};   
    for(int i=0; i<4; i++){
        int nextX = x+arrX[i];
        int nextY = y+arrY[i];
        if(nextX == fromX && nextY == fromY){
            continue;
        }
        hasCycle2(board,visited, n, m, nextX, nextY, x, y, found, ch);
    }
}
bool hasCycle2(vector<vector<char> > &board,int n,int m){
    bool foundCycle=false;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
            	hasCycle2(board, visited , n , m , i, j, -1, -1, foundCycle, board[i][j]);
            }
        }
    }
    return foundCycle;
}
void assignment3(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasCycle(board, n, m) ? "true" : "false");
    cout << (hasCycle2(board, n, m) ? "true" : "false");
}

/**
 *  Largest Piece
 *  -   It's Gary's birthday today and he has ordered his favourite square cake 
 *      consisting of '0's and '1's . But Gary wants the biggest piece of '1's 
 *      and no '0's . A piece of cake is defined as a part which consist of only 
 *      '1's, and all '1's share an edge with each other on the cake. Given the 
 *      size of cake N and the cake, can you find the count of '1's in the biggest 
 *      piece of '1's for Gary ?
 */
int getBiggestPiece(vector<vector<int> > &cake, int n, int i, int j, vector<vector<bool> > &visited){
    int count =1;
    if(i>0 && cake[i-1][j]==1 && !visited[i-1][j]){
        visited[i-1][j] = true;
        count += getBiggestPiece(cake, n, i-1, j, visited);
    }
    if(j>0 && cake[i][j-1]==1 && !visited[i][j-1]){
        visited[i][j-1] = true;
        count += getBiggestPiece(cake, n, i, j-1, visited);
    }
    if(i+1 < n && cake[i+1][j]==1 && !visited[i+1][j]){
        visited[i+1][j] = true;
        count += getBiggestPiece(cake, n, i+1, j, visited);
    }
    if(j+1 < n && cake[i][j+1]==1 && !visited[i][j+1]){
        visited[i][j+1] = true;
        count += getBiggestPiece(cake, n, i, j+1, visited);
    }
    return count;
}
int getBiggestPieceSize(vector<vector<int> > &cake, int n) {
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    int maximum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && cake[i][j] == 1){
                visited[i][j] = true;
                int ans = getBiggestPiece(cake, n, i, j, visited);
                maximum = max(maximum, ans);
            }
        }
    }
    return maximum;
}
void assignment4(){
    int n;
    cin >> n;
    vector<vector<int> > cake(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }
    cout << getBiggestPieceSize(cake, n);
}


/**
 *  3 Cycle
 *  -   Given a graph with N vertices (numbered from 0 to N-1) and M undirected 
 *      edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a 
 *      cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
 */
int numOf3Cycles(vector<vector<int> > &edges, int n){
    int count =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j && edges[i][j]==1){
                for(int k=0; k<n; k++){
                    if(k != j && k != i && edges[j][k]==1 && edges[i][k]==1){
                        count++;
                    }
                }
            }
        }
    }
    return count/6;
}
void assignment5(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edges(n, vector<int>(n, 0));
    for(int i=0; i<m;i++){
        int sv,lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    cout << numOf3Cycles(edges, n) << endl;
}

int main() {
    // Islands
    // assignment1();

    // Coding Ninjas
    // assignment2();

    // Connecting Dots
    // assignment3();

    // Largest Piece
    // assignment4();

    // 3 Cycle
    assignment5();

    return 0;
}