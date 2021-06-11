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
 *  Search node in Binary Search Tree
 *  -   Given a BST and an integer k. Find if the integer k is present 
 *      in given BST or not. You have to return true, if node with data 
 *      k is present, return false otherwise.
 *  -   Note: Assume that BST contains all unique elements.
 * 
 *  Input Format:
 *      The first line of input contains data of the nodes of the tree in   
 *      level order form. The data of the nodes of the tree is separated 
 *      by space. If any node does not have left or right child, take -1 
 *      in its place. Since -1 is used as an indication whether the left 
 *      or right nodes exist, therefore, it will not be a part of the data 
 *      of any node.   
 *      The following line of input contains an integer, that denotes the 
 *      value of k.
 *  Output Format:
 *      The first and only line of output contains a boolean value. Print true,
 *      if node with data k is present, print false otherwise. 
 *      
 *  Constraints:
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1 :
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      2
 *  Sample Output 1 :
 *      true
 *  
 *  Sample Input 2 :
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      12
 *  Sample Output 2 :
 *      false
 */
bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if(root == NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }
    if(k < root->data){
        return searchInBST(root->left, k);
    } else {
        return searchInBST(root->right, k);
    }
}
int main(){
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    delete root;

    return 0;
}