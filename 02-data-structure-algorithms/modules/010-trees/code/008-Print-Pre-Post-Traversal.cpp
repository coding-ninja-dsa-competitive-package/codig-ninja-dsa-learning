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

int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << endl << "Pre order : ";
    printPreOrder(root);
    cout << endl << "Post order : ";
    printPostOrder(root);
    cout << endl;

    return 0;
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