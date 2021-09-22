#include<bits/stdc++.h>

using namespace std;

/**
 *  Lazy Propagation 
 */

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    tree[treeNode] = min(tree[2*treeNode] ,tree[2*treeNode+1]);
}

void updateSegmentTreeLazy(int* tree, int* lazy, int low, int high, int start, int end, int currPos, int inc){
    if(low > high){
        return;
    }
    if(lazy[currPos] != 0){
        tree[currPos] += lazy[currPos];
        if(low != high){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }
        lazy[currPos] = 0;
    }

    // No overlap
    if(start > high || end < low){
        return;
    }
    // complete overlap
    if(start >= low && high <= end){
        tree[currPos] += inc;
        if(low != high){
            lazy[2*currPos] += inc;
            lazy[2*currPos+1] += inc;
        }
        return;
    }
    // partial overlap
    int mid = (low + high)/2;
    updateSegmentTreeLazy(tree, lazy, low, mid, start, end, 2*currPos, inc);
    updateSegmentTreeLazy(tree, lazy, mid+1, high, start, end, 2*currPos+1, inc);
    tree[currPos] = min(tree[2*currPos], tree[2*currPos+1]);
}

int main() {
    int arr[] = {1, 3, -2, 4};
    int* tree = new int[12]();
    buildTree(arr, tree, 0, 3, 1);

    int* lazy = new int[12]();
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 3, 1, 3);
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 1, 1, 2);

    cout << "Segment Tree : ";
    for(int i=1; i<12; i++){
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << "Lazy Tree : ";
    for(int i=1; i<12; i++){
        cout << lazy[i] << " ";
    }
    cout << endl;

    return 0;
}