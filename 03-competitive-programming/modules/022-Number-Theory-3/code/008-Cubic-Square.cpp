#include<bits/stdc++.h>

using namespace std;

/**
 *  Cubic Square
 *  -   Varun is learning method of successive squaring so that he can calculate a^b 
 *      mod m quickly. To give himself practice he wrote many tuples of a, b and m and 
 *      went to school thinking that he will do it after school.
 *  -   After school he found that tuples he wrote are modified by his little sister. 
 *      His sister converted each b into base 3. Varun wrote everything in base 10.
 *  -   Help Varun to do his excercise.
 *  
 *  Input
 *      First line of input contains a number T, number of test cases. Then T test 
 *      cases follows each containing three numbers a (<=10^9), b and m (<=10^5) (a 
 *      in base 10, b in base 3 and m in base 10). Number of digits in b will be less 
 *      than 250.
 *  Output
 *      Output a number for each test case a^b mod m in base 10.
 *  
 *  Sample Input:
 *      2   
 *      2 10 10
 *      3 21101 19
 *  Sample Output:
 *      8
 *      3
 */
typedef long long int ll;

int power(ll a, string b, int mod){
	int length = b.length();
	ll ans = 1;
	for(int i=length-1; i>=0; i--){
		if(b[i] == '0'){	
			a %= mod;
			a = (((a*a)%mod)*a)%mod;
		}
		if(b[i] == '1'){	
			ans = (ans*a)%mod;
			a = (((a*a)%mod)*a)%mod;
		}
		if(b[i] == '2'){
			ans = (((ans*a)%mod) * a)%mod;
			a = (((a*a)%mod)*a)%mod;
		}
	}
	return ans;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a;
		string b;
		int m; 
		cin >> a >> b >> m;
		cout << power(a, b, m) << endl;
	}
	return 0; 
}