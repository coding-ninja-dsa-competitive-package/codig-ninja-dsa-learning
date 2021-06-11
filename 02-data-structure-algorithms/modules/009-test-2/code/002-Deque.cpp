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
 *  Dequeue
 *  -   You need to implement a class for Dequeue i.e. for double ended queue. 
 *      In this queue, elements can be inserted and deleted from both the ends.
 * 
 *  Constraints:
 *      1 <= Length of Linked List <=10^6.
 *  
 *  Input format :
 *      Line 1 : Linked list elements (separated by space and terminated by -1)
 *  Output Format :
 *      Line 1: Updated linked list elements 
 * 
 *  Sample Input 1 :    
 *      3 9 2 5 -1
 *  Sample Output 1 :
 *      3 9 2 6
 * 
 *  Sample Input 2 :
 *      9 9 9 -1
 *  Sample Output 1 :
 *      1 0 0 0 
 */
class Deque {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
    
    public:
    	Deque(int total){
            arr = new int[total];
            capacity = total;
            size =0;
            front = -1;
            rear = 0;
        }
    
    	void insertFront(int data){
            if(size == capacity){
                cout << "-1" << endl;
                return;
            }
            if (front == -1){
                front = 0;
                rear = 0;
            } else if (front == 0)
                front = capacity - 1 ;
			else
                front = front-1;
            arr[front] = data ;
            size++;
        }
    
    	void insertRear(int data){
            if(size == capacity){
                cout << "-1" << endl;
                return;
            }
            if (front == -1){
                front = 0;
                rear = 0;
            }
            else if (rear == capacity-1)
                rear = 0;
            else
                rear = rear+1;
            arr[rear] = data ;
            size++;
        }
    
    	void deleteFront(){
            if (size==0){
                cout << "-1" << endl;
                return ;
            }
            if (front == rear){
                front = -1;
                rear = -1;
            }
            else if (front == capacity -1)
            	front = 0;
			else 
                front = front+1;
            size--;
        }
                
    	void deleteRear(){
            if (size==0){
                cout << "-1" << endl ;
                return ;
            }
            if (front == rear){
                front = -1;
                rear = -1;
            }
            else if (rear == 0)
                rear = capacity-1;
            else
                rear = rear-1;
        	size--;
        }
                
        int getFront(){
            if (size==0){
                return -1;
            }
            return arr[front];
        }
                
        int getRear(){
            if (size==0 || rear<0){
                return -1;
            }
            return arr[rear];
        }
};

int main(){
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return;
        }
    }
}