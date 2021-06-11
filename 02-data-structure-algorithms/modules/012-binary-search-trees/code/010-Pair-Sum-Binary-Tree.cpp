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
 *  Pair Sum Binary Tree
 *  -   Given a binary tree and an integer S, print all the pair of nodes 
 *      whose sum equals S.
 *      1.  Assume the given binary tree contains all unique elements.
 *      2.  In a pair, print the smaller element first. Order of different 
 *          pairs doesn't matter.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have a left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *      The following line of input contains an integer, that denotes the value of S.
 *  Output Format :
 *      Print each pair in a new line, as described in the task. 
 *  Constraints:
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *      15
 *  Sample Output 1:
 *      5 10
 *      6 9
 */
vector<int>* preOrderTraversal(BinaryTreeNode<int>* root){
    vector<int>* ans = new vector<int>();
    if(root == NULL){
        return ans;
    }
    ans->push_back(root->data);
    vector<int>* left = preOrderTraversal(root->left);
    vector<int>* right = preOrderTraversal(root->right);
    for(int i=0; i<left->size(); i++){
        ans->push_back(left->at(i));
    }
    for(int i=0; i<right->size(); i++){
        ans->push_back(right->at(i));
    }
    return ans;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
	vector<int>* arr = preOrderTraversal(root);
    sort(arr->begin(), arr->end());
    int start=0, end=arr->size()-1;
    while(start < end){
        if(arr->at(start) + arr->at(end) == sum){
            cout << arr->at(start) << " " << arr->at(end) << endl;
            start++;
            end--;
        } else if(arr->at(start) + arr->at(end) < sum){
            start++;
        } else {
            end--;
        }
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;

    return 0;
}