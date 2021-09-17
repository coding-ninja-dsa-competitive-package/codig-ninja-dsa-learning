#include<bits/stdc++.h>

using namespace std;

/**
 *  PARTY - Problem
 *  -   You just received another bill which you cannot pay because you lack the money.
 *  -   Unfortunately, this is not the first time to happen, and now you decide to  
 *      investigate the cause of your constant monetary shortness. The reason is quite 
 *      obvious: the lion's share of your money routinely disappears at the entrance of 
 *      party localities.
 *  -   You make up your mind to solve the problem where it arises, namely at the 
 *      parties themselves. You introduce a limit for your party budget and try to 
 *      have the most possible fun with regard to this limit.
 *  -   You inquire beforehand about the entrance fee to each party and estimate how 
 *      much fun you might have there. The list is readily compiled, but how do you 
 *      actually pick the parties that give you the most fun and do not exceed your budget?
 *  -   Write a program which finds this optimal set of parties that offer the most fun. 
 *      Keep in mind that your budget need not necessarily be reached exactly. Achieve 
 *      the highest possible fun level, and do not spend more money than is absolutely 
 *      necessary.
 *  
 *  Input
 *      The first line of the input specifies your party budget and the number n of parties.
 *      The following n lines contain two numbers each. The first number indicates the 
 *      entrance fee of each party. Parties cost between 5 and 25 francs. The second number 
 *      indicates the amount of fun of each party, given as an integer number ranging from 
 *      0 to 10.
 *      The budget will not exceed 500 and there will be at most 100 parties. All numbers 
 *      are separated by a single space.
 *      There are many test cases. Input ends with 0 0.
 *  Output
 *      For each test case your program must output the sum of the entrance fees and the 
 *      sum of all fun values of an optimal solution. Both numbers must be separated by 
 *      a single space. 
 *  
 *  Sample Input
 *      50 10
 *      12 3    
 *      15 8
 *      16 9
 *      16 6
 *      10 2
 *      21 9
 *      18 4
 *      12 4
 *      17 8
 *      18 9 
 * 
 *      50 10
 *      13 8
 *      19 10
 *      16 8
 *      12 9
 *      10 2
 *      12 8
 *      13 5
 *      15 5
 *      11 7
 *      16 2
 * 
 *      0 0
 *  Sample Output
 *      49 26
 *      48 32
 */

pair<int, int> maxFun(int* entry, int* fun, int budget, int n, pair<int, int>** dp){
    if(n==0){
        pair<int, int> ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    if(dp[budget][n].first != -1 && dp[budget][n].second != -1){
        return dp[budget][n];
    }
    
    if(entry[0] > budget){
        dp[budget][n] = maxFun(entry+1, fun+1, budget, n-1, dp);
    } else {
        pair<int, int> ans1 = maxFun(entry+1, fun+1, budget-entry[0], n-1, dp);
        ans1.first += entry[0];
        ans1.second += fun[0];	
        pair<int, int> ans2 = maxFun(entry+1, fun+1, budget, n-1, dp);
        if(ans1.second > ans2.second){
            dp[budget][n] = ans1;
        } else if(ans2.second > ans1.second){
            dp[budget][n] = ans2;
        } else {
            if(ans1.first < ans2.first){
                dp[budget][n] = ans1;
            } else {
                dp[budget][n] = ans2;
            }
        }
    }
    return dp[budget][n];
}

int main(){
    
    while(true){
        int budget, n;
        cin >> budget >> n;
        if(budget == 0 && n == 0){
            break;
        }
        
        int* entry = new int[n];
        int* fun = new int[n];
        for(int i=0; i<n; i++){
            cin >> entry[i] >> fun[i];
        }
        
        pair<int, int>** dp = new pair<int, int>*[budget+1];
        for(int i=0; i<=budget ; i++){
            dp[i] = new pair<int, int>[n+1];
            for(int j=0; j<=n; j++){
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }
        
        pair<int, int> res = maxFun(entry, fun, budget, n, dp);
        cout << res.first << " " << res.second << endl;
        
        for(int i=0; i<budget; i++){
            delete [] dp[i];
        }
        delete [] dp;
    }
    
    return 0;
}
