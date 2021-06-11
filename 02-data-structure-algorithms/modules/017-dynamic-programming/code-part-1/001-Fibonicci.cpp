#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Fibonicci Series
 */

// Approach 1 - Recursion - Brute Force - O(2^n)
int fib(int n){
    if(n<=1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

// Approach 2 - Memoization - Recursion - O(n)
int fib_helper(int n, int* arr){
    // base case
    if(n <= 1){
        return 1;
    }
    // Check if ans is present in memo array
    if(arr[n] != -1){
        return arr[n];
    }
    // calculate the ans using recursion
    int num1 = fib_helper(n-1, arr);
    int num2 = fib_helper(n-2, arr);
    //save the answer
    arr[n] = num1+num2;
    // return the answer
    return arr[n];
}
int fibonicci(int n){
    int* arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }
    return fib_helper(n, arr);
}

// Approach 3 - Dynamic Programming - Iterative - O(n)
int fibonicci2(int n){
    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}


int main(){
    int n ; 
    cin >> n;
    int fib = fibonicci(n);

    return 0;
}