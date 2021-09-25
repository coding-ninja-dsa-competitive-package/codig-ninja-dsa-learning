#include<bits/stdc++.h>

using namespace std;

/**
 *  Fractional Knapsack
 *  -   You want to paint your house. The total area of your house is D units. There are 
 *      a total of N workers. The ith worker is available after time Ti, has hiring cost 
 *      Xi and speed Yi. This means he becomes available for hiring from time Ti and 
 *      remains available after that. Once available, you can hire him with cost Xi, 
 *      after which he will start painting the house immediately, covering exactly Yi 
 *      units of house with paint per time unit. You may or may not hire a worker and 
 *      can also hire or fire him at any later point of time. However, no more than 1 
 *      worker can be painting the house at a given time.   
 *  -   Since you want the work to be done as fast as possible, figure out a way to hire 
 *      the workers, such that your house gets painted at the earliest possible time, 
 *      with minimum cost to spend for hiring workers.
 *  -   Note: You can hire a previously hired worker without paying him again.
 *  
 *  Input
 *      The first line of input contains two integers "N D", the number of workers and 
 *      the area of your house respectively. The ith of the next N lines denotes the ith 
 *      worker, and contains three integers "Ti Xi Yi", described in the statement.
 *  Output
 *      Output one integer, the minimum cost that you can spend in order to get your 
 *      house painted at the earliest.  
 *  
 *  Constraints
 *      1 ≤ N, T, X, Y ≤ 10^5
 *      1 ≤ D ≤ 10^11
 *  
 *  Sample Input
 *      3 3
 *      1 1 1
 *      2 2 2
 *      3 1 5
 *  Sample Output   
 *      3
 */

typedef long long int ll;

struct worker {
	ll ti;
	ll xi;
	ll yi;
};

bool compare(worker w1, worker w2){
    if(w1.ti == w2.ti){
        if(w1.yi == w2.yi){
            return w1.xi < w2.xi;
        }
        return w1.yi > w2.yi;
    }
    return w1.ti < w2.ti;
}

ll minCost(worker *workers, ll n, ll d) {
	ll currCost = workers[0].xi;
	ll currAreaCovered = 0;
	ll currWorker = 0;
	for(ll i=1; i<n && currAreaCovered<d; i++){
		currAreaCovered += (workers[i].ti-workers[i-1].ti)*workers[currWorker].yi;
		if(currAreaCovered >= d){
			return currCost;
		}
		if(workers[currWorker].yi<workers[i].yi){
			currWorker = i;
			currCost += workers[currWorker].xi;
		}
	}
	return currCost;
}

int main() {
	ll n, d;
    cin >> n >> d;
    
    worker* workers = new worker[n];
    for(ll i=0; i<n; i++){
        cin >> workers[i].ti >> workers[i].xi >> workers[i].yi;
    }
    
    sort(workers, workers+n, compare);
    
    cout << minCost(workers, n, d) << endl;
    
    return 0;
}