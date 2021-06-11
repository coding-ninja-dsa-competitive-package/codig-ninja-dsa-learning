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
 *  Code : Get Path - DFS
 *  -   Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
 *      find and print the path from v1 to v2 (if exists). Print nothing if there 
 *      is no path between v1 and v2.
 *  -   Find the path using DFS and print the first path that you encountered.
 *      1.  V is the number of vertices present in graph G and vertices are numbered 
 *          from 0 to V-1. 
 *      2.  E is the number of edges present in graph G.
 *      3.  Print the path in reverse order. That is, print v2 first, then 
 *          intermediate vertices and v1 at last.
 *      4.  Save the input graph in Adjacency Matrix.
 * 
 *  Input Format :
 *      The first line of input contains two integers, that denote the value of 
 *      V and E. Each of the following E lines contains two integers, that denote 
 *      that there exists an edge between vertex 'a' and 'b'.
 *      The following line contain two integers, that denote the value of v1 and v2.
 *  Output Format :
 *      Print the path from v1 to v2 in reverse order.
 *  
 *  Constraints :
 *      2 <= V <= 1000
 *      1 <= E <= (V * (V - 1)) / 2
 *      0 <= a <= V - 1
 *      0 <= b <= V - 1
 *      0 <= v1 <= 2^31 - 1
 *      0 <= v2 <= 2^31 - 1
 *  Time Limit: 1 second
 * 
 *  Sample Input 1 :
 *      4 4
 *      0 1
 *      0 3
 *      1 2
 *      2 3
 *      1 3
 *  Sample Output 1 :
 *      3 0 1
 *  
 *  Sample Input 2 :
 *      6 3
 *      5 3
 *      0 1
 *      3 4 
 *      0 3
 *  Sample Output 2 :
 *      
 */ 
vector<int> getPathDFS(vector<vector<int> >& edges,int v, int v1,int v2,vector<bool> visited){
    vector<int> path;
    if(v1 == v2){
        path.push_back(v1);
        return path;
    }
    visited[v1] = true;
    for(int i=0; i<v; i++){
        if(i == v1){
            continue;
        }
        if(edges[v1][i] == 1 && !visited[i]){
            visited[i] = true;
            vector<int> ans = getPathDFS(edges, v, i, v2, visited);
            if(ans.size() > 0){
                ans.push_back(v1);
                return ans;
            }
        }
    }
    return path;
}
int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int> > edges(v, vector<int>(v));
    for(int i=0; i<e; i++){
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = 1;
        edges[lv][sv] = 1;
    }
    int v1 , v2;
    cin >> v1 >> v2;
    vector<bool> visited(v, false);
    vector<int> path = getPathDFS(edges, v, v1, v2, visited);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }

    return 0;
}