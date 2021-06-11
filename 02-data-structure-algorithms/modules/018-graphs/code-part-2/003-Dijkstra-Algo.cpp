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
 *  Dijkstra Algorithm (greedy)
 *  ---------------------------
 *  -   To calculate the minimum distance between 2 nodes.
 *  -   Another variation of question - calculate the minimum distance of
 *      all the vertices from all other vertices.
 * 
 *  Algorithm:
 *  ---------
 *  -   Similar to Prims implementation:
 *      -   Take 2 arrays : visited[n], distances[n]
 *      -   default distance : INT_MAX
 *      -   for all the vertices : v {
 *              min = pick the vertex with minimum distance
 *              for each unvisited neighbour of 'min' {
 *                  decide where  to update the distance.
 *              }
 *          }
 */ 


/**
 *  Code : Dijkstra's Algorithm
 *  -   Given an undirected, connected and weighted graph G(V, E) with V number 
 *      of vertices (which are numbered from 0 to V-1) and E number of edges.
 *  -   Find and print the shortest distance from the source vertex (i.e. Vertex 0) 
 *      to all other vertices (including source vertex also) using Dijkstra's Algorithm.
 *  
 *  Input Format :
 *      Line 1: Two Integers V and E (separated by space)
 *      Next E lines : Three integers ei, ej and wi, denoting that there exists an 
 *          edge between vertex ei and vertex ej with weight wi (separated by space)
 * 
 *  Output Format :
 *      For each vertex, print its vertex number and its distance from source, in a 
 *      separate line. The vertex number and its distance needs to be separated by a 
 *      single space.
 * 
 *  Note : Order of vertices in output doesn't matter.
 * 
 *  Constraints :
 *      2 <= V, E <= 10^5
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
 *      0 0
 *      1 3
 *      2 4
 *      3 5
 */

int findMinDist(int* distance, bool* visited, int n){
    int minDistVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minDistVertex == -1 || distance[i] < distance[minDistVertex])){
            minDistVertex = i;
        }
    }
    return minDistVertex;
}

void dijkstra(int** edges, int n){
    // create visited array
    bool* visited = new bool[n];
    int* distance = new int[n];
    for(int i=0; i<n; i++){
        visited[i] =false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    // check for all the un-visited neighbours
    for(int i=0; i<n; i++){
        int m = findMinDist(distance, visited, n);
        visited[m] = true;
        for(int j=0; j<n; j++){
            if(!visited[j] && edges[m][j] > 0 && (distance[m]+edges[m][j]) < distance[j]){
                distance[j] = distance[m]+edges[m][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    int ** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int sv, lv, w;
        cin >> sv >> lv>> w;
        edges[sv][lv] = edges[lv][sv] = w;
    }
    dijkstra(edges, v);

    return 0;
}