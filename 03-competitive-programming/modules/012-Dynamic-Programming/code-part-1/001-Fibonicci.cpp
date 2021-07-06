#include<bits/stdc++.h>

using namespace std;

/**
 *  Fibonicci Series
 */

// Approach 1 - Brute Force - O(2^n)
int fib(int n){
    if(n ==0 || n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

// Approach 2 - Memoization - O(n)
int fib(int n, int* arr){
    if(n==0 || n==1){
        return 1;
    }
    if(arr[n] > 0){
        return arr[n];
    }
    int output = fib(n-1, arr) + fib(n-2, arr);
    arr[n] = output;
    return output;
}

// Approach 3 - DP - O(n)
int fib_dp(int n){
    int *arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    int output = arr[n];
    delete [] arr;
    return output;
}

int main() {
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = 0;
    }

    cout << fib(n) << endl;
    cout << fib(n, arr) << endl;
    cout << fib_dp(n) << endl;

    return 0;
}