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
 *  Queue implementation using array
 */
template <typename T>
class QueueUsingArray{
    T *data;
    int size;
    int capacity;
    int nextIndex;
    int firstIndex;

    public:
        QueueUsingArray(){
            data = new int[4];
            size=0;
            capacity=4;
            firstIndex=-1;
            nextIndex=0;
        }

        void ensureCapacity(){
            T *newData = new T[2*capacity];
            int k=0;
            for(int i=firstIndex; i<capacity; i++){
                newData[k++] = data[i];
            }
            for(int i=0; i<firstIndex; i++){
                newData[k++] = data[i];
            }
            delete data;
            data = newData;
            capacity *= 2;
            firstIndex =0;
            nextIndex = capacity;
        }

        void enqueue(T element){
            if(size == capacity){
                ensureCapacity();
                //cout << "Queue is full." << endl;
                //return;
            }
            data[nextIndex] = element;
            nextIndex = (nextIndex+1) % capacity;
            size++;
            if(firstIndex == -1){
                firstIndex = 0;
            }
        }

        T dequeue(){
            if(size == 0){
                cout << " Queue is empty." << endl;
                return -1;
            }
            T temp =  data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            if(size==0){
                firstIndex=-1;
                nextIndex=0;
            }
            return temp;
        }

        T front(){
            if(size == 0){
                cout << " Queue is empty." << endl;
                return -1;
            }
            return data[firstIndex];
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size==0;
        }
};
void problem1(){
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(45);
    //q.enqueue(4); // queue is full
    q.enqueue(4);

    cout << q.dequeue() << endl;  // 10
    cout << q.front() << endl; // 20
    cout << q.getSize() << endl; // 4
    cout << q.isEmpty() << endl; //0
    q.enqueue(23);
    cout << q.getSize() << endl; // 5
}

/**
 *  Linked List Implementation of Queue
 */
template <typename T>
class Node {
   public:
    T data;
    Node *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class QueueUsingLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
        QueueUsingLinkedList() {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size==0;
        }

        void enqueue(T data) {
            Node<T>* newNode = new Node<T>(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        T dequeue() {
            if(head == NULL){
                return -1;
            }
            Node<T>* temp = head;
            head = head->next;
            size--;
            T d = temp->data;
            delete temp;
            return d;
        }

        T front() {
            if(head == NULL){
                return -1;
            }
            return head->data;
        }
};
void problem2(){
    QueueUsingLinkedList<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(45);
    //q.enqueue(4); // queue is full
    q.enqueue(4);

    cout << q.dequeue() << endl;  // 10
    cout << q.front() << endl; // 20
    cout << q.getSize() << endl; // 4
    cout << q.isEmpty() << endl; //0
    q.enqueue(23);
    cout << q.getSize() << endl; // 5
}

/**
 *  Reverse Queue
 *  -   You have been given a queue that can store integers as the data. 
 *      You are required to write a function that reverses the populated 
 *      queue itself without using any other data structures.
 */
#include<queue>
void reverseQueue(queue<int> &input) {
 	if(input.empty()){
        return;
    }
    int temp = input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);
}
void assignment1(){
    int t;
    cin >> t;
    while (t--) {
        queue<int> q;
        int size;
        cin >> size;
        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }
        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
}

int main() {

    //Queue basic - using array implementation
    //problem1();
    
    //Queue implementation using linked list
    //problem2();

    //reverse queue
    assignment1();

    return 0;
}