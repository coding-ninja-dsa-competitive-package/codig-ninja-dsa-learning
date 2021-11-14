#include<bits/stdc++.h>

using namespace std;

/**
 *  -   Wilson's theorem states that a natural number n > 1 is a prime number if and 
 *      only if the product of all the positive integers less than n is one less than   
 *      a multiple of n. That is (using the notations of modular arithmetic), the 
 *      factorial (n−1)!=1×2×3×⋯×(n−1) satisfies
 *          (n−1)! ≡ −1(mod n)
 *      exactly when n is a prime number. In other words, any number n is a prime 
 *      number if, and only if, (n − 1)! + 1 is divisible by n.[1]
 */

int modularExponentiation(int a, int b, int c){
    if(a==0){
        return 0;
    }
    if(b==0){
        return 1;
    }
    long ans;
    if(b%2==0) {
        long smallAns=modularExponentiation(a, b/2, c);
        ans=(smallAns*smallAns)%c;
    } else {
        long smallAns=modularExponentiation(a, b-1, c);
        ans=((a%c)*smallAns)%c;
    }
    return int((ans+c)%c);
}

int inverseMod(int a, int p){
    return modularExponentiation(a, p-2, p);
}

int wilson(int n, int p){
    if(n>=p){
        return 0;
    }
    int ans=-1;
    for(int i=n+1; i<=p-1; i++){
        ans=((ans%p)*(inverseMod(i, p)%p))%p;
    }
    return ans+p;
}

int main(){
    int n, p;
    cin >> n >> p;
    cout << wilson(n, p) << endl;
}