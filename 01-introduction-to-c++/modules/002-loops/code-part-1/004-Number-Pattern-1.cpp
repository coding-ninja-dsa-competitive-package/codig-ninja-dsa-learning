#include<iostream>

using namespace std;

/**
 *  Number Pattern 1
 *  -   Print the following pattern
 *  -   Pattern for N = 4
 *              1
 *              23
 *              345
 *              4567
 *  
 *  Input Format :
 *      N (Total no. of rows)
 *  Output Format :
 *      Pattern in N lines
 *  
 *  Sample Input 1 :
 *      3
 *  Sample Output 1 :
 *      1
 *      23
 *      345
 */

int main(){
	int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = i, k =1;
        while(k <= i){
            cout << j;
            j = j+1;
            k = k+1;
        }
        cout << endl;
        i = i+1;
    }  
  
}

