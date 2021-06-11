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
 *  Even after Odd LinkedList
 *  -   For a given singly linked list of integers, arrange the elements such 
 *      that all the even numbers are placed after the odd numbers. The relative 
 *      order of the odd and even terms should remain unchanged.
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
 *      1 4 5 2 -1
 *  Sample Output 1 :
 *      1 5 4 2 
 * 
 *  Sample Input 2 :    
 *      2
 *      1 11 3 6 8 0 9 -1
 *      10 20 30 40 -1
 *  Sample Output 2 :
 *      1 11 3 9 6 8 0
 *      10 20 30 40
 */

Node* evenAfterOdd(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* oddHead=new Node(0);
    Node* odd=oddHead;
    Node* evenHead=new Node(0);
    Node* even=evenHead;
    Node* curr=head;
    while(curr != NULL){
        if((curr->data)%2 == 1){
    		if(odd == NULL){
                odd = curr;
            } else {
                odd->next = curr;
                odd= odd->next;
            }
        } else {
            if(even == NULL){
                even = curr;
            } else {
                even->next = curr;
                even = even->next;
            }
        }
        curr = curr->next;
    }
    even->next=NULL;
    odd->next = evenHead->next;
    Node* newHead = oddHead->next;
    delete oddHead;
    delete evenHead;
    return newHead;
}

int main(){
    int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
}