#include<bits/stdc++.h>

using namespace std;

/**
 *  2 vs 3
 *  -   The fight for the best number in the globe is going to finally come to 
 *      an end.The top two contenders for the best number are number 2 and 
 *      number 3.It's the final the entire world was waiting for. Expectorates 
 *      from all across the globe came to witness the breath taking finals.
 *  -   The finals began in an astonishing way.A common problem was set for 
 *      both of them which included both these number.The problem goes like this.
 *  -   Given a binary string (that is a string consisting of only 0 and 1). 
 *      They were supposed to perform two types of query on the string.
 *  -   Type 0: Given two indices l and r.Print the value of the binary string 
 *              from l to r modulo 3.
 *      Type 1: Given an index l flip the value of that index if and only if the 
 *              value at that index is 0.
 *  -   The problem proved to be a really tough one for both of them.Hours passed 
 *      by but neither of them could solve the problem.So both of them wants you 
 *      to solve this problem and then you get the right to choose the best number 
 *      in the globe.
 *  
 *  Input:
 *      The first line contains N denoting the length of the binary string .
 *      The second line contains the N length binary string.Third line contains 
 *      the integer Q indicating the number of queries to perform.
 *      This is followed up by Q lines where each line contains a query.
 *  Output:
 *      For each query of Type 0 print the value modulo 3.
 *  
 *  Constraints:
 *      1<= N <=10^5
 *      1<= Q <= 10^5
 *      0 <= l <= r < N
 *  
 *  Sample Input
 *      5
 *      10010
 *      6
 *      0 2 4
 *      0 2 3
 *      1 1
 *      0 0 4
 *      1 1
 *      0 0 3
 *  Sample Output   
 *      2
 *      1   
 *      2
 *      1
 */
int treeHelper[100001];

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
	if (start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	int right_child = tree[2*treeNode+1];
	int left_child = tree[2*treeNode];
	tree[treeNode] = (treeHelper[end-mid]*left_child + right_child)%3;
}

void updateTree(int *arr, int* tree, int start, int end, int treeNode, int index){
	if (start == end){
		arr[index]=1;
        tree[treeNode]=1;
        return;
    }
	int mid = (start + end) / 2;
	if (index > mid){
		updateTree(arr, tree, mid+1, end, 2*treeNode+1, index);
	} else {
		updateTree(arr, tree, start, mid, 2*treeNode, index);
	}

	int right_child = tree[2*treeNode+1];
	int left_child = tree[2*treeNode];
	tree[treeNode] = (treeHelper[end-mid]*left_child + right_child)%3;
}

int queryTree(int* tree, int start, int end, int treeNode, int left, int right){
	if (start > right || end < left){
		return 0;
	}
	if (start >= left && end <= right){
		return (tree[treeNode]*treeHelper[right-end])%3;
	}
	int mid = (start + end) / 2;
	int left_child = queryTree(tree, start, mid, 2*treeNode, left, right);
	int right_child = queryTree(tree, mid+1, end, 2*treeNode+1, left, right);
	return (left_child+right_child)%3;
}

int main(){
    treeHelper[0] = 1;
    for(int i = 1; i < 100001; i++){
        treeHelper[i] = (treeHelper[i-1]*2)%3;
    }

	int n;
	cin >> n;
	string s;
	cin >> s;
	int* arr = new int[n];
	for (int i = 0; i < n; i++){
		arr[i] = s[i]-'0';
	}

	int* tree = new int[4 * n]();
	buildTree(arr, tree, 0, n - 1, 1);
	
    int q;
	cin >> q;
	while (q--){
		int oper;
		cin >> oper;
		if (oper == 0){
			int left, right;
			cin >> left >> right;
			cout << queryTree(tree, 0, n - 1, 1, left, right) << endl;;
		} else {
			int index;
			cin >> index;
            if(arr[index]==0){
			    updateTree(arr, tree, 0, n - 1, 1, index);
            }
		}
	}
}