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
 *  Reverse LL (Recursive)
 *  -   Given a singly linked list of integers, reverse it using recursion and 
 *      return the head to the modified list. You have to do this in O(N) time 
 *      complexity where N is the size of the linked list.
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
 *      1 2 3 4 5 6 7 8 -1
 *  Sample Output 1 :
 *      8 7 6 5 4 3 2 1
 *  
 *  Sample Input 2 :
 *      2   
 *      10 -1
 *      10 20 30 40 50 -1
 *  Sample Output 2 :
 *      10 
 *      50 40 30 20 10 
 */
//====Approach 1 - Recursion - O(n^2)=======
Node *reverseLinkedListRec(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ans = reverseLinkedListRec(head->next);
    Node* temp = ans;
    while(temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return ans;
}
//====Approach 2 - Recursion Using Pair Class - O(n)=======
class Pair{
    public:
        Node* head;
        Node* tail;
};
Pair reverseLinkedListRecPair(Node *head){
    if(head == NULL || head->next == NULL){
        Pair pair;
        pair.head = head;
        pair.tail = head;
        return pair;
    }
    Pair ans = reverseLinkedListRecPair(head->next);
    ans.tail->next = head;
    head->next = NULL;
    
    Pair pair;
    pair.head = ans.head;
    pair.tail = head;
    return pair;
}
//====Approach 3 - Recursion - O(n)=======
Node *reverseLinkedListRecLinear(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ans = reverseLinkedListRecLinear(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL; 
    return ans;
}
//====Approach 4 - Iterative - O(n)=======
Node* reverseLinkedListIterative(Node* head){
    Node* previous=NULL;
    Node* next=NULL;
    Node* current=head;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous=current;
        current=next;
    }
    return previous;
}

int main(){
    Node *head = takeinput();
    Node* reversed1 = reverseLinkedListRec(head);
    print(reversed1);
    head = takeinput();
    Pair pair = reverseLinkedListRecPair(head);
    print(pair.head);
    head = takeinput();
    Node* reversed2 = reverseLinkedListRecLinear(head);
    print(reversed2);
    head = takeinput();
    Node* reversed3 = reverseLinkedListIterative(head);
    print(reversed3);
}