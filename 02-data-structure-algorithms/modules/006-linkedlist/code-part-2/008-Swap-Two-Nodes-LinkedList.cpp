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
 *  Swap two Nodes of LL
 *  -   You have been given a singly linked list of integers along with two 
 *      integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' 
 *      and 'j-th' positions.
 *  Note : Remember, the nodes themselves must be swapped and not the datas.
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first line of each test case or query contains the elements of the 
 *      singly linked list separated by a single space.
 *      The second line of input contains two integer values 'i,' and 'j,' 
 *      respectively. A single space will separate them.
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
 *      0 <= i < M
 *      0 <= j < M
 *  Time Limit: 1sec
 * 
 *  Sample Input 1 :
 *      1
 *      3 4 5 2 6 1 9 -1
 *      3 4
 *  Sample Output 1 :
 *      3 4 5 6 2 1 9 
 *      
 *  Sample Input 2 :
 *      2
 *      10 20 30 40 -1
 *      1 2
 *      70 80 90 25 65 85 90 -1
 *      0 6
 *  Sample Output 2 :
 *      10 30 20 40 
 *      90 80 90 25 65 85 70 
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

int main(){
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