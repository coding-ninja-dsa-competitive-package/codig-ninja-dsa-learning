#include<bits/stdc++.h>

using namespace std;

/**
 *  -   Segment tree are best suited when we want to solve problems with a range.
 *  -   Size of Segment tree to be considered:
 *          2^(ceil(logn)) => 4n
 */

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(int* arr, int* tree, int start, int end, int treeNode, int idx, int value){
    if(start == end) {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid) {
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    } else {
        updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int queryTree(int* tree, int start, int end, int treeNode, int left, int right){
    //completely outside given range
    if(start > right || end < left){
        return 0;
    }
    //completely inside given range
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    //partially inside and partially outside range
    int mid = (start+end)/2;
    int ans1 = queryTree(tree, start, mid, 2*treeNode, left, right);
    int ans2 = queryTree(tree, mid+1, end, 2*treeNode+1, left, right);
    return ans1+ans2;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int* tree = new int[10];
    //  Build Tree
    buildTree(arr, tree, 0, 4, 1);
    cout << "build tree : ";
    for(int i=1; i<10; i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    //  Update Tree
    updateTree(arr, tree, 0, 4, 1, 2, 10);
    cout << "update tree : ";
    for(int i=1; i<10; i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    //  Query Tree
    int ans = queryTree(tree, 0, 4, 1, 2, 4);
    cout << "query tree : " << ans << endl;

    return 0;
}