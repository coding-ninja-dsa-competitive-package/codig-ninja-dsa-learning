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
 *  Code : BFS Traversal
 *  -   Given an undirected and disconnected graph G(V, E), print its BFS traversal.
 *      Note:
 *      1. Here you need to consider that you need to print BFS path starting from 
 *          vertex 0 only. 
 *      2. V is the number of vertices present in graph G and vertices are numbered 
 *          from 0 to V-1. 
 *      3. E is the number of edges present in graph G.
 *      4. Take graph input in the adjacency matrix.
 *      5. Handle for Disconnected Graphs as well
 *  
 *  Input Format :
 *      The first line of input contains two integers, that denote the value of 
 *      V and E. Each of the following E lines contains space separated two 
 *      integers, that denote that there exists an edge between vertex a and b.
 *  Output Format :
 *      Print the DFS Traversal, as described in the task.
 *  
 *  Constraints :
 *      0 <= V <= 1000
 *      0 <= E <= (V * (V - 1)) / 2
 *      0 <= a <= V - 1
 *      0 <= b <= V - 1
 *  
 *  Time Limit: 1 second
 *      
 *  Sample Input 1:
 *      4 4
 *      0 1
 *      0 3
 *      1 2 
 *      2 3
 *  Sample Output 1:
 *      0 1 3 2 
 */
void printGraphBFS(int** edges, int n, int start ,bool* visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int f = q.front();
        cout << f << " ";
        q.pop();
        for(int i=0; i<n; i++){
            if(i==f){
                continue;
            }
            if(edges[f][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void printGraphBFS(int** edges, int n, bool* visited){
    for(int k=0; k<n; k++){
        if(!visited[k]){
            printGraphBFS(edges, n, k, visited);
        }
    }
}

int main() {
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
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    // print connected graph
    printGraphBFS(edges, v, 0, visited);
    // print disconnected graph
    printGraphBFS(edges, v, visited);
    for(int i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;

    return 0;
}