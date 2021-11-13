#include<bits/stdc++.h>

using namespace std;

/**
 *  Matrix Exponentiation : 
 *  -   Used to compute the recurrence relation fast.
 *  
 *  Calculate Nth fibonaaci number.
 */
void multiply(int arr[2][2], int mat[2][2]){
    int firstValue = arr[0][0] * mat[0][0] + arr[0][1] * mat[1][0];
    int secondValue = arr[0][0] * mat[0][1] + arr[0][1] * mat[1][1];
    int thirdValue = arr[1][0] * mat[0][0] + arr[1][1] * mat[1][0];
    int fourthValue = arr[1][0] * mat[0][1] + arr[1][1] * mat[1][1];
    arr[0][0] = firstValue;
    arr[0][1] = secondValue;
    arr[1][0] = thirdValue;
    arr[1][1] = fourthValue;
}

void power(int arr[2][2], int n){
    if(n==0 || n==1){
        return;
    }
    power(arr, n/2);
    // Multiplying arr^(n-2) with arr^(n-2)
    multiply(arr, arr);

    if(n%2 != 0){
        int mat[2][2] = {{1, 1}, {1, 0}};
        multiply(arr, mat);
    }
}

int fibonaaciNumber(int n){
    int arr[2][2] = {{1, 1}, {1, 0}};
    if(n==0){
        return 0;
    }

    power(arr, n-1);
    return arr[0][0];
}

int main() {
    int num = 8;
    cout << fibonaaciNumber(num) << endl;

    return 0;
}