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
 *  Count nodes
 *  -   Given a tree and an integer x, find and return the number of nodes 
 *      which contains data greater than x.
 * 
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.  
 *      The following line contains an integer, that denotes the value of x. 
 *  Output Format :
 *      The first and only line of output prints the count of nodes greater than x.
 * 
 *  Constraints:
 *      
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1 :
 *      10 3 20 30 40 2 40 50 0 0 0 0
 *      35 
 *  Sample Output 1 :
 *      3
 *  
 *  Sample Input 2 :
 *      10 3 20 30 40 2 40 50 0 0 0 0
 *      10 
 *  Sample Output 2:
 *      5
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

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << getLargeNodeCount(root, x);

    return 0;
}