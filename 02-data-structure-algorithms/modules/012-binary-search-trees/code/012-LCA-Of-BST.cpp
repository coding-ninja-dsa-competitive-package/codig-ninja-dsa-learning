#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

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
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
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
 *  LCA of BST
 *  -   Given a binary search tree and data of two nodes, find 'LCA' 
 *      (Lowest Common Ancestor) of the given two nodes in the BST.
 * 
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated 
 *      by space. If any node does not have left or right child, take -1 
 *      in its place. Since -1 is used as an indication whether the left 
 *      or right nodes exist, therefore, it will not be a part of the data 
 *      of any node.
 *      The following line of input contains two integers, denoting the value 
 *      of data of two nodes of given BST.
 *  Output Format:
 *      The first and only line of output contains the data associated with 
 *      the lowest common ancestor node.
 * 
 *  Constraints:
 * 
 *  Time Limit: 1 second
 * 
 *  Sample Input 1:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      2 10
 *  Sample Output 1:
 *      8
 * 
 *  Sample Input 2:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      2 6
 *  Sample Output 2:
 *      5
 * 
 *  Sample Input 3:
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *      12 78
 *  Sample Output 3:
 *      -1
 */
int getLCABst(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root == NULL){
        return -1;
    }
    if(root->data == val1 || root->data == val2){
        return root->data;
    }
    
    int lca=-1;
    if(val1 < root->data && val2 < root->data){
        lca = getLCABst(root->left, val1, val2);
    } else if(val1 >= root->data && val2 >= root->data){
        lca = getLCABst(root->right, val1, val2);
    } else{
        lca = root->data;
    }
    return lca;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCABst(root, a, b);
    delete root;

    return 0;
}