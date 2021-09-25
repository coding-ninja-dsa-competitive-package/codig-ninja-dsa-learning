#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

typedef long long ll;

ll tree[400000];
ll arr[100000];

void buildTree(int treeNode, int start, int end){
    if (start > end){
        return;
    }
    if (start == end){
        tree[treeNode] = arr[start] * arr[start];
        return;
    }
    int mid = (start + end)/2;
    int left = 2*treeNode;
    int right = left + 1;
    buildTree(left, start, mid);
    buildTree(right, mid+1, end);
    tree[treeNode] = tree[left] + tree[right];
}

void updateIncrement(int treeNode, int start, int end, int l, int r, int value){
    if (start > end || start > r || end < l){
        return;
    }
    if (start == end){
        arr[start] += value;
        tree[treeNode] = arr[start] * arr[start];
        return;
    }
    int mid = (start+end) / 2;
    int left = 2*treeNode;
    int right = left + 1;
    updateIncrement(left, start, mid, l, r, value);
    updateIncrement(right, mid+1, end, l, r, value);
    tree[treeNode] = tree[left] + tree[right];
}

void updateSetter(int treeNode, int start, int end, int l, int r, int value){
    if (start > end || start > r || end < l){
        return;
    }
    if (start == end){
        arr[start] = value;
        tree[treeNode] = arr[start] * arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int left = 2*treeNode;
    int right = left + 1;
    updateSetter(left, start, mid, l, r, value);
    updateSetter(right, mid+1, end, l, r, value);
    tree[treeNode] = tree[left] + tree[right];
}

ll queryTree(int treeNode, int start, int end, int l, int r){
    if (start > end || start > r || end < l){
        return 0;
    }
    if (l <= start && end <= r){
        return tree[treeNode];
    }
    int mid = (start+end) / 2;
    int left = 2*treeNode;
    int right = left + 1;
    ll ans1 = queryTree(left, start, mid, l, r);
    ll ans2 = queryTree(right, mid+1, end, l, r);
    return ans1 + ans2;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        buildTree(1, 0, n - 1);
        int flag = 0;

        int q;
        cin >> q;
        while (q--){
            int type;
            cin >> type;
            if (type == 0){
                int st, end, x;
                cin >> st >> end >> x;
                updateSetter(1, 0, n - 1, st - 1, end - 1, x);
            } else if (type == 1){
                int st, end, x;
                cin >> st >> end >> x;
                updateIncrement(1, 0, n - 1, st - 1, end - 1, x);
            } else {
                int st, end;
                cin >> st >> end;
                cout << queryTree(1, 0, n - 1, st - 1, end - 1) << endl;
            }
        }
    }
    return 0;
}