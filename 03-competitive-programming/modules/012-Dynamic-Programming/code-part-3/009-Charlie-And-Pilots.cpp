#include<bits/stdc++.h>

using namespace std;

/**
 *  Charlie and Pilots
 *  -   Charlie acquired airline transport company and to stay in business he needs to 
 *      lower the expenses by any means possible. There are N pilots working for his 
 *      company (N is even) and N/2 plane crews needs to be made. A plane crew consists 
 *      of two pilots - a captain and his assistant. A captain must be older than his 
 *      assistant. Each pilot has a contract granting him two possible salaries - one 
 *      as a captain and the other as an assistant. A captain's salary is larger than 
 *      assistant's for the same pilot. However, it is possible that an assistant has 
 *      larger salary than his captain. Write a program that will compute the minimal 
 *      amount of money Charlie needs to give for the pilots' salaries if he decides 
 *      to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots 
 *      in crews.
 *  
 *  Input
 *      The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number 
 *      of pilots working for the Charlie's company. The next N lines of input contain 
 *      pilots' salaries. The lines are sorted by pilot's age, the salaries of the 
 *      youngest pilot are given the first. Each of those N lines contains two integers 
 *      separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain 
 *      (X) and a salary as an assistant (Y).
 *  Output
 *      The first and only line of output should contain the minimal amount of money 
 *      Charlie needs to give for the pilots' salaries. 
 *  
 *  Sample Input
 *      4 
 *      5000 3000 
 *      6000 2000   
 *      8000 1000 
 *      9000 6000 
 *  Sample Output
 *      19000 
 */

int calculateMinMoneyneeded(int* pilots, int* assistants, int n, int diff_pilots_assistants, int** dp){
    if(n==0) {
        return 0;
    }
    if(dp[n][diff_pilots_assistants] > -1){
        return dp[n][diff_pilots_assistants];
    }
    
    int ans;
    if(diff_pilots_assistants == 0){
        ans = assistants[0] + calculateMinMoneyneeded(pilots+1, assistants+1, n-1, diff_pilots_assistants+1, dp);
    } else if(diff_pilots_assistants == n){
        ans = pilots[0] + calculateMinMoneyneeded(pilots+1, assistants+1, n-1, diff_pilots_assistants-1, dp);
    } else {
        int ans1 = assistants[0] + calculateMinMoneyneeded(pilots+1, assistants+1, n-1, diff_pilots_assistants+1, dp);
		int ans2 = pilots[0] + calculateMinMoneyneeded(pilots+1, assistants+1, n-1, diff_pilots_assistants-1, dp);
		ans= min(ans1, ans2);
    }
    dp[n][diff_pilots_assistants] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    
    int* pilots = new int[n];
    int* assistants = new int[n];
    for(int i=0; i<n; i++){
        cin >> pilots[i] >> assistants[i];
    }
    
    int** dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    
    cout << calculateMinMoneyneeded(pilots, assistants, n, 0, dp);
    
    for(int i=0; i<=n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    
    return 0;
}
