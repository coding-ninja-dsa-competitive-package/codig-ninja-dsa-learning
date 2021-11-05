#include<bits/stdc++.h>

using namespace std;

/**
 *  Sachin And Varun Problem
 *  -   Varun and you are talking about a movie that you have recently watched while 
 *      Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to 
 *      you and asked him to answer his question in order to save himself from punishment. 
 *      The question says:
 *      -   Given two weights of a and b units, in how many different ways you can 
 *          achieve a weight of d units using only the given weights? Any of the given 
 *          weights can be used any number of times (including 0 number of times).
 *  -   Since Varun is not able to answer the question, he asked you to help him otherwise 
 *      he will get punished.
 *  Note: Two ways are considered different if either the number of times a is used or 
 *      number of times b is used is different in the two ways.
 *  
 *  Input Format:
 *      The first line of input consists of an integer 
 *      T denoting the number of test cases.
 *      Each test case consists of only one line containing three space separated 
 *      integers a, b and d.
 *  Output Format:
 *      For each test case, print the answer in a separate line.
 *  Constraints:
 *      1 ≤T≤ 10^5
 *      1 ≤ a < b ≤ 10^9
 *      0≤d≤10^9
 *  
 *  Sample Input 1
 *      4
 *      2 3 7
 *      4 10 6
 *      6 14 0
 *      2 3 6
 *  Sample Output 1
 *      1
 *      0
 *      1
 *      2
 *  Explanation
 *      Test case 1: 7 can only be achieved by using 2 two times and 3 one time.
 *      Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.
 */

typedef long long int ll;

class Triplet{
    public:
        ll x, y, gcd;
};

Triplet gcdExtendedEuclid(ll a, ll b){
    if(b==0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallAns = gcdExtendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*(smallAns.y);
    return ans;
}

ll modInverse(ll a, ll m){
    ll x = gcdExtendedEuclid(a, m).x;
    return (x%m + m) % m;
}

ll countWays(ll a, int b, ll d){
    ll y1 = ((d%a) * modInverse(b, a))%a;
    ll first_value = d/b;
    if((d/b)<y1){
        return 0;
    }
    ll n = (first_value-y1)/a;
    return n+1;
}

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, d;
        cin >> a >> b >> d;
        ll g = gcd(a, b);
        if(d%g != 0){
            cout << 0 << endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        cout << countWays(a, b, d) << endl;
    }
}