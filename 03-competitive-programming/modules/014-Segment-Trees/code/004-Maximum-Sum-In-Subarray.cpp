#include<bits/stdc++.h>

using namespace std;

/**
 *  Maximum Sum In Subarray
 *  -   You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 
 *      1 ≤ N ≤ 50000 ). A query is defined as follows:
 *  -   Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
 *  -   Given M queries, your program must output the results of these queries.
 *  
 *  Input
 *      The first line of the input file contains the integer N.
 *      In the second line, N numbers follow.
 *      The third line contains the integer M.
 *      M lines follow, where line i contains 2 numbers xi and yi.
 *  Output
 *      Your program should output the results of the M queries, one query per line.
 *  
 *  Sample Input:
 *      3 
 *      -1 2 3 
 *      1
 *      1 2
 *  Sample Output:
 *      2
 */

struct node {
    int sum;
    int maxSum;
    int bestPrefixSum;
    int bestSuffixSum;
};

void buildTree(int* arr, node* tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].sum = arr[start];
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].bestPrefixSum = arr[start];
        tree[treeNode].bestSuffixSum = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    node l = tree[2*treeNode];
    node r = tree[2*treeNode+1];

    tree[treeNode].sum = l.sum + r.sum;
    tree[treeNode].bestPrefixSum = max(l.bestPrefixSum, l.sum + r.bestPrefixSum);
    tree[treeNode].bestSuffixSum = max(r.bestSuffixSum, r.sum + l.bestSuffixSum);
    tree[treeNode].maxSum = max(l.maxSum ,
                            max(r.maxSum, 
                            max(l.sum + r.bestPrefixSum, 
                            max(r.sum + l.bestSuffixSum, l.bestSuffixSum + r.bestPrefixSum))));
}

node queryTree(node* tree, int start, int end, int treeNode, int left, int right){
    if(start > right || end < left){
        return { -100000, -100000, -100000, -100000 };
    }
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node l = queryTree(tree, start, mid, 2*treeNode, left, right);
    node r = queryTree(tree, mid+1, end, 2*treeNode+1, left, right);
    node ans;
    ans.sum = l.sum + r.sum;
    ans.bestPrefixSum = max(l.bestPrefixSum , l.sum + r.bestPrefixSum);
    ans.bestSuffixSum = max(r.bestSuffixSum, r.sum + l.bestSuffixSum);
    ans.maxSum = max(l.maxSum, max(r.maxSum, 
                max(l.sum + r.bestPrefixSum, 
                max(r.sum + l.bestSuffixSum, l.bestSuffixSum + r.bestPrefixSum))));
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    node* tree = new node[4*n];
    buildTree(arr, tree, 0, n-1, 1);

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << queryTree(tree, 0, n-1, 1, x-1, y-1).maxSum << endl;
    }

    return 0;
}