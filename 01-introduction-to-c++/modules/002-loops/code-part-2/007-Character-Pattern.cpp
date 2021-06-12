#include<iostream>

using namespace std;

/**
 *  Character Pattern
 *  -   Print the following pattern for the given N number of rows.
 *  -   Pattern for N = 4
 *          A
 *          BC
 *          CDE
 *          DEFG
 *  Input format :
 *      Integer N (Total no. of rows)
 *  Output format :
 *      Pattern in N lines
 *  
 *  Constraints
 *      0 <= N <= 13
 *      
 *  Sample Input 1:
 *      5
 *  Sample Output 1:
 *      A
 *      BC
 *      CDE
 *      DEFG
 *      EFGHI
 *  
 *  Sample Input 2:
 *      6
 *  Sample Output 2:
 *      A
 *      BC
 *      CDE
 *      DEFG
 *      EFGHI
 *      FGHIJK
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1; 
        char startChar = 'A' + i -1;
        while(j <= i){
            char ch = startChar + j - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}