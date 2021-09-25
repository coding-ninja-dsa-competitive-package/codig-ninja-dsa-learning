#include<bits/stdc++.h>

using namespace std;

/**
 *  Horrible Queries
 *  -   World is getting more evil and it's getting tougher to get into the Evil 
 *      League of Evil. Since the legendary Bad Horse has retired, now you have 
 *      to correctly answer the evil questions of Dr. Horrible, who has a PhD in 
 *      horribleness (but not in Computer Science). You are given an array of N 
 *      elements, which are initially all 0. After that you will be given C 
 *      commands. They are - 0 p q v - you have to add v to all numbers in the 
 *      range of p to q (inclusive), where p and q are two indexes of the array.
 *  -   1 p q - output a line containing a single integer which is the sum of 
 *      all the array elements between p and q (inclusive)
 *  
 *  Input
 *      In the first line you'll be given T, number of test cases.
 *      Each test case will start with N (N <= 100 000) and C (C <= 100 000). After 
 *      that you'll be given C commands in the format as mentioned above. 1 <= p, 
 *      q <= N and 1 <= v <= 10^7.
 *  Output
 *      Print the answers of the queries.
 *  
 *  Input:
 *      1
 *      8 6
 *      0 2 4 26
 *      0 4 8 80
 *      0 4 5 20
 *      1 8 8 
 *      0 5 7 14
 *      1 4 8
 *  Output:
 *      80  
 *      508
 */

typedef long long int ll;

void updateTree(ll* tree, ll* lazy, ll start, ll end, ll treeNode, ll left, ll right, ll value){
    if(start > end){
        return;
    }
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end-start+1) * lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    //  completely outside
    if(start > right || end < left){
        return;
    }
    //  completely inside
    if(start >= left && end <= right){
        tree[treeNode] += (end-start+1) * value;
        if(start != end){
            lazy[2*treeNode] += value;
            lazy[2*treeNode+1] += value;
        }
        return;
    }
    //  partially inside
    ll mid = (start + end) / 2;
	updateTree(tree, lazy, start, mid, 2*treeNode, left, right, value);
	updateTree(tree, lazy, mid+1, end, 2*treeNode+1, left, right, value);
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

ll queryTree(ll* tree, ll* lazy, ll start, ll end, ll treeNode, ll left, ll right){
    if(start > end){
        return 0;
    }
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end-start+1)*lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
            lazy[2*treeNode+1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    //completely outside
    if(start > right || end < left){
        return 0;
    }
    // compleetely inside
    if(start >= left && end <= right){
        return tree[treeNode];
    }
    //  partially inside
    ll mid = (start + end) / 2;
	ll l = queryTree(tree, lazy, start, mid, 2*treeNode, left, right);
	ll r = queryTree(tree, lazy, mid+1, end, 2*treeNode+1, left, right);
	return (l + r);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        ll* tree = new ll[4*n]();
        ll* lazy = new ll[4*n]();

        while(q--){
            ll oper;
            cin >> oper;
            if(oper == 0){
                ll left, right, value;
                cin >> left >> right >> value;
                updateTree(tree, lazy, 0, n-1, 1, left-1, right-1, value);
            } else {
                ll left, right;
                cin >> left >> right;
                cout << queryTree(tree, lazy, 0, n-1, 1, left-1, right-1) << endl;
            }
        }
    }

    return 0;
}