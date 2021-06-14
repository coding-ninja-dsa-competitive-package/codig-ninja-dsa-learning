#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
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
 *  War on NinjaLand II
 *  -   War between NinjaLand and Pandora is still going on. The mayor of 
 *      NinjaLand has sanctioned a retaliation against Pandora. He has 
 *      ordered his soldiers to drop a single CHAIN BOMB on Pandora to 
 *      destroy their Military Outposts and cripple the defense.
 *  -   In Pandora, the Military Outposts are situated at nodes of a Binary 
 *      Tree. Each military outpost is given a unique integer ID (represented 
 *      by the value of that node). Captain Ninja of NinjaLand Airforce decides 
 *      which military outpost has to be bombarded with the Chain Bomb. Once 
 *      the bomb has been dropped on the target, it will spread a chain reaction 
 *      into its neighbouring outposts, who will again in turn spread the reaction 
 *      onto their neighbours. This way the chain reaction’s destruction will   
 *      spread to all the outposts.
 *  -   Your task is to print the sequence in which the outposts will be destroyed.
 *  -   Keep in mind that chain reaction will spread through connected (adjacent) 
 *      outposts only and once an outpost is destroyed, it cannot be bombarded again.
 * 
 *  Input Format:
 *      The first line of input contains an integer t, denoting the number of test cases. 
 *      For each test case, we need to input two things- Tree nodes and a target node.
 *      The first line of input contains data of the nodes of the tree in level order 
 *      form. The order is: data for root node, data for left child to root node,  data 
 *      for right child to root node and so on and so forth for each node. The data of 
 *      the nodes of the tree is separated by space. Data -1 denotes that the node 
 *      doesn't exist.
 *      Second line of each test case will contain an integer T representing the ID 
 *      of the target node.
 *  
 *  Constraints:
 *      Time Limit: 1 sec
 *  
 *  Output Format:
 *      For each query, you have to print the sequence in which outposts will be 
 *      destroyed. Each adjacent reaction will be printed in a separate line. To 
 *      avoid multiple answers, print the ID’s on each level in sorted form.
 *  
 *  Sample Input 1:
 *      8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 *      14
 *  Sample Output 1:
 *      14 
 *      10 13 
 *      8 
 *      3 
 *      1 6 
 *      4 7
 *  Explanation:
 *      For the given input the tree formed is given below.
 *      14 is the target node, which will be bombed initially. From there, chain 
 *      reaction will go to its adjacent nodes [ 10 , 13 ] will begin. 10 will 
 *      help destroy its adjacent nodes [ 8 ]. 8 will help destroy [ 3 ]. 3 will 
 *      help destroy [ 1 , 6 ] . 6 will help destroy  [ 4 , 7 ] 
 *  
 *  Sample Input 2:
 *      10 20 60 -1 -1 3 50 -1 -1 -1 -1 
 *      3
 *  Sample Output 2:
 *      3 
 *      60 
 *      10 50   
 *      20 
 *  Explanation:
 *      3 is the target node, which will be bombed initially. From there, chain 
 *      reaction to its adjacent nodes [ 60 ] will begin. 60 will help destroy 
 *      its adjacent nodes [ 10 , 50 ]. 10 will help destroy [ 20 ]. 
 */

void bomb(BinaryTreeNode<int>* root, int target) {
    
} 

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode;
    if (root){
        cin >> targetNode;
    }
    
	bomb(root, targetNode); 

    return 0;
}