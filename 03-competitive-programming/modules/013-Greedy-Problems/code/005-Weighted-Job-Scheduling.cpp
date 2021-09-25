#include<bits/stdc++.h>

using namespace std;

/**
 *  Weighted Job Scheduling
 *  -   You are given N jobs where every job is represented as: 
 *      1.  Start Time
 *      2.  Finish Time
 *      3.  Profit Associated
 *  -   Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
 *  
 *  Input
 *      The first line of input contains one integer denoting N.
 *      Next N lines contains three space separated integers denoting the start time,   
 *      finish time and the profit associated with the ith job. 
 *  Output
 *      Output one integer, the maximum profit that can be achieved.
 *  
 *  Constraints
 *      1 ≤ N ≤ 10^6
 *      1 ≤ ai, di, p ≤ 10^6
 *  
 *  Sample Input
 *      4
 *      3 10 20
 *      1 2 50
 *      6 19 100
 *      2 100 200
 *  Sample Output
 *      250
 */

struct job{
    int start, finish, profit;
};

bool compare(job j1, job j2){
    return j1.finish < j2.finish;
}

int binarySearch(job* jobs, int index){
    int lo = 0, hi = index - 1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start){
            if (jobs[mid + 1].finish <= jobs[index].start){
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

int maxProfit(job* jobs, int n){
    sort(jobs, jobs+n, compare);
    
    int* dp = new int[n];
    dp[0] = jobs[0].profit;

    for (int i=1; i<n; i++) {
        int includingProfit = jobs[i].profit;
        int idx = binarySearch(jobs, i);
        if (idx != -1) {
            includingProfit += dp[idx];
        }
        dp[i] = max(includingProfit, dp[i-1]);
    }
    
    int ans = dp[n-1];
    delete [] dp;
    return ans;
}

int main() {
    int n;
    cin >> n;

    job* jobs = new job[n];
    for(int i=0; i<n; i++){
        cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
    }
    
    cout << maxProfit(jobs, n) << endl;

    return 0;
}