#include<bits/stdc++.h>

using namespace std;

/**
 *  Sam and Substring
 *  -   Samantha and Sam are playing a numbers game. Given a number as a string, 
 *      no leading zeros, determine the sum of all integer values of substrings 
 *      of the string.
 *  -   Given an integer as a string, sum all of its substrings cast as integers. 
 *      As the number may become large, return the value modulo 10^9+7.
 *  
 *  Example
 *      n = '42'
 *      Here n is a string that has 3 integer substrings: 4, 2, and 42. Their 
 *      sum is 48, and 48 modulo (10^9+7) = 48.
 *  
 *  Function Description
 *      Complete the substrings function in the editor below.
 *      substrings has the following parameter(s):
 *          string n: the string representation of an integer
 *  Returns
 *      int: the sum of the integer values of all substrings in n, modulo 10^9+7 
 *  
 *  Input Format    
 *      A single line containing an integer as a string, without leading zeros.
 * 
 *  Constraints
 *      1 <= ncastasaninteger <= 2*10^5
 *  
 *  Sample Input 0
 *      16
 *  Sample Output 0
 *      23
 *  Explanation 0
 *      The substrings of 16 are 16, 1 and 6 which sum to 23.
 *  
 *  Sample Input 1
 *      123
 *  Sample Output 1
 *      164
 *  Explanation 1
 *      The substrings of 123 are 1, 2, 3, 12, 23, 123 which sum to 164.
 */

#define MOD 1000000007

int substringSum(string str){
    long long totalSum = str[0] - '0';
    long long lastValue = str[0] - '0';

    for(int i=1; i<str.length(); i++){
        lastValue = lastValue*10 + (str[i]-'0')*(i+1);
        lastValue = lastValue%MOD;
        totalSum = totalSum + lastValue;
        totalSum = totalSum%MOD;
    }
    return totalSum;
}

int main() {
    string str;
    cin >> str;
    int ans = substringSum(str);
    cout << ans << endl;

    return 0;
}