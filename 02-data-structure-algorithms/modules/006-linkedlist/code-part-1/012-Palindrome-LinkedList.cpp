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
 *  Palindrome LinkedList
 *  -   You have been given a head to a singly linked list of integers. 
 *      Write a function check to whether the list given is a 'Palindrome' 
 *      or not.
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
 *      9 2 3 3 2 9 -1
 *  Sample Output 1 :
 *      true
 * 
 *  Sample Input 2 :
 *      2
 *      0 2 3 2 5 -1
 *      -1
 *  Sample Output 2 :
 *      false
 *      true
 *  Explanation for the Sample Input 2 :
 *      For the first query, it is pretty intuitive that the the given list is 
 *      not a palindrome, hence the output is 'false'.
 *      For the second query, the list is empty. An empty list is always a 
 *      palindrome , hence the output is 'true'.
 */
Node* reverse(Node* head){
    Node* previous=NULL; 
    Node* current=head;
    Node* next=NULL;
    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}

bool isPalindrome(Node *head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    Node* previous=NULL;
    while(fast != NULL && fast->next != NULL){
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    previous->next = NULL;
    Node* reverseHead = reverse(slow);
    Node* temp1 = head;
    Node* temp2 = reverseHead;
    while(temp1 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}

int main(){
    Node *head = takeinput();
    bool ans = isPalindrome(head);

    if (ans) cout << "true";
    else cout << "false";

    cout << endl;
}