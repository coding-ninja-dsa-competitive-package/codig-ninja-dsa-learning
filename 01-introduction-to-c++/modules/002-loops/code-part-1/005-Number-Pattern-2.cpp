#include<iostream>
using namespace std;

/**
 *  Number Pattern 2
 *  -   Print the following pattern
 *  -   Pattern for N = 4
 *              1
 *             23
 *            345
 *           4567
 *  
 *  Input Format :
 *      N (Total no. of rows)
 *  Output Format :
 *      Pattern in N lines
 * 
 *  Sample Input :
 *      5
 *  Sample Output :
 *       1
 *      23
 *     345
 *    4567
 *   56789
 */

int main() {
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int l = 1;
        while(l <= N-i){
            cout << " ";
            l = l+1;
        }
        int j=i, k=1;
        while(k <= i){
            cout << j;
            j = j+1;
            k = k+1;
        }
        cout << endl;
        i = i+1;
    }   

    return 0;
}