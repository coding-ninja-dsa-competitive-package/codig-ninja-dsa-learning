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
 *  Merge Sort
 *  -   Given a singly linked list of integers, sort it using 'Merge Sort.'
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
 *      10 9 8 7 6 5 4 3 -1
 *  Sample Output 1 :
 *      3 4 5 6 7 8 9 10 
 *      
 *  Sample Output 2 :
 *      2
 *      -1  
 *      10 -5 9 90 5 67 1 89 -1
 *  Sample Output 2 :
 *      -5 1 5 9 10 67 89 90 
 */

Node* getMiddle(Node *head){
    Node* slow=head;
    Node* fast=head;
    Node* previous=NULL;
    while(fast != NULL && fast->next != NULL){
        previous = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return previous;
}
Node* merge(Node* head1, Node* head2){
    Node* result = new Node(0);
    Node* curr = result;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if(head1 != NULL){
        curr->next = head1;
    } else {
        curr->next = head2;
    }
    Node* newHead = result->next;
    delete result;
    return newHead;
}
Node *mergeSort(Node *head){
	if(head == NULL || head->next == NULL){
        return head;
    }
	Node* previousToMiddle = getMiddle(head);
    Node* mid = previousToMiddle->next;
    previousToMiddle->next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}

int main(){
    Node *head = takeinput();
    head = mergeSort(head);
    print(head);
}