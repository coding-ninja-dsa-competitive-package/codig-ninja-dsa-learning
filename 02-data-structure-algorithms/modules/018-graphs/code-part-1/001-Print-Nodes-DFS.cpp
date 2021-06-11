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
 *  Given an undirected and disconnected graph G(V, E), print its DFS traversal.
 *  Note:
 *  1.  Here you need to consider that you need to print DFS path starting from 
 *      vertex 0 only. 
 *  2.  V is the number of vertices present in graph G and vertices are numbered 
 *      from 0 to V-1. 
 *  3.  E is the number of edges present in graph G.
 *  4.  Take graph input in the adjacency matrix.
 *  5.  Handle for Disconnected Graphs as well
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
 *      0 1 2 3 
 */

// Print nodes using DFS traversal - Adjacency Matrix - connected
void printGraphDFS(int** edges, int n, int start,bool* visited){
    cout << start << " ";
    visited[start] = true;
    for(int i=0; i<n; i++){
        if(i == start){
            continue;
        }
        if(edges[start][i] == 1){
            if(visited[i]){
                continue;
            }
            printGraphDFS(edges, n, i, visited);
        }
    }
}
// disconnected graph
void printGraphDFS(int** edges, int n,bool* visited){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printGraphDFS(edges, n, i, visited);
        }
    }
}
int main(){
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i]  = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int firstVertex, secondVertex;
        cin >> firstVertex >> secondVertex;
        edges[firstVertex][secondVertex] = 1;
        edges[secondVertex][firstVertex] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    // connected graph
    printGraphDFS(edges, n, 0, visited);
    // disconnected graph
    printGraphDFS(edges, n, visited);

    return 0;
}