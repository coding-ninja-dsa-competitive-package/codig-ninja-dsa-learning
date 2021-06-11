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
 *  Largest BST
 *  -   Given a Binary tree, find the largest BST subtree. That is, 
 *      you need to find the BST with maximum height in the given 
 *      binary tree. You have to return the height of largest BST.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *  Output format:
 *      The first and only line of output contains the height of the largest BST.
 *  
 *  Constraints:
 * 
 *  Time Limit: 1 second
 *      
 *  Sample Input 1:
 *      5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output 1:
 *      2
 */
#include<climits>
class ReturnObject{
  	public:
    	int minimum;
    	int maximum;
    	bool isBST;
    	int heightMaxSubTree;
};

ReturnObject largestSubTreeHelper(BinaryTreeNode<int>* root){
    if(root == NULL){
        ReturnObject res;
        res.minimum = INT_MAX;
        res.maximum = INT_MIN;
        res.isBST = true;
        res.heightMaxSubTree = 0;
        return res;
    }
    ReturnObject left = largestSubTreeHelper(root->left);
    ReturnObject right = largestSubTreeHelper(root->right);
    ReturnObject res;
    res.minimum = min(root->data, min(left.minimum, right.minimum));
    res.maximum = max(root->data, max(left.maximum, right.maximum));
    res.isBST = left.isBST && right.isBST && root->data > left.maximum 
        								  && root->data <= right.minimum;
	if(res.isBST){
        res.heightMaxSubTree = max(left.heightMaxSubTree, right.heightMaxSubTree) + 1;
    } else {
        res.heightMaxSubTree = max(left.heightMaxSubTree, right.heightMaxSubTree);
    }
    return res;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    ReturnObject res = largestSubTreeHelper(root);
    return res.heightMaxSubTree;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;

    return 0;
}