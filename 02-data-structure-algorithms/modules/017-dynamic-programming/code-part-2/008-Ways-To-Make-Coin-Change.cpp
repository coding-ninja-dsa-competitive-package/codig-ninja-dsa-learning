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
 *  Ways To Make Coin Change
 *  -   For the given infinite supply of coins of each of denominations,
 *      D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total 
 *      number of ways W, in which you can make the change for Value V using 
 *      coins of denominations D.
 *  -   Return 0 if the change isn't possible.
 * 
 *  Input Format        
 *      The first line of the input contains an integer value N, which denotes 
 *      the total number of denominations.
 *      The second line of input contains N values, separated by a single 
 *      space. These values denote the value of denomination.
 *      The third line of the input contains an integer value, that denotes the value of V.
 * 
 *  Output Format
 *      Print the total total number of ways i.e. W.
 * 
 *  Constraints :
 *      1 <= n <= 10
 *      1 <= V <= 1000
 * 
 *  Time Limit: 1sec
 *  
 *  Sample Input 1 :
 *      3
 *      1 2 3
 *      4
 *  Sample Output 1 :
 *      4
 *  Explanation to Sample Input 1 : 
 *      Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
 * 
 *  Sample Input 2 :
 *      6
 *      1 2 3 4 5 6
 *      250
 *  Sample Output 2 :
 *      13868903
 */
// Approach 1 - Brute Force - O(2^n)
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }
    if(numDenominations<=0 && value>0){
        return 0;
    }
    int ans1 = countWaysToMakeChange(denominations, numDenominations-1, value);
    int ans2 = countWaysToMakeChange(denominations, numDenominations, value-denominations[numDenominations-1]);
    return ans1+ans2;
}
// Approach 2 - Memoization - O(n^2)
int countWaysToMakeChangeRec(int denominations[], int numDenominations, int value, int** arr){
	if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }
    if(numDenominations<=0 && value>0){
        return 0;
    }
    if(arr[numDenominations][value] != -1){
        return arr[numDenominations][value];
    }
    int ans1 = countWaysToMakeChangeRec(denominations, numDenominations-1, value, arr);
    int ans2 = countWaysToMakeChangeRec(denominations, numDenominations, value-denominations[numDenominations-1], arr);
    arr[numDenominations][value] = ans1+ans2;
    return arr[numDenominations][value];
}
int countWaysToMakeChange2(int denominations[], int numDenominations, int value){
    int** arr = new int*[numDenominations+1];
    for(int i=0; i<=numDenominations; i++){
        arr[i] = new int[value+1];
        for(int j=0; j<=value; j++){
            arr[i][j] = -1;
        }
    }
    return countWaysToMakeChangeRec(denominations, numDenominations, value, arr);
}
// Approach 3 - DP - O(n^2)
int countWaysToMakeChange3(int denominations[], int numDenominations, int value){
    int arr[numDenominations+1][value+1];
    for(int i=0; i<=numDenominations; i++){
        for(int j=0; j<=value; j++){
            if(i == 0){
                arr[i][j] = 0;  
            }
            if(j == 0){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=1; i<=numDenominations; i++){
        for(int j=1; j<=value; j++){
            if(denominations[i-1] > j){
                arr[i][j] = arr[i-1][j];
            } else {
                arr[i][j] = arr[i-1][j] + arr[i][j-denominations[i-1]];
            }
        }
    }
    return arr[numDenominations][value];
}

int main(){
    int numDenominations;
	cin >> numDenominations;
	int *denominations = new int[numDenominations];
	for (int i = 0; i < numDenominations; i++){
		cin >> denominations[i];
	}
	int value;
	cin >> value;
	cout << countWaysToMakeChange(denominations, numDenominations, value);
    cout << countWaysToMakeChange2(denominations, numDenominations, value);
    cout << countWaysToMakeChange3(denominations, numDenominations, value);
	delete[] denominations;

    return 0;
}