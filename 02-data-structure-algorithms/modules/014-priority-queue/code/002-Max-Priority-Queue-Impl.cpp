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
 *  Implement the class for Max Priority Queue which includes following functions -
 *  1.  getSize :
 *      -   Return the size of priority queue i.e. number of elements present in 
 *          the priority queue.
 *  2.  isEmpty :
 *      -   Check if priority queue is empty or not. Return true or false accordingly.
 *  3.  insert :
 *      -   Given an element, insert that element in the priority queue at the 
 *          correct position.
 *  4.  getMax :
 *      -   Return the maximum element present in the priority queue without 
 *          deleting. Return -Infinity if priority queue is empty.
 *  5.  removeMax :
 *      -   Delete and return the maximum element present in the priority queue. 
 *          Return -Infinity if priority queue is empty.
 *  Note : main function is given for your reference which we are using internally 
 *      to test the class.
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

int main(){
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

    return 0;
}