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
 *  Find a node
 *  -   For a given Binary Tree of type integer and a number X, find 
 *      whether a node exists in the tree with data X or not.
 * 
 *  Input Format:
 *      The first and the only line of input will contain the node data, 
 *      all separated by a single space. Since -1 is used as an indication 
 *      whether the left or right node data exist for root, it will not be 
 *      a part of the node data.
 *  Output Format:
 *      The only line of output prints 'true' or 'false'.
 * 
 *  Constraints:
 *      1 <= N <= 10^5
 *      Where N is the total number of nodes in the binary tree.
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 *      7
 *  Sample Output 1:
 *      true
 * 
 *  Sample Input 2:
 *      2 3 4 -1 -1 -1 -1
 *      10
 *  Sample Output 2:
 *      false
 */
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool ifPresentLeft = isNodePresent(root->left, x);
    bool ifPresentRight = isNodePresent(root->right, x);
    return ifPresentLeft || ifPresentRight;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}