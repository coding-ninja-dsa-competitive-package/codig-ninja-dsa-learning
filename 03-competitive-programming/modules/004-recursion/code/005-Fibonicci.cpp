#include<bits/stdc++.h>

using namespace std;

/**
 *  Fibonicci Series : 
 *      Fib(n) = Fib(n-1) + Fib(n-2)
 * 
 */
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans1 = fib(n-1);
    int ans2 = fib(n-2);
    return ans1 + ans2;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}