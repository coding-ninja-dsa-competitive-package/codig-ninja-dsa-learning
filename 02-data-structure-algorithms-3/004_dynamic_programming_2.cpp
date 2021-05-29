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
 *  Code : Min Cost Path
 *  -   An integer matrix of size (M x N) has been given. Find out the 
 *      minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
 *  -   From a cell (i, j), you can move in three directions:
 *      1. ((i + 1),  j) which is, "down"
 *      2. (i, (j + 1)) which is, "to the right"
 *      3. ((i+1), (j+1)) which is, "to the diagonal"
 *  -   The cost of a path is defined as the sum of each cell's values 
 *      through which the route passes.
 */
// Approach 1 - Recursive - Brute Force - O(3^n)
int minCostRec(int **arr, int i, int j, int n, int m){
    if(i == n && j == m){
        return arr[i][j];
    }
    int res = INT_MAX;
    if(i+1 <= n){
        res = min(res, minCostRec(arr, i+1, j, n, m));
    }
    if(j+1 <= m){
        res = min(res, minCostRec(arr, i, j+1, n, m));
    }
    if(i+1 <= n && j+1 <= m){
        res = min(res, minCostRec(arr, i+1, j+1, n, m));
    }
    int cost = res + arr[i][j];
    return cost;
}
int minCostPath(int **input, int m, int n){
    return minCostRec(input, 0, 0, m-1, n-1);
}
// Approach 2 - Memoization - Recursive
int minCostMemo(int **arr, int i, int j, int n, int m, int **out){
    if(i == n && j == m){
        return arr[i][j];
    }
    if(out[i][j] != -1){
        return out[i][j];
    }

    int res = INT_MAX;
    if(i+1 <= n){
        res = min(res, minCostMemo(arr, i+1, j, n, m, out));
    }
    if(j+1 <= m){
        res = min(res, minCostMemo(arr, i, j+1, n, m, out));
    }
    if(i+1 <= n && j+1 <= m){
        res = min(res, minCostMemo(arr, i+1, j+1, n, m, out));
    }
    int cost = res + arr[i][j];
    out[i][j] = cost;
    return cost;
}
int minCostPath2(int **input, int m, int n){
    int** out = new int*[m];
    for (int i = 0; i < m; i++){
        out[i] = new int[n];
		for (int j = 0; j < n; j++){
			out[i][j] = -1;
		}
	}
    return minCostMemo(input, 0, 0, m-1, n-1, out);
}
// Approach 3 - DP 
int minCostPath3(int **input, int m, int n){
    int** out = new int*[m];
    for (int i = 0; i < m; i++){
        out[i] = new int[n];
	}
    // fill last cell
    out[m-1][n-1] = input[m-1][n-1];
    // fill last row
    for(int j=n-2; j>=0; j--){
        out[m-1][j] = out[m-1][j+1] + input[m-1][j];
    }
    // fill last column
    for(int i=m-2; i>=0; i--){
        out[i][n-1] = out[i+1][n-1] + input[i][n-1];
    }
    // fill the rest
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            out[i][j] = min(out[i+1][j] , min(out[i][j+1], out[i+1][j+1])) + input[i][j];
        }
    }
    return out[0][0];
}
void problem1(){
    int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++){
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
    cout << minCostPath2(arr, n, m) << endl;
    cout << minCostPath3(arr, n, m) << endl;
}

/**
 *  Largest Common SubSequence from two strings
 */
// Approach 1 - Brute Force - Recursion - O(3^n)
int lcs(string s1, string s2){
    if(s1.length() == 0 || s2.length() == 0){
        return 0;
    }
    if(s1[0] == s2[0]){
        return 1 + lcs(s1.substr(1), s2.substr(1));
    } else {
        int a = lcs(s1.substr(1), s2);  
        int b = lcs(s1, s2.substr(1));
        int c = lcs(s1.substr(1), s2.substr(1));
        return max(a, max(b, c));
    }
}
// Approach 2 - Memoization - Recursion - O(m*n)
int lcsMemo(string s1, string s2, int** arr){
    int m = s1.size();
    int n = s2.size();
    // Base Case
    if(m == 0 || n == 0){
        return 0;
    }
    // Check if result already exist
    if(arr[m][n] != -1){
        return arr[m][n];
    }
    // Recursive Calls
    int ans;
    if(s1[0] == s2[0]){
        ans = 1 + lcsMemo(s1.substr(1), s2.substr(1), arr);
    } else {
        int a = lcsMemo(s1.substr(1), s2, arr);
        int b = lcsMemo(s1, s2.substr(1), arr);
        int c = lcsMemo(s1.substr(1), s2.substr(1), arr);
        ans = max(a, max(b, c));
    }
    arr[m][n] = ans;
    return ans;
}
int lcs2(string s1, string s2){
    int n = s1.length()+1;
    int m = s2.length()+1;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            arr[i][j] = -1;
        }
    }
    return lcsMemo(s1, s2, arr);
}
// Approach 3 - DP - O(m*n)
int lcs3(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int **arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
    }
    for(int i=0; i<=n; i++){
        arr[i][0] = 0;
    }
    for(int j=0; j<=m; j++){
        arr[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ans;
            if(s1[n-i] == s2[m-j]){
                ans = 1 +  arr[i-1][j-1];
            } else {
                int a = arr[i-1][j];
                int b = arr[i][j-1];
                int c = arr[i-1][j-1];
                ans = max(a, max(b, c));
            }
            arr[i][j] = ans;
        }
    }
    return arr[n][m];
}
void problem2(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    cout << lcs2(s1, s2) << endl;
    cout << lcs3(s1, s2) << endl;
}

/**
 *  Code : Edit Distance
 *  -   Given two strings s and t of lengths m and n respectively, find 
 *      the edit distance between the strings.
 *  -   Edit Distance
 *      -   Edit Distance of two strings is minimum number of operations 
 *          required to make one string equal to other. In order to do so 
 *          you can perform any of the following three operations only :
 *          1. Delete a character
 *          2. Replace a character with another one
 *          3. Insert a character
 */
// Approach 1 - Brute Force - O(3^n)
int editDistance(string s1, string s2) {
    if(s1.length() == 0 || s2.length() == 0){
        return max(s1.length(), s2.length());
    } 

    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    } else{
        int ans1 = 1 + editDistance(s1.substr(1), s2);
        int ans2 = 1 + editDistance(s1, s2.substr(1));
        int ans3 = 1 + editDistance(s1.substr(1), s2.substr(1));
        return min(ans1, min(ans2, ans3));
    }
}
// Approach 2 - Memoization - Recusrion
int editDistanceRec(string s1, string s2, int** arr) {
    int n = s1.size();
    int m = s2.size();
    if(n == 0 || m == 0){
        return max(n, m);
    } 

    if(arr[n][m] != -1){
        return arr[n][m];
    }

    if(s1[0] == s2[0]){
        arr[n][m] = editDistanceRec(s1.substr(1), s2.substr(1), arr);
    } else{
        int ans1 = 1 + editDistanceRec(s1.substr(1), s2, arr);
        int ans2 = 1 + editDistanceRec(s1, s2.substr(1), arr);
        int ans3 = 1 + editDistanceRec(s1.substr(1), s2.substr(1), arr);
        arr[n][m] = min(ans1, min(ans2, ans3));
    }
    return arr[n][m];
}
int editDistance2(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
        for(int j=0; j<=m; j++){
            arr[i][j] = -1;
        }
    }
    return editDistanceRec(s1, s2, arr);
}
// Approach 3 - DP - O(n*m)
int editDistance3(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int** arr = new int*[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int[m+1];
    }
    for(int j=0; j<=m; j++){
        arr[0][j] = j;
    }
    for(int i=1; i<=n; i++){
        arr[i][0] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[n-i] == s2[m-j]){
                arr[i][j] = arr[i-1][j-1];
            } else {
                int ans1 = 1 + arr[i-1][j];
                int ans2 = 1 + arr[i][j-1];
                int ans3 = 1 + arr[i-1][j-1];
                arr[i][j] = min(ans1, min(ans2, ans3));
            }
        }
    }
    return arr[n][m];
}
void problem3(){
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    cout << editDistance(s1, s2) << endl;
    cout << editDistance2(s1, s2) << endl;
    cout << editDistance3(s1, s2) << endl;
}

/**
 *  Code : Knapsack
 *  -   A thief robbing a store can carry a maximal weight of W into 
 *      his knapsack. There are N items, and i-th item weigh 'Wi' and 
 *      the value being 'Vi.' What would be the maximum value V, that 
 *      the thief can steal?
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
void problem4(){
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
}

int main() {
    // Code : Min Cost Path
    // problem1();

    // Largest Common SubSequence
    // problem2();

    // Code : Edit Distance
    // problem3();

    // Code : knapsack
    problem4();

    return 0;
}