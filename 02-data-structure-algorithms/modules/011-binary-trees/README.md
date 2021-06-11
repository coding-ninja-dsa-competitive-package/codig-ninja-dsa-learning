# Binary Trees

>   A tree whose elements have at most 2 children is called a **binary tree**. Since each element in a binary tree can have only 2 children, we typically name them the ```left``` and ```right``` child. 

---

### Binary Tree Representation: 
-   A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of ```root``` is ```NULL```. 
-   A Tree node contains following parts. 
    -   Data 
    -   Pointer to ```left``` child 
    -   Pointer to ```right``` child
>
    Example : 
                 Binary tree
                 -----------
                      1    <-- root
                    /   \
                   2     3  
                 /   
                4

---

### Types:

-   ```Full Binary Tree``` :  
    -   A **Binary Tree** is a ```full binary tree``` if every node has ```0 or 2 children```. 
    -   We can also say a full binary tree is a binary tree in which all nodes except leaf nodes have two children. 
-   ```Complete Binary Tree```: 
    -   A **Binary Tree** is a ```Complete Binary Tree``` if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible.
-   ```Perfect Binary Tree```:
    -   A **Binary tree** is a ```Perfect Binary Tree``` in which all the internal nodes have two children and all leaf nodes are at the same level.
-   ```Balanced Binary Tree```: 
    -   A **binary tree** is ```balanced``` if the **height of the tree** is ```O(Log n)``` where n is the number of nodes. 
    -   For Example, the ```AVL tree``` maintains ```O(Log n)``` height by making sure that the difference between the heights of the left and right subtrees is at most 1. 
    -   ```Red-Black trees``` maintain ```O(Log n)``` height by making sure that the number of Black nodes on every root to leaf paths is the same and there are no adjacent red nodes. -   ```Balanced Binary Search trees``` are **performance-wise good** as they provide ```O(log n)``` time for search, insert and delete.   
-   ```Degenerate (or pathological) tree```:
    -   A Tree where every internal node has one child. Such trees are **performance-wise** same as ```linked list```. 

---

## Problems

[001 - Print Binary Tree Recursive](./code/001-Print-BinaryTree-Recursive.cpp)<br>
[002 - Print Level Order Traversal](./code/002-Print-Level-Order-Traversal.cpp)<br>
[003 - Count Nodes](./code/003-Count-Nodes.cpp)<br>
[004 - Find a Node](./code/004-Find-Node.cpp)<br>
[005 - Height Of Binar Tree](./code/005-Height-Of-Binary-Tree.cpp)<br>
[006 - Mirror](./code/006-Mirror.cpp)<br>
[007 - PreOrder, PostOrder, InOrder Traversal](./code/007-Pre-Post-In-Order-Traversal.cpp)<br>
[008 - Construct Tree from PreOrder and InOrder](./code/008-Construct-Tree-From-PreOrder-InOrder.cpp)<br>
[009 - Construct Tree from PostOrder and InOrder](./code/009-Construct-Tree-From-PostOrder-InOrder.cpp)<br>
[010 - Diameter of Binary Tree](./code/010-Diameter-Of-Binary-Tree.cpp)<br>
[011 - Min and Max of Binary Tree](./code/011-Min-Max-In-Binary-Tree.cpp)<br>
[012 - Sum of Nodes](./code/012-Sum-Of-Nodes.cpp)<br>
[013 - Check Balanced](./code/013-Check-Balanced.cpp)<br>
[014 - Level Order Traversal](./code/014-Level-Order-Traversal.cpp)<br>
[015 - Remove Leaf Nodes](./code/015-Remove-Leaf-Nodes.cpp)<br>
[016 - Level Wise LinkedList](./code/016-Level-Wise-LinkedList.cpp)<br>
[017 - ZigZag Tree](./code/017-ZigZag-Tree.cpp)<br>
[018 - Nodes without Siblings](./code/018-Nodes-Without-Siblings.cpp)<br>

---