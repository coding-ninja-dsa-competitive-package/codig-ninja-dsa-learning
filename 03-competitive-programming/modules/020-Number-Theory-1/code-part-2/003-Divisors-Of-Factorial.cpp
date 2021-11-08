#include<bits/stdc++.h>

using namespace std;

/**
 *  Divisors Of Factorial
 *  -   Given a number, find the total number of divisors of the factorial of the 
 *      number. Since the answer can be very large, print answer modulo 10^9+7.
 *  
 *  Input
 *      The first line contains T, number of testcases.
 *      T lines follows each containing the number N.
 *  Output
 *      Print T lines of output each containing the answer.
 *  Constraints
 *      1 <= T <= 500
 *      0 <= N <= 50000
 *  
 *  Sample Input:
 *      3
 *      2
 *      3
 *      4
 *  Sample Output:
 *      2
 *      4   
 *      8
 */
typedef long long int ll;
#define MOD 1000000007

void divisors(ll n){
    bool *isPrime = new bool[n+1];
    for (ll i=0; i<=n; i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (ll i=2; i*i<=n; i++){
        if (isPrime[i])
            for (ll j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
    }
    ll numDivisors = 1;
    for (ll i=0; i<=n; i++){
        if (isPrime[i]){
            ll currSum = 0;
            for (ll j=1; pow(i, j)<=n; j++){
                currSum += n/pow(i, j);
            }
            numDivisors =(numDivisors%MOD * (currSum + 1)%MOD)%MOD;
        }
    }
    cout << numDivisors << endl;
    delete[] isPrime;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        divisors(n);
    }

    return 0;
}