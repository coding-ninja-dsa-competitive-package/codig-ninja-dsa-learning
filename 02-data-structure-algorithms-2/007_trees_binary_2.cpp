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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


/**
 *  Sum Of Nodes
 *  -   For a given Binary Tree of integers, find and return the sum of all the nodes data.
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
void assignment1(){
    BinaryTreeNode<int>* root = takeInput();
    cout << getSum(root);
}

/**
 *  Check Balanced
 *  -   Given a binary tree, check if it is balanced. Return true if given 
 *      binary tree is balanced, false otherwise.
 */ 
bool isBalanced(BinaryTreeNode<int> *root) {
	if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }
    if(root->left == NULL || root->right == NULL){
        return false;
    }
    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);
    return isLeftBalanced && isRightBalanced;
}
void assignment2(){
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}

/**
 *  Level order traversal
 *  -   For a given a Binary Tree of type integer, print it in a level order 
 *      fashion where each level will be printed on a new line. Elements on 
 *      every level will be printed in a linear fashion and a single space 
 *      will separate them.
 */
void printLevelWise(BinaryTreeNode<int> *root) {
   	if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else {
         	q.pop();   
            cout << f->data << " ";
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
        }
    }
}
void assignment3(){
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}

/**
 *  Remove Leaf nodes
 *  -   Given a binary tree, remove all leaf nodes from it. Leaf nodes are 
 *      those nodes, which don't have any children.
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
void assignment4(){
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelWise(root);
}

/**
 *  Level wise linkedlist
 *  -   Given a binary tree, write code to create a separate linked list 
 *      for each level. You need to return the array which contains head 
 *      of each level linked list.
 */
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
vector<Node<int>*> result;
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return result;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front(); 
        if(f == NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            Node<int>* root = new Node<int>(f->data);
            q.pop();
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
            Node<int>* curr = root;
            f = q.front();
            while(f != NULL){
                q.pop();
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
                Node<int>* newNode = new Node<int>(f->data);
                curr->next = newNode;
                curr = curr->next;
                f = q.front();
            }
            result.push_back(root);
        } 
    }
    return result;
}
void assignment5(){
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}

/**
 *  ZigZag tree
 *  -   Given a binary tree, print the zig zag order. In zigzag order, 
 *      level 1 is printed from left to right, level 2 from right to left 
 *      and so on. This means odd levels should get printed from left to 
 *      right and even level right to left.
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
void assignment6(){
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}

/**
 *  Nodes without sibling
 *  -   For a given Binary Tree of type integer, print all the nodes without any siblings.
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
void assignment7(){
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}

int main() {
    //Sum Of Nodes
    //assignment1();

    //Check Balanced
    //assignment2();

    //Level order traversal
    //assignment3();

    //Remove Leaf nodes
    //assignment4();

    //Level wise linkedlist
    //assignment5();

    //ZigZag tree
    //assignment6();

    //Nodes without sibling
    //assignment7();

    return 0;
}