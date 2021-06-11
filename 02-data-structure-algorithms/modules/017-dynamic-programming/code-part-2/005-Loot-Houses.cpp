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
 *  Loot Houses
 *  -   A thief wants to loot houses. He knows the amount of money in each house. 
 *      He cannot loot two consecutive houses. Find the maximum amount of money 
 *      he can loot.
 * 
 *  Input format :
 *      The first line of input contains an integer value of 'n'. It is the 
 *      total number of houses.
 *      The second line of input contains 'n' integer values separated by a 
 *      single space denoting the amount of money each house has.
 *  Output format :
 *      Print the the maximum money that can be looted.
 * 
 *  Constraints :
 *      0 <= n <= 10 ^ 4
 *      
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      6
 *      5 5 10 100 10 5
 *  Sample Output 1 :
 *      110
 * 
 *  Sample Input 2 :
 *      6
 *      10 2 30 20 3 50
 *  Sample Output 2 :
 *      90
 *  Explanation of Sample Output 2 :
 *      Looting first, third, and the last houses([10 + 30 + 50]) will result 
 *      in the maximum loot, and all the other possible combinations would result 
 *      in less than 90.
 */
// Approach 1 - Brute Force - O(2^n)
int maxMoneyLooted(int *arr, int n){
	if(n <= 0){
        return 0;
    }
    int ans1 = arr[0] + maxMoneyLooted(arr+2, n-2);
    int ans2 = maxMoneyLooted(arr+1, n-1);
    return max(ans1 , ans2);
}
// Approach 2 - Memoization
int maxMoneyLootedRec(int *arr, int n, int* out){
	if(n <= 0){
        return 0;
    }
    if(out[n] != -1){
        return out[n];
    }
    int ans1 = arr[0] + maxMoneyLootedRec(arr+2, n-2, out);
    int ans2 = maxMoneyLootedRec(arr+1, n-1, out);
    out[n] = max(ans1 , ans2);
    return out[n];
}
int maxMoneyLooted2(int *arr, int n){
    int* out = new int[n+1];
    for(int i=0; i<=n; i++){
        out[i] = -1;
    }
    return maxMoneyLootedRec(arr, n, out);
}
// Approach 3 - DP
int maxMoneyLooted3(int *arr, int n){
    int* out = new int[n+1];
    out[0] = 0;
    out[1] = arr[0];
    for(int i=2; i<=n; i++){
        out[i] = max(out[i-1], arr[i-1]+out[i-2]);
    }
    return out[n];
}

int main(){
    int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxMoneyLooted(arr, n);
    cout << maxMoneyLooted2(arr, n);
    cout << maxMoneyLooted3(arr, n);
	delete[] arr;

    return 0;
}