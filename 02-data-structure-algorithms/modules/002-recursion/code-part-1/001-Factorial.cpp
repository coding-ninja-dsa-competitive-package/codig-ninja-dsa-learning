#include<iostream>
using namespace std;

/**
 *  Works on thre principle of mathematical induction.
 *  1.  Prove that F(0) , F(1) true.
 *  2.  Assume that F(K)  is true.
 *  3.  Prove that F(K+1) is true.
 * 
 *  For Recusrsion problems:
 *  1.  Write base case.
 *  2.  Assume it will work for smaller problem.
 *  3.  Solve big problem using the smaller problem output.
 */
int factorial(int n){
    if(n == 0){
        return 1;
    }
    int smallerOutput = factorial(n-1);
    return n*smallerOutput;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout<<"========================"<<endl;
}