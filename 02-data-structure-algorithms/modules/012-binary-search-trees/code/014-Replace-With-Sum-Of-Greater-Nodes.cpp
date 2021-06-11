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
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
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
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

/**
 *  Replace with Sum of greater nodes
 *  -   Given a binary search tree, you have to replace each node's data 
 *      with the sum of all nodes which are greater or equal than it. You 
 *      need to include the current node's data also.
 *  -   That is, if in given BST there is a node with data 5, you need to 
 *      replace it with sum of its data (i.e. 5) and all nodes whose data 
 *      is greater than or equal to 5.
 *  -   Note: You don't need to return or print, just change the data of each node.
 * 
 *  Input format:
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *  Output format:
 *      In the output, data of the nodes of the tree are printed in level order 
 *      form. Each level of the tree is printed on a separate line.
 *  
 *  Constraints:
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1 :
 *      8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 *  Sample Output 1 :
 *      18 
 *      36 10 
 *      38 31 
 *      25 
 */
int replace(BinaryTreeNode<int>* root, int sum){
    if(root == NULL){
        return sum;
    }
    sum = replace(root->right, sum);
    sum += root->data;
    root->data=sum;
    sum = replace(root->left, sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replace(root, 0);
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;

    return 0;
}

