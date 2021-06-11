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
 *  Code : Has Path
 *  -   Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
 *      check if there exists any path between them or not. Print true if the path 
 *      exists and false otherwise.
 *  Note:
 *      1.  V is the number of vertices present in graph G and vertices are numbered 
 *          from 0 to V-1. 
 *      2.  E is the number of edges present in graph G.
 * 
 *  Input Format :
 *      The first line of input contains two integers, that denote the value of 
 *      V and E. Each of the following E lines contains two integers, that denote 
 *      that there exists an edge between vertex 'a' and 'b'.
 *      The following line contain two integers, that denote the value of v1 and v2.
 *  Output Format :
 *      The first and only line of output contains true, if there is a path between 
 *      v1 and v2 and false otherwise.
 *  
 *  Constraints :
 *      0 <= V <= 1000
 *      0 <= E <= 1000
 *      0 <= a <= V - 1
 *      0 <= b <= V - 1
 *      0 <= v1 <= 2^31 - 1
 *      0 <= v2 <= 2^31 - 1
 *  
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
 *      true
 *  
 *  Sample Input 2 :
 *      6 3
 *      5 3
 *      0 1
 *      3 4
 *      0 3
 *  Sample Output 2 :
 *      false
 */
bool hasPath(int** edges,int n, int v1, int v2, bool* visited){
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        if(f == v2){
            return true;
        }
        for(int i=0; i<n; i++){
            if(i == f){
                continue;
            }
            if(edges[f][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}
// Approach 2 - DFS
bool hasPathDFS(int** edges,int n, int v1, int v2, bool* visited){
    if(v1 == v2){
        return true;
    }
    visited[v1] = true;
    for(int i=0; i<n; i++){
        if(i == v1){
            continue;
        }
        if(edges[v1][i] == 1 && !visited[i]){
            visited[i] = true;
            bool ans = hasPathDFS(edges, n, i, v2, visited);
            if(ans){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int v, e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    hasPath(edges, v, v1, v2, visited) ? cout << "true" : cout << "false";
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    hasPathDFS(edges, v, v1, v2, visited) ? cout << "true" : cout << "false";
    for(int i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;

    return 0;
}