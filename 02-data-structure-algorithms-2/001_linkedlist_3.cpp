#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  Node class
 */
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
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
 *  Find a node in LL (recursive)
 *  -   Given a singly linked list of integers and an integer n, find and 
 *      return the index for the first occurrence of 'n' in the linked list. 
 *      -1 otherwise.
 */
int findNodeRec(Node *head, int n){
	if(head == NULL){
        return -1;
    }
    if(head->data == n){
        return 0;
    }
    int ans = findNodeRec(head->next, n);
    if(ans == -1){
        return -1;
    }
    return 1+ans;
}
void assignment1(){
    int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}

/**
 *  Even after Odd LinkedList
 *  -   For a given singly linked list of integers, arrange the elements 
 *      such that all the even numbers are placed after the odd numbers. 
 *      The relative order of the odd and even terms should remain unchanged.
 */
Node *evenAfterOdd(Node *head){
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
void assignment2(){
    int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
}

/**
 *  Delete every N nodes
 *  -   You have been given a singly linked list of integers along with 
 *      two integers, 'M,' and 'N.' Traverse the linked list such that you 
 *      retain the 'M' nodes, then delete the next 'N' nodes. Continue the 
 *      same until the end of the linked list.
 *  -   To put it in other words, in the given linked list, you need to 
 *      delete N nodes after every M nodes.
 */
Node *skipMdeleteN(Node *head, int M, int N){
	if(head == NULL){
        return head;
    }
    Node*curr = head;
    Node*previous=NULL;
    while(curr != NULL){
        int i=0;
        while(curr != NULL && i<M){
            previous = curr;
            curr = curr->next;
            i++;
        }
        i=0;
        while(curr != NULL && i<N){
            Node* temp = curr;
            curr = curr->next;
            delete temp;
            i++;
        }
        if(previous != NULL){
            previous->next = curr;
        } else {
            head = curr;
        }
    }
    return head;
}
void assignment3(){
    int t;
	cin >> t;
	while (t--){
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
}

/**
 *  Swap two Nodes of LL
 *  -   You have been given a singly linked list of integers along with 
 *      two integers, 'i,' and 'j.' Swap the nodes that are present at 
 *      the 'i-th' and 'j-th' positions.
 */
Node *swapNodes(Node *head, int m, int n){
    if(m==n || head == NULL || head->next == NULL){
        return head;
    }
    //choose i as smaller and j as greater
    int i = (m<n) ? m : n;
    int j = (i==m) ? n : m;
    
	Node* previous1= NULL;
    Node* previous2=NULL;
    Node* curr1=head;
    Node* curr2=head;
    int a=0;
    while(curr1 != NULL && a<i){
        previous1 = curr1;
        curr1 = curr1->next;
        a++;
    }
    a=0;
    while(curr2 != NULL && a<j){
        previous2 = curr2;
        curr2 = curr2->next;
        a++;
    }

    // if i==0 and |i-j| == 1 i.e. one index is zero and are adjacent elements
    if(i==0 && (j-i) == 1){
        curr1->next = curr2->next;
        curr2->next = previous2;
        head = curr2;
    // if |i-j| == 1 i.e. are adjacent elements
    } else if((j-i) == 1){
        previous1->next = curr2;
        curr1->next = curr2->next;
        curr2->next = previous2;
    // if i==0 i.e. one index is zero
    } else if (i==0){
        previous2->next = curr1;
        Node* temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
        head = curr2;
    // else for any other normal case.
    } else{
        previous1->next = curr2;
        previous2->next = curr1;
        Node* temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
    }
    return head;
}
void assignment4(){
    int t;
	cin >> t;
	while (t--){
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
}

/**
 *  kReverse
 *  -   Given a singly linked list of integers, reverse the nodes of the 
 *      linked list 'k' at a time and return its modified list.
 *  -   'k' is a positive integer and is less than or equal to the length 
 *      of the linked list. If the number of nodes is not a multiple of 'k,' 
 *      then left-out nodes, in the end, should be reversed as well.
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
void assignment5(){
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

/**
 *  Bubble Sort (Iterative) LinkedList
 *  -   Given a singly linked list of integers, sort it using 'Bubble Sort.'
 */
int length(Node* head){
    int count=0;
    Node* curr = head;
    while(curr != NULL){
        curr=curr->next;
        count++;
    }
    return count;
}
Node *bubbleSort(Node *head){
    int len = length(head);
    for(int i=0; i<len; i++){
        Node* previous=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr != NULL && curr->next != NULL){
            next = curr->next;
            if(curr->data <= next->data){
                previous = curr;
                curr = curr->next;
            } else {
                if(previous == NULL){
                    head = next;
                }else {
                    previous->next = next;
                }
                curr->next=next->next;
                next->next=curr;
                if(previous == NULL){
                    previous = head;
                }else {
                    previous = previous->next;
                }
            }
        }
    }
    return head;
}
void assignment6(){
    Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}

int main() {
    
    //Find a node in LL (recursive)
    //assignment1();

    //Even after Odd LinkedList
    //assignment2();

    // Delete every N nodes
    //assignment3();

    //Swap two Nodes of LL
    //assignment4();

    //kReverse
    //assignment5();

    //Bubble Sort (Iterative) LinkedList
    //assignment6();

    return 0;
}