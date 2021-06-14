#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  Power
 *  -   Ninja is given an easy task. He has to implement a function which calculates 
 *      a^b. But there is a small difference, b is an extremely large positive number 
 *      given in the form of an array.
 *  Note: Since answers can be huge, print answer mod 1337.
 *      It is given that b will not contain leading zeros.
 * 
 *  Input Format:
 *      First line of input contains an integer a
 *      Second line of input contains an integer n, representing the size of the array.
 *      Third line of input contains an array (space separated).
 *  
 *  Constraints:
 *      1 <= a <= 2^31 - 1
 *      1 <= b.length <= 3 * 10^6
 *      0 <= b[i] <= 9
 *      
 *  Time Limit: 1 second
 *  Output Format:
 *      Single line of output printing a^b
 *  
 *  Sample Input 1:
 *      5
 *      2
 *      1 5
 *  Sample Output:
 *      944
 *  Explanation:
 *      5 to the power 15 is 30517578125. Its mod with 1337 is 944.
 */

#define M 1337
#define ll unsigned long long int

ll calculatePower(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2 == 1){
            res = (res * a) % M;
        }
        b = b/2;
        a = (a * a) % M;
    }
    return res%M;
}
int main(){
    
    ll a;
    ll n;
    cin >> a >> n;
    ll b=0;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        b = ((b * 10) + num);
    }
    cout << calculatePower(a, b);
    
    return 0;
}