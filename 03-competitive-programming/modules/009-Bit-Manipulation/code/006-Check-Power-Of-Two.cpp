#include<bits/stdc++.h>

using namespace std;

/**
 *  Check if the given number is power of two.
 *  
 *  Sample Input:
 *      8
 *  Sample Output:
 *      true
 */

void checkPowerOfTwo(int n){
    if((n & (n-1)) == 0){
        cout << "true" << endl;
        return;
    }
    cout << "false" << endl;
}

int main() {
    int n;
    cin >> n;
    checkPowerOfTwo(n);

    return 0;
}