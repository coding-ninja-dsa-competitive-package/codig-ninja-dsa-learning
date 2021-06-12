#include<iostream>

using namespace std;

/**
 *  N=4,
 *          4444444
 *          4333334
 *          4322234
 *          4321234
 *          4322234
 *          4333334  
 *          4444444
 */
int main(){
    int N;
    cin >> N;

    int i =1;
    int num = N;
    while(i <= N){
        int k = 0;
        int m = N;
        while(k < i-1){
            cout << m;
            k++;
            m--;
        }

        int j = 1;
        while(j <= 2*num -1 ){
            cout << num;
            j++;
        }
        num--;

        int p = 0;
        int q = N-i+2;
        while(p < i-1){
            cout << q;
            p++;
            q++;
        }
        i++;
        cout << endl;
    }

    int n = N-1;
    int a = n-1;
    int b = 2;
    int row = 1;
    while(a >=0){
        int j=1, num=N;
        while(j <= a){
            cout << num;
            num--;
            j++;
        }
        int k = 1;
        while(k <= 2*row+1){
            cout << b;
            k++;
        }
        b++;

        int l=1, num1=N-a+1;
        while(l <= a){
            cout << num1;
            num1++;
            l++;
        }

        a--;
        row++;
        cout << endl;
    }

}