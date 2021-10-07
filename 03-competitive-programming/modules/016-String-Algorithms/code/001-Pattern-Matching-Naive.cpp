#include<bits/stdc++.h>

using namespace std;

/**
 *  Given 2 string (s, p). We need to find if p is a matching pattern in s. 
 */

// Complexity - O(n*m)
bool isMatching(string s, string p){
    int n = s.length();
    int m = p.length();
    for(int i=0; i<n+m; i++){
        bool isFound = true;
        for(int j=0; j<m; j++){
            if(s[i+j] != p[j]) {
                isFound = false;
                break;
            }
        }
        if(isFound){
            return true;
        }
    }
    return false;
}

int main() {
    string s, p;
    cin >> s >> p;

    isMatching(s, p) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}