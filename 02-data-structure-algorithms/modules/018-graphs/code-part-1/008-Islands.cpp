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
 * 
 *  Input Format :
 *      The first line of input contains two integers, that denote the value of 
 *      V and E. Each of the following E lines contains two integers, that denote 
 *      that there exists an edge between vertex a and b. 
 *  Output Format :
 *      Print the count the number of connected groups of islands
 *  
 *  Constraints :
 *      0 <= V <= 1000  
 *      0 <= E <= (V * (V-1)) / 2
 *      0 <= a <= V - 1
 *      0 <= b <= V - 1
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      5 8
 *      0 1
 *      0 4
 *      1 2
 *      2 0
 *      2 4
 *      3 0
 *      3 2
 *      4 3
 *  Sample Output 1:
 *      1 
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
int main() {
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

    return 0;
}