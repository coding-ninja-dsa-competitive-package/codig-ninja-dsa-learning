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
 *  Binary Search Trees
 *  -   Everything on the left to the node will be less than the node's data.
 *  -   Everything on the right to the node will be greater than the node's data.
 */
template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
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

    ~BinaryTreeNode() {
        if (left) 
            delete left;
        if (right) 
            delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void preOrderPrint(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
 *  Search node in Binary Search Tree
 *  -   Given a BST and an integer k. Find if the integer k is present 
 *      in given BST or not. You have to return true, if node with data 
 *      k is present, return false otherwise.
 *  -   Note: Assume that BST contains all unique elements.
 */
bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if(root == NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }
    if(k < root->data){
        return searchInBST(root->left, k);
    } else {
        return searchInBST(root->right, k);
    }
}
void problem1(){
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    cout << ((searchInBST(root, k)) ? "true" : "false");
    delete root;
}

/**
 *  Print Elements in Range
 *  -   Given a Binary Search Tree and two integers k1 and k2, find and 
 *      print the elements which are in range k1 and k2 (both inclusive).
 *  -   Print the elements in increasing order.
 */
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL){
        return;
    }
    if ( k1 < root->data ){
    	elementsInRangeK1K2(root->left, k1, k2);
    }
   	if ( k1 <= root->data && k2 >= root->data ){
      	cout<<root->data<<" ";
    }
   	if ( k2 > root->data ){
      	elementsInRangeK1K2(root->right, k1, k2);
    }
}
void problem2(){
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}

/**
 *  Check if a Binary Tree is BST
 *  -   Given a binary tree with N number of nodes, check if that 
 *      input tree is BST (Binary Search Tree). If yes, return true, 
 *      return false otherwise.
 *      Note: Duplicate elements should be kept in the right subtree.
 */

//Approach 1 - O(n*h) i.e. O(nlogn) if tree balanced , O(n^2) if tree height is O(n)
int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool ans = (root->data > leftMax) && (root->data <= rightMin) 
                    && isBST(root->left) && isBST(root->right);
    return ans;
}

//Approach 2 - O(n) - one pass solution
class HelperBST{
    public:
        int min;
        int max;
        bool isBST;
};
HelperBST isBST2Helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        HelperBST ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }
    HelperBST left = isBST2Helper(root->left);
    HelperBST right = isBST2Helper(root->right);
    HelperBST ans;
    ans.min = min(root->data, min(left.min, right.min));
    ans.max = max(root->data, max(left.max, right.max));
    ans.isBST = (root->data > left.max) && (root->data <= right.min) && left.isBST && right.isBST;
    return ans;
}
bool isBST2(BinaryTreeNode<int> *root) {
	HelperBST ans = isBST2Helper(root);
    return ans.isBST;
}

//Approach 3 - O(n)
bool isBST3Helper(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool left = isBST3Helper(root->left, min, root->data-1);
    bool right = isBST3Helper(root->right, root->data, max);
    return left && right;
}
bool isBST3(BinaryTreeNode<int> *root) {
	bool ans = isBST3Helper(root);
    return ans;
}
void problem3(){
    // 5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}

/**
 *  Construct BST from a Sorted Array
 *  -   Given a sorted integer array A of size n, which contains all unique 
 *      elements. You need to construct a balanced BST from this input array. 
 *      Return the root of constructed BST.
 *  -   Note: If array size is even, take first mid as root.
 */
BinaryTreeNode<int>* makeTree(int *input, int start, int end) {
	if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left = makeTree(input, start, mid-1);
    BinaryTreeNode<int>* right = makeTree(input, mid+1, end);
    root->left = left;
    root->right = right;
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	return makeTree(input, 0, n-1);
}
void problem4(){
    int size;
    cin >> size;
    int* input = new int[size];
    for (int i = 0; i < size; i++) 
        cin >> input[i];
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrderPrint(root);
    delete[] input;
}

/**
 *  BST to Sorted LL
 *  -   Given a BST, convert it into a sorted linked list. You have to 
 *      return the head of LL.
 */
class Pair{
  	public:
    	Node<int>* head;
    	Node<int>* tail;
    	
    	Pair(){
            this->head = NULL;
            this->tail = NULL;
        }
};
Pair constructLL(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    if(root->left == NULL && root->right == NULL){
        Node<int>* node = new Node<int>(root->data);
        Pair ans;
        ans.head = node;
        ans.tail = node;
        return ans;
    }
    Pair left = constructLL(root->left);
    Pair right = constructLL(root->right);
    Node<int>* node = new Node<int>(root->data);
    Pair ans;
    if(left.tail == NULL){
        ans.head = node;
    }else {
        left.tail->next = node;
        ans.head = left.head;
    }
    node->next = right.head;
    if(right.head == NULL){
        ans.tail = node;
    } else{
        ans.tail = right.tail;
    }
    return ans;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	Pair ans = constructLL(root);
    return ans.head;   
}
void problem5(){
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

/**
 *  Root to Node Path - Binary Tree
 */
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        vector<int>* res = new vector<int>();
        res->push_back(root->data);
        return res;
    }
    vector<int>* left = getRootToNodePath(root->left, k);
    if(left != NULL){
        left->push_back(root->data);
        return left;
    }
    vector<int>* right = getRootToNodePath(root->right, k);
    if(right != NULL){
        right->push_back(root->data);
        return right;
    }
    return NULL;
}
void problem6(){
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getRootToNodePath(root, k);
    if (output != NULL) {
        for (int i = output->size()-1; i >= 0; i--) {
            cout << output->at(i) << " ";
        }
    }
}

/**
 *  Find Path in BST
 *  -   Given a BST and an integer k. Find and return the path from the node 
 *      with data k and root (if a node with data k is present in given BST) 
 *      in a list. Return empty list otherwise.
 *  -   Note: Assume that BST contains all unique elements.
 */
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    vector<int>* res = new vector<int>();
	if(root == NULL){
        return res;
    }
    if(root->data == data){
        res->push_back(root->data);
        return res;
    }else if(root->data > data){
        vector<int>* left = getPath(root->left, data);
        if(left->size() > 0){
            left->push_back(root->data);
            return left;
        }
    }else{
        vector<int>* right = getPath(root->right, data);
        if(right->size() > 0){
            right->push_back(root->data);
            return right;
        }
    }
    return res;
}
void problem7(){
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);
    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }
    delete root;
}

int main() {
    
    //Search in BST
    //problem1();

    //8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    //Print Elements in Range
    //problem2();

    //Check if a Binary Tree is BST
    //problem3();

    //Construct BST from a Sorted Array
    //problem4();

    //BST to Sorted LL
    //problem5();

    //Root to Node Path
    //problem6();

    //Find Path in BST
    problem7();

    return 0;
}