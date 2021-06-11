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
 *  Delete every N nodes
 *  -   You have been given a singly linked list of integers along with two 
 *      integers, 'M,' and 'N.' Traverse the linked list such that you retain 
 *      the 'M' nodes, then delete the next 'N' nodes. Continue the same until 
 *      the end of the linked list.
 *  -   To put it in other words, in the given linked list, you need to delete 
 *      N nodes after every M nodes.
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      The first and the only line of each test case or query contains the 
 *      elements(in ascending order) of the singly linked list separated by 
 *      a single space.
 *      The second line of input contains two integer values 'M,' and 'N,' 
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
 *      0 <= P <= 10^5
 *      Where P is the size of the singly linked list.
 *      0 <= M <= 10^5
 *      0 <= N <= 10^5 
 *  Time Limit: 1sec
 * 
 *  Sample Input 1 :
 *      1
 *      1 2 3 4 5 6 7 8 -1
 *      2 2
 *  Sample Output 1 :
 *      1 2 5 6
 *  
 *  Sample Input 2 :
 *      2
 *      10 20 30 40 50 60 -1
 *      0 1
 *      1 2 3 4 5 6 7 8 -1
 *      2 3
 *  Sample Output 2 :
 *      1 2 6 7
 *  Explanation of Sample Input 2 :
 *      For the first query, we delete one node after every zero elements hence 
 *      removing all the items of the list. Therefore, nothing got printed.
 *      For the second query, we delete three nodes after every two nodes, resulting 
 *      in the final list, 1 -> 2 -> 6 -> 7.
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

int main(){
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