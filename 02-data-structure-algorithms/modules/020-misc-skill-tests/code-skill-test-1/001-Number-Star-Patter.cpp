/**
 *  Number Star Pattern
 *  -   Print the following pattern for given number of rows.
 *     
 *  Input format :
 *      Line 1 : N (Total number of rows)
 *  
 *  Sample Input :
 *      5
 *  Sample Output :
 *      1234554321
 *      1234**4321
 *      123****321
 *      12******21
 *      1********1
 */


#include<iostream>
using namespace std;


int main(){
  	int n;
	cin >> n;
    
    int row =0;
    while(row < n){
        int num=1;
        for(int i=0; i<n-row; i++){
            cout << num;
            num++;
        }
        for(int i=0; i < 2*row; i++){
            cout << "*";
        }
        num = n-row;
        for(int i=0; i<n-row; i++){
            cout << num;
            num--;
        }
        row++;
        cout << endl;
    }
}


