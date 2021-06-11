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
 *  Tree Traversals
 *  -   Print PreOrder
 *  
 *  Input Format:
 *      The first and the only line of input will contain the nodes data, all 
 *      separated by a single space. Since -1 is used as an indication whether the 
 *      left or right node data exist for root, it will not be a part of the node data.
 *  Output Format:
 *      The only line of output prints the pre-order traversal of the given binary tree.
 *      
 *  Constraints:
 *      1 <= N <= 10^6
 *      Where N is the total number of nodes in the binary tree.
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Ouptut 1:
 *      5 6 2 3 9 10 
 *  
 *  Sample Input 2:
 *      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Ouptut 2:
 *      1 2 4 5 3 6 7 
 */
void preOrder(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main(){
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInput();
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
}