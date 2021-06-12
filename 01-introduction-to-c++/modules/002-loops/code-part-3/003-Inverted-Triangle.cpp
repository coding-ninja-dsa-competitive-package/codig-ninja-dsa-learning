#include<iostream>

using namespace std;

/**
 *  Inverted Triangle
 *      N=4, 
 *          ****
 *          ***
 *          **
 *          *
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i+1){
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }
}