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
 *  Code : Min Steps to 1
 *  -   Given a positive integer 'n', find and return the minimum number 
 *      of steps that 'n' has to take to get reduced to 1. You can perform 
 *      any one of the following 3 steps:
 *      1.  Subtract 1 from it. (n = n - ­1) ,
 *      2.  If its divisible by 2, divide by 2.( if n%2==0, then n=n/2) ,
 *      3.  If its divisible by 3, divide by 3. (if n%3==0, then n=n/3).  
 * 
 *  Input format :
 *      The first and the only line of input contains an integer value, 'n'.
 *  Output format :
 *      Print the minimum number of steps.
 * 
 *  Constraints :
 *      1 <= n <= 200
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      4
 *  Sample Output 1 :   
 *      2 
 *  Explanation of Sample Output 1 :
 *      For n = 4
 *      Step 1 :  n = 4 / 2  = 2
 *      Step 2 : n = 2 / 2  =  1 
 * 
 *  Sample Input 2 :
 *      7
 *  Sample Output 2 :
 *      3
 *  Explanation of Sample Output 2 :
 *      For n = 7
 *      Step 1 :  n = 7 ­- 1 = 6
 *      Step 2 : n = 6  / 3 = 2 
 *      Step 3 : n = 2 / 2 = 1  
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

int main(){
    int n;
	cin >> n;
    cout << countStepsToOne(n) << endl;
	cout << countStepsToOne3(n) << endl;

    return 0;
}