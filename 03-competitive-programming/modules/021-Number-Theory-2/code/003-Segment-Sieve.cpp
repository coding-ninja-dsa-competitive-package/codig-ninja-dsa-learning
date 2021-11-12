#include<bits/stdc++.h>

using namespace std;

/**
 *  Segmented Sieve Problem
 *  -   In this problem you have to print all primes from given interval.
 *  
 *  Input
 *      t - the number of test cases, then t lines follows. [t <= 150]
 *      On each line are written two integers L and U separated by a blank. L - lower 
 *      bound of interval, U - upper bound of interval. [2 <= L < U <= 2147483647] 
 *      [U-L <= 1000000].
 *  Output
 *      For each test case output must contain all primes from interval [L; U] in 
 *      increasing order.
 *  
 *  Sample Input:
 *      2
 *      2 10
 *      3 7
 *  Sample Output:
 *      2
 *      3
 *      5
 *      7
 *      3
 *      5   
 *      7 
 */

typedef long long int ll;
#define MAX 100001

vector<int>* makeSieve(){
    bool isPrime[SIZE];
    for(int i=0; i<SIZE; i++){
        isPrime[i] = true;
    }
    for(int i=2; i*i<SIZE; i++){
        if(isPrime[i]){
            for(int j=i*i; j<SIZE; j+=i){
                isPrime[j] = false;
            }
        }
    }

    vector<int>* primes = new vector<int>();
    primes->push_back(2);
    for(int i=3; i<SIZE; i+=2){
        if(isPrime[i]){
            primes->push_back(i);
        }
    }
    return primes;
}

void printPrimes(ll left, ll right, vector<int>* &primes){
    bool isPrime[right-left+1];
    for(int i=0; i<=right-left; i++){
        isPrime[i] = true;
    }

    for (int i=0; primes->at(i) * (ll)primes->at(i) <= right; i++){
        int currPrime = primes->at(i);
        ll base = (left / currPrime) * currPrime;
        if (base < left){
            base += currPrime;
        }
        for (ll j=base; j<=right; j+=currPrime){
            isPrime[j-left] = false;
        }
        if (base==currPrime){
            isPrime[base-left] = true;
        }
    }
    for (int i=0; i<=right-left; i++){
        if (isPrime[i]){
            cout << i + left << endl;
        }
    }
}

int main() {
    vector<int>* primes = makeSieve();
    int t;
    cin >> t;
    while(t--){
        ll left, right;
        cin >> left >> right;
        printPrimes(left, right, primes);
    }    

    return 0;
}