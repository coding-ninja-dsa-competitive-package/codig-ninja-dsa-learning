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

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
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

    ~BinaryTreeNode() {
        if (left) 
            delete left;
        if (right) 
            delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void preOrderPrint(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

/**
 *  Construct BST from a Sorted Array
 *  -   Given a sorted integer array A of size n, which contains all unique 
 *      elements. You need to construct a balanced BST from this input array. 
 *      Return the root of constructed BST.
 *  -   Note: If array size is even, take first mid as root.
 * 
 *  Input format:
 *      The first line of input contains an integer, which denotes the value 
 *      of n. The following line contains n space separated integers, that 
 *      denote the values of array.
 *  Output Format:
 *      The first and only line of output contains values of BST nodes, printed 
 *      in pre order traversal.
 *  
 *  Constraints:
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1:
 *      7
 *      1 2 3 4 5 6 7
 *  Sample Output 1:
 *      4 2 1 3 6 5 7 
 */
BinaryTreeNode<int>* makeTree(int *input, int start, int end) {
	if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left = makeTree(input, start, mid-1);
    BinaryTreeNode<int>* right = makeTree(input, mid+1, end);
    root->left = left;
    root->right = right;
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	return makeTree(input, 0, n-1);
}

int main(){
    int size;
    cin >> size;
    int* input = new int[size];
    for (int i = 0; i < size; i++) 
        cin >> input[i];
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrderPrint(root);
    delete[] input;

    return 0;
}