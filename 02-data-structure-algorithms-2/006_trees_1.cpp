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
 *  Tree Node
 */
template<typename T>
class TreeNode{
    public:
        T data;
        // If parent is of T type, children will also have also data type
        //vector<TreeNode<T>*> children;
        vector<TreeNode*> children;

        TreeNode(T data){
            this->data = data;
        }

        //Delete Tree using destructor
        ~TreeNode(){
            for(int i=0; i<children.size(); i++){
                delete children[i];
            }
        }
};
//print tree
void printTree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : " ;
    for(int i=0; i<root->children.size(); i++){
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}
//Take input recursive
TreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void problem1(){
    // TreeNode<int>* root = new TreeNode<int>(10);
    // TreeNode<int>* node1 = new TreeNode<int>(20);
    // TreeNode<int>* node2 = new TreeNode<int>(30);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int>* root = takeInput();
    printTree(root);
}

/**
 *  Given a generic tree, print the input tree in level wise order.
 */
void printLevelWise(TreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for(int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data;
            if((i+1) < front->children.size()){
                cout << ",";
            }
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}
//Level Traversal take Input
TreeNode<int>* takeInputLevelOrder(){
    int rootData;
    cout << "Enter the root element : ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children for " << node->data << endl;
        cin >> n;
        for(int i=0; i<n; i++){
            cout<< "Enter the " << i << "th element for " << node->data << endl;
            int num; 
            cin >> num;
            TreeNode<int>* newNode = new TreeNode<int>(num);
            node->children.push_back(newNode);
            q.push(newNode);
        }
    }
    return root;
}
void assignment1(){
    TreeNode<int>* root = takeInputLevelOrder();
    printLevelWise(root);
}

/**
 *  Count Number of Nodes
 */
int countNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
        
    }
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans += countNodes(root->children[i]);
    }
    return ans;
}
void assignment2(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << countNodes(root) << endl;
}

/**
 *  Find Sum of Nodes
 *  -   Given a generic tree, find and return the sum of all nodes present 
 *      in the given tree.
 */
int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int ans = root->data;
    for(int i=0 ;i<root->children.size(); i++){
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}
void assignment3(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << sumOfNodes(root) << endl;
}

/**
 *  Code : Max data node
 *  -   Given a generic tree, find and return the node with maximum data. 
 *      You need to return the node which is having maximum data.
 *  -   Return null if tree is empty.
 */
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    TreeNode<int>* ans = root;
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* curr = maxDataNode(root->children[i]);
        if(curr->data > ans->data){
            ans = curr;
        }
    }
    return ans;
}
void assignment4(){
    TreeNode<int>* root = takeInputLevelOrder();
    TreeNode<int>* ans = maxDataNode(root);
    if (root != NULL) {
        cout << ans->data;
    }
}

/**
 *  Find Height
 *  -   Given a generic tree, find and return the height of given tree.
 */
int getHeight(TreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        int height = getHeight(root->children[i]);
        if(height+1 > ans){
            ans = height+1;
        }
    }
    return ans;
}
void assignment5(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << getHeight(root);
}

/**
 *  Print at level K
 */
void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout << root->data << " ";
        return;
    }
    for(int i=0; i<root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}
void assignment6(){
    TreeNode<int>* root = takeInputLevelOrder();
    int k ;
    cin >> k;
    printAtLevelK(root, k);
}

/**
 *  Count Leaf nodes
 *  -   Given a generic tree, count and return the number of leaf nodes 
 *      present in the given tree.
 */ 
int getLeafNodeCount(TreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i=0; i<root->children.size(); i++){
        ans += getLeafNodeCount(root->children[i]);
    }
    return ans;
}
void assignment7(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << getLeafNodeCount(root) << endl;
}

/**
 *  Print in pre order and post order
 */
void printPreOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    for(int i=0 ; i<root->children.size(); i++){
        printPreOrder(root->children[i]);
    }
}
void printPostOrder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i=0 ; i<root->children.size(); i++){
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}
void assignment8(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << endl << "Pre order : ";
    printPreOrder(root);
    cout << endl << "Post order : ";
    printPostOrder(root);
    cout << endl;
}

/**
 *  Delete Tree
 */
void deleteTree(TreeNode<int>* root){
    for(int i=0; i<root->children.size() ; i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main() {
    //Tree basics
    //problem1();

    //Level Order Print Tree
    //assignment1();

    //count number of nodes
    //assignment2();

    //Find Sum of Nodes
    //assignment3();

    //Finx Max Node
    //assignment4();

    //height of tree
    //assignment5();

    //print at level K
    //assignment6();

    //Count Leaf nodes
    //assignment7();

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    //print in pre and post order
    assignment8();

    return 0;
}