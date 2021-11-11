#include<bits/stdc++.h>

using namespace std;

/**
 *  Euler Totient Function
 *      Ø(n) -> Number of 'm' such that 1<=m<n and gcd(m, n) = 1 , for all m E N
 * 
 *  Property:
 *      Ø(ab) = Ø(a) * Ø(b) , gcd(a, b)=1
 * 
 */

void eulerPhi(int n) {
    int phi[n+1];
    for(int i=1; i<=n; i++){
        phi[i] = i;
    }
    for(int i=2; i<=n; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j=2*i; j<=n; j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << "Euler totient phi for " << i << " is : " << phi[i] << endl;
    }
}

int main() {
    eulerPhi(10);

    return 0;
}