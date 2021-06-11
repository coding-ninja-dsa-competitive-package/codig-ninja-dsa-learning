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
 * 
 *  Input Format :  
 *      The first line of input contains two space separated integers N and M, 
 *      where N is number of rows and M is the number of columns of the board. 
 *      Each of the following N lines contain M characters. Please note that 
 *      characters are not space separated. Each character is an uppercase Latin 
 *      letter.
 *  Output Format :
 *      Print true if there is a cycle in the board, else print false.
 *  
 *  Constraints :
 *      2 <= N <= 1000
 *      2 <= M <= 1000
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      3 4
 *      AAAA
 *      ABCA
 *      AAAA
 *  Sample Output 1:
 *      true
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
int main(){
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
    return 0;
}