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
 *  Mirror
 *  -   For a given Binary Tree of type integer, update it with its 
 *      corresponding mirror image.
 *  
 *  Input Format:
 *      The first and the only line of input will contain the node data, all 
 *      separated by a single space. Since -1 is used as an indication whether the 
 *      left or right node data exist for root, it will not be a part of the node data.
 *  Output Format:
 *      The only line of output prints the mirrored tree in a level-wise order. 
 *      Each level will be printed on a new line. Elements printed at each level 
 *      will be separated by a single line.
 *  
 *  Constraints:
 *      1 <= N <= 10^5
 *      Where N is the total number of nodes in the binary tree.
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 1:
 *      1 
 *      3 2 
 *      7 6 5 4
 *  Sample Input 2:
 *      5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output 2:
 *      5 
 *      6 10 
 *      3 2 
 *      9
 */
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    mirrorBinaryTree(root);
    printLevelATNewLine(root);

    return 0;
}