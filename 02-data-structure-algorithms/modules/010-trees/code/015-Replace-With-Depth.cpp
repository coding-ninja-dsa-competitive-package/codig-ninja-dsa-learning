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
 *  Replace with depth
 *  -   You are given a generic tree. You have to replace each node with 
 *      its depth value. You just have to update the data of each node, there   
 *      is no need to return or print anything.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.  
 *  Output format:
 *      The updated tree is printed level wise. Each level is printed in a 
 *      new line. Please refer to sample output 1 for more details. 
 * 
 *  Constraints:
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output 1:
 *      0 
 *      1 1 1 
 *      2 2
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

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);

    return 0;
}