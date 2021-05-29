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
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if(first == NULL) {
            if(q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first -> data << " ";
        if(first -> left != NULL) {
            q.push(first -> left);
        }
        if(first -> right != NULL) {
            q.push(first -> right);
        }
    }
}

/**
 *  Check cousins
 *  -   Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether 
 *      the two nodes are cousins of each other or not. Two nodes are said to be 
 *      cousins of each other if they are at same level of the Binary Tree and 
 *      have different parents.
 *  -   Do it in O(n).
 * 
 *  Smaple Input :
 *      5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1 
 *      2
 *      4
 *  Sample output :
 *      true
 */
#include<queue>
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
   	if(root==NULL){
        return false;
    }
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
	bool foundP=false, foundQ=false;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        if(f == NULL){
            if(foundP && foundQ){
                return true;
            } else if((foundP && !foundQ) || (foundQ && !foundP)){
                return false;
            }
            pendingNodes.pop();
            if(!pendingNodes.empty()){
                pendingNodes.push(NULL);
            }
        } else {
            pendingNodes.pop();
            if(f->data == p){
                foundP=true;
            } else if(f->data == q){
                foundQ=true;
            }
            if(f->left && f->right){
                if(f->left->data == p && f->right->data == q ){
                	return false;
                } else if(f->left->data == q && f->right->data == p){
                    return false;
                }
            }
            
            if(f->left != NULL){
                pendingNodes.push(f->left);
            }
            if(f->right != NULL){
                pendingNodes.push(f->right);
            }
        }
    }
	return false;
}
void problem1(){
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}

/**
 *  Longest Leaf to root path
 *  -   Given a binary tree, return the longest path from leaf to root. 
 *      Longest means, a path which contain maximum number of nodes from 
 *      leaf to root.
 *  Sample Input :
 *       5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 *  Sample Output :
 *      9 3 6 5 
 */
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	vector<int>* res = new vector<int>();
    if(root==NULL){
        return res;
    }
	if(root->left == NULL && root->right == NULL){
        res->push_back(root->data);
        return res;
    }
    vector<int>* left = longestPath(root->left);
    vector<int>* right = longestPath(root->right);
    if(left->size() > right->size()){
        left->push_back(root->data);
        return left;
    } else{
        right->push_back(root->data);
        return right;
    }
}
void problem2(){
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}

/**
 *  Remove leaf nodes in Tree
 *  -   Remove all leaf nodes from a given generic Tree. Leaf nodes are 
 *      those nodes, which don't have any children.
 *  SampleInput :
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output:
 *      10 20
 */
template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;
		
		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }	

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
    
    void removeChild(int i) {
        for(int j = i + 1; j < childCount; j++) {
            children[j - 1] = children[j];
        }
        childCount--;
    }
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}
		
		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}
		
		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}
		~Queue() {
			delete [] data;
        }
};
TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();
		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {
			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

void printLevelATNewLine(TreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    Queue<TreeNode<int>*> q;
    q.enqueue(root);
    q.enqueue(NULL);
    while(!q.isEmpty()) {
        TreeNode<int> *first = q.dequeue();
        if(first == NULL) {
            if(q.isEmpty()) {
                break;
            }
            cout << endl;
            q.enqueue(NULL);
            continue;
        }
        cout << first -> data << " ";
        for(int i = 0; i < first -> numChildren(); i++) {
            q.enqueue(first -> getChild(i));
        }
    }
}

#include<vector>
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if(root==NULL || root->numChildren()==0){
        return NULL;
    }
    vector<int> arr;
    for(int i=0; i<root->numChildren(); i++){
        TreeNode<int>* child = root->getChild(i);
        if(child->numChildren()==0){
            arr.push_back(i);
        }
    }
    for(int j=arr.size()-1; j>=0; j--){
        root->removeChild(arr[j]);
    }
    for(int i=0; i<root->numChildren(); i++){
        TreeNode<int>* childRoot = removeLeafNodes(root->getChild(i));
        if(childRoot==NULL){
            root->removeChild(i);
        }
    }
    return root;
}
void problem3(){
    TreeNode<int>* root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);
}

int main() {
    // Check cousins
    //problem1();

    // Longest Leaf to root path
    //problem2();

    // Remove leaf nodes in Tree
    //problem3();

    return 0;
}