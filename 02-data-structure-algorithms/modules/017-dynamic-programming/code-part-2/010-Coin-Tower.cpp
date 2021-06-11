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
 *  Coin Tower
 *  -   Whis and Beerus are playing a new game today. They form a tower of N coins 
 *      and make a move in alternate turns. Beerus plays first. In one step, the 
 *      player can remove either 1, X, or Y coins from the tower. The person to 
 *      make the last move wins the game. Can you find out who wins the game?
 * 
 *   Input format : 
 *      The first and the only line of input contains three integer values 
 *      separated by a single space. They denote the value of N, X and Y, respectively.
 *  Output format :
 *      Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
 *  
 *  Constraints :
 *      1 <= N <= 10 ^ 6
 *      2 <= X <= Y<= 50
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      4 2 3
 *  Sample Output 1 :
 *      Whis
 * 
 *  Sample Input 2 :
 *      10 2 4
 *  Sample Output 2 :
 *      Beerus
 */
// Approach 1 - Brute Force - O(3^n)
int findGameWinner(int n, int x, int y){
    if(n<=0){
        return 0;
    }
    int ans1 = 1 ^ findGameWinner(n-1, x, y);
    int ans2 = 0;
    if(n >= x){
        ans2 = 1 ^ findGameWinner(n-x, x, y);
    }
    int ans3 = 0;
    if(n >= y){
        ans3 = 1 ^ findGameWinner(n-y, x, y);
    }
    if(ans1+ans2+ans3 > 0){
        return 1;
    }
    return 0;
}
string findWinner(int n, int x, int y, int index = 0){
	if(findGameWinner(n, x, y) == 1){
        return "Beerus";
    }
    return "Whis";
}

// Approach 2 - Memoization = O(n)
int findGameWinnerRec(int n, int x, int y, int* arr){
    if(n<=0){
        return 0;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int ans1 = 1 ^ findGameWinnerRec(n-1, x, y, arr);
    int ans2 = 0;
    if(n >= x){
        ans2 = 1 ^ findGameWinnerRec(n-x, x, y, arr);
    }
    int ans3 = 0;
    if(n >= y){
        ans3 = 1 ^ findGameWinnerRec(n-y, x, y, arr);
    }
    if(ans1+ans2+ans3 > 0){
        arr[n] = 1;
    } else {
        arr[n] = 0;
    }
    return arr[n];
}
string findWinner2(int n, int x, int y, int index = 0){
    int* arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
	if(findGameWinnerRec(n, x, y, arr) == 1){
        return "Beerus";
    }
    return "Whis";
}
// Approach 3 - DP - O(n)
string findWinner3(int n, int x, int y, int index = 0){
    int* arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = -1;
    }
    arr[0] = 0;
    for(int i=1; i<=n; i++){
        int ans1 = 1^arr[i-1];
        int ans2=0, ans3=0;
        if(i >= x){
            ans2 = 1^arr[i-x];
        }
        if(i >= y){
            ans3 = 1^arr[i-y];
        }
        if(ans1 + ans2 + ans3 > 0){
        	arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
	if(arr[n] == 1){
        return "Beerus";
    }
    return "Whis";
}

int main(){
    int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
    cout << findWinner2(n, x, y);
    cout << findWinner3(n, x, y);

    return 0;
}