#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/**
 *  BinaryTreeNode
 */
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
//print tree 
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    if(root->left != NULL){
        cout << "L - " << root->left->data <<" , ";
    }
    if(root->right != NULL){
        cout << "R - " << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
//take input
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData ;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}
//basic binary tree use
void problem1(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(3);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(2);
    root->left = node1;
    root->right = node2;
    printTree(root);

    //take input : 1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 7 -1 -1
    BinaryTreeNode<int>* root1 = takeInput();
    printTree(root1);
}

/**
 *  take input and print level wise
 */
BinaryTreeNode<int>* takeInputLevelOrder(){
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
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        pendingNodes.pop();
        cout << f->data << ":";
        if(f->left != NULL){
            cout << "L:" << f->left->data<< ",";
            pendingNodes.push(f->left);
        }else {
            cout << "L:-1,";
        }
        if(f->right != NULL){
            cout << "R:" << f->right->data;
            pendingNodes.push(f->right);
        }else {
            cout << "R:-1";
        }
        cout << endl;
    }
}
void problem2(){
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelOrder();
    printLevelWise(root);
}

/**
 *  Count number of Nodes
 */
int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
void problem3(){
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelOrder();
    cout << countNodes(root) << endl;
}

/**
 *  Find a node
 *  -   For a given Binary Tree of type integer and a number X, find 
 *      whether a node exists in the tree with data X or not.
 */
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool ifPresentLeft = isNodePresent(root->left, x);
    bool ifPresentRight = isNodePresent(root->right, x);
    return ifPresentLeft || ifPresentRight;
}
void assignment1(){
     BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}

/**
 *  Height of Binary Tree
 *  -   For a given Binary Tree of integers, find and return the height of the tree.
 */ 
int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left > right){
        return left+1;
    } else {
        return right+1;
    }
}
void assignment2(){
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root);
}

/**
 *  Mirror
 *  -   For a given Binary Tree of type integer, update it with its 
 *      corresponding mirror image.
 */
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void assignment3(){
    BinaryTreeNode<int> *root = takeInput();
    mirrorBinaryTree(root);
    printLevelWise(root);
}

/**
 *  Tree Traversals
 *  -   Print PreOrder, PostOrder , InOrder
 */
void preOrder(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void inOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void assignment4(){
    //8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInput();
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
}

/**
 *  Construct Tree from Preorder and Inorder
 *  -   For a given preorder and inorder traversal of a Binary Tree of type 
 *      integer stored in an array/list, create the binary tree using the 
 *      given two arrays/lists. You just need to construct the tree and return 
 *      the root.
 */
BinaryTreeNode<int>* buildTreeRecursive(int *preOrder, int *inOrder, int preStart, 
                                        int preEnd, int inStart, int inEnd){
    if(preStart > preEnd){
        return 0;
    }
    int rootData = preOrder[preStart];
    int lPreStart = preStart+1;
    int lPreEnd;
    int lInStart=inStart;
    int lInEnd;
    int rPreStart;
    int rPreEnd = preEnd;
    int rInStart;
    int rInEnd = inEnd;
    for(int i=inStart ; i<=inEnd; i++){
        if(inOrder[i] == rootData){
            lInEnd = i-1;
            lPreEnd = lPreStart + lInEnd - lInStart;
            rPreStart = lPreEnd + 1;
            rInStart = i+1;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftSubTree = buildTreeRecursive(preOrder, inOrder, lPreStart, lPreEnd, lInStart, lInEnd);
    BinaryTreeNode<int>* rightSubTree = buildTreeRecursive(preOrder, inOrder, rPreStart, rPreEnd, rInStart, rInEnd);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTreeRecursive(preorder, inorder, 0, preLength-1, 0, inLength-1);
}

//Approach 2
BinaryTreeNode<int>* builTreeRecApp2(int *preOrder, int *inOrder, int start, int end){
    if(start > end){
        return 0;
    }
    int rootData = preOrder[start];
    int index=-1;
    for(int i=start ; i<=end; i++){
        if(inOrder[i] == rootData){
            index = i;
            break;
        }
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = builTreeRecApp2(preOrder, inOrder,  start, index-1);
    root->right = builTreeRecApp2(preOrder, inOrder, index+1, end);
    return root;
}
void assignment5(){
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    //BinaryTreeNode<int>* root = builTreeRecApp2(pre, in, 0, size-1);
    printLevelWise(root);
}

/**
 *  Construct Tree from Postorder and Inorder
 *  -   For a given postorder and inorder traversal of a Binary Tree of type integer 
 *      stored in an array/list, create the binary tree using the given two arrays/lists. 
 *      You just need to construct the tree and return the root.
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
void assignment6(){
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelWise(root);
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
void problem4(){
    BinaryTreeNode<int>* root = takeInputLevelOrder();
    cout << diameterOfTree(root) << endl;

    pair<int, int> r = heightDiameterOfTree(root);
    cout << "Height : " << r.first << endl;
    cout << "Diameter : " << r.second << endl;
}

/**
 *  Min and Max of Binary Tree
 *  -   For a given a Binary Tree of type integer, find and return the 
 *      minimum and the maximum data values.
 *  -   Return the output as an object of Pair class, which is already created.
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
void assignment7(){
    BinaryTreeNode<int>* root = takeInputLevelOrder();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}

int main() {
    //binary tree basic usage
    //problem1();

    //level order take input and print
    //problem2();

    //count nnumber of nodes
    //problem3();

    //Find a node
    //assignment1();

    //Height of Binary Tree
    //assignment2();

    //Mirror
    //assignment3();

    //Print PreOrder, PostOrder , InOrder tree
    //assignment4();

    //Construct Tree from Preorder and Inorder
    //assignment5();

    //Construct Tree from Postorder and Inorder
    //assignment6();

    //Diameter of Tree
    //problem4();

    //Min and Max of Binary Tree
    assignment7();

    return 0;
}