#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

/**
 *  Next Number
 *  -   Given a large number represented in the form of a linked list. 
 *      Write code to increment the number by 1 in-place(i.e. without 
 *      using extra space).
 */
Node* reverse(Node* head){
    Node* previous=NULL;
    Node* next=NULL;
    Node* curr=head;
    while(curr != NULL){
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}
Node* NextLargeNumber(Node *head) {
    Node* reverseNumber = reverse(head);
    Node* curr = reverseNumber;
    Node* previous=NULL;
    int carry=1;
    while(curr != NULL){
        int sum = curr->data + carry;
        curr->data = sum%10;
        carry = sum/10;
        previous = curr;
        curr = curr->next;
    }
    if(carry > 0){
        Node* newNode = new Node(carry);
        previous->next = newNode;
    }
    return reverse(reverseNumber);
}
void problem1(){
    Node *head = takeinput();
    head = NextLargeNumber(head);
    print(head);
}

/**
 *  Dequeue
 *  -   You need to implement a class for Dequeue i.e. for double ended queue. 
 *      In this queue, elements can be inserted and deleted from both the ends.
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
void problem2(){
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

/**
 *  Delete alternate nodes
 *  -   Given a Singly Linked List of integers, delete all the alternate nodes in the list.
 */
void deleteAlternateNodes(Node *head) {
    if (head == NULL || head->next == NULL)
        return;
 
    Node *prev = head;
    Node *curr = head->next;
 
    while (prev != NULL && curr != NULL){
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev != NULL)
            curr = prev->next;
    }
}
void problem3(){
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
}

int main() {
    //Next Number
    problem1();
    //Dequeue
    problem2();
    //Delete alternate nodes
    problem3();
    return 0;
}