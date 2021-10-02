#include<bits/stdc++.h>

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

void hasCycle(vector<vector<char> > &board, vector<vector<bool> >& visited, int n, int m, int x, int y, int fromX, int fromY, bool& found, char ch){
    if(x<0 || x>=n || y<0 || y>=m || board[x][y] != ch){
        return;
    }
    if(visited[x][y]){
        found = true;
        return;
    }
    visited[x][y] = true;
    int rows[] = {-1, 1, 0, 0};
    int cols[] = {0, 0, -1, 1};
    for(int i=0; i<4; i++){
        int row = x+rows[i];
        int col = y+cols[i];
        if(row == fromX && col == fromY){
            continue;
        }
        hasCycle(board, visited, n, m, row, col, x, y, found, ch);
    }
}

bool hasCycle(vector<vector<char> > &board, int n, int m) {
	vector<vector<bool> > visited(n, vector<bool>(m, false));
    bool foundCycle = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                hasCycle(board, visited, n, m, i, j, -1, -1, foundCycle, board[i][j]);
            }
        }
    }
    return foundCycle;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasCycle(board, n, m) ? "true" : "false");
}