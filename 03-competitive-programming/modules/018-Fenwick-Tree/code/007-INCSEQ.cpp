#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

/**
 *  INCSEQ
 *  -   Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), 
 *      compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 
 *      and K ≤ N); that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 
 *      < ... < iK ≤ N and Si1 < ... < SiK.
 *  
 *  Input
 *      The first line contains the two integers N and K. The following N lines 
 *      contain the integers of the sequence in order.
 *  Output
 *      Print a single integer representing the number of increasing subsequences 
 *      of S of length K, modulo 5,000,000.
 *  
 *  Sample Input
 *      4 3
 *      1
 *      2
 *      2
 *      10
 *  Output:
 *      2
 */
typedef long long int ll;
#define M 5000000;

ll n, k;
ll binaryIndexTree[52][300001];

void update(ll index, ll val, ll i){
    for(; index <= n; index += index & (-index)){
        binaryIndexTree[i][index] = (binaryIndexTree[i][index] + val) % M;
    }
}

ll query(ll index, ll i){
    ll res = 0;
    for(; index > 0; index -= index & (-index)){
        res = (binaryIndexTree[i][index] + res) % M;
    }
    return res;
}

void compress(vector<ll> &arr){
    vector<ll> b = arr;
    sort(b.begin(), b.end());
    unordered_map<ll, ll> map;
    for (ll i=1, c=1; i<=n; i++){
        if (map.find(b[i]) == map.end())
            map[b[i]] = c++;
    }
    for (ll i=1; i<=n; i++){
        arr[i] = map[arr[i]];
    }
}

int main(){
    cin >> n >> k;
    if (k == 1){
        cout << n;
        return 0;
    }
    vector<ll> arr(n+1);
    for (ll i=1; i<=n; i++){
        cin >> arr[i];
    }
    compress(arr);

    ll ans = 0;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=k; j++){
            ll p = (j==1 ? 1 : query(arr[i]-1, j-1));
            update(arr[i], p, j);
            if (j == k){
                ans = (ans + p) % M;
            }
        }
    }
    cout << ans << endl;

    return 0;
}