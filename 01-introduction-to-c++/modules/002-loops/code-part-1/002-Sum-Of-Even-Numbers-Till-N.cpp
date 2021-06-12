#include<iostream>

using namespace std;

/**
 *  Sum of Even Numbers till N
 *  -   Given a number N, print sum of all even numbers from 1 to N.
 *  
 *  Input Format :
 *      Integer N
 *  Output Format :
 *      Required Sum 
 *  
 *  Sample Input 1 :
 *      6
 *  Sample Output 1 :
 *      12
 */
int main(){
    int N;
    cin >> N;
    
    int sum = 0 , ptr = 2;
    while( ptr <= N ){
        sum += ptr;
        ptr = ptr+2;
    }
    cout << sum << endl;
}