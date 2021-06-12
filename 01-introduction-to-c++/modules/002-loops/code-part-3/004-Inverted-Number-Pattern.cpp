#include<iostream>

using namespace std;

/**
 *  Inverted Number Pattern
 *  -   Print the following pattern for the given N number of rows.
 *  -   Pattern for N = 4
 *          4444
 *          333
 *          22
 *          1
 *  
 *  Input format :
 *      Integer N (Total no. of rows)
 *  Output format :
 *      Pattern in N lines
 *  Constraints :
 *      0 <= N <= 50
 *  
 *  Sample Input 1:
 *      5
 *  Sample Output 1:
 *      55555 
 *      4444
 *      333
 *      22
 *      1
 * 
 *  Sample Input 2:
 *      6
 *  Sample Output 2:
 *      666666
 *      55555 
 *      4444
 *      333
 *      22
 *      1
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i+1){
            cout << N-i+1;
            j++;
        }
        cout << endl;
        i++;
    }
}