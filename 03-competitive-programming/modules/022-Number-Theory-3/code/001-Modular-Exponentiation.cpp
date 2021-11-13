#include<bits/stdc++.h>

using namespace std;

/**
 *  Calculate (a^b % mod)
 */

// Recursive Approach
int modularExponentiation(int a, int b, int mod){
    if(a==0){
        return 0;
    }
    if(b==0){
        return 1;
    }
    long ans;
    if(b%2==0){
        long smallAns = modularExponentiation(a, b/2, mod);
        ans = (smallAns*smallAns) % mod;
    } else {
        long smallAns = modularExponentiation(a, b-1, mod);
        ans = (a%mod);
        ans = (ans*smallAns) % mod;
    }
    return int((ans+mod) % mod);
}

// Iterative Approach
int modularExponentiationIterative(int a, int b, int mod){
    int ans=1;
    while(b){
        if(b%2 == 1){
            ans = (ans*a) % mod;
        }
        a = (a*a) % mod;
        b = b/2;
    }
    return ans;
}

int main() {
    int a = 2;
    int b = 2783;
    int mod = 5;
    cout << modularExponentiation(a, b, mod) << endl;
    cout << modularExponentiationIterative(a, b, mod) << endl;

    return 0;
}