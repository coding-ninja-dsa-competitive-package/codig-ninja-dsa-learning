#include<bits/stdc++.h>

using namespace std;

/**
 *  Number of APs
 *  -   Given an array of n positive integers. The task is to count the number 
 *      of Arithmetic Progression subsequences in the array. As the answer could 
 *      be very large, output it modulo 100001.
 *  -   Note: Empty sequence or single element sequence is Arithmetic Progression.
 *  
 *  Input Format:
 *      First Line: N (the size of the array)
 *      Second Line: Elements of the array separated by spaces.
 *  Output:
 *      Print total number of subsequences
 *  Input Constraints:
 *      1 <= arr[i] <= 1000
 *      1 <= sizeof(arr) <= 1000
 *  
 *  Sample Input 1 :
 *      3
 *      1 2 3
 *  Sample output:
 *      8
 *  Sample Output Explanation:
 *      Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, 
 *      { 1, 3 }, { 1, 2, 3 }
 * 
 *  Sample Input 2:
 *      7
 *      1 2 3 4 5 9 10
 *  Sample Output:
 *      37
 */

#include<unordered_map>
using namespace std;

#define MOD 100001

int numofAP(int *arr, int n){
    int ans=n+1;
    unordered_map<int, int>* map = new unordered_map<int, int>[n];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int diff = arr[j]-arr[i];
            map[i][diff] += 1;
            ans = (ans+1)%MOD;
        }
    }
    for(int i=n-3; i>=0; i--){
        for(int j=i+1; j<n; j++){
            int diff = arr[j]-arr[i];
            map[i][diff] = (map[i][diff]%MOD + map[j][diff]%MOD)%MOD;
            ans = (ans%MOD + map[j][diff]%MOD)%MOD;
        }
    }
    delete [] map;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << numofAP(arr, n) << endl;
}