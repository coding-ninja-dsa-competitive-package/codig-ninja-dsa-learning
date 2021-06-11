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
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

/**
 *  Remove Leaf nodes
 *  -   Given a binary tree, remove all leaf nodes from it. Leaf nodes are 
 *      those nodes, which don't have any children.
 * 
 *  Note:
 *      1.  Root will also be a leaf node if it doesn't have left and right child. 
 *      2.  You don't need to print the tree, just remove all leaf nodes and 
 *          return the updated root.
 * 
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have a left or right child, take -1 in 
 *      its place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *  Output Format:
 *      The updated binary tree, after removing leaf nodes, is printed level 
 *      wise. Each level is printed in new line.
 * 
 *  Constraints
 *      Time Limit: 1 second
 *  
 * Sample Input 1:
 *      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 1:
 *      8
 *      3 10
 *      6 14     
 */
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    BinaryTreeNode<int>* leftSubTree = removeLeafNodes(root->left);
    BinaryTreeNode<int>* rightSubTree = removeLeafNodes(root->right);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);
}