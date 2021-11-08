#include<bits/stdc++.h>

using namespace std;

/**
 *  Number Of Factors
 *  -   A number is called n-factorful if it has exactly n distinct prime factors. 
 *      Given positive integers a, b, and n, your task is to find the number of 
 *      integers between a and b, inclusive, that are n-factorful. We consider 1 
 *      to be 0-factorful.
 *  
 *  Input
 *      Your input will consist of a single integer T followed by a newline and T 
 *      test cases. Each test cases consists of a single line containing integers a, 
 *      b, and n as described above.
 *  Output
 *      Output for each test case one line containing the number of n-factorful 
 *      integers in [a, b].
 *  Constraints
 *      T < 10000
 *      1 ≤ a ≤ b ≤ 10^6
 *      0 ≤ n ≤ 10
 *  
 *  Sample Input
 *      5
 *      1 3 1
 *      1 10 2
 *      1 10 3
 *      1 100 3
 *      1 1000 0
 *  Sample Output
 *      2 
 *      2
 *      0
 *      8
 *      1
 */

void makeSievePrime(int* isPrime, int n){
    for (int i=0; i<n+1; i++){
        isPrime[i] = 0;
    }
    for (int i=2; i<=n; i++){
        if (isPrime[i] == 0)
            for (int j=1; j*i<=n; j++){
                isPrime[j*i] += 1;
            }
    }
}

int main(){
    int t;
    cin >> t;
    int* primes = new int[1000001];
    int** nFactor=new int* [11];
    for(int i=0; i<11; i++){
        nFactor[i]=new int[10000001];
    }
    makeSievePrime(primes, 1000001);
    for(int i=0; i<11; i++){
        nFactor[i][0]=0;
        nFactor[i][1]=0;
        for(int j=2; j<1000001; j++){
            if(i==primes[j]){
                nFactor[i][j] = nFactor[i][j-1]+1;
            } else {
                nFactor[i][j] = nFactor[i][j-1];
            }
        }
    }
    for(int i=1; i<=t; i++){
        int a, b, n;
        cin >> a >> b >> n;
        if(a==1 && n==0){
            cout << 1 << endl;
            continue;
        }
        cout << nFactor[n][b] - nFactor[n][a-1] << endl;
    }
}