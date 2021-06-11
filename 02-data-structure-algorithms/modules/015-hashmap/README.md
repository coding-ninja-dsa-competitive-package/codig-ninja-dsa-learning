# Hashmap 

 *  If we want to store data in the form of ```Key-Value``` pair. We can use ```Hashmap```.

---

## Implementation
We can implement it using :
1.  **Using BST**:
    -   map (```STL```) - implemented using BST - O(logn)
2.  **Using Hashtable**:
    -   unordered_map (```STL```) - implemented using hashtable - O(1)

---

## Hash Function Logic
-   An array of limited size is used as bucket.
-   ```Hashcode``` is calculated for the key and value is put at that address.
-   Consist of 2 functions :
    1.  ```hashcode``` : this function can be implemented in many ways. 
    2.  ```compression function``` : We can use modulus (%) to fit our key in bucket size range.

-   ```Collision``` : If 2 different keys produce same hash, it will go to same address in the bucket array/ hash table.
    1.  ```Closed Hashing```: all the entries in collision will go to same location and data will be stored in linked list. Also called as separate chaining.
    2.  ```Open Addressing```: if the location is occupied with other data, we need to find alternate place for the data storage. <br>
     > ```hi(a) = h.f.(a) + f(i)```<br>
     > **f(i)** depends on the type of **open addressing** technique:
    -   Technique in ```Open Addressing```:
        -   **Linear Probing** : check the next position i.e. ```i+1```
        -   **Quadratic probing** : check the quadratic position i.e. ```i^2```
        -   **Double Hashing** :  ```f(i) = i * h'(a)```
-   In practice, separate chaining works fine as open addressing. 
-   ```Load Factor```:
    -   Consider, we are entering data in map and all entries are going to same bucket index, so to maintain the ```O(1)``` time for insertion/deletion, load factor is maintained so that linked list doesn't become large.<br>
    -   Example : load factor 0.75 signifies - if the bucket contains 3/4 of the total number of elements - rehashing will be done which will increase the array size and load factor will decrease.


---

 ##  Reason to choose Tries over HashMap for Dictionary:
 *  Due to space optimization, **Trie** is preferred over **hashmap**.
 *  Fast Searching.

---

### Hashmap Implementation:
[HashMap Implemention](./code/001-HashMap-Impl.cpp)<br>
[Basic usage with STL](./code/002-Basic-Usage.cpp)<br>

---

### Problems:
[001 - Remove Duplicates](./code/003-Remove-Duplicates.cpp)<br>
[002 - Maximum Frequency Number](./code/004-Maximum-Frequency-Number.cpp)<br>
[003 - Print Intersection](./code/005-Print-Intersection.cpp)<br>
[004 - Pair Sum To 0](./code/006-Pair-Sum.cpp)<br>
[005 - Extract Unique Characters](./code/007-Extract-Unique-Characters.cpp)<br>
[006 - Longest Consecutive Sequence](./code/008-Longest-Consecutive-Sequence.cpp)<br>
[007 - Pairs With Difference K  ](./code/009-Pairs-With-Diff-K.cpp)<br>
[008 - Largest Subset Zero Sum](./code/010-Largest-Subset-Zero-Sum.cpp)<br>

---