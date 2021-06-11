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
 *  Level order traversal
 *  -   For a given a Binary Tree of type integer, print it in a level order 
 *      fashion where each level will be printed on a new line. Elements on 
 *      every level will be printed in a linear fashion and a single space 
 *      will separate them.
 * 
 *  Input Format:
 *      The first and the only line of input will contain the node data, all 
 *      separated by a single space. Since -1 is used as an indication whether 
 *      the left or right node data exist for root, it will not be a part of 
 *      the node data.
 *  Output Format:
 *      The given input tree will be printed in a level order fashion where 
 *      each level will be printed on a new line. 
 *      Elements on every level will be printed in a linear fashion. A single 
 *      space will separate them.
 *  Constraints:
 *      1 <= N <= 10^5
 *      Where N is the total number of nodes in the binary tree.
 *      
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
 *  Sample Output 1:
 *      10 
 *      20 30 
 *      40 50 60 
 *  
 *  Sample Input 2:
 *      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 *  Sample Output 2:
 *      8 
 *      3 10 
 *      1 6 14 
 *      4 7 13 
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

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}