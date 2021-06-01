#include<iostream>
using namespace std;

/**
 *  Graph :
 *  =====
 *  -   A Graph is a non-linear data structure consisting of nodes and edges. 
 *  -   The nodes are sometimes also referred to as vertices and the edges are 
 *      lines or arcs that connect any two nodes in the graph.
 *  -   Tree is special kind of graph where nodes have a way to reach any 
 *      other node only and trees doesn't have cycles.
 *  -   Example: 
 *      -   Social network (how person(as node) is connected to other people).
 *      -   Map for any country where cities are connected via roads.   
 * 
 *  Terminologies:
 *  -   Vertices : nodes of data.
 *  -   Edge : the component to connect 2 nodes.
 *  -   Adjacent Vertices : nodes which are connected to each other.
 *  -   Degree : degree of vertex is number is edges which are passing through it.
 *  -   Path : collection of edges between 2 nodes.
 *  -   Connected Graph : there should be a path between any 2 nodes . That is 
 *          connected Graph.
 *  -   Connected Component: There can be a graph having more than one component.
 *          i.e. few nodes are connected forms a component.
 * 
 *  Minimum number of edges:
 *  -   In graph :              0
 *  -   In connected graph :    n-1  => O(n)
 *  
 *  Maximum number of edges :
 *  -   In Connected graph : nC2 => n(n-1)/2 => O(n^2)
 * 
 *  Ways to Implement Graph:
 *  ------------------------
 *  1.  Edge List : 
 *      -   We can store vertices in an array/list.
 *      -   We can edges in the form of pair in another array/list.
 *      -   But the very common query to check if path exist between 2 nodes may 
 *          take O(n^2) since there can be n(n-1)/2 edges. 
 *          So not an efficient way.
 *  2.  Adjacency List:
 *      -   We can store the adjacent nodes with node.
 *      -   So, if we have to check if path exist - it might take O(n) time.
 *  3.  Adjacency Matrix:
 *      -   We can store nodes using a matrix of n*n nodes. 
 *      -   Big disadvantage : takes a lot of space.
 * 
 *  DFS (Depth First Search):
 *  ========================
 *  -   Go deep until we can't go further i.e. traverse height wise.
 *  -   For example : if A has 2 children B, C where B, C have further children.
 *      We will traverse one child first either B or C along with the its children.
 *      And then we will proceed to next node.
 * 
 *  BFS (Breadth First Search):
 *  =========================
 *  -   Go wide until we can't go further i.e traverse breadth wise.
 *  -   For example : if A has 2 children B, C where B, C have further children.
 *      We will traverse both child first and then we will proceed to its children.
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
void problem1(){
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
}

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
 */
#include<queue>
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
void problem2(){
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
}

/**
 *  Code : Has Path
 *  -   Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
 *      check if there exists any path between them or not. Print true if the path 
 *      exists and false otherwise.
 *  Note:
 *      1.  V is the number of vertices present in graph G and vertices are numbered 
 *          from 0 to V-1. 
 *      2.  E is the number of edges present in graph G.
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
void problem3(){
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
}

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
 */ 
vector<int> getPathDFS(vector<vector<int> > edges,int v, int v1,int v2,vector<bool> visited){
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
void problem4(){
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
    // vector<int> path;
    vector<int> path = getPathDFS(edges, v, v1, v2, visited);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
}

/**
 *  Code : Get Path - BFS
 *  -   Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
 *      find and print the path from v1 to v2 (if exists). Print nothing if there 
 *      is no path between v1 and v2.
 *  -   Find the path using BFS and print the shortest path available.
 *  Note:
 *  1.  V is the number of vertices present in graph G and vertices are numbered 
 *      from 0 to V-1. 
 *  2.  E is the number of edges present in graph G.
 *  3.  Print the path in reverse order. That is, print v2 first, then intermediate 
 *      vertices and v1 at last.
 *  4.  Save the input graph in Adjacency Matrix.
 */
#include<unordered_map>
#include<queue>
#include<vector>
vector<int> getPathBFS(vector<vector<int> > edges, int n, int v1, int v2, vector<bool> visited){
    queue<int> q;
    unordered_map<int, int> mp;
    vector<int> res;
    q.push(v1);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        int i;
        for(i=0; i<n; i++){
            if((i != f) && (edges[f][i] == 1) && !visited[i]){
                visited[i] = true;
                q.push(i);
                mp[i] = f;
                cout << i << " " << f << endl;
                if(i == v2){
                    while(mp[i] != v1){
                        res.push_back(i);
                        i = mp[i];
                    }
                    res.push_back(i);
                    res.push_back(mp[i]);
                    return res;
                }
            }
        }
    }
    return res;
}
void problem5(){
    int v,e;
    cin >> v >> e;
    vector<vector<int> > edges(v, vector<int>(v));
    for(int i=0; i<e; i++){
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    cout << endl;
    vector<bool> visited(v);
    vector<int> path = getPathBFS(edges, v, v1, v2, visited);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
}

/**
 *  Code : Is Connected ?
 *  -   Given an undirected graph G(V,E), check if the graph G is connected 
 *      graph or not.
 *  Note:
 *  1.  V is the number of vertices present in graph G and vertices are numbered 
 *      from 0 to V-1. 
 *  2.  E is the number of edges present in graph G.
 */
void DFS(int** edges, int n, int start, vector<bool> & visited){
    for(int i=0; i<n; i++){
        if(i != start && edges[start][i] == 1 && !visited[i]){
            visited[i] = true;
            DFS(edges, n, i, visited);
        }
    }
}
void problem6(){
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
        int sv, lv;
        cin >> sv >> lv;
        edges[sv][lv] = edges[lv][sv] = 1;
    }
    vector<bool> visited(v);
    visited[0] = true;
    DFS(edges, v, 0, visited);
    bool isConnected=true;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            isConnected = false;
            break;
        }
    }
    cout << endl;
    isConnected ? cout << "true" << endl : cout << "false" << endl;
}

/**
 *  Code : Is Connected ?
 *  -   Given an undirected graph G(V,E), check if the graph G is connected 
 *      graph or not.
 *  Note:
 *  1.  V is the number of vertices present in graph G and vertices are numbered 
 *      from 0 to V-1. 
 *  2.  E is the number of edges present in graph G.
 */
void problem7(){
    
}

int main() {
    // Adjacency matrix
    // problem1();

    // BFS Traversal
    // problem2();

    // Has Path
    // problem3();

    // Get Path - DFS
    // problem4();

    // Get Path - BFS
    // problem5();

    // Is Connected
    // problem6();

    // Return all connected components
    problem7();


    return 0;
}