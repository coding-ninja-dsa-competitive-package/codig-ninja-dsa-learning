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
 *  Node with maximum child sum
 *  -   Given a generic tree, find and return the node for which sum of 
 *      its data and data of all its child nodes is maximum. In the sum, 
 *      data of the node and data of its immediate child nodes has to be taken.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in level 
 *      order form. The order is: data for root node, number of children to root 
 *      node, data of each of child nodes and so on and so forth for each node. 
 *      The data of the nodes of the tree is separated by space. 
 *  Output format :
 *      The first and only line of output contains the data of the node with 
 *      maximum sum, as described in the task.
 * 
 *  Constraints:
 *      
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
 *  Sample Output 1 :
 *      1
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

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if (ans != NULL) {
        cout << ans->data;
    }

    return 0;
}