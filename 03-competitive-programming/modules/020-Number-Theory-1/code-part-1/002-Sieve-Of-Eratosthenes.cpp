#include<bits/stdc++.h>

using namespace std;

/**
 *  Find Prime Numbers From 1 to N
 *  -   Given a number N, find number of primes in the range [1,N].
 *      
 *  Input:
 *      The only line of input consists of a number N
 *  Output:
 *      Print the number of primes in the range [1,N].`
 *  Constraints:
 *      1≤N≤1000000
 *  
 *  Sample Input :
 *      3 
 *  Sample Output -
 *      2
 */ 

// sieve of eratosthenes - N*log(log(N))
int makeSieve(int n){
    bool isPrime[n+1];
    for(int i=0; i<=n ; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    int count=0;
    for(int i=0; i<=n; i++) {
        if(isPrime[i]){
            ++count;
        }
    }
    return count;
}

int main(){
    int n; 
    cin >> n;
    int numPrimes = makeSieve(n);
    cout << numPrimes << '\n';
    return 0;
}