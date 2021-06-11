#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) 
            delete left;
        if (right) 
            delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void preOrderPrint(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
 *  BST to Sorted LL
 *  -   Given a BST, convert it into a sorted linked list. You have to 
 *      return the head of LL.
 * 
 *  Input format:
 *      The first and only line of input contains data of the nodes of the 
 *      tree in level order form. The data of the nodes of the tree is separated 
 *      by space. If any node does not have left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right nodes 
 *      exist, therefore, it will not be a part of the data of any node.   
 *  Output Format:
 *      The first and only line of output prints the elements of sorted linked list.
 *  
 *  Constraints:
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *  Sample Output 1:
 *      2 5 6 7 8 10
 */
class Pair{
  	public:
    	Node<int>* head;
    	Node<int>* tail;
    	
    	Pair(){
            this->head = NULL;
            this->tail = NULL;
        }
};
Pair constructLL(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    if(root->left == NULL && root->right == NULL){
        Node<int>* node = new Node<int>(root->data);
        Pair ans;
        ans.head = node;
        ans.tail = node;
        return ans;
    }
    Pair left = constructLL(root->left);
    Pair right = constructLL(root->right);
    Node<int>* node = new Node<int>(root->data);
    Pair ans;
    if(left.tail == NULL){
        ans.head = node;
    }else {
        left.tail->next = node;
        ans.head = left.head;
    }
    node->next = right.head;
    if(right.head == NULL){
        ans.tail = node;
    } else{
        ans.tail = right.tail;
    }
    return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	Pair ans = constructLL(root);
    return ans.head;   
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}