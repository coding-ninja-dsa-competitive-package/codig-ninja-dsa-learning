# Linked Lists

> Like ```arrays```, ```Linked List``` is a ```linear data structure```. Unlike ```arrays```, ```linked list``` elements are not stored at a contiguous location. The elements are linked using **pointers**.

---

### Why Linked List? 
-   Arrays can be used to store linear data of similar types, but arrays have the following limitations. 
    -   The size of the arrays is fixed
    -   Insertion/Deletion is an expensive operation in ```Arrays```.

---

### Advantages over arrays 
-   Dynamic size 
-   Ease of insertion/deletion

---

### Drawbacks: 
-   Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists efficiently with its default implementation.
-   Extra memory space for a pointer is required with each element of the list. 

---

###  Representation: 
-   A linked list is represented by a pointer to the first node of the linked list.
-   The first node is called the ```head```. If the linked list is empty, then the value of the head is ```NULL```.
-   Each node in a list consists of at least two parts: 
    1.  data 
    2.  Pointer (Or Reference) to the next node 

---

## Problems - Part 1:

[001 - Singly Linked List Implementation](./code-part-1/001-SinglyLinkedList-Impl.cpp)<br>
[002 - Guess the Outout - Assignments](./code-part-1/002-Guess-Output.cpp)<br>
[003 - Print ith Node](./code-part-1/003-Print-ith-Node.cpp)<br>
[004 - Delete Node](./code-part-1/004-Delete-Node.cpp)<br>
[005 - Length of LinkedList - Recursive](./code-part-1/005-Length-LinkedList-Recursive.cpp)<br>
[006 - Insert Node - Recursive](./code-part-1/006-Insert-Node-Recursive.cpp)<br>
[007 - Delete Node - Recursive](./code-part-1/007-Delete-Node-Recursive.cpp)<br>
[008 - Find a Node in LinkedList](./code-part-1/008-Find-Node.cpp)<br>
[009 - Append Last N to First](./code-part-1/009-Append-Last-N-To-First.cpp)<br>
[010 - Eliminate duplicates froom LinkedlList](./code-part-1/010-Eliminate-Duplicates-From-LL.cpp)<br>
[011 - Print Reverse LinkedList](./code-part-1/011-Print-Reverse-LinkedList.cpp)<br>
[012 - Palindrome LinkedList](./code-part-1/012-Palindrome-LinkedList.cpp)<br>

---

## Problems - Part 2:

[001 - MidPoint of LinkedList](./code-part-2/001-Mid-Point-LinkedList.cpp)<br>
[002 - Merge Two Sorted LinkedList](./code-part-2/002-Merge-Two-Sorted-LinkedList.cpp)<br>
[003 - Merge Sort](./code-part-2/003-Merge-Sort.cpp)<br>
[004 - Reverse LinkedList - Recursive - Iterative](./code-part-2/004-Reverse-LinkedList-Recursive.cpp)<br>
[005 - Find a Node in LinkedList - Recursive](./code-part-2/005-Find-Node-In-LinkedList-Recursive.cpp)<br>
[006 - Even after Odd LinkedList](./code-part-2/006-Even-After-Odd-LinkedList.cpp)<br>
[007 - Delete Every N Nodes](./code-part-2/007-Delete-Every-N-Nodes.cpp)<br>
[008 - Swap Two Nodes of LinkedList](./code-part-2/008-Swap-Two-Nodes-LinkedList.cpp)<br>
[009 - kReverse](./code-part-2/009-kReverse.cpp)<br>
[010 - BubbleSort - Iterative](./code-part-2/010-Bubble-Sort-Iterative.cpp)<br>

---