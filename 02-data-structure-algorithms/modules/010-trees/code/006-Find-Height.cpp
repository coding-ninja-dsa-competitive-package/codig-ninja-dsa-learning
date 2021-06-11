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
 *  Find Height
 *  -   Given a generic tree, find and return the height of given tree.
 * 
 *  Input Format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The order is: data for root node, number of children 
 *      to root node, data of each of child nodes and so on and so forth for 
 *      each node. The data of the nodes of the tree is separated by space.  
 *  Output Format :
 *      The first and only line of output prints the height of the given generic tree.
 * 
 *  Constraints:
 *      
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output 1:
 *      3
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

int main(){
    TreeNode<int>* root = takeInputLevelOrder();
    cout << getHeight(root);

    return 0;
}