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
 *  AppendLastNToFirst
 *  -   You have been given a singly linked list of integers along with 
 *      an integer 'N'. Write a function to append the last 'N' nodes 
 *      towards the front of the singly linked list and returns the new 
 *      head to the list.
 * 
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first line of each test case or query contains the elements of the 
 *      singly linked list separated by a single space. 
 *      The second line contains the integer value 'N'. It denotes the number 
 *      of nodes to be moved from last to the front of the singly linked list.
 *  Remember/Consider :
 *      While specifying the list elements for input, -1 indicates the end of the 
 *      singly linked list and hence, would never be a list element.
 *  Output format :
 *      For each test case/query, print the resulting singly linked list of 
 *      integers in a row, separated by a single space.
 *      Output for every test case will be printed in a seperate line.
 * 
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= M <= 10^5
 *      0 <= N < M
 *  Time Limit: 1sec
 *      Where 'M' is the size of the singly linked list.
 * 
 *  Sample Input 1 :
 *      2
 *      1 2 3 4 5 -1
 *      3
 *      10 20 30 40 50 60 -1
 *      5
 *  Sample Output 1 :
 *      3 4 5 1 2
 *      20 30 40 50 60 10
 *  Sample Input 2 :
 *      1
 *      10 6 77 90 61 67 100  -1
 *      4
 *  Sample Output 2 :
 *      90 61 67 100 10 6 77 
 *  Explanation to Sample Input 2 :
 *  We have been required to move the last 4 nodes to the front of the list. 
 *  Here, "90->61->67->100" is the list which represents the last 4 nodes. When 
 *  we move this list to the front then the remaining part of the initial list 
 *  which is, "10->6->77" is attached after 100. Hence, the new list formed with 
 *  an updated head pointing to 90.
 */
int length(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1+length(head->next);
}
Node *appendLastNToFirst(Node *head, int n){
    int len = length(head);
    if(n>=len || n<=0){
        return head;
    }
    Node* temp = head;
    int i=0;
    while(temp != NULL && i < len-n-1){
        temp = temp->next;
        i++;
    }
    if(temp != NULL){
        Node* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp != NULL && temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        head = newHead;
        return head;
    }
    return NULL;
}

int main(){
    Node *head = takeinput();
    int n;
    cin >> n;
    head = appendLastNToFirst(head, n);
    print(head);
}