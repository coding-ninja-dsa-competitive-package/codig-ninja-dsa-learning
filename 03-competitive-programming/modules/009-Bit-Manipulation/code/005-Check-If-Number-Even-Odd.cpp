#include<bits/stdc++.h>

using namespace std;

/**
 *  Check if number is is odd or even . 
 * 
 *  Sample Input:
 *      556
 *  Sample Output:
 *      even
 */

void checkEven(int num){
    if(num & 1){
        cout << "odd" << endl;
        return;
    }
    cout << "even" << endl;
}

int main() {
    int n;
    cin >> n;
    checkEven(n);

    return 0;
}