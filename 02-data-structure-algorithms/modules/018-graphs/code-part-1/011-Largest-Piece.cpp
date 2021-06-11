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
 *  Largest Piece
 *  -   It's Gary's birthday today and he has ordered his favourite square cake 
 *      consisting of '0's and '1's . But Gary wants the biggest piece of '1's 
 *      and no '0's . A piece of cake is defined as a part which consist of only 
 *      '1's, and all '1's share an edge with each other on the cake. Given the 
 *      size of cake N and the cake, can you find the count of '1's in the biggest 
 *      piece of '1's for Gary ?
 * 
 *  Input Format :
 *      The first line of input contains an integer, that denotes the value of N. 
 *      Each of the following N lines contain N space separated integers.
 *  Output Format :
 *      Print the count of '1's in the biggest piece of '1's, according to the 
 *      description in the task.
 * 
 *  Constraints :
 *      1 <= N <= 1000
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      2
 *      1 1 
 *      0 1
 *  Sample Output 1:
 *      3
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
int main(){
    int n;
    cin >> n;
    vector<vector<int> > cake(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }
    cout << getBiggestPieceSize(cake, n);
    return 0;
}