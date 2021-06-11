#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

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
Node* takeinput(){
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
void print(Node *head){
	Node *temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

/**
 *  Print Reverse LinkedList
 *  -   You have been given a singly linked list of integers. Write a 
 *      function to print the list in a reverse order.
 *      To explain it further, you need to start printing the data from 
 *      the tail and move towards the head of the list, printing the head 
 *      data at the end.
 * 
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first and the only line of each test case or query contains the 
 *      elements(in ascending order) of the singly linked list separated by 
 *      a single space.
 *  Remember/Consider :
 *      While specifying the list elements for input, -1 indicates the end of 
 *      the singly linked list and hence, would never be a list element.
 *  Output format :
 *      For each test case/query, print the resulting singly linked list of 
 *      integers in a row, separated by a single space.
 *      Output for every test case will be printed in a seperate line.
 * 
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= M <= 10^5
 *  Time Limit: 1sec
 *      Where 'M' is the size of the singly linked list.
 * 
 *  Sample Input 1 :
 *      1
 *      1 2 3 4 5 -1
 *  Sample Output 1 :
 *      5 4 3 2 1
 *  
 *  Sample Input 2 :
 *      2
 *      1 2 3 -1
 *      10 20 30 40 50 -1
 *  Sample Output 2 :
 *      3 2 1
 *      50 40 30 20 10
 */ 
void printReverse(Node *head){
    if(head==NULL){
        cout << "";
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}

int main(){
    Node *head = takeinput();
    printReverse(head);
    cout << endl;
}