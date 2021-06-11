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
 *  Delete node
 *  -   You have been given a linked list of integers. Your task is to write a 
 *      function that deletes a node from a given position, 'pos'.
 *  Note :  Assume that the Indexing for the linked list always starts from 0.
 *  -   If the position is greater than or equal to the length of the linked list, 
 *      you should return the same linked list without any change.
 * 
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first line of each test case or query contains the elements of the 
 *      linked list separated by a single space. 
 *      The second line of each test case contains the integer value of 'pos'. 
 *      It denotes the position in the linked list from where the node has to be deleted.
 *  Remember/Consider :
 *      While specifying the list elements for input, -1 indicates the end of the 
 *      singly linked list and hence, would never be a list element
 * 
 *  Output format :
 *      For each test case/query, print the resulting linked list of integers in a 
 *      row, separated by a single space.
 *      Output for every test case will be printed in a separate line.
 * 
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= N <= 10^5
 *      pos >= 0
 *      
 *  Time Limit: 1sec
 *      Where 'N' is the size of the singly linked list.
 *  
 *  Sample Input 1 :
 *      1 
 *      3 4 5 2 6 1 9 -1
 *      3
 *  Sample Output 1 :
 *      3 4 5 6 1 9
 *  
 *  Sample Input 2 :
 *      2
 *      3 4 5 2 6 1 9 -1
 *      0
 *      10 20 30 40 50 60 -1
 *      7
 *  Sample Output 2 :
 *      4 5 2 6 1 9
 *      10 20 30 40 50 60
 */

Node *deleteNode(Node *head, int pos){
    Node* temp = head;
    if(pos == 0){
        head = head->next;
        delete temp;
        return head;
    }
    int i=0;
    while(temp != NULL && i < pos-1){
        temp = temp->next;
        i++;
    }
    if(temp != NULL && temp->next != NULL){
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    return head;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}