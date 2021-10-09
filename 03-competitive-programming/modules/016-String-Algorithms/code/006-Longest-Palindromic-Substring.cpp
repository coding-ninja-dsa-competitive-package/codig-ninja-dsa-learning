#include<bits/stdc++.h>

using namespace std;

int longestPalindromicSubstring(string s){
    int maximum = 0;
    int n = s.length();
    for(int i=0; i<n; i++){
        // odd length
        int l=i, r=i;
        while(l >= 0 && r<n && s[l]==s[r]){
            int curr_l = r-l+1;
            if(curr_l > maximum){
                maximum = curr_l;
            }
            l--;
            r++;
        }

        // even length
        l=i, r=i+1;
        while(l >= 0 && r<n && s[l]==s[r]){
            int curr_l = r-l+1;
            if(curr_l > maximum){
                maximum = curr_l;
            }
            l--;
            r++;
        }
    }
    return maximum;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindromicSubstring(s) << endl;

    return 0;
}