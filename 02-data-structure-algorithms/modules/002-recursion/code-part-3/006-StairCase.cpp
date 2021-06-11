#include<iostream>
#include<cstring>

using namespace std;

/**
 *  Staircase
 *  -   A child is running up a staircase with N steps, and can hop either 
 *      1 step, 2 steps or 3 steps at a time. Implement a method to count how 
 *      many possible ways the child can run up to the stairs. You need to 
 *      return number of possible ways W.
 * 
 *  Input format :
 *      Integer N
 *  Output Format :
 *      Integer W
 *  Constraints :   
 *      1 <= N <= 30
 *  
 *  Sample Input 1 :
 *      4
 *  Sample Output 1 :
 *      7
 * 
 *  Sample Input 2 :
 *      5
 *  Sample Output 2 :
 *      13
 */
int staircase(int n){
    if(n ==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int step1 = staircase(n-1);
    int step2 = staircase(n-2);
    int step3 = staircase(n-3);
    return step1+step2+step3;
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}