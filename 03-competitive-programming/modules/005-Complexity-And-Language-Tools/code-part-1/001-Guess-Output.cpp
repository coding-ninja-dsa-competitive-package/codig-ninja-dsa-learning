#include<bits/stdc++.h>

using namespace std;

/**
 *  Time Complexity of Code
 *  -   What will be the Time Complexity of following code in terms of ‘n’ ?
 *  -   Refer the code for C++ -
 * 
 *  Ans : O(n)
 */
void problem1(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(; i < n; i++){
            cout << i << endl;
        }
    }
}

/**
 *  Time Complexity of Code
 *  -   What will be the Time Complexity of following code in terms of ‘n’ ?
 *  -   Note : Assume k to be a constant value
 * 
 *  Ans : 
 */ 
void problem2(){
    int n, k;
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < k; j++){
            cout << (i + j ) << endl;
        }
    }
}

/**
 *  Operations for merging
 *  -   For merging two sorted arrays of size m and n into a sorted array 
 *      of size m+n, we require operations -
 *  Ans : O(m+n)
 */

/**
 *  Recurrence for Merge Sort
 *  -   What is the recurrence relation for merge sort :
 *  Ans :  T(n) = 2T(n/2) + O(n)
 * 
 *  -   What is the time complexity of merge sort :
 *  Ans :  O(nlogn)
 */

/**
 *  What is time complexity
 *  -   What is the time complexity of following code ?
 *  Ans : O(n)
 */ 
int multiplyRec(int m, int n){
    if(n == 1)
        return m;
    return m + multiplyRec(m,  n - 1);  
}
void problem3(){
    int n, m;
    cin >> n >> m;
    multiplyRec(n, m);
}

/**
 *  What is time complexity
 *  -   What is the time complexity of following code ?
 *  Ans : O(logn) - log is to the base 10
 */
int sumOfDigits(int n){
    int sum;
    if(n < 10){
        return n;
    }
    sum = (n % 10) + sumOfDigits(n / 10);
    return sum;
}
void problem4(){
    int n;
    cin >> n;
    sumOfDigits(n);
}

/**
 *  Fibonacci
 *  -   What is the time complexity of following code for calculating 
 *      nth fibonacci number.
 *  Ans : O(2^n)
 */ 
long fib(int n){
    if(n == 0 || n == 1){
         return n;
    }
    return fib(n - 1) + fib(n - 2);
}
void problem5(){
    int n;
    cin >> n;
    cout << fib(n);
}

/**
 *  Merge Sort space
 *  -   The space complexity for merge sort is :
 *  Ans : O(n)
 */

/**
 *  Fibonacci - Space Complexity
 *  -   The space complexity for finding nth fibonacci number using recursion is :
 *  Ans : O(n)
 */

int main() {
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();

    return 0;
}