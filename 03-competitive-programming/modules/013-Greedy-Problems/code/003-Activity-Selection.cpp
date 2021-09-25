#include<bits/stdc++.h>

using namespace std;

/**
 *  Activity Selection
 *  -   You are given n activities with their start and finish times. Select the 
 *      maximum number of activities that can be performed by a single person, assuming 
 *      that a person can only work on a single activity at a time.
 *  
 *  Input
 *      The first line of input contains one integer denoting N.
 *      Next N lines contains two space separated integers denoting the start time and 
 *      finish time for the ith activity.    
 *  Output
 *      Output one integer, the maximum number of activities that can be performed
 *  
 *  Constraints
 *      1 ≤ N ≤ 10^6
 *      1 ≤ ai, di ≤ 10^9
 *  
 *  Sample Input
 *      6
 *      1 2
 *      3 4
 *      0 6
 *      5 7
 *      8 9
 *      5 9
 *  Sample Output
 *      4
 */

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int numActivities(pair<int, int>* p, int n){
    int currEndTime = p[0].second;
    int count = 1;
    for(int i=1; i<n; i++){
        if(p[i].first >= currEndTime){
            count++;
            currEndTime = p[i].second;
        }
    }
    return count;
}

int main() {
	int n;
    cin >> n;
    
    pair<int, int>* intervals = new pair<int, int>[n];
    for(int i=0; i<n; i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    sort(intervals, intervals+n, compare);
    cout << numActivities(intervals, n) << endl;
    
    return 0;
}