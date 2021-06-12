#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

/**
 *  Reverse Triangle
 *      N=4 , 
 *              *
 *             **
 *            ***
 *           ****
 */
int main(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int spaces = 1; 
        while(spaces <= N - i){
            cout << " ";
            spaces++;
        }
        int stars = 1;
        while(stars <= i){
            cout << "*";
            stars++;
        }
        cout << endl;
        i++;
    }
}