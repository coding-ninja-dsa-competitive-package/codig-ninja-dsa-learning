#include<iostream>

using namespace std;

/**
 *  Pyramid Number Pattern : Print the following pattern for the given number of rows.
 *      N=4,
 *               1
 *              212
 *             32123
 *            4321234
 * 
 *  Input format : N (Total no. of rows)
 *  Output format : Pattern in N lines
 *  
 *  Sample Input :
 *      5
 *  Sample Output :
 *          1
 *         212
 *        32123
 *       4321234
 *      543212345
 */

int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1;
        while(j <= N-i){
            cout << " ";
            j++;
        }

        int k=i;
        while(k>=1){
            cout << k;
            k--;
        }
        int a=1 , b=2;
        while(a <= i-1){
            cout << b;
            b++;
            a++;
        }

        i++;
        cout << endl;
    }
}