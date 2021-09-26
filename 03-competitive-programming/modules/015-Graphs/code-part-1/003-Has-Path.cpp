#include<bits/stdc++.h>

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

bool hasPathDFS(int** edges, int n, bool* visited, int start, int end){
    if(edges[start][end] == 1){
        return true;
    }
    visited[start] = true;
    for(int i=0; i<n; i++){
        if(i != start && !visited[i] && edges[start][i] == 1){
            visited[i] = true;
            bool ans = hasPathDFS(edges, n, visited, i, end);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

bool hasPathBFS(int** edges, int n, bool* visited, int start, int end){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int currVertex = q.front();
        q.pop();
        if(currVertex == end){
            return true;
        }
        for(int i=0; i<n; i++){
            if(i != currVertex && !visited[i] && edges[currVertex][i] == 1){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n]();
    }

    for(int i=0; i<e; i++){
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = edges[sv][fv] = 1;
    }

    int start, end;
    cin >> start >> end;

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    hasPathDFS(edges, n, visited, start, end) ? cout << "true" << endl : cout << "false" << endl;
    hasPathBFS(edges, n, visited, start, end) ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}