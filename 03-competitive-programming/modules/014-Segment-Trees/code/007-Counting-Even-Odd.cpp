#include<bits/stdc++.h>

using namespace std;

/**
 *  Counting Even/Odd
 *  -   Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to 
 *      test his intelligence.He gives him an array of N natural numbers and asks   
 *      him to solve the following queries:-
 *  -   Query 0 :- modify the element present at index i to x.
 *      Query 1:- count the number of even numbers in range l to r inclusive.
 *      Query 2:- count the number of odd numbers in range l to r inclusive.
 *      
 *  Input:
 *      First line of the input contains the number N. Next line contains N
 *       natural numbers. 
 *      Next line contains an integer Q followed by Q queries.
 *      0 x y - modify the number at index x to y. 
 *      1 x y - count the number of even numbers in range l to r inclusive.
 *      2 x y - count the number of odd numbers in range l to r inclusive.
 * 
 *  Constraints:
 *      1<=N,Q<=10^5
 *      1<=l<=r<=N 
 *      0<=Ai<=10^9
 *      1<=x<=N
 *      0<=y<=10^9
 *    
 *  Note:-
 *      indexing starts from 1.
 *      
 *  Sample Input
 *      6
 *      1 2 3 4 5 6
 *      4
 *      1 2 5
 *      2 1 4
 *      0 5 4
 *      1 1 6
 *  Sample Output
 *      2
 *      2   
 *      4
 */

struct node{
    int even, odd;
};

void buildTree(int* arr, node* tree, int start, int end, int treeNode){
    if(start == end){
		if(arr[start]%2 == 0){
            tree[treeNode].odd = 0;
            tree[treeNode].even = 1;
        } else {
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    node l = tree[2*treeNode];
    node r = tree[2*treeNode+1];
    tree[treeNode].odd = l.odd + r.odd;
    tree[treeNode].even = l.even + r.even;
}

void updateTree(int* arr, node* tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
		if(value%2 == 0){
            tree[treeNode].odd = 0;
            tree[treeNode].even = 1;
        } else {
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }
    
    int mid = (start+end)/2;
    if(idx > mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    } else {
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    
    node l = tree[2*treeNode];
    node r = tree[2*treeNode+1];
    tree[treeNode].odd = l.odd + r.odd;
    tree[treeNode].even = l.even + r.even;
}

node queryTree(node* tree, int start, int end, int treeNode, int left, int right){
	if(start > right || end < left){
        return { 0, 0 };
    }    
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    
    int mid = (start+end)/2;
    node l = queryTree(tree, start, mid, 2*treeNode, left, right);
    node r = queryTree(tree, mid+1, end, 2*treeNode+1, left, right);
    node ans;
    ans.even = l.even + r.even;
    ans.odd = l.odd + r.odd;
    return ans;
}

int main() {
	int n;
    cin >> n;
    
	int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    node* tree = new node[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin >> q;
    while(q--){
        int oper;
        cin >> oper;
        if(oper == 0){
            int idx, value;
            cin >> idx >> value;
            updateTree(arr, tree, 0, n-1, 1, idx-1, value);
        } else if(oper == 1) {
            int left, right;
            cin >> left >> right;
            node ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
            cout << ans.even << endl;
        } else if(oper == 2) {
            int left, right;
            cin >> left >> right;
            node ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
            cout << ans.odd << endl;
        }
    }
}