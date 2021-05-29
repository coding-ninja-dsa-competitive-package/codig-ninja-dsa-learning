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

/**
 *  What is the output
 *  Ans : 11 21
 */
void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void increment(Node *head){
    Node *temp = head;
    while(temp != NULL){
        temp -> data++;
        temp = temp -> next;
    }
}
void assignment1(){
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    node1 -> next = node2;
    increment(node1);
    print(node1);  
}
void assignment2(){
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    node2 -> next = node1;
    print(node2); // 20 10
}
void assignment3(){
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(20);
    Node *node4 = new Node(20);
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    print(node2);  // 20 20 20
}

/**
 *  Print the ith Node data
 */
void printIthNode(Node *head, int i){
    Node* temp = head;
    int idx=0;
    while(temp != NULL && idx < i){
        temp = temp->next;
        idx++;
    }
    if(temp != NULL){
        cout << temp->data << endl;
    }
}
void assignment4(){
    LinkedListImpl list;
    Node* head = list.takeInput();
    int pos;
    cin >> pos;
    printIthNode(head, pos);
    cout << endl;
}

/**
 *  Insert and delete Nodes
 */
void assignment5(){
    LinkedListImpl list;
    Node* head = list.takeInput();
    int data, index;
    cin >> data >> index;
    cout << "List before insertion : ";
    list.print(head);
    list.insertAtIndex(head, data, index);
    cout << "List after insertion : ";
    list.print(head);

    //deletion
    cin >> index;
    list.deleteAtIndex(head, index);
    cout << "List after deletion : ";
    list.print(head);
}

/**
 *  Length Recursive
 */
int length(Node *head) {
    if(head == NULL){
        return 0;
    }
    int ans = length(head->next);
    return 1+ans;
}
void assignment6(){
    LinkedListImpl list;
    Node *head = list.takeInput();
    cout << length(head) << "\n";
}

/**
 *  Insert Recursively
 */
Node* insertNode(Node *head, int i, int data) {
	if(head == NULL){
        return head;
    }
    if(i==0){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* ans = insertNode(head->next, i-1, data);
	head->next = ans;
    return head;
}
void assignment7(){
    LinkedListImpl list;
    Node *head = list.takeInput();
    int pos, data;
    cin >> data >> pos;
    head = insertNode(head, pos, data);
    print(head);
}

/**
 *  delete recursively
 */
Node *deleteNodeRec(Node *head, int pos) {
	if(head == NULL){
        return head;
    }
    if(pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        head->next = deleteNodeRec(head->next, pos-1);
    }
    return head;
}
void assignment8(){
    LinkedListImpl list;
    Node *head = list.takeInput();
    int pos;
    cin >> pos;
    head = deleteNodeRec(head, pos);
    print(head);
}

int main() {
    //Basics
    //problem1();
    //problem2(); // take Input

    //assignment1();
    //assignment2();
    //assignment3();

    //print ith node
    //assignment4();

    //insertion , deletion test
    //assignment5();

    //length recursive function
    //assignment6();

    //insert recursively
    //assignment7();

    //delete recursively
    assignment8();

    return 0;
}