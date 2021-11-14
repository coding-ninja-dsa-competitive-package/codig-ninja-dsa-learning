#include<bits/stdc++.h>

using namespace std;

/**
 *  -   Fermat’s little theorem states that if p is a prime number, then for any 
 *      integer a, the number a p – a is an integer multiple of p. 
 *  -   Here p is a prime number 
 *          a^p ≡ a (mod p).
 *  -   Special Case: If a is not divisible by p, Fermat’s little theorem is 
 *      equivalent to the statement that a^(p-1) - 1 is an integer multiple of p. 
 * 
 *  -   Take an Example How Fermat’s little theorem works 
 *      Examples:  
 *          P = an integer Prime number   
 *          a = an integer which is not multiple of P  
 *          Let a = 2 and P = 17 
 *          According to Fermat's little theorem 
 *          2 17 - 1     ≡ 1 mod(17)
 *          we got  65536 % 17 ≡ 1   
 *          that mean (65536-1) is an multiple of 17 
 */

int power(int x, unsigned int y, unsigned int mod){
    if (y==0){
        return 1;
    }
    int p = power(x, y/2, mod) % mod;
    p = (p*p) % mod;

    return (y%2 == 0) ? p : (x*p)%mod;
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

void modInverse(int a, int m){
    if (gcd(a, m) != 1){
        cout << "Inverse doesn't exist";
    } else {
        cout << "Modular multiplicative inverse is " << power(a, m-2, m);
    }
}
int main(){
    int a=3, m=11;
    modInverse(a, m);
    return 0;
}