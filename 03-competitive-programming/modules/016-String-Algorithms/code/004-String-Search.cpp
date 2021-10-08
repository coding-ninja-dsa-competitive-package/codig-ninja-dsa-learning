#include<bits/stdc++.h>

using namespace std;

/**
 *  String Search
 *  -   Given two strings S and T, write a function to find if T is present as a 
 *      substring inside S or not. If yes, return the starting index otherwise 
 *      return -1.
 *  
 *  Input format :
 *      Line 1 : String S
 *      Line 2 : String T
 *  
 *  Sample Input 1:
 *      WelcomeBack
 *      come 
 *  Sample Output 1:
 *      3
 * 
 *  Sample Input 2:
 *      WelcomeBack
 *      code
 *  Sample Output 2:
 *      -1
 */
int* getLongestPrefixSuffix(string pattern){
    int len = pattern.length();
    int* lps = new int[len];
    lps[0] = 0;
    int i=1, j=0;

    while(i < len) {
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            i++;
            j++;
        } else {
            if(j != 0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }   
        }
    }
    return lps;
}

int kmpSearch(string text, string pattern){
    int lenText = text.length();
    int lenPattern = pattern.length();
    int* lps = getLongestPrefixSuffix(pattern);
    int i=0, j=0;
    while(i < lenText && j < lenPattern) {
        if(text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return j==lenPattern ? i-j : -1;
}

int findString(char S[], char T[]) {
    string s = S;
    string p = T;
    return kmpSearch(s, p);
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
