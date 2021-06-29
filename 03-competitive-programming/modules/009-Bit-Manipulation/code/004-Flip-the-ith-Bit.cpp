#include<bits/stdc++.h>

using namespace std;

/**
 *  Flip the ith bit of a Number. 
 * 
 *  Sample Input :
 *      11 2
 *  Sample Output : 
 *      15
 */

int flip(int n , int i){
    return n ^ (1 << i);
}

int main() {
    int n, i;
    cin >> n >> i;
    int ans = flip(n, i);
    cout << ans << endl;

    return 0;
}