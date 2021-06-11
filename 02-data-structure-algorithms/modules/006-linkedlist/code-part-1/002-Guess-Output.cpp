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

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

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

int main(){
    assignment1();

    assignment2();

    assignment3();
}