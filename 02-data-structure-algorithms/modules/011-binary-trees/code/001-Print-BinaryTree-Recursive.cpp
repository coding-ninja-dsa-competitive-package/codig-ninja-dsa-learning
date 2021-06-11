#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/**
 *  BinaryTreeNode
 */
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
//print tree 
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    if(root->left != NULL){
        cout << "L - " << root->left->data <<" , ";
    }
    if(root->right != NULL){
        cout << "R - " << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
//take input
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData ;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

//basic binary tree use
int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(2);
    root->left = node1;
    root->right = node2;
    printTree(root);

    //take input : 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1
    BinaryTreeNode<int>* root1 = takeInput();
    printTree(root1);

    return 0;
}