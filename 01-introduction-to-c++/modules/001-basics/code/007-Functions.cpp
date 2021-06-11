#include<iostream>
using namespace std;

//function for increment
void increment(int a){
    a = a+1;
}

int main(){

    //Pass by value function
    // When increment function is called - n is copied to a . So that value of n remain
    int n=10;
    increment(n);
    cout << n << endl;

    return 0;
}