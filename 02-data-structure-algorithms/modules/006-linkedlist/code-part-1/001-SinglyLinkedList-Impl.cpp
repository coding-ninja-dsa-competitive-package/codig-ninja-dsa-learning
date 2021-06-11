#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  Node Class
 */
class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

class LinkedListImpl{
    public:
        //pass head as reference because we need to handle case for insertion at head.
        void insertAtIndex(Node* &head, int data, int index){
            Node* newNode = new Node(data);
            //insertion at head
            if(index == 0){
                newNode->next = head;
                head = newNode;
                return;
            }
            //insertion at specified index other than 0
            Node* temp = head;
            int i=0;
            while(temp != NULL && i<index-1){
                temp = temp->next;
                i++;
            }
            if(temp != NULL){
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        void deleteAtIndex(Node* &head, int index){
            Node* temp = head;
            if(index == 0){
                head = head->next;
                delete temp;
                return;
            }
            int i=0;
            while(temp != NULL && i < index-1){
                temp = temp->next;
                i++;
            }
            if(temp != NULL && temp->next != NULL){
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
            }
        }

        //calculate the size of the linked list
        int length(Node *head){
            int len=0;
            Node* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            return len;
        }


        Node* takeInput(){
            int data;
            cin>>data;
            Node* head = NULL;
            Node* tail = NULL;
            while(data != -1){
            //while(cin >> data){ // if we want to take input from a file
                Node* newNode = new Node(data);
                if(head == NULL){
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                    //OR
                    //tail = tail->next;
                }
                cin >> data;
            }
            return head;
        }

        void print(Node* head){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data;
                temp = temp->next;
                if(temp != NULL){
                    cout << "->";
                }
            }
            cout << endl;
        }
};

void problem1(){
    Node* n1=new Node(10);
    Node* head = n1;
    Node n2(20);
    Node n3(30);
    // since n2 is normal object - we can use . to access members.
    n2.next = &n3;
    // since n1 is pointer - we need to use lambda
    n1->next = &n2;

    //print linked list
    LinkedListImpl list;
    list.print(head);
}
void problem2(){
    LinkedListImpl list;
    Node* head = list.takeInput();
    list.print(head);
}

int main(){
    // Create Linked List using hard coded nodes
    problem1();
    // Take input and create LinkedList
    problem2();
}