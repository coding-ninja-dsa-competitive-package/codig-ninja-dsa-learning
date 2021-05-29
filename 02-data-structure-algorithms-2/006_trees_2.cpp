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
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
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
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}



/**
 *  Contains x
 *  -   Given a generic tree and an integer x, check if x is present 
 *      in the given tree or not. Return true if x is present, return 
 *      false otherwise.
 */
bool isPresent(TreeNode<int>* root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool childRes=false;
    for(int i=0; i<root->children.size(); i++){
        childRes = childRes || isPresent(root->children[i], x);
    }
    return childRes;
}
void assignment1(){
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}

/**
 *  Count nodes
 *  -   Given a tree and an integer x, find and return the number of nodes 
 *      which contains data greater than x.
 */
int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == NULL){
        return 0;
    }
    int ans = 0;
    if(root->data > x){
        ans++;
    }
    for(int i=0; i<root->children.size(); i++){
        ans += getLargeNodeCount(root->children[i] , x);
    }
    return ans;
}
void assignment2(){
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << getLargeNodeCount(root, x);
}

/**
 *  Node with maximum child sum
 *  -   Given a generic tree, find and return the node for which sum of 
 *      its data and data of all its child nodes is maximum. In the sum, 
 *      data of the node and data of its immediate child nodes has to be taken.
 */
class Pair{
  	public:
    	TreeNode<int>* node;
    	int sum;
};

Pair maxNode(TreeNode<int>* root){
    int sum=root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += root->children[i]->data;
    }
    Pair res;
    res.node = root;
    res.sum = sum;
    for(int i=0; i<root->children.size(); i++){
        Pair max = maxNode(root->children[i]);
        if(max.sum > res.sum){
            res.node = max.node;
            res.sum = max.sum;
        }
    }
    return res;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    Pair res = maxNode(root);
    return res.node;
}
void assignment3(){
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if (ans != NULL) {
        cout << ans->data;
    }
}

/**
 *  Structurally identical
 *  -   Given two generic trees, return true if they are structurally 
 *      identical. Otherwise return false.
 */
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 == NULL){
        return true;
    } else if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    if(root1->children.size() != root2->children.size()){
        return false;
    }
    bool ans = true;
    for(int i=0 ; i<root1->children.size(); i++){
        ans = ans && areIdentical(root1->children[i] , root2->children[i]);
    }
    return ans;
}
void assignment4(){
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}

/**
 *  Next larger
 *  -   Given a generic tree and an integer n. Find and return the node with 
 *      next larger element in the tree i.e. find a node with value just greater than n.
 *  -   Note: Return NULL if no node is present with the value greater than n.
 */
#include<climits>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root == NULL){
        return NULL;
    }
    int result = INT_MAX;
    TreeNode<int>* node = NULL;
    if(root->data > x && root->data < result){
        result = root->data;
        node = root;
    }
    for(int i=0 ; i<root->children.size(); i++){
        TreeNode<int>* child = getNextLargerElement(root->children[i], x);
        if(child != NULL && child->data > x && child->data < result){
            result = child->data;
        	node = child;
        }
    }
    return node;
}
void assignment5(){
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}

/**
 *  Second Largest Element In Tree
 *  -   Given a generic tree, find and return the node with second largest 
 *      value in given tree.
 *  -   Note: Return NULL if no node with required value is present.
 */
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root == NULL || root->children.size() == 0){
        return NULL;
    }
    TreeNode<int>* largest = root;
    TreeNode<int>* second = NULL;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        q.pop();
        if(f != NULL && largest != NULL && f->data > largest->data){
            second = largest;
            largest = f;
        } else if (f != NULL && second != NULL && f->data > second->data 
                  	&& f->data != largest->data){
            second = f;
        }
        for(int i=0; i<f->children.size() ; i++){
            q.push(f->children[i]);
        }
    }
    return second;
}
void assignment6(){
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = getSecondLargestNode(root);
    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }
}

/**
 *  Replace with depth
 *  -   You are given a generic tree. You have to replace each node with 
 *      its depth value. You just have to update the data of each node, there   
 *      is no need to return or print anything.
 */
void replaceWithDepthValue(TreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    int i=0;
    while(!q.empty()){
        TreeNode<int>* f = q.front();
        while(f != NULL){
            f->data = i;
            q.pop();
            for(int i=0; i<f->children.size(); i++){
                q.push(f->children[i]);
            }
            f = q.front();
            if(f == NULL){
                q.push(NULL);
            }
        }
        q.pop();
        i++;
    }
}
void assignment7(){
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}

int main() {
    //Contains x
    //assignment1();

    //Count Nodes
    //assignment2();

    //Node with maximum child sum
    //assignment3();

    //Structurally identical
    //assignment4();

    //Next larger
    //assignment5();

    //Second Largest Element In Tree
    //assignment6();

    //Replace with depth
    assignment7();

    return 0;
}