#include<bits/stdc++.h>

using namespace std;

/**
 *  Fibonacci Sum
 *  -   The fibonacci sequence is defined by the following relation:
 *          F(0) = 0
 *          F(1) = 1
 *          F(N) = F(N - 1) + F(N - 2), N >= 2
 *  -   Your task is very simple. Given two non-negative integers N and M (N <= M), 
 *      you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 
 *      1000000007.
 *  
 *  Input Format :  
 *      Two non-negative integers N and M. (N <= M)
 *  Output Format :
 *      A single line containing the answer for the task.
 *  Sample Input :  
 *      10 
 *      19
 *  Sample Output :
 *      10857
 */
typedef unsigned long long ll;
#define MOD 1000000007

void multiply(ll mat1[2][2], ll mat2[2][2]){
    ll firstValue = ((mat1[0][0]%MOD) * (mat2[0][0]%MOD) + (mat1[0][1]%MOD) * (mat2[1][0]%MOD))%MOD;
    ll secondValue = ((mat1[0][0]%MOD) * (mat2[0][1]%MOD) + (mat1[0][1]%MOD) * (mat2[1][1]%MOD))%MOD;
    ll thirdValue = ((mat1[1][0]%MOD) * (mat2[0][0]%MOD) + (mat1[1][1]%MOD) * (mat2[1][0]%MOD))%MOD;
    ll fourthValue = ((mat1[1][0]%MOD) * (mat2[0][1]%MOD) + (mat1[1][1]%MOD) * (mat2[1][1]%MOD))%MOD;
    mat1[0][0] = firstValue;
    mat1[0][1] = secondValue;
    mat1[1][0] = thirdValue;
    mat1[1][1] = fourthValue;
}

void power(ll mat[2][2], ll n){
    if(n==0 || n==1){
        return;
    }
    power(mat, n/2);
    multiply(mat, mat);
    if(n%2 != 0){
        ll arr[2][2] = {{1, 1}, {1, 0}};
        multiply(mat, arr);
    }
}

ll fibonaaci(ll n){
    ll mat[2][2] = {{1, 1} , {1, 0}};
    if(n==0) {
        return 0;
    }
    power(mat, n-1);
    return mat[0][0]%MOD;
}

unsigned long long fiboSum(unsigned long long m, unsigned long long n){
    return (fibonaaci(n+2)%MOD - fibonaaci(m+1)%MOD + MOD) % MOD;
}

int main() {
    unsigned long long m,n;
    cin >> m >> n;
	cout << fiboSum(m,n) << endl;

    return 0;
}