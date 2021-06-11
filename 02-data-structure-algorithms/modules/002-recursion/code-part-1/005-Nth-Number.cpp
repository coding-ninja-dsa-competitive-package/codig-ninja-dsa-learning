#include<iostream>
using namespace std;

/**
 *  Nth Fibinacci Number
 */
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smallerOutput1 = fib(n-1);
    int smallerOutput2 = fib(n-2);
    return smallerOutput1 + smallerOutput2;
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
}