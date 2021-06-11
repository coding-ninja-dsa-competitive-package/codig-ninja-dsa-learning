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
 *  Print Elements in Range
 *  -   Given a Binary Search Tree and two integers k1 and k2, find and 
 *      print the elements which are in range k1 and k2 (both inclusive).
 *  -   Print the elements in increasing order.
 * 
 *  Input format:   
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *      The following line contains two integers, that denote the value of k1 and k2.
 *  Output Format:  
 *      The first and only line of output prints the elements which are in 
 *      range k1 and k2 (both inclusive). Print the elements in increasing order.
 * 
 *  Constraints:
 *      
 *  Time Limit: 1 second
 *      
 *  Sample Input 1:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      6 10
 *  Sample Output 1:
 *      6 7 8 10
 */
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL){
        return;
    }
    if ( k1 < root->data ){
    	elementsInRangeK1K2(root->left, k1, k2);
    }
   	if ( k1 <= root->data && k2 >= root->data ){
      	cout<<root->data<<" ";
    }
   	if ( k2 > root->data ){
      	elementsInRangeK1K2(root->right, k1, k2);
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);

    return 0;
}