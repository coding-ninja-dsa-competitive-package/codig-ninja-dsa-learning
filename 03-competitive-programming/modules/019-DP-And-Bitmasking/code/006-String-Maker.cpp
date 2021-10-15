#include<bits/stdc++.h>

using namespace std;

/**
 *  String Maker
 *  -   According to Ancient Ninjas , string making is an art form . There are 
 *      various methods of string making , one of them uses previously generated 
 *      strings to make the new one . Suppose you have two strings A and B , to 
 *      generate a new string C , you can pick a subsequence of characters from A 
 *      and a subsequence of characters from B and then merge these two subsequences 
 *      to form the new string.
 *  -   Though while merging the two subsequences you can not change the relative 
 *      order of individual subsequences. What this means is - suppose there two 
 *      characters Ai and Aj in the subsequence chosen from A , where i < j , then 
 *      after merging if i acquires position k and j acquires p then k<p should be 
 *      true and the same apply for subsequence from C.
 *  -   Given string A , B , C can you count the number of ways to form string C from 
 *      the two strings A and B by the method described above. Two ways are different 
 *      if any of the chosen subsequence is different .
 *  -   As the answer could be large so return it after modulo 10^9+7 .
 *  
 *  Input Format :
 *      Line 1 : String A
 *      Line 2 : String B
 *      Line 3 : String C
 *  Output Format :
 *      The number of ways to form string C
 *  Constraints :
 *      1 <= |A|, |B|, |C| <= 50
 *  
 *  Sample Input :
 *      abc
 *      abc 
 *      abc
 *  Sample Output :
 *      8
 */

#define MOD 1000000007
typedef long long int ll;

int numWaysToMergeString(string s1, string s2, string s3, ll ***dp){
    int n1=s1.length(), n2=s2.length(), n3=s3.length();
    if(n3==0){
        return 1;
    }
    if(n1<=0 && n2<=0){
        return 0;
    }
    if(dp[n1][n2][n3] > -1){
        return dp[n1][n2][n3]%MOD;
    }

    ll ans=0;
    for(ll i=0; i<n1; i++){
        if(s1[i]==s3[0]){
            ans += numWaysToMergeString(s1.substr(i+1), s2, s3.substr(1), dp)%MOD;
        }
    }
    for(ll i=0; i<n2; i++){
        if(s2[i]==s3[0]){
            ans += numWaysToMergeString(s1, s2.substr(i+1), s3.substr(1), dp)%MOD;
        }
    }
    dp[n1][n2][n3]=ans%MOD;
    return dp[n1][n2][n3];
}

int solve(string s1, string s2, string s3){
    ll ***dp=new ll **[51];
    for(ll i=0; i<51; i++){
        dp[i]=new ll *[51];
        for(ll j=0; j<51; j++){
            dp[i][j]=new ll [51];
            for(ll k=0; k<51; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    ll res= numWaysToMergeString(s1, s2, s3, dp)%MOD;

    for(ll i=0; i<51; i++){
        for(ll j=0; j<51; j++){
            delete [] dp[i][j];
        }
    }
    return res;
}

int main() {
    string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;

    return 0;
}