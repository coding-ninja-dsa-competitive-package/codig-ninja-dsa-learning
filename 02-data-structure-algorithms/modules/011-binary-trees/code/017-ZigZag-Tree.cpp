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
 *  ZigZag tree
 *  -   Given a binary tree, print the zig zag order. In zigzag order, 
 *      level 1 is printed from left to right, level 2 from right to left 
 *      and so on. This means odd levels should get printed from left to 
 *      right and even level right to left.
 *  
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated 
 *      by space. If any node does not have a left or right child, take -1 
 *      in its place. Since -1 is used as an indication whether the left or 
 *      right nodes exist, therefore, it will not be a part of the data of 
 *      any node.
 *  Output Format:
 *      The binary tree is printed level wise, as described in the task. 
 *      Each level is printed in new line.
 * 
 *  Constraints
 * 
 *  Time Limit: 1 second
 * 
 *  Sample Input :
 *      5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output :
 *      5
 *      10 6    
 *      2 3
 *      9
 */
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    int flag = 1;
    while(!s1.empty() || !s2.empty()){
        if(flag == 0){
            BinaryTreeNode<int>* t = s2.top();
            s2.pop();
            cout << t->data << " ";
            if(t->right != NULL){
                s1.push(t->right);
            }
            if(t->left != NULL){
                s1.push(t->left);
            }
                   
            if(s2.empty()){
                flag = 1;
                cout << endl;
            }
        } else if(flag == 1){
            BinaryTreeNode<int>* t = s1.top();
            s1.pop();
            cout << t->data << " ";
            if(t->left != NULL){
                s2.push(t->left);
            }
            if(t->right != NULL){
                s2.push(t->right);
            }
            
            if(s1.empty()){
                flag = 0;
                cout << endl;
            }
        }
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}