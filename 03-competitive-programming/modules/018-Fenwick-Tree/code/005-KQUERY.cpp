#include<bits/stdc++.h>

using namespace std;

/**
 *  KQUERY
 *  -   Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. 
 *      A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), 
 *      you have to return the number of elements greater than k in the subsequence 
 *      ai, ai+1, ..., aj.
 *  
 *  Input Format
 *      Line 1: n (1 ≤ n ≤ 30000).
 *      Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).
 *      Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.
 *      In the next q lines, each line contains 3 numbers i, j, k representing a 
 *      k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
 *  Output Format
 *      For each k-query (i, j, k), print the number of elements greater than k in 
 *      the subsequence ai, ai+1, ..., aj in a single line.
 *  
 *  Sample Input
 *      5
 *      5 1 2 3 4
 *      3
 *      2 4 1
 *      4 4 4
 *      1 5 2 
 *  Sample Output
 *      2
 *      0   
 *      3 
 */

int res[200002];
int binaryIndexTree[30002];

int query(int index){
    int ans=0;
    for(; index>0;  index -= index & (-index)){
        ans += binaryIndexTree[index];
    }
    return ans;
}

void update(int index,int n){
    for(; index<=n; index += index & (-index)){
        binaryIndexTree[index]++;
    }
}

int main(){
    int n;
    cin>>n;
    vector < pair <int,int > > arr;
    vector < pair <pair <int,int >,pair <int,int> > > queries;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        arr.push_back(make_pair(x,i));
    }
    sort(arr.begin(),arr.end());

    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int left,right,value;
        cin >> left >> right >> value;
        queries.push_back(make_pair(make_pair(value,i),make_pair(left,right)));
    }
    sort(queries.begin(), queries.end(), greater<pair <pair <int,int> ,pair <int,int> > >());
    
    for(int i=0; i<queries.size(); i++){
        pair <pair <int,int> ,pair <int,int> > p = queries[i];
        int value = p.first.first;
        int index =p.first.second;
        int left= p.second.first;
        int right = p.second.second;
        for(int j=arr.size()-1; j>=0; j--){
            if(arr[j].first>value){
                update(arr[j].second,n);
                arr.pop_back();
            } else {
                break;
            }
        }
        res[index] = query(right)-query(left-1);
    }

    for(int i=1; i<=queries.size(); i++) {
        cout << res[i] << "\n";
    }
    return 0;
}