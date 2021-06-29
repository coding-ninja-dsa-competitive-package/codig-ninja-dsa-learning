#include<bits/stdc++.h>

using namespace std;

/**
 *  Clear All Bits From LSB
 *  -   You are given two integers N and i. You need to clear all bits from LSB 
 *      to ith bit (start i from right to left) and return the updated N.
 *  -   Counting of bits starts from 0 from right to left.
 *  
 *  Input Format :
 *      Two integers N and i (separated by space)
 *  Output Format :
 *      Updated N
 *  
 *  Sample Input 1 :
 *      15 1
 *  Sample Output 1 :
 *      12
 */

int clearAllBits(int n, int i){
    int mask = ~((1 << (i+1))-1);
    return n & mask;
}

int main() {
    int n, i;
	cin >> n >> i;
	cout<< clearAllBits(n, i) <<endl;

    return 0;
}