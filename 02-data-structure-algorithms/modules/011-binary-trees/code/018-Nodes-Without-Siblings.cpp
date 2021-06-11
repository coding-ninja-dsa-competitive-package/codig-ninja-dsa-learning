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
 *  Nodes without sibling
 *  -   For a given Binary Tree of type integer, print all the nodes without any siblings.
 * 
 *  Input Format:
 *      The first and the only line of input will contain the node data, all 
 *      separated by a single space. Since -1 is used as an indication whether 
 *      the left or right node data exist for root, it will not be a part of 
 *      the node data.
 *  Output Format:
 *      The only line of output prints the node data in a top to down fashion 
 *      with reference to the root. 
 *      Node data in the left subtree will be printed first and then the right subtree.
 *      A single space will separate them all.
 *  
 *  Constraints:
 *      1 <= N <= 10^5
 *      Where N is the total number of nodes in the binary tree.
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1:
 *      5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output 1:
 *      9       
 * 
 *  Sample Input 2:
 *      2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 2:
 *      6 7  
 */
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    if((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL)){
        if(root->left != NULL){
            cout << root->left->data << " ";
        } else if(root->right != NULL){
            cout << root->right->data << " ";
        }
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}