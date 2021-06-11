#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

/**
 *  Next Number
 *  -   Given a large number represented in the form of a linked list. 
 *      Write code to increment the number by 1 in-place(i.e. without 
 *      using extra space).
 * 
 *  Input format :
 *      Line 1 : Linked list elements (separated by space and terminated by -1)
 *  Output Format :
 *      Line 1: Updated linked list elements 
 * 
 *  Sample Input 1 :
 *      3 9 2 5 -1
 *  Sample Output 1 :   
 *      3 9 2 6
 * 
 *  Sample Input 2 :
 *      9 9 9 -1
 *  Sample Output 1 :
 *      1 0 0 0 
 */
Node* reverse(Node* head){
    Node* previous=NULL;
    Node* next=NULL;
    Node* curr=head;
    while(curr != NULL){
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}
Node* NextLargeNumber(Node *head) {
    Node* reverseNumber = reverse(head);
    Node* curr = reverseNumber;
    Node* previous=NULL;
    int carry=1;
    while(curr != NULL){
        int sum = curr->data + carry;
        curr->data = sum%10;
        carry = sum/10;
        previous = curr;
        curr = curr->next;
    }
    if(carry > 0){
        Node* newNode = new Node(carry);
        previous->next = newNode;
    }
    return reverse(reverseNumber);
}

int main(){
    Node *head = takeinput();
    head = NextLargeNumber(head);
    print(head);
}