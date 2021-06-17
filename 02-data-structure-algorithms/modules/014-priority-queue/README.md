 # Priority Queue 
-   Extension of Queue (FIFO) data structure. 
-   Data is inserted similar to insertion happens in Queue.
-   Data extraction happens according to priority or importance factor.
    >   Ex: decresing sorting order i.e. max element first.
 
---

### Types:
1.  ```Min Priority Queue``` : Elements sorted in increasing order.
2.  ```Max Priority Queue``` : Elements sorted in decreasing order. 

###  Which Data Structure could be best suited for PriorityQueue
 >        
|   DS                  |   Insert  |  getMin/Max   |   removeMin/Max   |
| -----------------     | --------- | ------------- | ----------------- |  
| Array(unsorted)       |   O(1)    |   O(n)        |       O(n)        |
| Array(sorted)         |   O(n)    |   O(1)        |       O(n)        |
| LinkedList(unsorted)  |   O(1)    |   O(n)        |       O(n)        |
| LinkedList(sorted)    |   O(n)    |   O(1)        |       O(1)        |
| BST                   |   O(h)    |   O(h)        |       O(h)        |
| Balanced BST          |   O(logn) |   O(logn)     |       O(logn)     |
| HashMap               |   O(1)    |   O(n)        |       O(n)        |

-   Seeing above table , ```Balanced BST``` seems the best data structure for it.
-   But we need to maintain :
    1.  Balancing 
    2.  Storing in sorted order.

-   So new Data structure - ```Heap``` is choosen for it which is a complete binary tree.
  
---

## Heap :
-   Two properties:
    1.  **Complete Binary Tree (CBT)**:
        -   All the levels except last level should be completely filled.
        -   last level also should be filled from left to right.
    2.  Element can be inserted/deleted in the last level from left to right order.

-   **Minimum number of nodes in CBT** : ```2^(h-1)```<br>
    **Maximum number of nodes in CBT** : ```2^h - 1```<br>
    >
        => log(n+1) <= h <= logn+1
        => logn <= h <= logn
-   How to store efficiently in CBT:
    -   We can backed the heap by an array.
        -   left child index = ```2*i + 1```
        -   right child index = ```2*i + 2```
        -   parent index from child = ```(childIndex-1)/2```

---

### Problems:
[001 - Min Priority Queue Implementaion](./code/001-Min-Priority-Queue-Impl.cpp)<br>
[002 - Max Priority Queue Implementaion](./code/002-Max-Priority-Queue-Impl.cpp)<br>
[003 - Heap Sort](./code/003-Heap-Sort.cpp)<br>
[004 - In-built STL Priority Queue Usage](./code/004-InBuilt-PQ-Usage.cpp)<br>
[005 - K Sorted Array](./code/005-K-Sorted-Array.cpp)<br>
[006 - K Smallest Elements](./code/006-K-Smallest-Elements.cpp)<br>
[007 - K Largest Elements](./code/007-K-Largest-Elements.cpp)<br>
[008 - Check Max Heap](./code/008-Check-Max-Heap.cpp)<br>
[009 - Kth Largest Element](./code/009-Kth-Largest-Element.cpp)<br>
[010 - Merge K Sorted Arrays](./code/010-Merge-K-Sorted-Arrays.cpp)<br>
[011 - Running Median](./code/011-Running-Median.cpp)<br>
[012 - Buy the Ticket](./code/012-Buy-The-Ticket.cpp)<br>

---