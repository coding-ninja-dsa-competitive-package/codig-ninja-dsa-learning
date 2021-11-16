#include<bits/stdc++.h>

using namespace std;

/**
 *  Sehwag And ETF
 *  -   Sehwag has been solving a lot of mathematical problems recently. He was 
 *      learning ETF (Euler Totient Function) and found the topic quite interesting. 
 *      So, he tried solving a question on ETF. He will be given two numbers L and R. 
 *      He has to find the probability that the ETF of a number in the range [L, R] 
 *      is divisible by a number K.
 *  
 *  Input:
 *      The first line contains the number of test cases i.e. T.
 *      The next T lines will contain three integers L, R and K.
 *  Output:
 *      Print the answer in a new line after rounding off the first 6 digits after 
 *      the decimal place.
 *  Constraints:
 *      1 <= T <= 10
 *      1 <= L <= R <= 10^12
 *      0 <= R - L <= 10^5
 *      1 <= K <= 10^6
 *    
 *  Sample Input:
 *      3
 *      1 4 2
 *      2 5 2
 *      3 10 4
 *  Sample Output:
 *      0.500000
 *      0.750000
 *      0.375000
 */

typedef long long int ll;
#define MAX 1100001

bool primes[MAX];
ll phi[MAX];
ll arr[300001];
ll num[MAX];

int main(){
    for (ll i=3; i<MAX; i+=2){
        primes[i] = 1;
    }
    primes[2] = 1;
    for(ll i=3; i*i<MAX; i+=2){
        if (primes[i]){
            for (ll j=i*i; j<MAX; j+=2*i){
                primes[j] = 0;
            }
        }
    }
    arr[0] = 2;
    ll c = 1;
    for (ll i=3; i<MAX; i+=2){
        if (primes[i]){
            arr[c++] = i;
        }
    }

    ll t, a, b, k, x, base;
    cin >> t;
    while (t--){
        cin >> a >> b >> k;
        if (k == 1){
            cout << fixed << setprecision(6) << 1 << endl;
            continue;
        }
        for (ll i=a; i<=b; i++){
            phi[i-a] = i;
            num[i-a] = i;
        }
        for(ll i=0; arr[i]*arr[i] <= b; i++){
            base = a / arr[i] * arr[i];
            while (base < a){
                base += arr[i];
            }
            while (base < arr[i]){
                base += arr[i];
            }
            if (base == arr[i]){
                base += arr[i];
            }
            for(ll j=base; j<=b; j+=arr[i]){
                while (num[j-a] % arr[i] == 0){
                    num[j-a] /= arr[i];
                }
                phi[j-a] -= phi[j-a] / arr[i];
            }
        }
        for(ll i = a; i <= b; i++){
            if (num[i-a] > 1){
                phi[i-a] -= phi[i-a] / num[i-a];
            }
            num[i-a] = 1;
        }
        ll c = 0;
        for(ll i=a; i<=b; i++){
            if (phi[i-a] % k == 0){
                c++;
            }
        }
        double ans = c;
        ans /= (b-a+1);
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}