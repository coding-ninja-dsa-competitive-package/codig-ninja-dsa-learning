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
 *  Diameter of Binary Tree
 */
//Approach 1 - O(n*h) -> h can be logn or n^2 depending on how tree is structured.
int heightOfTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}
int diameterOfTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans1 = heightOfTree(root->left) + heightOfTree(root->right);
    int ans2 = diameterOfTree(root->left);
    int ans3 = diameterOfTree(root->right);
    return max(ans1 , max(ans2, ans3));
}
//optimized approach - O(n)
pair<int, int> heightDiameterOfTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftSubTree = heightDiameterOfTree(root->left);
    pair<int, int> rightSubTree = heightDiameterOfTree(root->right);

    int lh = leftSubTree.first;
    int ld = leftSubTree.second;
    int rh = rightSubTree.first;
    int rd = rightSubTree.second;

    int h = 1 + max(lh, rh);
    int d = max(lh+rh , max(ld, rd));

    pair<int, int> res;
    res.first = h;
    res.second = d;
    return res;
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout << diameterOfTree(root) << endl;

    pair<int, int> r = heightDiameterOfTree(root);
    cout << "Height : " << r.first << endl;
    cout << "Diameter : " << r.second << endl;
}