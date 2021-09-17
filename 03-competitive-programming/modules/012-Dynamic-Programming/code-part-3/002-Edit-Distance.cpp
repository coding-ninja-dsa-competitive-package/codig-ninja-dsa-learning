#include<bits/stdc++.h>

using namespace std;

/**
 *  Code : Edit Distance
 *  -   You are given two strings S and T of lengths M and N, respectively. 
 *      Find the 'Edit Distance' between the strings.
 *  -   Edit Distance of two strings is the minimum number of steps required to make 
 *      one string equal to the other. In order to do so, you can perform the following 
 *      three operations:
 *      1. Delete a character
 *      2. Replace a character with another one
 *      3. Insert a character
 *  
 *  Note :
 *      Strings don't contain spaces in between.
 *  
 *  Input format :
 *      The first line of input contains the string S of length M.
 *      The second line of the input contains the String T of length N.
 *  Output format :
 *      Print the minimum 'Edit Distance' between the strings.
 *  
 *  Constraints :
 *      0 <= M <= 10 ^ 3
 *      0 <= N <= 10 ^ 3
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1 :
 *      abc
 *      dc
 *  Sample Output 1 :
 *      2
 *  Explanation to the Sample Input 1 :
 *      In 2 operations we can make string T to look like string S.
 *      First, insert character 'a' to string T, which makes it "adc".
 *      And secondly, replace the character 'd' of string T with 'b' from the string S. 
 *      This would make string T as "abc" which is also string S. 
 *      Hence, the minimum distance.
 *  
 *  Sample Input 2 :
 *      whgtdwhgtdg
 *      aswcfg
 *  Sample Output 2 :
 *      9
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