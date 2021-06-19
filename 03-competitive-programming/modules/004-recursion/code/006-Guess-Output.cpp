#include<bits/stdc++.h>

using namespace std;

/**
 *  What is the output
 *  -   What will be the output of the following code ?
 *  Ans : Runtime Error
 *      Since the base case is missing in the code, therefore there will be 
 *      infinite recursion calls and hence runtime error will occur.
 */
int func(int num){
    return func(num- 1);
}
void problem1() {
    int num = 5;
    int ans = func(num - 1);
    cout << ans;
}

/**
 *  What is the output
 *  -   What will be the output ?
 *  Ans : 5 3 1
 */
void print(int n){
    if(n < 0){
        return;
    }
    cout << n << " ";
    print(n - 2);
}
void problem2() {
    int num = 5;
    print(num);
}

/**
 *  What is the output
 *  -   What will be the output of the following code ?
 *  Ans : Runtime Error
 *      In function print when recursion call is being made  n-- is being 
 *      passed as input. Here we are using post decrement operator, so 
 *      argument passed to next function call is n and not n - 1. Thus 
 *      there will be infinite recursion calls and runtime error will come.
 */
void print(int n){
    if(n < 0){
        return;
    }
    if(n == 0){
        cout << n << " ";
        return;
    }
    print(n --);
    cout << n << " ";
}
void problem3() {
    int num = 3;
    print(num);
}



int main() {
    problem1();
    problem2();
    problem3();

    return 0;
}