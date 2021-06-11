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
 *  Bubble Sort (Iterative) LinkedList    
 *  -   Given a singly linked list of integers, sort it using 'Bubble Sort.'
 *  Example :
 *      Given this linked list: 1 -> 2 -> 3 -> 4 -> 5   
 *      For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
 *      For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *  Remember/Consider :
 *      While specifying the list elements for input, -1 indicates the end of 
 *      the singly linked list and hence, would never be a list element.
 *  Output format :
 *      For each test case/query, print the resulting singly linked list of 
 *      integers in a row, separated by a single space.
 *      Output for every test case will be printed in a seperate line.
 * 
 *  Constraints :  
 *      0 <= M <= 10^3
 *      Where M is the size of the singly linked list.
 *  Time Limit: 1sec
 * 
 *  Sample Input 1 :
 *      10 9 8 7 6 5 4 3 -1
 *  Sample Output 1 :
 *      3 4 5 6 7 8 9 10 
 *  
 *  Sample Input 2 :
 *      10 -5 9 90 5 67 1 89 -1
 *  Sample Output 2 :
 *      -5 1 5 9 10 67 89 90 
 */

int length(Node* head){
    int count=0;
    Node* curr = head;
    while(curr != NULL){
        curr=curr->next;
        count++;
    }
    return count;
}
Node *bubbleSort(Node *head){
    int len = length(head);
    for(int i=0; i<len; i++){
        Node* previous=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr != NULL && curr->next != NULL){
            next = curr->next;
            if(curr->data <= next->data){
                previous = curr;
                curr = curr->next;
            } else {
                if(previous == NULL){
                    head = next;
                }else {
                    previous->next = next;
                }
                curr->next=next->next;
                next->next=curr;
                if(previous == NULL){
                    previous = head;
                }else {
                    previous = previous->next;
                }
            }
        }
    }
    return head;
}

int main(){
    Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}