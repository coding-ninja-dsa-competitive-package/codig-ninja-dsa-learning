#include<bits/stdc++.h>

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

void printBFS(int** edges, int n, int startVertex, bool* visited){
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    while(!q.empty()){
        int currVertex = q.front();
        cout << currVertex << " ";
        q.pop();
        for(int i=0; i<n; i++){
            if(i != currVertex && !visited[i] && edges[currVertex][i] == 1){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// disconnected graph
void printGraphBFS(int** edges, int n, bool* visited){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(edges, n, i, visited);
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

    // connected
    printBFS(edges, n, 0, visited);
    cout << endl;

    // disconnected
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    printGraphBFS(edges, n, visited);
    cout << endl;

    delete [] visited;
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}