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
 *  Sum Of Nodes
 *  -   For a given Binary Tree of integers, find and return the sum of all the nodes data.
 * 
 *   Input Format:
 *      The first and the only line of input will contain the nodes data, all 
 *      separated by a single space. Since -1 is used as an indication whether 
 *      the left or right node data exist for root, it will not be a part of the 
 *      node data.
 *  Output Format:
 *      The first and the only line of output prints the sum of all the nodes 
 *      data present in the binary tree.
 *  
 *  Constraints:
 *      1 <= N <= 10^6  
 *      Where N is the total number of nodes in the binary tree.
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      2 3 4 6 -1 -1 -1 -1 -1
 *  Sample Output 1:
 *      15
 * 
 *  Sample Input 2:
 *      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 2:
 *      28
 */
int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int rootData = root->data;
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    return rootData + leftSum + rightSum;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);
}