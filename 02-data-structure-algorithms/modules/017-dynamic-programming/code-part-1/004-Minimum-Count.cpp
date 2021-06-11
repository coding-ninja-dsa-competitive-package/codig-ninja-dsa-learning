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
 *  Code : Minimum Count
 *  -   Given an integer N, find and return the count of minimum numbers 
 *      required to represent N as a sum of squares.
 *  -   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} 
 *      and {2^2}. The output will be 1, as 1 is the minimum count of numbers 
 *      required to represent N as sum of squares.
 * 
 *  Input format :
 *      The first and the only line of input contains an integer value, 'N'.
 *  Output format :
 *      Print the minimum count of numbers required.
 *  
 *  Constraints :
 *      0 <= n <= 10 ^ 4
 *      
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      12
 *  Sample Output 1 :
 *      3
 *  Explanation of Sample Output 1 :
 *      12 can be represented as : 
 *      A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)
 *      B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)
 *      C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)
 *      D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)
 *      As we can see, the output should be 3.
 * 
 *  Sample Input 2 :
 *      9
 *  Sample Output 2 :
 *      1
 */

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

int main(){
    int n;
	cin >> n;
	cout << minCount(n) << endl;
    cout << minCount2(n) << endl;
    cout << minCount3(n) << endl;

    return 0;
}