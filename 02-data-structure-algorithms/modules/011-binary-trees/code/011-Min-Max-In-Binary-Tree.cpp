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
 *  Min and Max of Binary Tree
 *  -   For a given a Binary Tree of type integer, find and return the 
 *      minimum and the maximum data values.
 *  -   Return the output as an object of Pair class, which is already created.
 * 
 *  Input Format:
 *      The first and the only line of input will contain the node data, all 
 *      separated by a single space. Since -1 is used as an indication whether 
 *      the left or right node data exist for root, it will not be a part of 
 *      the node data.
 *  Output Format:
 *      The only line of output prints two integers denoting the minimum and 
 *      the maximum data values respectively. A single line will separate them both.
 * 
 *  Constraints:
 *      2 <= N <= 10^5
 *      Where N is the total number of nodes in the binary tree.
 *  
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 1:
 *      1 14
 *  
 *  Sample Input 2:
 *      10 20 60 -1 -1 3 50 -1 -1 -1 -1 
 *  Sample Output 2:
 *      3 60
 */
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	if(root == NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int, int> leftSubTree = getMinAndMax(root->left);
    pair<int, int> rightSubTree = getMinAndMax(root->right);
    int minimum = min(root->data, min(leftSubTree.first, rightSubTree.first));
    int maximum = max(root->data, max(leftSubTree.second, rightSubTree.second));
    pair<int, int> res;
    res.first = minimum;
    res.second = maximum;
    return res;   
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}