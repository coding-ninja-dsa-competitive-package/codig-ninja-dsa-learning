#include<iostream>

using namespace std;

//  inline function - compiler will replace the body of this function wherever it is used.
//  it is not sure that compiler will do if code is of more than 1 line.
inline int max(int a, int b){
    return (a>b) ? a : b;
}

// default arguments - it should be right most argument
int sum(int a[], int size, int si=0){
    int ans = 0;
    for(int i=si; i<size; i++){
        ans += a[i];
    }
    return ans;
}

void basics(){
    int a,b;
    cin >> a >> b;
    int c = max(a, b);
    cout << c << endl;

    int arr[20] = {1,2,3,4,5,6,7,8,9,9,1,2,3,4,5,6,7,8,9,1};
    cout << sum(arr, 20, 10);
    cout << sum(arr, 20);
}

/**
 *  Q/A
 *  1.  Inline functions are useful when ______
 *  Ans :   Function is small & we want to avoid function call overhead
 *          Inline functions are used to reduce the function call overhead. Inline 
 *          function is a function that is expanded in line when it is called.
 * 
 *  2.  Default arguments - Which of the following statement is correct?
 *  Ans :   All the parameters of the function can be default parameters.
 */

/**
 *  What is the output
 *  -   What is the output of the following program ?
 *  Ans : Error - Default parameters must be added last in C++ functions
 */
int getValue(int x = 0, int y = 0, int z){  
    return (x + y + z); 
}
void problem1(){
   cout << getValue(10);
}

int main() {
    basics();
    
    problem1();

    return 0;
}