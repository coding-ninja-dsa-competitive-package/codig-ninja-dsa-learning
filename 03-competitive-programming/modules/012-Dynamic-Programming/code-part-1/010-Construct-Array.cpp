#include<bits/stdc++.h>

using namespace std;

/**
 *  Construct the array:
 *  -   Your goal is to find the number of ways to construct an array such that 
 *      consecutive positions contain different values.
 *  -   Specifically, we want to construct an array with  elements such that 
 *      each element between  and , inclusive. We also want the first and last 
 *      elements of the array to be  and .
 *  -   Given ,  and , find the number of ways to construct such an array. Since 
 *      the answer may be large, only find it modulo .
 *      For example, for n=4, k=3, x=2, there are 3  ways, as shown here:
 *          1 2 1 2
 *          1 2 3 2
 *          1 3 1 2
 *  -   Complete the function countArray which takes input ,  and . Return the 
 *      number of ways to construct the array such that consecutive elements    
 *      are distinct.
 *      
 *  Constraints
 *      3 <= n <= 10^5
 *      2 <= k <= 10^5
 *      1 <= x <= k
 *  
 *  Sample Input
 *      n=4, k=3, x=2 
 *  Sample Output
 *      3   
 */
#define MOD 1000000007

long countArray(int n, int k, int x) {
    int oneCount = 1;
    int nonOneCount = 0;
    for(int i=1; i<n; i++){
        long prevCountOne = oneCount;
        oneCount = (nonOneCount*(k-1))%MOD;
        nonOneCount = (prevCountOne + ((nonOneCount)*(k-2))%MOD)%MOD;
    }
    if(x == 1){
        return oneCount;
    } else {
        return nonOneCount;
    }
}


int main() {
    int n, k, r;
    cin >> n >> k >> r;
    long ans = countArray(n, k, r);
    cout << ans;
    return 0;
}