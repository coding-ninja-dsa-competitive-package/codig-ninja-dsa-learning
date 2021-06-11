#include<iostream>

using namespace std;

/**
 *  Number Star Pattern
 *  -   Print the following pattern for given number of rows.
 *      N=5, 
 *          1234554321
 *          1234**4321
 *          123****321
 *          12******21
 *          1********1
 */

int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1;
        while(j <= N-i+1){
            cout << j;
            j++;
        }
        int k=1;
        while(k <= 2*i-2){
            cout << "*";
            k++;
        }
        int l=N-i+1;
        while(l >=1){
            cout << l;
            l--;
        }

        i++;
        cout << endl;
    }
}