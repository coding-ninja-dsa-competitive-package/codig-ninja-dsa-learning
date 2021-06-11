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
 *  Structurally identical
 *  -   Given two generic trees, return true if they are structurally 
 *      identical. Otherwise return false.
 *  
 *  Input format :
 *      The first line of input contains data of the nodes of the first tree 
 *      in level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.  
 *      The following line of input contains data of the nodes of the second 
 *      tree in level order form. The order is: data for root node, number of 
 *      children to root node, data of each of child nodes and so on and so forth 
 *      for each node. The data of the nodes of the tree is separated by space.
 *  Output format :
 *      The first and only line of output contains true, if the given trees are 
 *      structurally identical and false, otherwise.
 * 
 *  Constraints:
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *      10 3 20 30 40 2 40 50 0 0 0 0
 *  Sample Output 1 :
 *      true
 * 
 *  Sample Input 2 :
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *      10 3 2 30 40 2 40 50 0 0 0 0
 *  Sample Output 2:
 *      false
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

int main(){
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");

    return 0;
}