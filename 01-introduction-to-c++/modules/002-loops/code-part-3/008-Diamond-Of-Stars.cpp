#include<iostream>

using namespace std;

/**
 *  Diamond of stars
 *  -   Print the following pattern for the given number of rows.
 * 
 *  Input format :
 *      N (Total no. of rows and can only be odd)
 *  Output format :
 *      Pattern in N lines
 *  
 *  Constraints :
 *      1 <= N <= 49
 *      
 *  Sample Input 1:
 *      5
 *  Sample Output 1:
 *      *
 *     ***
 *    *****
 *     ***
 *      *
 *  
 *  Sample Input 2:
 *      3
 *  Sample Output 2 
 *      *
 *     ***
 *      *
 */
int main(){
    int N;
    cin >> N;

    int i = 1;
    while(i <= N/2+1){
        int j = 1; 
        while(j <= (N/2+1)-i){
            cout << " ";
            j++;
        }
        int k=1;
        while(k <= 2*i -1){
            cout << "*";
            k++;
        }
        cout << endl;
        i++;
    }

    N = N - (N/2 + 1);
    int row = 1;
    int m = N;
    while(m >= 1){
        int n = 1;
        while(n <= row){
            cout << " ";
            n++;
        }
        int p = 1;
        while(p <= 2*m -1 ){
            cout << "*";
            p++;
        }
        cout << endl;
        row++;
        m--;
    }
}