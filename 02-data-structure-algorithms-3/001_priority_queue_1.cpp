#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/**
 *  Priority Queue:
 *  ===============
 *  -   Extension of Queue (FIFO) data structure. 
 *  -   Data is inserted similar to insertion happens in Queue.
 *  -   Data extraction happens according to priority or importance factor.
 *      Ex: decresing sorting order i.e. max element first.
 *  
 *  -   Two types:
 *      1.  Min Priority Queue
 *      2.  Max Priority Queue
 * 
 *  -   Which Data Structure could be best suited for PriorityQueue
 *          DS              |   Insert  |  getMin/Max   |   removeMin/Max
 *      -----------------------------------------------------------------
 *      Array(unsorted)     |   O(1)    |   O(n)        |       O(n)
 *      Array(sorted)       |   O(n)    |   O(1)        |       O(n)
 *      LinkedList(unsorted)|   O(1)    |   O(n)        |       O(n)
 *      LinkedList(sorted)  |   O(n)    |   O(1)        |       O(1)
 *      BST                 |   O(h)    |   O(h)        |       O(h)
 *      Balanced BST        |   O(logn) |   O(logn)     |       O(logn)
 *      HashMap             |   O(1)    |   O(n)        |       O(n)
 * 
 *  -   Seeing above table , Balanced BST seems the best data structure for it.
 *      But we need to maintain :
 *      1.  Balancing 
 *      2.  Storing in sorted order.
 * 
 *  -   So new Data structure - Heap is choosen for it which is a complete binary tree.
 * 
 *  Heap :
 *  =====
 *  -   Two properties:
 *      1.  Complete Binary Tree (CBT):
 *          -   All the levels except last level should be completely filled.
 *          -   last level also should be filled from left to right.
 *      2.  Element can be inserted/deleted in the last level from left to right order.
 *  -   Minimum number of nodes in CBT : 2^(h-1)
 *      Maximum number of nodes in CBT : 2^h - 1
 *       => log(n+1) <= h <= logn+1
 *       => logn <= h <= logn
 *  -   How to store efficiently in CBT:
 *      -   We can backed the heap by an array.
 *          -   left child index = 2*i + 1
 *          -   right child index = 2*i + 2
 *          -   parent index from child = (childIndex-1)/2
 */

/**
 *  Minimum Priority Queue Implementation backed by an array
 *  -   We can call it Heap Sort.
 *          Time : nlogn(insert) + nlogn(delete) => O(nlogn)
 *          Space : O(n)
 *          
 */
class MinPriorityQueue{
    vector<int> pq;

    public:
        MinPriorityQueue(){}

        int getMin(){
            if(pq.empty()){
                return 0; // represent the pq is empty
            }
            return pq.at(0);
        }

        void insert(int data){
            pq.push_back(data); 
            int childIndex = pq.size()-1;
            while(childIndex > 0){
                int parentIndex = (childIndex-1)/2;
                if (pq[childIndex] < pq[parentIndex]) {
                    int temp = pq[childIndex];
                    pq[childIndex] = pq[parentIndex];
                    pq[parentIndex] = temp;
                } else {
                    break;
                }
                childIndex = parentIndex;
            }
        }

        int removeMin(){
            int n = getSize();
            if(n > 0){
                int elementToDelete = pq[0];
                pq[0] = pq[n-1];
                pq.pop_back();
                int parentIndex = 0;
                while(parentIndex < n){
                    int leftChildIdx = 2*parentIndex + 1;
                    int rightChildIdx = 2*parentIndex + 2;
                    int minIndex = -1;
                    if(leftChildIdx < n && rightChildIdx < n){
                        if(pq[leftChildIdx] < pq[rightChildIdx]){
                            minIndex = leftChildIdx;
                        } else {
                            minIndex = rightChildIdx;
                        }
                    } else if(leftChildIdx < n){
                        minIndex = leftChildIdx;
                    } else if(rightChildIdx < n){
                        minIndex = rightChildIdx;
                    }
                    if(minIndex != -1 && pq[parentIndex] > pq[minIndex]){
                        swap(pq[parentIndex], pq[minIndex]);
                        parentIndex = minIndex;
                    } else {
                        break;
                    }
                }
                return elementToDelete;
            }
            return 0;
        }

        bool isEmpty(){
            return pq.size()==0;
        }

        // return the size of priority queue
        int getSize(){
            return pq.size();
        }
};
void problem1(){
    MinPriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return;
        }
        
        cin >> choice;
    }
}

/**
 *  Max Priority Queue implementation
 */
#include<climits>
class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {}

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] > pq[parentIndex]){
                swap(pq[childIndex], pq[parentIndex]);
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax() {
        if(pq.empty()){
            return INT_MIN;
        }
        return pq.at(0);
    }

    int removeMax() {
        int n = getSize();
        if(n <= 0){
            return INT_MIN;
        }
        int elementToDelete = pq[0];
        pq[0] = pq[n-1];
        pq.pop_back();

        int parentIndex = 0;
        while(parentIndex < n){
            int leftChildIdx = 2*parentIndex + 1;
            int rightChildIdx = 2*parentIndex + 2;
            int maxIndex = -1;
            if(leftChildIdx < n && rightChildIdx < n){
                if(pq[leftChildIdx] > pq[rightChildIdx]){
                    maxIndex = leftChildIdx;
                } else {
                    maxIndex = rightChildIdx;
                }
            } else if (leftChildIdx < n){
                maxIndex = leftChildIdx;
            } else if (rightChildIdx < n){
                maxIndex = rightChildIdx;
            }
            if(maxIndex != -1 && pq[maxIndex] > pq[parentIndex]){
                swap(pq[maxIndex], pq[parentIndex]);
                parentIndex = maxIndex;
            } else {
                break;
            }
        }   
        return elementToDelete;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};
void problem2(){
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return;
        }
        
        cin >> choice;
    }
}

/**
 *  Heap Sort
 *  -   Given an integer array of size N. Sort this array (in decreasing 
 *      order) using heap sort.
 *  -   Note: Space complexity should be O(1).
 */
void buildHeap(int arr[], int n){
    for(int i = 1; i < n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            } else {
                break;
            }
            childIndex = parentIndex;
        }
    }
}
void removeMin(int arr[], int n){
    int size = n;
    while(size > 1){
        int min = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = min;
        size--;
        
        int parentIndex = 0;
        while(parentIndex < size){
            int leftChildIdx = 2*parentIndex+1;
            int rightChildIdx = 2*parentIndex+2;
            int minIndex = -1;
            if(leftChildIdx < size && rightChildIdx < size){
                if(arr[leftChildIdx] < arr[rightChildIdx]){
                    minIndex = leftChildIdx;
                } else {
                    minIndex = rightChildIdx;
                }
            } else if(leftChildIdx < size){
                minIndex = leftChildIdx;
            } else if(rightChildIdx < size){
                minIndex = rightChildIdx;
            }
            if(minIndex != -1 && arr[parentIndex] > arr[minIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[minIndex];
                arr[minIndex] = temp;
                
                parentIndex = minIndex;
            } else {
                break;
            }
        }
    }
}
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    removeMin(arr, n);
}
void problem3(){
    int size;
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 
    heapSort(input, size);
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 
    delete[] input;
}

int main() {
    // Min Priority Class Implementation using array
    // problem1();

    // Max Priority Class Implementation using array
    // problem2();

    // Heap Sort
    problem3();

    return 0;
}