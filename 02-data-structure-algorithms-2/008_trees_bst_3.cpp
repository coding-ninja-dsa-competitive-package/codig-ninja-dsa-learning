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
 *  Create & Insert Duplicate Node
 *  -   For a given a Binary Tree of type integer, duplicate every node 
 *      of the tree and attach it to the left of itself.
 *  -   The root will remain the same. So you just need to insert nodes 
 *      in the given Binary Tree.
 */
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    BinaryTreeNode<int>* node = new BinaryTreeNode<int>(root->data);
    node->left = root->left;
    node->right = NULL;
    root->left = node;
    insertDuplicateNode(root->left->left);
    insertDuplicateNode(root->right);
}
void assignment1(){
    BinaryTreeNode<int>* root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    delete root;
}

/**
 *  Pair Sum Binary Tree
 *  -   Given a binary tree and an integer S, print all the pair of nodes 
 *      whose sum equals S.
 *      1.  Assume the given binary tree contains all unique elements.
 *      2.  In a pair, print the smaller element first. Order of different 
 *          pairs doesn't matter.
 */
#include<algorithm>
vector<int>* preOrderTraversal(BinaryTreeNode<int>* root){
    vector<int>* ans = new vector<int>();
    if(root == NULL){
        return ans;
    }
    ans->push_back(root->data);
    vector<int>* left = preOrderTraversal(root->left);
    vector<int>* right = preOrderTraversal(root->right);
    for(int i=0; i<left->size(); i++){
        ans->push_back(left->at(i));
    }
    for(int i=0; i<right->size(); i++){
        ans->push_back(right->at(i));
    }
    return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
	vector<int>* arr = preOrderTraversal(root);
    sort(arr->begin(), arr->end());
    int start=0, end=arr->size()-1;
    while(start < end){
        if(arr->at(start) + arr->at(end) == sum){
            cout << arr->at(start) << " " << arr->at(end) << endl;
            start++;
            end--;
        } else if(arr->at(start) + arr->at(end) < sum){
            start++;
        } else {
            end--;
        }
    }
}
void assignment2(){
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}

/**
 *  LCA of Binary Tree  
 *  -   Given a binary tree and data of two nodes, find 'LCA' (Lowest Common 
 *      Ancestor) of the given two nodes in the binary tree.
 *  -   LCA of two nodes A and B is the lowest or deepest node which has both 
 *      A and B as its descendants. 
 */ 
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL){
        return -1;
    }
    if(root->data == a || root->data == b){
        return root->data;
    }
    int left = getLCA(root->left, a, b);
    int right = getLCA(root->right, a, b);
    if(left == -1 && right == -1){
        return -1;
    } else if(left == -1){
        return right;
    } else if(right == -1){
        return left;
    } else {
        return root->data;
    }
}
void assignment3(){
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}

/**
 *  LCA of BST
 *  -   Given a binary search tree and data of two nodes, find 'LCA' 
 *      (Lowest Common Ancestor) of the given two nodes in the BST.
 */
int getLCABst(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root == NULL){
        return -1;
    }
    if(root->data == val1 || root->data == val2){
        return root->data;
    }
    
    int lca=-1;
    if(val1 < root->data && val2 < root->data){
        lca = getLCABst(root->left, val1, val2);
    } else if(val1 >= root->data && val2 >= root->data){
        lca = getLCABst(root->right, val1, val2);
    } else{
        lca = root->data;
    }
    return lca;
}
void assignment4(){
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCABst(root, a, b);
    delete root;
}

/**
 *  Largest BST
 *  -   Given a Binary tree, find the largest BST subtree. That is, 
 *      you need to find the BST with maximum height in the given 
 *      binary tree. You have to return the height of largest BST.
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
void assignment5(){
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}

/**
 *  Replace with Sum of greater nodes
 *  -   Given a binary search tree, you have to replace each node's data 
 *      with the sum of all nodes which are greater or equal than it. You 
 *      need to include the current node's data also.
 *  -   That is, if in given BST there is a node with data 5, you need to 
 *      replace it with sum of its data (i.e. 5) and all nodes whose data 
 *      is greater than or equal to 5.
 *  -   Note: You don't need to return or print, just change the data of each node.
 */
int replace(BinaryTreeNode<int>* root, int sum){
    if(root == NULL){
        return sum;
    }
    sum = replace(root->right, sum);
    sum += root->data;
    root->data=sum;
    sum = replace(root->left, sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replace(root, 0);
}
void assignment6(){
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;
}

/**
 *  Path Sum Root to Leaf
 *  -   For a given Binary Tree of type integer and a number K, print out 
 *      all root-to-leaf paths where the sum of all the node data along the 
 *      path is equal to K.
 */
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string path){
    if(root == NULL){
        return;
    }   
    if(root->left == NULL && root->right == NULL && k==root->data){
        path += to_string(root->data);
        cout << path << endl;
        return;
    }
    rootToLeafPathsSumToK(root->left, k-root->data, path+to_string(root->data)+" ");
    rootToLeafPathsSumToK(root->right, k-root->data, path+to_string(root->data)+" ");
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
 	rootToLeafPathsSumToK(root, k, "");
}
void assignment7(){
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}

/**
 *  Print nodes at distance k from node
 *  -   You are given a Binary Tree of type integer, a target node, 
 *      and an integer value K.
 *  -   Print the data of all nodes that have a distance K from the     
 *      target node. The order in which they would be printed will not matter.
 */
void printAtLevelK(BinaryTreeNode<int>* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << endl;
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
}
int nodesAtDistK(BinaryTreeNode<int> *root, int node, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        printAtLevelK(root, k);
        return 0;
    }
    int left = nodesAtDistK(root->left, node, k);
    if(left != -1){
        if(left+1 == k){
            cout << root->data << endl;
        } else {
            printAtLevelK(root->right, k-left-2);
        }
        return left+1;
    }
    int right = nodesAtDistK(root->right, node, k);
    if(right != -1){
        if(right+1 == k){
            cout << root->data << endl;
        } else{
            printAtLevelK(root->left, k-right-2);
        }
        return 1+right;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistK(root, node, k);
}
void assignment8(){
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}

/**
 *  Pair sum in a BST
 *  -   Given a binary search tree and an integer S, find pair of nodes 
 *      in the BST which sum to S. You can use extra space of the order 
 *      of O(log n).
 */
void inOrderTraversal(BinaryTreeNode<int>* root, vector<int> & arr){
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    vector<int> arr;
    inOrderTraversal(root, arr);
    int l=0, r=arr.size()-1;
    while(l<r){
        if(arr[l] + arr[r] == s){
            cout << arr[l] << " " << arr[r] << endl;
            l++;
            r--;
        } else if(arr[l]+arr[r] < s){
            l++;
        } else {
            r--;
        }
    }
}
//Approach 2 : time O(n) , space O(logn)
void printNodesSumToSLogN(BinaryTreeNode<int> *root, int s) {
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    BinaryTreeNode<int>* curr1 = root;
    BinaryTreeNode<int>* curr2 = root;
    int val1 = 0, val2 = 0;
    bool done1 = false, done2 = false;
    while(1){
        while(done1==false){
            if(curr1 != NULL){
                s1.push(curr1);
                curr1 = curr1->left;
            } else {
                if(s1.empty()){
                    done1 = true;
                } else{
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        while(done2==false){
            if(curr2 != NULL){
                s2.push(curr2);
                curr2 = curr2->right;
            } else {
                if(s2.empty()){
                    done2 = true;
                } else{
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }
        if(val1 != val2 && (val1+val2) == s){
            cout << val1 << " " << val2 << endl;
            return;
        } else if(val1 + val2 < s){
            done1 = false;
        } else if (val1+val2 > s){
            done2 = false;
        }
        if(val1 >= val2){
            return;
        }
    }
}

void assignment9(){
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    //printNodesSumToS(root, s);
    printNodesSumToSLogN(root, s);
    delete root;
}


int main() {
    //Create & Insert Duplicate Node
    //assignment1();

    //Pair Sum Binary Tree
    //assignment2();

    //LCA of Binary Tree
    //assignment3();

    //LCA of BST
    //assignment4();

    //Largest BST
    //assignment5();

    //Replace with Sum of greater nodes
    //assignment6();

    //Path Sum Root to Leaf
    //assignment7();

    //Print nodes at distance k from node
    //assignment8();

    //Pair sum in a BST
    assignment9();


    return 0;
}