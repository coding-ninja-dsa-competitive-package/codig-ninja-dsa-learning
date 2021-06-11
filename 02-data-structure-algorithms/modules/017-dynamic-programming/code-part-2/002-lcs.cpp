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
 *  Largest Common SubSequence from two strings
 */
// Approach 1 - Brute Force - Recursion - O(3^n)
int lcs(string s1, string s2){
    if(s1.length() == 0 || s2.length() == 0){
        return 0;
    }
    if(s1[0] == s2[0]){
        return 1 + lcs(s1.substr(1), s2.substr(1));
    } else {
        int a = lcs(s1.substr(1), s2);  
        int b = lcs(s1, s2.substr(1));
        int c = lcs(s1.substr(1), s2.substr(1));
        return max(a, max(b, c));
    }
}
// Approach 2 - Memoization - Recursion - O(m*n)
int lcsMemo(string s1, string s2, int** arr){
    int m = s1.size();
    int n = s2.size();
    // Base Case
    if(m == 0 || n == 0){
        return 0;
    }
    // Check if result already exist
    if(arr[m][n] != -1){
        return arr[m][n];
    }
    // Recursive Calls
    int ans;
    if(s1[0] == s2[0]){
        ans = 1 + lcsMemo(s1.substr(1), s2.substr(1), arr);
    } else {
        int a = lcsMemo(s1.substr(1), s2, arr);
        int b = lcsMemo(s1, s2.substr(1), arr);
        int c = lcsMemo(s1.substr(1), s2.substr(1), arr);
        ans = max(a, max(b, c));
    }
    arr[m][n] = ans;
    return ans;
}
int lcs2(string s1, string s2){
    int n = s1.length()+1;
    int m = s2.length()+1;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            arr[i][j] = -1;
        }
    }
    return lcsMemo(s1, s2, arr);
}
// Approach 3 - DP - O(m*n)
int lcs3(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int **arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
    }
    for(int i=0; i<=n; i++){
        arr[i][0] = 0;
    }
    for(int j=0; j<=m; j++){
        arr[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ans;
            if(s1[n-i] == s2[m-j]){
                ans = 1 +  arr[i-1][j-1];
            } else {
                int a = arr[i-1][j];
                int b = arr[i][j-1];
                int c = arr[i-1][j-1];
                ans = max(a, max(b, c));
            }
            arr[i][j] = ans;
        }
    }
    return arr[n][m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    cout << lcs2(s1, s2) << endl;
    cout << lcs3(s1, s2) << endl;

    return 0;
}