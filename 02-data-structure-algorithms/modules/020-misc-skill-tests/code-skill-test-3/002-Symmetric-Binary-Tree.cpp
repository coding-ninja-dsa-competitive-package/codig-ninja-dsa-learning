#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
		q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/**
 *  Symmetric Binary Tree
 *  -   Given a binary tree, check whether it is symmetric around its center at 
 *      every level. That means, return true if the given binary tree and its 
 *      mirror is exactly same. Otherwise return false.
 *  
 *  Input Format :
 *      Nodes in level order form (separated by space). If any node does not 
 *      have left or right child, take -1 in its place. 
 *  Output Format :
 *      Return true or false.
 *  
 *  Constraints :
 *      1 <= Number of Nodes <= 10^5
 *  
 *  Sample Input 1 :
 *      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 1 :
 *      false
 * 
 *  Sample Input 2 :
 *      1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 2 :
 *      true
 *  
 *  Sample Input 3 :
 *      1 2 2 -1 3 -1 3 -1 -1 -1 -1
 *  Sample Output 3 :
 *      false
 */
bool isSymmetric(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if (left == NULL || right == NULL){
        return left==NULL && right==NULL;
    }
    int ans1 = left->data == right->data;
    int leftAns = isSymmetric(left->left, right->right);
    int rightAns = isSymmetric(left->right, right->left);
    return ans1 && leftAns && rightAns;
}
bool isSymmetric(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return true;
    }
    return isSymmetric(root->left, root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    bool b = isSymmetric(root);
    if(b) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}