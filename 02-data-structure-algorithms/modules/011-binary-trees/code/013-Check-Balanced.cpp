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

template<typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << f->data << " : ";
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftChild);
            f->left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child of " << f->data << " : ";
        int rightChild;
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightChild);
            f->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

/**
 *  Check Balanced
 *  -   Given a binary tree, check if it is balanced. Return true if given 
 *      binary tree is balanced, false otherwise.
 * 
 *  Balanced Binary Tree:
 *      A empty binary tree or binary tree with zero nodes is always balanced. 
 *      For a non empty binary tree to be balanced, following conditions must be met:
 *      1.  The left and right subtrees must be balanced.
 *      2.  |hL - hR| <= 1, where hL is the height or depth of left subtree and 
 *          hR is the height or depth of right subtree.    
 * 
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in level 
 *      order form. The data of the nodes of the tree is separated by space. If 
 *      any node does not have a left or right child, take -1 in its place. Since 
 *      -1 is used as an indication whether the left or right nodes exist, therefore, 
 *      it will not be a part of the data of any node.
 *  Output format
 *      The first and only line of output contains true or false.
 * 
 *  Constraints
 *  Time Limit: 1 second
 *  
 *  Sample Input 1 :
 *      5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output 1 :
 *      false
 * 
 *  Sample Input 2 :
 *      1 2 3 -1 -1 -1 -1
 *  Sample Output 2 :
 *      true
 */ 
bool isBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }
    if(root->left == NULL || root->right == NULL){
        return false;
    }
    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);
    return isLeftBalanced && isRightBalanced;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");

    return 0;
}