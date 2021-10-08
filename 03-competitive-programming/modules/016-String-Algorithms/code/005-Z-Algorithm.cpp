#include<bits/stdc++.h>

using namespace std;

/** 
 *  Z function(k) : length of the longest substring starting at K which is also the 
 *                  prefix of the string.
 */ 

void build(int* zArr, string str){
    int l=0, r=0, n=str.length();
    for(int i=1; i<n; i++) {
        if(i > r){
            // i does not lie between l and r
            // Z for this doesn't exist
            l=i, r=i;
            while(r<n && str[r-l] == str[r]){
                r++;
            }
            zArr[i] = r-l;
            r--;
        } else {
            int k = i-1;
            if(zArr[k] <= r-i){
                // i lies between l and r
                // Z will exist previously
                zArr[i] = zArr[k];
            } else {
                // some part of Z is already included
                //  you have to start matching further
                l = i;
                while(r<n && str[r-l] == str[r]){
                    r++;
                }
                zArr[i] = r-l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern){
    string str = pattern + "$" + text;
    int n = str.length();
    int* zArr = new int[n]();
    build(zArr, str);
    for(int i=0; i<n; i++){
        if(zArr[i] == pattern.length()){
            cout << i-pattern.length()-1 << endl;
        }
    }
}

int main() {
    string text = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    searchString(text, pattern);

    return 0;
}