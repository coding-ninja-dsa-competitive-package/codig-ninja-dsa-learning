#include<bits/stdc++.h>

using namespace std;

/**
 *  Loot Houses
 *  -   A thief wants to loot houses. He knows the amount of money in each house. 
 *      He cannot loot two consecutive houses. Find the maximum amount of money 
 *      he can loot.
 *  
 *  Input format :
 *      The first line of input contains an integer value of 'n'. It is the total 
 *      number of houses.
 *      The second line of input contains 'n' integer values separated by a single 
 *      space denoting the amount of money each house has.
 *  Output format :
 *      Print the the maximum money that can be looted.
 *  
 *  Constraints :
 *      0 <= n <= 10 ^ 4
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
 *      Looting first, third, and the last houses([10 + 30 + 50]) will result in 
 *      the maximum loot, and all the other possible combinations would result in 
 *      less than 90.
 */

int maxLoot(int* arr, int n, int* temp){
    if(n <= 0){
        return 0;
    }
    if(temp[n] != -1){
        return temp[n];
    }
    int ans1 = maxLoot(arr+1, n-1, temp);
    int ans2 = arr[0] + maxLoot(arr+2, n-2, temp);
    temp[n] = max(ans1, ans2);
    return temp[n];
}

int maxMoneyLooted(int *arr, int n){
	int* temp = new int[n+1];
    for(int i=0; i<=n; i++){
        temp[i] = -1;
    }
    return maxLoot(arr, n, temp);
}

int main() {
    int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
    return 0;
}