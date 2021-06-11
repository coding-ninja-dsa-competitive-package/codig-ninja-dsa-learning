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
 *  Second Largest Element In Tree
 *  -   Given a generic tree, find and return the node with second largest 
 *      value in given tree.
 *  -   Note: Return NULL if no node with required value is present.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in   
 *      level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.
 *  Output Format :
 *      The first and only line of output contains data of the node with 
 *      second largest data.
 *  
 *  Constraints:
 * 
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1 :
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output 1 :
 *      40
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

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = getSecondLargestNode(root);
    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

    return 0;
}