#include<bits/stdc++.h>

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

// connected graph
void printDFS(int** edges, int n, int startVertex, bool* visited) {
    cout << startVertex << " ";
    visited[startVertex] = true;
    for(int i=0; i<n; i++){
        if(i != startVertex && !visited[i] && edges[startVertex][i] == 1){
            printDFS(edges, n, i, visited);
        }
    }
}

// disconnected graph
void printGraphDFS(int** edges, int n, bool* visited){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printDFS(edges, n, i, visited);
        }
    }
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n]();
    }

    for(int i=0; i<e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    //  connected graph
    printDFS(edges, n, 0, visited);
    cout << endl;

    //  disconnected graph
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    printGraphDFS(edges, n, visited);
    cout << endl;

    delete [] visited;
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}