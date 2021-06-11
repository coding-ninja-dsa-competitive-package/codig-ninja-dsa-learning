#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Code : Knapsack
 *  -   A thief robbing a store can carry a maximal weight of W into 
 *      his knapsack. There are N items, and i-th item weigh 'Wi' and 
 *      the value being 'Vi.' What would be the maximum value V, that 
 *      the thief can steal?
 * 
 *  Input Format :
 *      The first line contains an integers, that denote the value of N. 
 *      The following line contains N space separated integers, that 
 *      denote the values of weight of items. The following line contains 
 *      N space separated integers, that denote the values associated with 
 *      the items. The following line contains an integer that denote the 
 *      value of W. W denotes maximum weight that thief can carry.
 *  Output Format :
 *      The first and only line of output contains the maximum value that 
 *      thief can generate, as described in the task.
 *  
 *  Constraints
 *      1 <= N <= 10^4
 *      1<= wi <= 100
 *      1 <= vi <= 100
 *  
 *  Time Limit: 1 second
 * 
 *  Sample Input 1 :
 *      4
 *      1 2 4 5
 *      5 4 8 6
 *      5
 *  Sample Output 1 :
 *      13
 */
// Approach 1 - Brute Force - O(2^n)
int knapsack(int *weights, int *values, int n, int maxWeight){
	if(n==0 || maxWeight == 0){
        return 0;
    }
    if(weights[0] > maxWeight){
        return knapsack(weights+1, values+1, n-1, maxWeight);
    }
    int res1 = values[0] + knapsack(weights+1, values+1, n-1, maxWeight-weights[0]);
    int res2 = knapsack(weights+1, values+1, n-1, maxWeight);
    int res = max(res1 , res2);
    return res;
}
// Approach 2 - Memoization - O(n*w)
int knapsackRec(int *weights, int *values, int n, int maxWeight, int** arr){
	if(n==0 || maxWeight == 0){
        return 0;
    }
    if(arr[n][maxWeight] != -1){
        return arr[n][maxWeight];
    }
    if(weights[0] > maxWeight){
        arr[n][maxWeight] = knapsackRec(weights+1, values+1, n-1, maxWeight, arr);
    } else {
        int res1 = values[0] + knapsackRec(weights+1, values+1, n-1, maxWeight-weights[0], arr);
        int res2 = knapsackRec(weights+1, values+1, n-1, maxWeight, arr);
        int res = max(res1 , res2);
        arr[n][maxWeight] = res;
    }
    return arr[n][maxWeight];
}
int knapsack2(int *weights, int *values, int n, int maxWeight){
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[maxWeight+1];
        for(int j=0; j<=maxWeight; j++){
            arr[i][j] = -1;
        }
    }
    return knapsackRec(weights, values, n, maxWeight, arr);
}
// Approach 3 - DP - O(n*w)
int knapsack3(int *weights, int *values, int n, int maxWeight){
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[maxWeight+1];
        for(int j=0; j<=maxWeight; j++){
            arr[i][j]=-1;
        }
    }
    for(int j=0; j<=maxWeight; j++){
        arr[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        arr[i][0] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=maxWeight; j++){
            if(weights[i-1] > j){
                arr[i][j] = arr[i-1][j];
            } else {
                int a = values[i-1] + arr[i-1][j-weights[i-1]];
                int b = arr[i-1][j];
                arr[i][j] = max(a , b);
            }
        }
    }
    return arr[n][maxWeight];
}


int main(){
    int n;
	cin >> n;
	int *weights = new int[n];
	int *values = new int[n];
	for (int i = 0; i < n; i++){
		cin >> weights[i];
	}
	for (int i = 0; i < n; i++){
		cin >> values[i];
	}
	int maxWeight;
	cin >> maxWeight;
	cout << knapsack(weights, values, n, maxWeight) << endl;
    cout << knapsack2(weights, values, n, maxWeight) << endl;
    cout << knapsack3(weights, values, n, maxWeight) << endl;
	delete[] weights;
	delete[] values;

    return 0;
}
