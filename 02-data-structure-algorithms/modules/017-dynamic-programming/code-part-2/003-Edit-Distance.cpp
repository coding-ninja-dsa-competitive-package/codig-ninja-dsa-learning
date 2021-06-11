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
 *  Code : Edit Distance
 *  -   Given two strings s and t of lengths m and n respectively, find 
 *      the edit distance between the strings.
 *  -   Edit Distance
 *      -   Edit Distance of two strings is minimum number of operations 
 *          required to make one string equal to other. In order to do so 
 *          you can perform any of the following three operations only :
 *          1. Delete a character
 *          2. Replace a character with another one
 *          3. Insert a character
 * 
 *  Input Format :
 *      The first line of input contains a string, that denotes the value 
 *      of s. The following line contains a string, that denotes the value of t.
 *  Output Format :
 *      The first and only line of output contains the edit distance value 
 *      between the given strings.
 * 
 *  Constraints :
 *      1<= m,n <= 10
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1 :
 *      abc
 *      dc
 *  Sample Output 1 :
 *      2
 */
// Approach 1 - Brute Force - O(3^n)
int editDistance(string s1, string s2) {
    if(s1.length() == 0 || s2.length() == 0){
        return max(s1.length(), s2.length());
    } 

    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    } else{
        int ans1 = 1 + editDistance(s1.substr(1), s2);
        int ans2 = 1 + editDistance(s1, s2.substr(1));
        int ans3 = 1 + editDistance(s1.substr(1), s2.substr(1));
        return min(ans1, min(ans2, ans3));
    }
}
// Approach 2 - Memoization - Recusrion
int editDistanceRec(string s1, string s2, int** arr) {
    int n = s1.size();
    int m = s2.size();
    if(n == 0 || m == 0){
        return max(n, m);
    } 

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    if(s1[0] == s2[0]){
        arr[n][m] = editDistanceRec(s1.substr(1), s2.substr(1), arr);
    } else{
        int ans1 = 1 + editDistanceRec(s1.substr(1), s2, arr);
        int ans2 = 1 + editDistanceRec(s1, s2.substr(1), arr);
        int ans3 = 1 + editDistanceRec(s1.substr(1), s2.substr(1), arr);
        arr[n][m] = min(ans1, min(ans2, ans3));
    }
    return arr[n][m];
}
int editDistance2(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
        for(int j=0; j<=m; j++){
            arr[i][j] = -1;
        }
    }
    return editDistanceRec(s1, s2, arr);
}
// Approach 3 - DP - O(n*m)
int editDistance3(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
    }
    for(int j=0; j<=m; j++){
        arr[0][j] = j;
    }
    for(int i=1; i<=n; i++){
        arr[i][0] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[n-i] == s2[m-j]){
                arr[i][j] = arr[i-1][j-1];
            } else {
                int ans1 = 1 + arr[i-1][j];
                int ans2 = 1 + arr[i][j-1];
                int ans3 = 1 + arr[i-1][j-1];
                arr[i][j] = min(ans1, min(ans2, ans3));
            }
        }
    }
    return arr[n][m];
}

int main(){
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    cout << editDistance(s1, s2) << endl;
    cout << editDistance2(s1, s2) << endl;
    cout << editDistance3(s1, s2) << endl;

    return 0;
}