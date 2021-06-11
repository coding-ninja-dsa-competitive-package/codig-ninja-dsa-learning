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
 *  Code : No. of balanced BTs
 *  -   Given an integer h, find the possible number of balanced binary 
 *      trees of height h. You just need to return the count of possible 
 *      binary trees which are balanced.
 *  -   This number can be huge, so, return output modulus 10^9 + 7.
 * 
 *  Input Format :
 *      The first and only line of input contains an integer, that denotes 
 *      the value of h. Here, h is the height of the tree.
 *  Output Format :
 *      The first and only line of output contains the count of balanced 
 *      binary trees modulus 10^9 + 7.
 *  
 *  Constraints :
 *      1 <= h <= 24
 * 
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      3
 *  Sample Output 1:
 *      15
 * 
 *  Sample Input 2:
 *      4
 *  Sample Output 2:
 *      315
 */
// Approach 1 - Brute Force - O(2^n)
#define M 1000000007

int balancedBTs(int n) {
    if(n <= 1){
        return 1;
    }
    int a = balancedBTs(n-1);
    int b = balancedBTs(n-2);
    int ans1 = (int)(((long)(a)*a)%M);
    int ans2 = (int)((2*(long)(a)*b)%M);
    int ans = (int)(ans1 + ans2)%M;
    return ans;
}

/**
 *  Code : No. of balanced BTs using DP
 */
// Approach 2 - Memoization - Recursive
int balancedBTs(int n, int* arr) {
    if(arr[n] != -1){
        return arr[n];
    }
    int a = balancedBTs(n-1, arr);
    int b = balancedBTs(n-2, arr);
    int ans1 = (int)(((long)(a)*a)%M);
    int ans2 = (int)((2*(long)(a)*b)%M);
    arr[n] = (int)(ans1 + ans2)%M;
    return arr[n];
}
int balancedBTsMemo(int n){
    int* arr = new int[n+1];
    arr[0] = arr[1] = 1;
    for(int i=2; i<=n; i++){
        arr[i] = -1;
    }
    return balancedBTs(n, arr);
}
// Approach 3 - DP - O(n)
int balancedBTsDP(int n){
    int* arr = new int[n+1];
    arr[0] = arr[1] = 1;
    for(int i=2; i<=n; i++){
        int a = arr[i-1];
        int b = arr[i-2];
        int ans1 = (int)(((long)(a)*a)%M);
        int ans2 = (int)((2*(long)(a)*b)%M);
        arr[i] = (int)((ans1 + ans2)%M);
    }
    return arr[n];
}
int main(){
    int n;
    cin >> n;
    cout << balancedBTs(n) << endl; 
    cout << balancedBTsMemo(n) << endl;
    cout << balancedBTsDP(n) << endl;

    return 0;
}