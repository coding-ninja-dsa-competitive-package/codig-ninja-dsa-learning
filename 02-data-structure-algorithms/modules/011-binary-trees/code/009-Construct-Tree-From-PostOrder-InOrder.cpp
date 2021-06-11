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
 *  Construct Tree from Postorder and Inorder
 *  -   For a given postorder and inorder traversal of a Binary Tree of type integer 
 *      stored in an array/list, create the binary tree using the given two arrays/lists. 
 *      You just need to construct the tree and return the root.
 * 
 *  Input Format:
 *      The first line of input contains an integer N denoting the size of 
 *      the list/array. It can also be said that N is the total number of 
 *      nodes the binary tree would have.
 *      The second line of input contains N integers, all separated by a single 
 *      space. It represents the preorder-traversal of the binary tree.
 *      The third line of input contains N integers, all separated by a single 
 *      space. It represents the inorder-traversal of the binary tree.
 *  Output Format:
 *      The given input tree will be printed in a level order fashion where 
 *      each level will be printed on a new line. Elements on every level will 
 *      be printed in a linear fashion. A single space will separate them.
 * 
 *  Constraints:
 *      1 <= N <= 10^4
 *      Where N is the total number of nodes in the binary tree.
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1:
 *      7
 *      4 5 2 6 7 3 1 
 *      4 2 5 1 6 3 7 
 *  Sample Output 1:
 *      1 
 *      2 3 
 *      4 5 6 7 
 * 
 *  Sample Input 2:
 *      6
 *      2 9 3 6 10 5 
 *      2 6 3 9 5 10 
 *  Sample Output 2:
 *      5 
 *      6 10 
 *      2 3 
 *      9 
 */
BinaryTreeNode<int>* buildTreeRecursive(int *postOrder, int*inOrder, int postStart, int postEnd, 
                                        int inStart, int inEnd){
    if(inStart > inEnd){
        return NULL;
    }
    int rootData = postOrder[postEnd];
    int rootIndex = 0;
    for(int i=inStart; i<=inEnd; i++){
        if(inOrder[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int lPostStart = postStart;
    int lInStart = inStart;
    int lInEnd = rootIndex-1;
    int lPostEnd = lPostStart+lInEnd-lInStart;
    int rPostStart = lPostEnd+1;
    int rPostEnd = postEnd-1;
    int rInStart = rootIndex+1;
    int rInEnd = inEnd;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftSubTree = buildTreeRecursive(postOrder, inOrder, lPostStart,
                                                        lPostEnd, lInStart, lInEnd);
    BinaryTreeNode<int>* rightSubTree = buildTreeRecursive(postOrder, inOrder, rPostStart,
                                                          rPostEnd, rInStart, rInEnd);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeRecursive(postorder, inorder, 0, postLength-1, 0, inLength-1);
}

int main(){
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);

    return 0;
}