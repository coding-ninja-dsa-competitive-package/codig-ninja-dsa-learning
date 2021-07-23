#include<bits/stdc++.h>

using namespace std;

/**
 *  StairCase Problem
 *  -   A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps 
 *      or 3 steps at a time. Implement a method to count and return all possible ways 
 *      in which the child can run-up to the stairs.
 *  
 *  Input format :
 *      The first and the only line of input contains an integer value, 'n', denoting 
 *      the total number of steps.
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
long staircase(int n, long* out){
    if(n==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(out[n] != 0){
        return out[n];
    }
    long ans1 = staircase(n-1, out);
    long ans2 = staircase(n-2, out);
    long ans3 = staircase(n-3, out);
    out[n] = ans1+ans2+ans3;
    return out[n];
}

long staircase(int n){
    long* out = new long[n+1]();
    return staircase(n, out);
}

int main(){
	int n;
	cin >> n;
	cout << staircase(n);
}