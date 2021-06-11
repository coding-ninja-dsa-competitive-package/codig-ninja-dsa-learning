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
 *  Merge Two Sorted LL
 *  -   You have been given two sorted(in ascending order) singly linked 
 *      lists of integers.
 *  -   Write a function to merge them in such a way that the resulting singly 
 *      linked list is also sorted(in ascending order) and return the new head 
 *      to the list.
 * 
 *  Note :  Try solving this in O(1) auxiliary space.
 *  
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first and the only line of each test case or query contains the 
 *      elements(in ascending order) of the singly linked list separated by 
 *      a single space.
 *      The second line of the input contains the elements of the second sorted 
 *      singly linked list separated by a single space. 
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
 *      2 5 8 12 -1
 *      3 6 9 -1
 *  Sample Output 1 :
 *      2 3 5 6 8 9 12 
 * 
 *  Sample Input 2 :
 *      2
 *      2 5 8 12 -1
 *      3 6 9 -1    
 *      10 40 60 60 80 -1       
 *      10 20 30 40 50 60 90 100 -1
 *  Sample Output 2 :
 *      2 3 5 6 8 9 12 
 *      10 10 20 30 40 40 50 60 60 60 80 90 100
 */
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    Node* result = new Node(0);
    Node* curr = result;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        } else{
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

int main(){
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
    print(head3);
}