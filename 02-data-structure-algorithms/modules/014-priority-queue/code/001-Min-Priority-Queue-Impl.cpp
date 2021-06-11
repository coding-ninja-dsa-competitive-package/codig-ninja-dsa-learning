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
 *  Minimum Priority Queue Implementation backed by an array
 *  -   We can call it Heap Sort.
 *          Time : nlogn(insert) + nlogn(delete) => O(nlogn)
 *          Space : O(n)      
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

int main(){
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

    return 0;
}