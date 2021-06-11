# Graphs

 *  A Graph is a non-linear data structure consisting of nodes and edges. 
 *  The nodes are sometimes also referred as **vertices** and the edges are lines or arcs that connect any two nodes in the graph.
 *  Tree is special kind of graph where nodes have a way to reach any other node only and trees doesn't have cycles.
 >  Example: 
 >  -   Social network (how person(as node) is connected to other people).
 >  -   Map for any country where cities are connected via roads.   

---

 ### Terminologies:
 *  **Vertices** : nodes of data.
 *  **Edge** : the component to connect 2 nodes.
 *  **Adjacent Vertices** : nodes which are connected to each other.
 *  **Degree** : degree of vertex is number is edges which are passing through it.
 *  **Path** : collection of edges between 2 nodes.
 *  **Connected Graph** : there should be a path between any 2 nodes . That is connected Graph.
 *  **Connected Component**: There can be a graph having more than one component. i.e. few nodes are connected forms a component.
 *  **Minimum number of edges**:
    -   In graph :   ```0```
    -   In connected graph :    ```n-1  => O(n)```
 *  **Maximum number of edges** :
    -   In Connected graph : ```nC2 => n(n-1)/2 => O(n^2)```
 * 
 
 ---

 ### Ways to Implement Graph:
 1. **Edge List** : 
    -   We can store vertices in an array/list.
    -   We can edges in the form of pair in another array/list.
    -   But the very common query to check if path exist between 2 nodes may take ```O(n^2)```since there can be n(n-1)/2 edges. So not an efficient way.
 2.  **Adjacency List**:
    -   We can store the adjacent nodes with node.
    -   So, if we have to check if path exist - it might take O(n) time.
 3.  **Adjacency Matrix**:
    -   We can store nodes using a matrix of n*n nodes. 
    -   **Big disadvantage** : takes a lot of space.

---

### DFS (Depth First Search):
-   Go deep until we can't go further i.e. traverse height wise.
-   **For example** : if A has 2 children B, C where B, C have further children. We will traverse one child first either B or C along with the its children. And then we will proceed to next node.
 
 ---

### BFS (Breadth First Search):
-   Go wide until we can't go further i.e traverse breadth wise.
-   **For example** : if A has 2 children B, C where B, C have further children. We will traverse both child first and then we will proceed to its children.

---

### UnDirected Graph:
-   Where element would not have any direction.
-   In undirected graph, we put edges in both direction i.e. ```edges[i][j] = edges[i][j] = 1```.

---

### Directed Graph:
-   Where element would have some direction.
-   In undirected graph, we use to ```edges[i][j] = edges[i][j] = 1```, so here in directed graph, we will need to only store ```edges[i][j] = 1```

---

### Weighted Graphs:
-   Not all edges are equal i.e. weightage can be different.
-   Each edge can have different weightage i.e. <br>
            ```edges[i][j] = weight_of_edge```

---

### Tree
-  Graph which is connected.
-  It contains no cycle.

---

### Spanning Tree
-  A tree which contains all the vertices of graph.
-  **Number of Vertices** : ```n```
-  **Number of Edges** : ```n-1```

---

### Minimum Spanning Tree
-  Spanning Tree which has the minimum weight as well i.e Tree which contains all the vertices and has minimum weight.

---

### Problems - Part 1:
[001- Print Nodes using DFS](./code-part-1/001-Print-Nodes-DFS.cpp)<br>
[002 - Print Nodes using BFS](./code-part-1/002-Print-Nodes-BFS.cpp)<br>
[003 - Has Path](./code-part-1/003-Has-Path.cpp)<br>
[004 - Get Path - DFS](./code-part-1/004-Get-Path-DFS.cpp)<br>
[005 - Get Path - BFS](./code-part-1/005-Get-Path-BFS.cpp)<br>
[006 - Is Connected](./code-part-1/006-Is-Connected.cpp)<br>
[007 - All Connected Components](./code-part-1/007-All-Connected-Components.cpp)<br>
[008 - Islands](./code-part-1/008-Islands.cpp)<br>
[009 - Coding Ninjas](./code-part-1/009-CodingNinjas.cpp)<br>
[010 - Connecting Dots](./code-part-1/010-Connecting-Dots.cpp)<br>
[011 - Largest Piece](./code-part-1/011-Largest-Piece.cpp)<br>
[012 - 3 Cycle](./code-part-1/012-3-Cycle.cpp)<br>

---

### Problems - Part 2
[001 - Kruskal's Algorithm](./code-part-2/001-Kruskals-Algo.cpp) : To find the **Minimum Spanning Tree** <br>
[002 - Prims Algorithm](./code-part-2/002-Prims-Algo.cpp) : Another way to find the **Minimum Spanning Tree**<br>
[003 - Dijsktra Algorithm](./code-part-2/003-Dijkstra-Algo.cpp) : To calculate the minimum distance or shortest path between two nodes<br>
