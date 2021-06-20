#include<bits/stdc++.h>

using namespace std;

/**
 *  Mindbending Product:
 *  -   You are given an array ‘ARR’ of size N, you have to construct a 
 *      Product Array ‘P’ of the same size such that P[i] is equal to the 
 *      product of all the elements of ARR except ARR[i]. The constraint 
 *      is that you are not allowed to use the division operator.
 *  Input Format:
 *      The first line contains an Integer 't' which denotes the number 
 *      of test cases/queries to be run. 
 *      Then the test cases follow. 
 *      The first line of input for each test case/query contains an integer N 
 *      representing the size of the array.
 *      The second line of input for each test case/query contains N 
 *      space-separated integers representing the elements of the array.
 *  Output Format:
 *      For each test case, print the product array P.
 *      Output for every test case will be printed in a separate line.
 *  Note:
 *      1. You do not need to print anything, it has already been taken care of. 
 *         Just implement the function.
 *      2. The value of P[i] will fit into a 64-bit data type.
 *  Constraints:
 *      1 <= t <= 50
 *      1 <= N <= 10
 *      1 <= ARR [i] <= 20
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      2
 *      5
 *      10 3 5 6 2
 *      2
 *      12 20
 *  Sample Output 1:
 *      180 600 360 300 900
 *      20 12
 *  Explanation:
 *  Test Case 1: 
 *      For the product array P,
 *      At i=0 we have 3*5*6*2 = 180.
 *      At i=1 we have 10*5*6*2 = 600. 
 *      At i=2 we have 10*3*6*2 = 360. 
 *      At i=3 we have 10*3*5*2 = 300. 
 *      At i=4 we have 10*3*5*6 = 900
 *      So, the P array is 180 600 360 300 900
 *  Test Case 2: 
 *      For the product array P, 
 *      At i=0, we have 20. 
 *      At i=1, we have 12.
 *      So, the P array is 20 12. 
 */

// Approach 1 - using the division operator
void mindbendingProduct1(int arr[], int n){
    long total_product = 1;
    for(int i=0; i<n; i++){
        total_product *= arr[i];
    }
    for(int i=0; i<n; i++){
        cout << (total_product/arr[i]) << " ";
    }
    cout << endl;
}

// Approach 2 - using 2 arrays -  left product array, right product array - Space O(n)
void mindbendingProduct2(int arr[], int n){
    long lpa[n], rpa[n];
    lpa[0]=rpa[n-1]=1;
    for(int i=1, j=n-2; i<n && j>=0; i++, j--){
        lpa[i] = lpa[i-1] * arr[i-1];
        rpa[j] = rpa[j+1] * arr[j+1];
    }
    for(int i=0; i<n; i++){
        cout << lpa[i] * rpa[i] << " ";
    }
    cout << endl;
}

// Approach 3 - using 2 vars - left product element, right product element - Spact O(1)
void mindbendingProduct3(int arr[], int n){
    long product[n];
    long lp=1, rp=1;
    for(int i=0; i<n; i++){
        product[i] = lp;
        lp = lp*arr[i];
    }
    for(int i=n-1; i>=0; i--){
        product[i] = product[i]*rp;
        rp = rp*arr[i];
    }
    for(int i=0; i<n; i++){
        cout << product[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        mindbendingProduct1(arr, n);
        mindbendingProduct2(arr, n);
    }    

    return 0;
}