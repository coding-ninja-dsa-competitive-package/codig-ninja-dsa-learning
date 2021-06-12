#include<iostream>

using namespace std;

/**
 *  Mirror Number Pattern
 *  -   Print the following pattern for the given N number of rows.
 *  
 *  Input format :
 *      Integer N (Total no. of rows)
 *  Output format :
 *      Pattern in N lines
 *  Constraints
 *      0 <= N <= 50
 *  
 *  Sample Input 1:
 *      3
 *  Sample Output 1:
 *      1
 *     12
 *    123
 *  
 *  Sample Input 2:
 *      4
 *  Sample Output 2:
 *      1 
 *     12
 *    123
 *   1234
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int spaces = 1; 
        while(spaces <= N-i){
            cout << " ";
            spaces++;
        }
        int j=1;
        while(j <= i){
            cout << j;
            j++;
        }

        cout<<endl;
        i++;
    }
}