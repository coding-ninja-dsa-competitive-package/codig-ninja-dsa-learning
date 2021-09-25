#include<bits/stdc++.h>

using namespace std;

/**
 *  Vasya vs Rhezo
 *  -   Queen Vasya is preparing for a war against Rhezo. She has N warriors in 
 *      total arranged in a line. Let us number the warriors by numbers from 1 
 *      to N. She will fight Rhezo's army for Q days, and each day she can choose 
 *      only one warrior.
 *  -   For each warrior, we know 2 values associated with him, let us call these 
 *      A and B. Each day Vasya can choose her warrior from a range Li to Ri, 
 *      she must choose the warrior with maximum A value. If there is more than 
 *      1 warrior having the same maximum A value, she chooses the warrior with 
 *      minimum B value. If still there is more than 1 warrior with same maximum 
 *      A value and same minimum B value, she chooses the one with lower index in 
 *      line.
 *  -   You being the hand of Queen Vasya, need to help her in choosing the warrior 
 *      for each day.
 *  
 *  Input:
 *      First line contains a single integer N, denoting the number of warriors 
 *      Queen Vasya has. 
 *      Second line contains N space separated integers Ai. Third line contains     
 *      N space separated integers Bi.
 *      Next line contains a single integer Q, denoting the number of days Queen 
 *      Vasya chooses a warrior. 
 *      Each of the next Q lines contains 2 integers Li and Ri.
 *  Output:
 *      For each Li and Ri, print the index of the warrior that Queen Vasya 
 *      should choose.
 *  
 *  Constraints:
 *      1≤ N,Q ≤10^6
 *      1≤ Ai,Bi ≤10^9
 *      1≤Li≤Ri
 *  
 *  Sample Input
 *      5
 *      1 8 4 6 8   
 *      4 8 6 3 7   
 *      4
 *      1 4
 *      2 4
 *      3 4
 *      1 5
 *  Sample Output   
 *      2
 *      2
 *      4
 *      5
 */

struct warriors{
	int a;
	int b;
};

struct tree_node{
	int a;
	int b;
	int index;
};

void buildTree(warriors* arr, tree_node* tree, int start, int end, int treeNode){
	if (start == end){
		tree[treeNode].a = arr[start].a;
		tree[treeNode].b = arr[start].b;
		tree[treeNode].index = start;
		return;
	}
	int mid = (start + end) / 2;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	tree_node leftChild = tree[2*treeNode];
	tree_node rightChild = tree[2*treeNode+1];
	if (leftChild.a > rightChild.a){
		tree[treeNode].a = leftChild.a;
		tree[treeNode].b = leftChild.b;
		tree[treeNode].index = leftChild.index;
	} else if(leftChild.a < rightChild.a) {
		tree[treeNode].a = rightChild.a;
		tree[treeNode].b = rightChild.b;
		tree[treeNode].index = rightChild.index;
	} else {
		if (leftChild.b < rightChild.b) {
			tree[treeNode].a = leftChild.a;
			tree[treeNode].b = leftChild.b;
			tree[treeNode].index = leftChild.index;
		} else if (leftChild.b > rightChild.b) {
			tree[treeNode].a = rightChild.a;
			tree[treeNode].b = rightChild.b;
			tree[treeNode].index = rightChild.index;
		} else {
			if (leftChild.index < rightChild.index) {
				tree[treeNode].a = leftChild.a;
				tree[treeNode].b = leftChild.b;
				tree[treeNode].index = leftChild.index;
			} else {
				tree[treeNode].a = rightChild.a;
				tree[treeNode].b = rightChild.b;
				tree[treeNode].index = rightChild.index;
			}
		}
	}
}

tree_node query(tree_node* tree, int start, int end, int treeNode, int left, int right){
	//completely outside
	if (start > right || end < left){
		tree_node ans;
		ans.a = INT_MIN;
		ans.b = INT_MAX;
		ans.index = INT_MAX;
		return ans;
	}
	//completely inside
	if (start >= left && end <= right){
		return tree[treeNode];
	}
	//partial overlap
	int mid = (start + end) / 2;
	tree_node l = query(tree, start, mid, 2*treeNode, left, right);
	tree_node r = query(tree, mid+1, end, 2*treeNode+1, left, right);
	if (l.a > r.a){
		return l;
	} else if (l.a < r.a) {
		return r;
	} else {
		if (l.b < r.b){
			return l;
		} else if (l.b > r.b){
			return r;
		} else{
			if (l.index < r.index){
				return l;
			} else {
				return r;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	warriors* arr = new warriors[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i].a;
	}
	for (int i = 0; i < n; i++){
		cin >> arr[i].b;
	}
	tree_node* tree = new tree_node[4*n]();
	buildTree(arr, tree, 0, n-1, 1);
	
    int q;
	cin >> q;
	while (q--){
		int left, right;
		cin >> left >> right;
		cout << query(tree, 0, n-1, 1, left-1, right-1).index+1 << endl;
	}
}