#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  Node Class
 */
class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1){
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
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
 *  Find a Node in Linked List
 *  -   You have been given a singly linked list of integers. Write a 
 *      function that returns the index/position of an integer data 
 *      denoted by 'N' (if it exists). Return -1 otherwise.
 *  -   Assume that the Indexing for the singly linked list always starts from 0.
 */
int findNode(Node *head, int n){
    if(head == NULL){
        return -1;
    }
    if(head->data == n){
        return 0;
    }
    int ans = findNode(head->next, n);
    if(ans == -1){
        return -1;
    }
    return 1+ans;
}
void assignment1(){
    Node *head = takeinput();
    int val;
    cin >> val;
    cout << findNode(head, val) << endl;
}

/**
 *  AppendLastNToFirst
 *  -   You have been given a singly linked list of integers along with 
 *      an integer 'N'. Write a function to append the last 'N' nodes 
 *      towards the front of the singly linked list and returns the new 
 *      head to the list.
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
void assignment2(){
    Node *head = takeinput();
    int n;
    cin >> n;
    head = appendLastNToFirst(head, n);
    print(head);
}

/**
 *  Eliminate duplicates from LL
 *  -   You have been given a singly linked list of integers where the 
 *      elements are sorted in ascending order. Write a function that 
 *      removes the consecutive duplicate values such that the given 
 *      list only contains unique elements and returns the head to the 
 *      updated list.
 */
Node *removeDuplicates(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ans = removeDuplicates(head->next);
    if(head->data == ans->data){
        return ans;
    }
    head->next = ans;
    return head;
}
void assignment3(){
    Node *head = takeinput();
    head = removeDuplicates(head);
    print(head);
}

/**
 *  Print Reverse LinkedList
 *  -   You have been given a singly linked list of integers. Write a 
 *      function to print the list in a reverse order.
 *      To explain it further, you need to start printing the data from 
 *      the tail and move towards the head of the list, printing the head 
 *      data at the end.
 */ 
void printReverse(Node *head){
    if(head==NULL){
        cout << "";
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}
void assignment4(){
    Node *head = takeinput();
    printReverse(head);
    cout << endl;
}

/**
 *  Palindrome LinkedList
 *  -   You have been given a head to a singly linked list of integers. 
 *      Write a function check to whether the list given is a 'Palindrome' 
 *      or not.
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

bool isPalindrome(Node *head)
{
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
void assignment5(){
    Node *head = takeinput();
    bool ans = isPalindrome(head);

    if (ans) cout << "true";
    else cout << "false";

    cout << endl;
}

/**
 *  Code: Midpoint of LL
 *  -   For a given singly linked list of integers, find and return the 
 *      node present at the middle of the list.
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
void assignment6(){
    Node *head = takeinput();
    Node *mid = midPoint(head);
    if (mid != NULL){
        cout << mid->data;
    }
    cout << endl;
}

/**
 *  Merge Two Sorted LL
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
void assignment7(){
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
    print(head3);
}

/**
 *  Merge Sort
 */
Node* getMiddle(Node *head){
    Node* slow=head;
    Node* fast=head;
    Node* previous=NULL;
    while(fast != NULL && fast->next != NULL){
        previous = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return previous;
}
Node* merge(Node* head1, Node* head2){
    Node* result = new Node(0);
    Node* curr = result;
    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        } else {
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
Node *mergeSort(Node *head){
	if(head == NULL || head->next == NULL){
        return head;
    }
	Node* previousToMiddle = getMiddle(head);
    Node* mid = previousToMiddle->next;
    previousToMiddle->next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}
void assignment8(){
    Node *head = takeinput();
    head = mergeSort(head);
    print(head);
}

/**
 *  Reverse LL (Recursive)
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
void assignment9(){
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

int main() {
    //Find a Node in Linked List
    //assignment1();

    //AppendLastNToFirst
    //assignment2();

    //Eliminate duplicates from LL
    //assignment3();

    //Print Reverse LinkedList
    //assignment4();

    //Palindrome LinkedList
    //assignment5();

    //Code: Midpoint of LL
    //assignment6();

    //Merge Two Sorted LL
    //assignment7();

    //Merge Sort
    //assignment8();

    //Reverse LL (Recursive)
    assignment9();

    return 0;
}