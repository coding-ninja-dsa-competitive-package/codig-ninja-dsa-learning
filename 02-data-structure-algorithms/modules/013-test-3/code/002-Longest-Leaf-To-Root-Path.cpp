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

#include<BinaryTreeNode.h>

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/**
 *  Longest Leaf to root path
 *  -   Given a binary tree, return the longest path from leaf to root. 
 *      Longest means, a path which contain maximum number of nodes from 
 *      leaf to root.
 * 
 *  Sample Input :
 *       5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output :
 *      9 
 *      3 
 *      6 
 *      5 
 */
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	vector<int>* res = new vector<int>();
    if(root==NULL){
        return res;
    }
	if(root->left == NULL && root->right == NULL){
        res->push_back(root->data);
        return res;
    }
    vector<int>* left = longestPath(root->left);
    vector<int>* right = longestPath(root->right);
    if(left->size() > right->size()){
        left->push_back(root->data);
        return left;
    } else{
        right->push_back(root->data);
        return right;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }

    return 0;
}