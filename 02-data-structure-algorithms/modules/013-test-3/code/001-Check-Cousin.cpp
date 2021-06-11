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
 *  Check cousins
 *  -   Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether 
 *      the two nodes are cousins of each other or not. Two nodes are said to be 
 *      cousins of each other if they are at same level of the Binary Tree and 
 *      have different parents.
 *  -   Do it in O(n).
 * 
 *  Input format :
 *      Line 1 : Nodes in level order form (separated by space). If any node 
 *      does not have left or right child, take -1 in its place
 *      Line 2 : integer value of p 
 *      Line 3 : Integer value of q
 *  Output format :
 *      true or false
 *  
 *  Constraints :
 *      1 <= N <= 10^5
 *  
 *  Sample Input :
 *      5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
 *      2
 *      4
 *  Sample Output :
 *      true
 */

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
   	if(root==NULL){
        return false;
    }
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
	bool foundP=false, foundQ=false;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        if(f == NULL){
            if(foundP && foundQ){
                return true;
            } else if((foundP && !foundQ) || (foundQ && !foundP)){
                return false;
            }
            pendingNodes.pop();
            if(!pendingNodes.empty()){
                pendingNodes.push(NULL);
            }
        } else {
            pendingNodes.pop();
            if(f->data == p){
                foundP=true;
            } else if(f->data == q){
                foundQ=true;
            }
            if(f->left && f->right){
                if(f->left->data == p && f->right->data == q ){
                	return false;
                } else if(f->left->data == q && f->right->data == p){
                    return false;
                }
            }
            
            if(f->left != NULL){
                pendingNodes.push(f->left);
            }
            if(f->right != NULL){
                pendingNodes.push(f->right);
            }
        }
    }
	return false;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

    return 0;
}