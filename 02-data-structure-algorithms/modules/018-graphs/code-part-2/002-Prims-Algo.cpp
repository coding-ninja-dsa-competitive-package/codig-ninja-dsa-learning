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
 *  Prim's Algorithm:
 *  -   Another way of finding minimum spanning tree (mst).
 * 
 *  Algo:
 *  -   Take 3 arrays : visited[n], weights[n], parents[n] 
 *      -   default weight : INT_MAX, default parent : -1
 *  -   for all the vertices : v {
 *          min = pick the vertex with minimum weight
 *          for each unvisited neighbour of 'min' {
 *              decide where  to update the parent and weight.
 *          }
 *      }
 * 
 *  Time Complexity : O(V^2)
 * 
 *  Optimizations cann be done:
 *  1.  Adjacency List can be used in place of Adjacency Matrix
 *  2.  To find min, rather traversing all vertices, we can use the min priority queue.
 *      Using it - Time Complexity can be made like : (E+V)logV
 */

/**
 *  Code : Prim's Algorithm
 *  -   Given an undirected, connected and weighted graph G(V, E) with V number 
 *      of vertices (which are numbered from 0 to V-1) and E number of edges.
 *  -   Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
 *  -   For printing MST follow the steps -
 *      1.  In one line, print an edge which is part of MST in the format - v1 v2 w
 *          where, v1 and v2 are the vertices of the edge which is included in MST and 
 *          whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while 
 *          printing an edge.
 *      2.  Print V-1 edges in above format in different lines.
 * 
 *  Note : Order of different edges doesn't matter.
 * 
 *  Input Format :
 *      Line 1: Two Integers V and E (separated by space)
 *      Next E lines : Three integers ei, ej and wi, denoting that there exists an 
 *          edge between vertex ei and vertex ej with weight wi (separated by space)
 * 
 *  Output Format : 
 *      Print the MST, as described in the task.
 *  
 *  Constraints :
 *      2 <= V, E <= 10^5
 *      1 <= Wi <= 10^5
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      4 4
 *      0 1 3
 *      0 3 5
 *      1 2 1
 *      2 3 8
 *  Sample Output 1 :
 *      0 1 3
 *      1 2 1
 *      0 3 5
 */
 
 int findMinvertex(int* weights, bool* visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void primsMST(int** edges, int n){
    bool* visited = new bool[n];
    int* parent = new int[n];
    int* weights = new int[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for(int i=0; i<n; i++){
        // find min vertex
        int m = findMinvertex(weights, visited, n);
        visited[m] = true;
        // explore unvisited vertex neighbours
        for(int j=0; j<n; j++){
            if(!visited[j] && edges[m][j] != 0 && edges[m][j] < weights[j]){
                weights[j] = edges[m][j];
                parent[j] = m;
            }
        }
    }
    for(int i=1; i<n; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i <<  " " << weights[i] << endl;
        } else {
            cout << i <<  " " << parent[i] << " " << weights[i] << endl;
        }
    }
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
    for(int k=0; k<e; k++){
        int sv, lv, w;
        cin >> sv >> lv >> w;
        edges[sv][lv] = edges[lv][sv] =w; 
    }
    primsMST(edges, v);

    for(int i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}