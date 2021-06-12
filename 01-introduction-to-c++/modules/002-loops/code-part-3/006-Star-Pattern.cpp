#include<iostream>
using namespace std;

/**
 *  Star Pattern
 *  -   Print the following pattern
 *      
 *  Input Format :
 *      N (Total no. of rows)
 *  Output Format :
 *      Pattern in N lines
 *  
 *  Constraints :
 *      0 <= N <= 50
 *  
 *  Sample Input 1 :
 *      3   
 *  Sample Output 1 :
 *      *
 *     *** 
 *    *****
 *  
 *  Sample Input 2 :
 *      4
 *  Sample Output 2 :
 *      *
 *     *** 
 *    *****
 *   *******
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i){
            cout << " ";
            j++;
        }
        int k =1;
        while(k <= 2*i - 1){
            cout << "*";
            k++;
        }

        cout << endl;
        i++;
    }
}