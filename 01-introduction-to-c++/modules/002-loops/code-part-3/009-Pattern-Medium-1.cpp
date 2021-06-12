#include<iostream>
using namespace std;

/**
 *     N= 4, 
 *      1 2 3 4
 *      9 10 11 12
 *      13 14 15 16
 *      5 6 7 8
 */
int main()
{
    int n;
    cin >> n;
    
	// Write your code here
    int n1, n2;
    if(n%2 == 0){
        n1 = n2 = n/2;
    } else {
        n1 = n/2+1;
        n2 = n/2;
    }
    
    int i=1;
    int num = 1;
    while(i <= n1){
        int j = 1;
        while(j <= n){
            cout << num << " ";
            num++;
            j++;
        }
        i++;
        num = num+n;
        cout<< endl;
    }

    if(n%2 == 0){
        num = num - n;
    } else {
        num = num - 3*n;
    }

    int k= 1;
    while(k <= n2){
        int j = 1;
        while(j <= n){
            cout << num << " ";
            num++;
            j++;
        }
        num = num - 3*n;
        k++;
        cout << endl;
    }
}