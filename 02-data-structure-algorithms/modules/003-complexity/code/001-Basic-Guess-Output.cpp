#include<iostream>

using namespace std;

/**
 *  What will be the Time Complexity of following code in terms of ‘n’ ?
 *  Time - O(n)
 *  Space - O(1)
 */
void problem1(){
    int n, k;
    //Time - O(n)
    //Space - O(1)
    for(int i = 0; i < n; i++){
        for(; i < n; i++){
            cout << i << endl;
        }
    }     
    //Time - O(n*k) => O(n) as K is constant
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < k; j++){
            cout << (i + j ) << endl;
        }
    }
    //Recurrence for merge sort
    //  T(n) = 2T(n/2) + O(n) => O(nlogn)
    //  S(n) = O(n) (n elements array is required at max while merge)
}

//Time - O(n)
int multiplyRec(int m, int n){
    if(n == 1)
        return m;
    return m + multiplyRec(m,  n - 1);  
}

//Time - O(logn) => log is to base 10
int sumOfDigits(int n){
    int sum;
    if(n < 10){
        return n;
    }
    sum = (n % 10) + sumOfDigits(n / 10);
    return sum;
}

//Time - O(2^n)
//Space - O(n)
long fib(int n){
    if(n == 0 || n == 1){
         return n;
    }
    return fib(n - 1) + fib(n - 2);
}