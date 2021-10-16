#include<bits/stdc++.h>

using namespace std;

/**
 *  Counting Strings
 *  -   Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 
 *      'Z'. Your task is to find how many strings 't' with length equal to that 
 *      of 's', also consisting of upper case alphabets are there satisfying the 
 *      following conditions:
 *      -   String 't' is lexicographical larger than string 's'.
 *      -   When you write both 's' and 't' in the reverse order, 't' is still 
 *          lexicographical larger than 's'.
 *  -   Find out number of such strings 't'. As the answer could be very large, 
 *      take MODulo 10^9 + 7.
 *  
 *  Input Format:
 *      The first and only line of input contains the string s.
 *  Output Format:
 *      Output the number of strings (t) %(10^9 + 7) in new line.
 *  Constraints:
 *      1 <= |S| <= 10^5
 *  
 *  Sample Input 1:
 *      A
 *  Sample Output 1:
 *      25
 *  
 *  Sample Input 2:
 *      XKS
 *  Sample Output 2:
 *      523
 */ 

#define MOD 1000000007
typedef long long int ll;

int countStrings(char* str) {
    int n = strlen(str);
    ll idx=0, dp[100005], arr[100005], ans=0;
    for(int i=0; i<n; i++){
        arr[i] = (ll)(90 - str[i]);
    }

    dp[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        idx = (arr[i+1] + (26*idx)%MOD) % MOD;
        dp[i] = (arr[i] + (arr[i]*idx) % MOD) % MOD;
    }
    
    for(int i=0; i<n; i++){
        ans = (ans+dp[i]) % MOD;
    }
    ans = ans%MOD;
    return ans;
}

int main() {
    char s[100005];
    cin >> s;
    int ans = countStrings(s);
    cout << ans << endl;

    return 0;
}