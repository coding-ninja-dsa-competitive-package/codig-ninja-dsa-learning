#include<bits/stdc++.h>

using namespace std;

/**
 *  Sanchit And Nuclear Reactor
 *  -   We all know Sanchit Lee Cooper who is a Caltech theoretical physicist. He 
 *      has eccentric and arrogant behavior. Due to his belief that he's intellectually 
 *      superior, he's not ashamed to insult his own friends, like Howard, who is an 
 *      engineer and not a real scientist. But nobody messes with an engineer. So 
 *      Howard accepted an challenge from Sanchit. Sanchit was involved in numerous 
 *      experiments as a wunderkind, such as his plan for building his own nuclear 
 *      reactor - a plan stopped by government. So Sanchit presented Howard with a 
 *      problem about his own nuclear reactor. It contains a large tank and at each 
 *      second an atom is introduced in the tank which reacts with already existing 
 *      atoms and produces some energy. Also he defined a special threshold number for 
 *      his reactor called Cooper number m which is always a prime number. Energy output 
 *      is defined as previous energy output of the tank multiplied by number of atoms 
 *      present in it. But due to some special condition of the tank, all atoms attains 
 *      stable state when number of atoms are multiple of Cooper number and no new 
 *      reaction occurs. Energy output in this case is same as previous case. Also 
 *      initial energy of the reactor is 1 and initially there is no atom in the tank. 
 *      Now Sanchit ask Howard to tell the energy output after time T. But sadly Howard 
 *      is not able to solve it and ask for your help.
 *  
 *  Input Format
 *      The first line of the input will contain a single integer N (N <= 100) indicating 
 *      the number of test cases. Then N lines follow. Each line contains two integers, 
 *      time T(0<=T<=10^18) and Cooper number m(m<=10,000).
 *  Output Format
 *      You have to determine the energy output after time T. As the number can be quite 
 *      large so output it modulo Cooper number m.
 *  
 *  Sample Input
 *      2
 *      1 5
 *      2 5
 *  Sample Output
 *      1
 *      2
 *  Explanation
 *      After 1 seconds, there is only 1 atom in the tank. Hence energy output is 1. 
 *      After 2 seconds, there are 2 atoms which reacts to give energy output of 2.
 */

typedef long long int ll;

ll factorial(ll a, ll mod){
	ll res=1;
	for(ll i=2; i<=a; i++){
		res=(res%mod * i%mod)%mod;
    }
	return res;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		if(n < m){
			if(m-n==1){
				cout << 1 << endl;
				continue;
			} else {
				cout << factorial(n, m)%m << endl;
				continue;
			}
		}
		else{
			ll last = n%m;
			ll fact = factorial(last, m)%m;

			if((n/m)%2==0)
				cout << fact << endl;
			else
				cout << ((m-1)%m * fact%m)%m << endl;
		}
	}
	return 0;
}