#include <bits/stdc++.h>

using namespace std;

/**
 *  Maximum Pair Sum
 *  -   You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 
 *      2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined 
 *      as follows:
 *  
 *  -   Update:
 *          This will be indicated in the input by a 'U' followed by space and 
 *          then two integers i and x.
 *              U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
 *          This operation sets the value of A[i] to x.
 *  -   Query:
 *          This will be indicated in the input by a 'Q' followed by a single 
 *          space and then two integers i and j.
 *              Q x y, 1 ≤ x < y ≤ N.
 *  -   You must find i and j such that x ≤ i, j ≤ y and i != j, such that the 
 *      sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
 *  
 *  Input
 *      The first line of input consists of an integer N representing the length 
 *      of the sequence. 
 *      Next line consists of N space separated integers A[i]. Next line contains 
 *      an integer Q, Q ≤ 10^5, representing the number of operations. Next Q 
 *      lines contain the operations.
 *  Output
 *      Output the maximum sum mentioned above, in a separate line, for each Query.
 *  
 *  Input:
 *      5
 *      1 2 3 4 5
 *      6
 *      Q 2 4
 *      Q 2 5
 *      U 1 6
 *      Q 1 5   
 *      U 1 7   
 *      Q 1 5
 *  Output:
 *      7   
 *      9
 *      11
 *      12
 */

void buildTree(int *arr, pair<int, int> *tree, int start, int end, int treeNode){
    if (end == start) {
        tree[treeNode] = make_pair(arr[start], INT_MIN);
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid + 1, end, 2*treeNode+1);

    pair<int, int> left = tree[2*treeNode];
    pair<int, int> right = tree[2*treeNode+1];

    tree[treeNode].first = max(left.first, right.first);
    tree[treeNode].second = min(max(left.first, right.second), max(left.second, right.first));
}

void updateTree(int *arr, pair<int, int> *tree, int start, int end, int treeNode, int idx, int value){
    int mid = (start+end)/2;
    if (start == end){
        arr[idx] = value;
        tree[treeNode] = make_pair(value, INT_MIN);
        return;
    }
    if (idx <= mid){
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    } else {
        updateTree(arr, tree, mid + 1, end, 2*treeNode+1, idx, value);
    }

    pair<int, int> left = tree[2*treeNode];
    pair<int, int> right = tree[2*treeNode+1];
    tree[treeNode].first = max(left.first, right.first);
    tree[treeNode].second = min(max(left.first, right.second), max(left.second, right.first));
}

pair<int, int> queryTree(pair<int, int> *tree, int start, int end, int treeNode, int left, int right){
    if (left > end || right < start) {
        pair<int, int> temp = make_pair(INT_MIN, INT_MIN);
        return temp;
    }
    if (start >= left && end <= right){
        return tree[treeNode];
    }

    int mid = (start + end) / 2;
    pair<int, int> l = queryTree(tree, start, mid, 2*treeNode, left, right);
    pair<int, int> r = queryTree(tree, mid + 1, end, 2*treeNode+1, left, right);

    pair<int, int> maxPairSumNode;
    maxPairSumNode.first = max(l.first, r.first);
    maxPairSumNode.second = min(max(l.first, r.second), max(l.second, r.first));
    return maxPairSumNode;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    pair<int, int> *tree = new pair<int, int>[4*n];
    buildTree(arr, tree, 0, n-1, 1);

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;

        if (c == 'Q'){
            int l, r;
            cin >> l >> r;
            pair<int, int> maxPairSumNode = queryTree(tree, 0, n-1, 1, l-1, r-1);
            cout << maxPairSumNode.first + maxPairSumNode.second << endl;
        } else {
            int x, y;
            cin >> x >> y;
            updateTree(arr, tree, 0, n-1, 1, x-1, y);
        }
    }

    return 0;
}