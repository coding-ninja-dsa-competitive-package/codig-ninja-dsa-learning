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
 *  Code: Midpoint of LL
 *  -   For a given singly linked list of integers, find and return the 
 *      node present at the middle of the list.
 *  Note :
 *      If the length of the singly linked list is even, then return the 
 *      first middle node.
 *      Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the 
 *      nodes present at the middle with respective data values are, 20 and 30. 
 *      We return the first node with data 20.
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
 *      3
 *      
 *  Sample Input 2 :
 *      2 
 *      -1
 *      1 2 3 4 -1
 *  Sample Output 2 :
 *      2
 */
Node *midPoint(Node *head){
    if(head == NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    Node *head = takeinput();
    Node *mid = midPoint(head);
    if (mid != NULL){
        cout << mid->data;
    }
    cout << endl;
}