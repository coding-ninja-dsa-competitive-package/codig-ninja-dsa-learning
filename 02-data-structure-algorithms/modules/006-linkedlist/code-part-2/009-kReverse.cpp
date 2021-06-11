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
 *  kReverse    
 *  -   Given a singly linked list of integers, reverse the nodes of the    
 *      linked list 'k' at a time and return its modified list.
 *  -   'k' is a positive integer and is less than or equal to the length of 
 *      the linked list. If the number of nodes is not a multiple of 'k,' then 
 *      left-out nodes, in the end, should be reversed as well.
 *  Example :
 *      Given this linked list: 1 -> 2 -> 3 -> 4 -> 5   
 *      For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
 *      For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first line of each test case or query contains the elements of the 
 *      singly linked list separated by a single space.
 *      The second line of input contains a single integer depicting the value of 'k'.
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
 *      Where M is the size of the singly linked list.
 *      0 <= k <= M
 *  Time Limit: 1sec
 * 
 *  Sample Input 1 :
 *      1
 *      1 2 3 4 5 6 7 8 9 10 -1
 *      4
 *  Sample Output 1 :
 *      4 3 2 1 8 7 6 5 10 9
 *  
 *  Sample Input 2 :
 *      2
 *      1 2 3 4 5 -1
 *      0
 *      10 20 30 40 -1
 *      4
 *  Sample Output 2 :
 *      1 2 3 4 5 
 *      40 30 20 10 
 */

class Pair{
    public:
    	Node* head;
    	Node* tail;
};
Pair reverse(Node* head){
    if(head == NULL or head->next==NULL){
        Pair pair;
        pair.head = head;
        pair.tail = head;
        return pair;
    }
	Pair ans = reverse(head->next);
    ans.tail->next = head;
    head->next = NULL;
    ans.tail = head;
    return ans;
}
Node *kReverse(Node *head, int k){
    if(head == NULL or head->next == NULL){
        return head;
    }
    int i=1;
    Node* nextHead = NULL;
    Node* tail = head;
	while( tail != NULL && tail->next != NULL  && i<k){
        tail=tail->next;
        i++;
    }
    nextHead = tail->next;
    tail->next = NULL;
    Pair reverseResult = reverse(head);
    Node* ans = kReverse(nextHead, k);
    reverseResult.tail->next = ans;
    return reverseResult.head;
}

int main(){
    int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
}