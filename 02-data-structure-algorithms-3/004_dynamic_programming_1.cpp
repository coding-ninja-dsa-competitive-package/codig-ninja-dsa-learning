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
 *  Dynamic Programming : 
 *  ====================
 *  -   In recursion problems, sometimes we do repetitive computation. Ex. Fibonicci
 *  -   To reduce the time complexity , we can save the ans at the first time calculation
 *      which is nothing but called as dynamic programming .
 *  -   Bottom - Up approach.
 *  -   Problems are solved iteratively.
 *  
 *  Memoization: 
 *  ============
 *  -   Process of saving the previous results for future use is known as Memoization.
 *  -   Helps in reducing the time complexity drastically.
 *  -   Top - Down approach.
 *  -   Recursion is used.
 */

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
void problem1(){
    int n ; 
    cin >> n;
    int fib = fibonicci(n);
}

/**
 *  Code : Min Steps to 1
 *  -   Given a positive integer 'n', find and return the minimum number 
 *      of steps that 'n' has to take to get reduced to 1. You can perform 
 *      any one of the following 3 steps:
 *      1.  Subtract 1 from it. (n = n - ­1) ,
 *      2.  If its divisible by 2, divide by 2.( if n%2==0, then n=n/2) ,
 *      3.  If its divisible by 3, divide by 3. (if n%3==0, then n=n/3).  
 *  -   Write brute-force recursive solution for this.
 */
// Approach 1 - Brute Force recursive - O(3^n) 
int countMinStepsToOne(int n){
    if(n<=1){
        return 0;
    }
    int res = countMinStepsToOne(n-1);
    if(n%2 == 0){
        int r = countMinStepsToOne(n/2);
        res = min(res, r);
    }
    if(n%3 == 0){
        int r = countMinStepsToOne(n/3);
        res = min(res, r);
    }
    return 1 + res;
}
void problem2(){
    int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}

/**
 *  Code : Min Steps to 1 using DP
 */
// Approach 2 - Memoization - Recursive - Top Down approach -  O(n)
int minSteps(int n, int* arr){
    if(arr[n] != -1){
        return arr[n];
    }
    int res = minSteps(n-1, arr);
    if(n%2 == 0){
        int r = minSteps(n/2, arr);
        res = min(res, r);
    }
    if(n%3 == 0){
        int r = minSteps(n/3, arr);
        res = min(res, r);
    }
    arr[n] = 1+res;
    return arr[n];
}
int countStepsToOne(int n){
    int* arr = new int[n+1];
    arr[0] = arr[1] = 0;
    for(int i=2; i<n+1; i++){
        arr[i] = -1;
    }
    return minSteps(n, arr);
}
// Approach 3 - DP - Iterative - Bottom Up approach -  O(n)
int countStepsToOne3(int n){
    int* arr = new int[n+1];
    arr[1] = 0;
    for(int i=2; i<n+1; i++){
        int res = arr[i-1];
        if(i%2 == 0){
            res = min(res, arr[i/2]);
        }
        if(i%3 == 0){
            res = min(res, arr[i/3]);
        }
        arr[i] = 1+res;
    }
    return arr[n];
}
void problem3(){
    int n;
	cin >> n;
    cout << countStepsToOne(n) << endl;
	cout << countStepsToOne3(n) << endl;
}

/**
 *  Code : Staircase using Dp
 *  -   A child runs up a staircase with 'n' steps and can hop either 1 step, 
 *      2 steps or 3 steps at a time. Implement a method to count and return 
 *      all possible ways in which the child can run-up to the stairs.
 */
// Approach 1 - Recursive Brute Force - O(3^n)
long staircase(int n){
    if(n==0 || n ==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    long ans1 = staircase(n-1);
    long ans2 = staircase(n-2);
    long ans3 = staircase(n-3);
    return ans1 + ans2 + ans3;
}
// Approach 2 - Memoization - O(n)
long waysStairMemo(int n , long* arr){
    if(arr[n] != -1){
        return arr[n];
    }
    arr[n] = waysStairMemo(n-1, arr) + waysStairMemo(n-2, arr) +waysStairMemo(n-3, arr);
    return arr[n];
}
long staircase2(int n){
    long* arr = new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i] = -1;
    }
    return waysStairMemo(n, arr);
}
// Approach 3 - DP - O(n)
long staircase3(int n){
    long* arr = new long[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}
void problem4(){
    int n;
	cin >> n;
	cout << staircase(n) << endl;
    cout << staircase2(n) << endl;
    cout << staircase3(n) << endl;
}

/**
 *  Code : Minimum Count
 *  -   Given an integer N, find and return the count of minimum numbers 
 *      required to represent N as a sum of squares.
 *  -   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} 
 *      and {2^2}. The output will be 1, as 1 is the minimum count of numbers 
 *      required to represent N as sum of squares.
 */
#include<cmath>
// Approach 1 - Brute Force
int minCount(int n){
    if(n<=0){
        return 0;
    }
    int res=INT_MAX;
    for(int i=1; i*i<=n; i++){
        int ans = minCount(n - i*i);
        res = min(res, ans);
    }   
    return 1 + res;
}
// Approach 2 - Memoization
int minCountMemo(int n, int* arr){
    if(arr[n] != -1){
        return arr[n];
    }
    int res=INT_MAX;
    for(int i=1; i*i<=n; i++){
        int ans = minCountMemo(n - i*i, arr);
        res = min(res, ans);
    }  
    arr[n] = 1+res;
    return arr[n];
}
int minCount2(int n){
    int* arr = new int[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        arr[i] = -1;
    }
    return minCountMemo(n, arr);
}
// Approach 3 - DP
int minCount3(int n){
    int* arr = new int[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        int res = INT_MAX;
        for(int j = 1; j*j <= i; j++){
            res = min(res, arr[i - j*j]);
        }
        arr[i] = 1 + res;
    }
    return arr[n];
}
void problem5(){
    int n;
	cin >> n;
	cout << minCount(n) << endl;
    cout << minCount2(n) << endl;
    cout << minCount3(n) << endl;
}

/**
 *  Code : No. of balanced BTs
 *  -   Given an integer h, find the possible number of balanced binary 
 *      trees of height h. You just need to return the count of possible 
 *      binary trees which are balanced.
 *  -   This number can be huge, so, return output modulus 10^9 + 7.
 *  -   Write a simple recursive solution.
 */
// Approach 1 - Brute Force - O(2^n)
#define M 1000000007
int balancedBTs(int n) {
    if(n <= 1){
        return 1;
    }
    int a = balancedBTs(n-1);
    int b = balancedBTs(n-2);
    int ans1 = (int)(((long)(a)*a)%M);
    int ans2 = (int)((2*(long)(a)*b)%M);
    int ans = (int)(ans1 + ans2)%M;
    return ans;
}
void problem6(){
    int n;
    cin >> n;
    cout << balancedBTs(n);
}

/**
 *  Code : No. of balanced BTs using DP
 */
// Approach 2 - Memoization - Recursive
int balancedBTs(int n, int* arr) {
    if(arr[n] != -1){
        return arr[n];
    }
    int a = balancedBTs(n-1, arr);
    int b = balancedBTs(n-2, arr);
    int ans1 = (int)(((long)(a)*a)%M);
    int ans2 = (int)((2*(long)(a)*b)%M);
    arr[n] = (int)(ans1 + ans2)%M;
    return arr[n];
}
int balancedBTsMemo(int n){
    int* arr = new int[n+1];
    arr[0] = arr[1] = 1;
    for(int i=2; i<=n; i++){
        arr[i] = -1;
    }
    return balancedBTs(n, arr);
}
// Approach 3 - DP - O(n)
int balancedBTsDP(int n){
    int* arr = new int[n+1];
    arr[0] = arr[1] = 1;
    for(int i=2; i<=n; i++){
        int a = arr[i-1];
        int b = arr[i-2];
        int ans1 = (int)(((long)(a)*a)%M);
        int ans2 = (int)((2*(long)(a)*b)%M);
        arr[i] = (int)((ans1 + ans2)%M);
    }
    return arr[n];
}
void problem7(){
    int n;
    cin >> n;
    cout << balancedBTsMemo(n) << endl;
    cout << balancedBTsDP(n) << endl;
}

int main() {
    // Fibonicci
    //problem1();

    // Code : Min Steps to 1
    //problem2();

    // Code : Min Steps to 1 using DP
    // problem3();

    // Code : Staircase using Dp
    // problem4();

    // Code : Minimum Count
    // problem5();

    // Code : No. of balanced BTs
    // problem6();

    // Code : No. of balanced BTs using DP
    problem7();

    return 0;
}