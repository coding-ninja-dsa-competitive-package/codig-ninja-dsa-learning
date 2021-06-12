#include<iostream>

using namespace std;

/**
 *  Isoceles Triangle
 *      N=4,
 *          1
 *         121
 *        12321
 *       1234321
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
        int k = 1;
        while(k <= i){
            cout << k ;
            k++;
        }
        int l=i-1;
        while(l > 0){
            cout << l;
            l--;
        }

        cout << endl;
        i++;
    }
}