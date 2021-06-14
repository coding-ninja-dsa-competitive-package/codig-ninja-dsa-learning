#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[4000];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        sort(arr, arr+n);
        
        int sum=0; 
        int size=n/4;
        int idx = n-3;
        for(int i=size; i>0; i--){
            sum += arr[idx];
            idx -= 3;
        }
        
        cout << sum << endl;
    }
    return 0;
}