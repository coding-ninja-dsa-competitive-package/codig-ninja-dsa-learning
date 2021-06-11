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


/**
 *  Print Level Wise:
 *  -   Given a generic tree, print the input tree in level wise order.
 *  -   For printing a node with data N, you need to follow the exact format - 
 *          N:x1,x2,x3,...,xn
 *          where, N is data of any node present in the generic tree. 
 *          x1, x2, x3, ...., xn are the children of node N. 
 *      Note that there is no space in between.
 *  -   You need to print all nodes in the level order form in different lines.
 *  
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.
 *  Output Format :
 *      The first and only line of output contains the elements of the tree 
 *      in level wise order, as described in the task.
 * 
 *  Constraints:
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output 1:
 *      10:20,30,40
 *      20:40,50
 *      30:
 *      40:
 *      40:
 *      50:
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

int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    printLevelWise(root);

    return 0;
}