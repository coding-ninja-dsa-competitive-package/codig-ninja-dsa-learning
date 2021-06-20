#include<bits/stdc++.h>

using namespace std;

/**
 *  Sum me Up
 *  -   There will be ‘t’ test cases having an integer. You have to sum up 
 *      all the digits of this integer. For e.g. For 6754, the answer will 
 *      be 6 + 7 + 5 + 4 = 22.
 *  Input Format:
 *      First line will have an integer ‘t’ denoting the number of test cases.
 *      Next ‘t’ lines will have an integer ‘val’ each.
 *  Output format:
 *      Print ‘t’ lines of output denoting the sum of all the digits of the 
 *      number in each test case.
 *  
 *  Constraints:
 *      1 <= t <= 10^5
 *      0 <= val <= 10^18
 *  
 *  Sample Input:
 *      2
 *      1547
 *      45876
 *  Sample Output:
 *      17
 *      30
 *  Explanation:
 *      1 + 5 + 4 + 7 = 17
 *      4 + 5 + 8 + 7 + 6 = 30
 */

typedef long long int ll;

int sumDigits(ll num){
   	int ans = 0;
	while(num){
        ans += num%10;
        num = num/10;
    }
    return ans;
}

int main() {

	int t;
    cin >> t ;
    
    while(t--){
        ll num;
        cin >> num;
        cout << sumDigits(num) << endl;
    }
}