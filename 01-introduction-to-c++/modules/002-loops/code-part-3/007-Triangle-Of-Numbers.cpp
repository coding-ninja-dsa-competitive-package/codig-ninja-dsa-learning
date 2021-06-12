#include<iostream>

using namespace std;

/**
 *  Triangle of Numbers
 *  -   Print the following pattern for the given number of rows.
 *  
 *  Input format :
 *      Integer N (Total no. of rows)
 *  Output format :
 *      Pattern in N lines
 *  
 *  Constraints :
 *      0 <= N <= 50
 *  
 *  Sample Input 1:
 *      5
 *  Sample Output 1:
 *          1
 *        232
 *      34543
 *    4567654
 *  567898765
 *  
 *  Sample Input 2:
 *      4
 *  Sample Output 2:
 *          1
 *        232
 *      34543
 *    4567654
 */
int main(){
    int N;
    cin >>N;

    int i = 1;
    while(i <= N){
        int spaces = 1;
        while(spaces <= N-i){
            cout << " ";
            spaces++;
        }
        int j = 1, m= i;
        while(j <= i){
            cout << m;
            j++;
            m++;
        }
        int k = i-1, n = 2*(i-1);
        while(k > 0){
            cout << n;
            n--;
            k--;
        }

        cout << endl;
        i++;
    }
}