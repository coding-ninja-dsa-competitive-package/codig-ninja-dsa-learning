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

/**
 *  Remove leaf nodes in Tree
 *  -   Remove all leaf nodes from a given generic Tree. Leaf nodes are 
 *      those nodes, which don't have any children.
 *  Note : Root will also be a leaf node if it doesn't have any child. 
 *      You don't need to print the tree, just remove all leaf nodes and 
 *      return the updated root.
 * 
 *  Input format :  
 *      Line 1 : Elements in level order form separated by space (as per 
 *      done in class). Order is - 
 *      Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
 *  Output Format :
 *      Elements are printed level wise, each level in new line (separated by space)
 * 
 *  Sample Input 1 :
 *      10 3 20 30 40 2 40 50 0 0 0 0 
 *  Sample Output 1 : (Level wise, each level in new line)
 *      10
 *      20
 */
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

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);

    return 0;
}