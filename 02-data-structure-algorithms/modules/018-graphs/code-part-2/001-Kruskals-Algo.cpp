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
 *  Kruskal's Algirithm:
 *  -------------------
 *  -   Helps to fund the MST i.e. minimum spanning tree.
 *  -   Steps:
 *      1.  Identify the edge with mininum weight.  
 *      2.  check if cycle is formed before adding the identified edge to the result.
 *      3.  if cylce found , identify next edge with minimum edge.
 *      4.  Repeat step 1-3 till we have n-1 edges in the result.
 *  -   Cycle Detection:
 *      -   Maintain what all vertices are already added to result.
 *      -   Ways to detect cylce.
 *          a.  Not a full proof way :
 *              -   If both the vertices of the edge is present in result means 
 *                  we have cycle. Because there can be chance that we don't have 
 *                  the cycle but both vertices are present in result.
 *          b.  Calculating the path between 2 vertices:
 *              -   We will check if any path present in both the vertices. If yes,
 *                  ignore it and check for next edge.
 *                      Time : O(E+V) of each vertices => E might be O(V^2) =>O(V^2)
 *                             O(V^3) for all vertices.
 *          c.  Union Find Algorithm:
 *              -   Maintain an array which store the parent of vertices starting with
 *                  parent same as the vertix.
 *              -   Check if both the vertices lies in different component and also
 *                  their topmost parent is different. If yes, we can connect the edge.
 *              -   Also made the changes in the parent array with the parent as any 
 *                  one of them.
 *                      Time : O(V) better than previous.
 *                             O(V^2) for all vertices.
 */

/**
 *  Code : Kruskal's Algorithm
 *  -   Given an undirected, connected and weighted graph G(V, E) with V number 
 *      of vertices (which are numbered from 0 to V-1) and E number of edges.
 *  -   Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
 *  -   For printing MST follow the steps -
 *      1.  In one line, print an edge which is part of MST in the format - v1 v2 w
 *          where, v1 and v2 are the vertices of the edge which is included in MST 
 *          and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first 
 *          while printing an edge.
 *      2.  Print V-1 edges in above format in different lines.
 * 
 *  Note : Order of different edges doesn't matter.
 * 
 *  Input Format :
 *      Line 1: Two Integers V and E (separated by space)
 *      Next E lines : Three integers ei, ej and wi, denoting that there exists an 
 *          edge between vertex ei and vertex ej with weight wi (separated by space)
 *  Output Format :
 *      Print the MST, as described in the task.
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
 *      1 2 1
 *      0 1 3
 *      0 3 5
 */

class Edge{ 
    public:   
        int source;
        int destination;
        int weight;
};

int getTopMostParent(int* parent, int index){
    while(parent[index] != index){
        index = parent[index];
    }
    return index;
}

bool cmp_edge_by_weight(const Edge e1,  const Edge e2){ 
    return e1.weight < e2.weight;
}

void kruskal(Edge* edges, int n, int e){
    // sort the edges in increasing order of weight.
    sort(edges, edges+e, cmp_edge_by_weight);
    // mst i.e. result vector of edges in mst.
    Edge* mst = new Edge[n-1];
    // create parent array with value as index.
    int* parent = new int[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    // create mst array and apply the logic i.e. check topmost parent and add to mst.
    int count = 0;
    int i=0;
    while(count < n-1){
        int p1 = getTopMostParent(parent, edges[i].source);
        int p2 = getTopMostParent(parent, edges[i].destination);
        if(p1 != p2){
            mst[count] = edges[i];
            count++;
            parent[p1] = p2;
        }
        i++;  
    }

    // print the mst array
    for(int i=0; i<n-1; i++){
        Edge edge = mst[i];
        if(edge.source < edge.destination){
            cout << edge.source << " " << edge.destination << " " << edge.weight << endl;
        } else {
            cout << edge.destination << " " << edge.source << " " << edge.weight << endl;
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    Edge* edges = new Edge[e];
    for(int i=0; i<e; i++){
        int source, destination, weight;
        cin >> source >> destination >> weight;
        edges[i].source = source;
        edges[i].destination= destination;
        edges[i].weight = weight;
    }
    kruskal(edges, v, e);

    return 0;
}