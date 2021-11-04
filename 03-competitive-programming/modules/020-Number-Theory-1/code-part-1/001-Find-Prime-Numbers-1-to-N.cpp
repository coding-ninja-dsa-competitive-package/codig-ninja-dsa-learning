#include<bits/stdc++.h>

using namespace std;

/**
 *  Find Prime Numbers From 1 to N
 *  -   Given a number N, find number of primes in the range [1,N].
 *      
 *  Input:
 *      The only line of input consists of a number N
 *  Output:
 *      Print the number of primes in the range [1,N].`
 *  Constraints:
 *      1≤N≤1000000
 *  
 *  Sample Input :
 *      3 
 *  Sample Output -
 *      2
 */ 
bool checkPrime(int n){
    int countFactors = 0;
    for(int i=1; i*i<=n; i++){
        if((n%i)==0){
            if(i*i == n){
                countFactors += 1;
            } else {
                countFactors +=2;
            }
        }
    }
    return (countFactors==2);
}

int main() {
    int n;
    cin >> n;

    int count=0;
    for (int i=1; i<=n; i++){
        if(checkPrime(i)){
            count++;
        }
    }
    cout << count << endl;
    
    return 0;
}