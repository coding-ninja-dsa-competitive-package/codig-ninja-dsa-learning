#include<bits/stdc++.h>

using namespace std;

/**
 *  Number Of Balanced BTs   
 *  -   Given an integer h, find the possible number of balanced binary trees of 
 *      height h. You just need to return the count of possible binary trees which 
 *      are balanced.
 *  -   This number can be huge, so, return output modulus 10^9 + 7.
 *  -   Write a simple recursive solution.
 *  
 *  Input Format :
 *      The first and only line of input contains an integer, that denotes the value 
 *      of h. Here, h is the height of the tree.
 *  Output Format :
 *      The first and only line of output contains the count of balanced binary trees 
 *      modulus 10^9 + 7.
 *  
 *  Constraints :
 *      1 <= h <= 24
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      3
 *  Sample Output 1:
 *      15
 *  
 *  Sample Input 2:
 *      4
 *  Sample Output 2:
 *      315
 */

#define M 1000000007

int balancedBTs(int n) {
	if(n <= 1){
        return 1;
    }
    int a = balancedBTs(n-1);
    int b = balancedBTs(n-2);
    int ans1 = (int)(((long)(a) * a)%M);
    int ans2 = (int)((2*(long)(a)*b)%M);
    int ans = (int)(ans1 + ans2)%M;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);

    return 0;
}