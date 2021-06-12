#include<iostream>

using namespace std;

/**
 *      N=5,
 *          *****
 *          ** **
 *          *   *
 *          ** **
 *          *****
 */
int main(){
    int n;
    cin >> n;

    if(n%2 == 0){
        n = n+1;
    }
    int i = 1;
    int n1= n/2+1;
    while(i <= n1){
        int j=n1;
        int count =0;
        while(j >= i){
            cout << "*";
            j--;
            count++;
        }
        int space=1;
        while(space <= 2*i-3){
            cout << " ";
            space++;
            count++;
        }
        while(count < n){
            cout << "*";
            count++;
        }
        
        i++;
        cout << endl;
    }
    int n2 = n/2;
    int j = n2, row=1;
    while(row <= n2){
        int k = row+1;
        int count=0;
        while(k >= 1){
            cout << "*";
            k--;
            count++;
        }
        int space = 1;
        while(space <= 2*j-3){
            cout << " ";
            space++;
            count++;
        }
        while(count < n){
            cout << "*";
            count++;
        }

        row++;
        j--;
        cout << endl;
    }
}