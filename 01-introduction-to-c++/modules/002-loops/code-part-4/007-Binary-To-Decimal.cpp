#include<iostream>

using namespace std;

/**
 *  Binary to decimal
 *  ->  Given a binary number as an integer N, convert it into decimal and print.
 *  
 *  Input format :
 *      An integer N in the Binary Format
 *  Output format :
 *      Corresponding Decimal number (as integer)
 * 
 *  Constraints :
 *      0 <= N <= 10^9
 *      
 *  Sample Input 1 :
 *      1100
 *  Sample Output 1 :
 *      12
 *  
 *  Sample Input 2 :
 *      111
 *  Sample Output 2 :
 *      7
 */
int power(int n, int p){
    int result = 1;
    for(int i=1; i<=p ; i++){
        result *= n;
    }
    return result;
}

int main(){
    int N;
    cin >> N;

    int i = 0, result = 0;
    while(N){
        if(N%10 == 1){
            result += power(2, i);
        }
        i++;
        N = N/10;
    }
    cout << result << endl;
}