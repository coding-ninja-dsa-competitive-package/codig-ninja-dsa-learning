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
 *  Check if a Binary Tree is BST
 *  -   Given a binary tree with N number of nodes, check if that 
 *      input tree is BST (Binary Search Tree). If yes, return true, 
 *      return false otherwise.
 *      Note: Duplicate elements should be kept in the right subtree.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have a left or right child, take -1 in 
 *      its place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *  Output format :
 *      The first and only line of output contains either true or false.
 * 
 *  Constraints :
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1 :
 *      3 1 5 -1 2 -1 -1 -1 -1
 *  Sample Output 1 :
 *      true
 *  
 *  Sample Input 2 :
 *      5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
 *  Sample Output 2 :
 *      false
 */

//Approach 1 - O(n*h) i.e. O(nlogn) if tree balanced , O(n^2) if tree height is O(n)
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool ans = (root->data > leftMax) && (root->data <= rightMin) 
                    && isBST(root->left) && isBST(root->right);
    return ans;
}

//Approach 2 - O(n) - one pass solution
class HelperBST{
    public:
        int min;
        int max;
        bool isBST;
};
HelperBST isBST2Helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        HelperBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    HelperBST left = isBST2Helper(root->left);
    HelperBST right = isBST2Helper(root->right);
    HelperBST ans;
    ans.min = min(root->data, min(left.min, right.min));
    ans.max = max(root->data, max(left.max, right.max));
    ans.isBST = (root->data > left.max) && (root->data <= right.min) && left.isBST && right.isBST;
    return ans;
}
bool isBST2(BinaryTreeNode<int> *root) {
	HelperBST ans = isBST2Helper(root);
    return ans.isBST;
}

//Approach 3 - O(n)
bool isBST3Helper(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool left = isBST3Helper(root->left, min, root->data-1);
    bool right = isBST3Helper(root->right, root->data, max);
    return left && right;
}
bool isBST3(BinaryTreeNode<int> *root) {
	bool ans = isBST3Helper(root);
    return ans;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
    cout << (isBST2(root) ? "true" : "false");
    cout << (isBST3(root) ? "true" : "false");

    return 0;
}