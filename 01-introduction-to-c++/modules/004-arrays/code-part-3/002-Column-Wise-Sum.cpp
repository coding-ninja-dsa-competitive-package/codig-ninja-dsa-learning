#include<iostream>
using namespace std;

/**
 *  Column Wise Sum
 *  -   Given a 2D integer array of size M*N, find and print the sum of ith column elements 
 *      separated by space.
 *  
 *  Input Format :
 *      First and only line of input contains M and N, followed by M * N space 
 *      separated integers representing the elements in the 2D array.
 *  Output Format :
 *      Sum of every ith column elements (separated by space)
 *  Constraints :
 *      1 <= M, N <= 10^3
 *  
 *  Sample Input :
 *      4 2 1 2 3 4 5 6 7 8
 *  Sample Output :
 *      16 20
 */

int main(){
    int a[100][100];
    int m,n;
    cin >> m >> n;
    //taking input
    for(int i=0; i<m; i++){
        for(int j=0; j<n ; j++){
            cin >> a[i][j];
        }
    }
    // Print sum column wise
    int result[n];
    for(int i=0; i<n; i++){
        result[i] = 0;
        for(int j=0; j<m ; j++){
            result[i] += a[j][i];
        }
    }
    for(int i=0; i<n ; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}