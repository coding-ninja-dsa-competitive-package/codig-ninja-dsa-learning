#include<bits/stdc++.h>

using namespace std;

/**
 *  LCM SUM
 *  -   Given n, calculate and print the sum :
 *          LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
 *      where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
 *  
 *  Input Format :
 *      Line 1 : Integer n
 *  Output Format :
 *      Required sum
 *  Constraints :   
 *      1 <= T <= 300000    
 *      1 <= n <= 1000000
 *  
 *  Sample Input 1 :
 *      5
 *  Sample Output 1 :
 *      55
 *  
 * Sample Input 2 :
 *      2
 *  Sample Output 2 :
 *      4
 */


typedef long long int ll;

ll gcd(ll a, ll b){
    if(a<b){
        return gcd(b, a);
    }
    if(b==0){
        return a;
    }
    return gcd(b, a%b);   
}

void func(long long n){
	ll sum=0;
    for(ll i=1; i<=n-1; i++){
        sum += (n*n)/gcd(i*1.0, n);
    }
    ll ans=2*n + sum;
    cout << ans/2;
}

int main(){
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}