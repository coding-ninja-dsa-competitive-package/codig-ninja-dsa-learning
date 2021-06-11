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
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode(){
            delete left;
            delete right;
        }
};

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << f->data << " : ";
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftChild);
            f->left = left;
            pendingNodes.push(left);
        }
        cout << "Enter right child of " << f->data << " : ";
        int rightChild;
        cin >> rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int>* right = new BinaryTreeNode<int>(rightChild);
            f->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}

/**
 *  Level wise linkedlist
 *  -   Given a binary tree, write code to create a separate linked list 
 *      for each level. You need to return the array which contains head 
 *      of each level linked list.
 * 
 *  Input format :
 *      The first line of input contains data of the nodes of the tree in 
 *      level order form. The data of the nodes of the tree is separated by 
 *      space. If any node does not have left or right child, take -1 in its 
 *      place. Since -1 is used as an indication whether the left or right 
 *      nodes exist, therefore, it will not be a part of the data of any node.
 *  Output format :
 *      Each level linked list is printed in new line (elements are separated by space).
 *  
 *  Constraints:
 *      Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output 1:
 *      5
 *      6 10 
 *      2 3 
 *      9
 */
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
vector<Node<int>*> result;
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return result;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front(); 
        if(f == NULL){
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            Node<int>* root = new Node<int>(f->data);
            q.pop();
            if(f->left != NULL){
                q.push(f->left);
            }
            if(f->right != NULL){
                q.push(f->right);
            }
            Node<int>* curr = root;
            f = q.front();
            while(f != NULL){
                q.pop();
                if(f->left != NULL){
                    q.push(f->left);
                }
                if(f->right != NULL){
                    q.push(f->right);
                }
                Node<int>* newNode = new Node<int>(f->data);
                curr->next = newNode;
                curr = curr->next;
                f = q.front();
            }
            result.push_back(root);
        } 
    }
    return result;
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }

    return 0;
}