# Trees

>   Unlike ```Arrays```, ```Linked Lists```, ```Stack``` and ```queues```, which are linear data structures, **trees** are ```hierarchical``` data structures.

---

### Terminology:
-   ```Root``` : The topmost node is called root of the tree. 
-   ```Child``` : The elements that are directly under an element are called its children. 
-   ```Parent``` : The element directly above something is called its parent. 

> 
    For example, ‘a’ is a child of ‘f’, and ‘f’ is the parent of ‘a’. Finally, elements with no children are called leaves. 

                        tree
                        ----
                          j    <-- root
                        /   \
                      f      k  
                    /   \      \
                   a     h      z    <-- leaves

---

## Why Trees? 
-   One reason to use trees might be because you want to store information that naturally forms a hierarchy. For example, the file system on a computer: 
>
                    file system
                    -----------
                         /    <-- root
                    /         \
                  ...         home
                  /              \
                ugrad           course
                /            /      |     \
               ...         cs101  cs112  cs113

-   **Trees** (with some ordering e.g., ```BST```) provide moderate access/search (quicker than ```Linked List``` and slower than ```arrays```). 
-   **Trees** provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists). 
-   Like ```Linked Lists``` and unlike ```Arrays```, **Trees** don’t have an upper limit on number of nodes as nodes are linked using pointers.

---

### Main applications of trees include: 
1. Manipulate hierarchical data. 
2. Make information easy to search (see tree traversal). 
3. Manipulate sorted lists of data. 
4. As a workflow for compositing digital images for visual effects. 
5. Router algorithms 

---

## Problems:

[001 - Print Tree - Recursively](./code/001-Print-Tree-Recursive.cpp)<br>
[002 - Print Tree - Level Order Traversal](./code/002-Print-Tree-Level-Order-Traversal.cpp)<br>
[003 - Count Number of Nodes](./code/003-Count-Number-Of-Nodes.cpp)<br>
[004 - Find Sum of Nodes](./code/004-Find-Sum-Of-Nodes.cpp)<br>
[005 - Maximum Data Node](./code/005-Max-Data-Node.cpp)<br>
[006 - Find Height](./code/006-Find-Height.cpp)<br>
[007 - Count Leaf Nodes](./code/007-Count-Leaf-Nodes.cpp)<br>
[008 - Print PreOrder, PostOrder](./code/008-Print-Pre-Post-Traversal.cpp)<br>
[009 - Contains X](./code/009-Contains-X.cpp)<br>
[010 - Count Nodes](./code/010-Count-Nodes.cpp)<br>
[011 - Nodes With Maximum Child Sum](./code/011-Node-With-Max-Child-Sum.cpp)<br>
[012 - Structurally Identical](./code/012-Structurally-Identical.cpp)<br>
[013 - Next Larger](./code/013-Next-Larger.cpp)<br>
[014 - Second Largest Element](./code/014-SecondLargest-Element.cpp)<br>
[015 - Replace With Depth](./code/015-Replace-With-Depth.cpp)<br>


---