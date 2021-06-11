# Tries 

 *  Tree like data structure and used to store data like dictionary words.
 *  The first letter would be at first position and so on...
 *  Each node can have maximum 26 children since we have 26 letters only.

---

### Structure

[<img align="left" alt="trie" src="./images/trie-1.png" width="250px"  height="250px">](Structure)

<br><br><br><br><br><br><br><br><br><br><br>

---

 ###  Reason to choose Tries over HashMap for Dictionary:
 *  Due to space optimization, **Trie** is preferred over **hashmap**.
 *  Fast Searching.

---

### Types of Tries:
1.  **Compressed Tries** : 
    -   Space optimization.
    -   Merge the nodes which have only one child.
        -   Ex: bend and bean will stored as :
>                         be
>                        /  \
>                       nd  an 
2.  **Suffix Tries** : 
    -   In this , we store all the suffix as well in the trie.
    -   Ex: bend - we will store bend, end, en, nd, d

---

### Problems:
[001 - Trie Implementtaion](./code/001-Trie-Implementation.cpp)<br>
[002 - Pattern Matching](./code/002-Pattern-Matching.cpp)<br>
[003 - Palindrome Pair](./code/003-Palindrome-Pair.cpp)<br>
[004 - Auto Complete](./code/004-Auto-Complete.cpp)<br>

---