#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Remove Duplicates
 */ 
vector<int> removeDuplicates(int *arr, int n){
    vector<int> res;
    unordered_map<int, bool> mp;
    for(int i=0; i<n; i++){
        if(mp.count(arr[i]) > 0){
            continue;
        }
        mp[arr[i]] = true;
        res.push_back(arr[i]);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int *arr  = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> res = removeDuplicates(arr, n);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}