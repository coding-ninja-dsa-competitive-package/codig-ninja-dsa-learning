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
 *  Code : Staircase using Dp
 *  -   A child runs up a staircase with 'n' steps and can hop either 1 step, 
 *      2 steps or 3 steps at a time. Implement a method to count and return 
 *      all possible ways in which the child can run-up to the stairs.
 *  
 *  Input format :
 *      The first and the only line of input contains an integer value, 'n', 
 *      denoting the total number of steps.
 *  Output format :
 *      Print the total possible number of ways.
 *  
 *  Constraints :
 *      0 <= n <= 10 ^ 4
 *  
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      4
 *  Sample Output 1:
 *      7
 *  
 *  Sample Input 2:
 *      10
 *  Sample Output 2:
 *      274
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

int main(){
    int n;
	cin >> n;
	cout << staircase(n) << endl;
    cout << staircase2(n) << endl;
    cout << staircase3(n) << endl;

    return 0;
}