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
 *  Maximum Square Matrix With All Zeros
 *  -   Given an NxM matrix that contains only 0s and 1s, find out the size 
 *      of the maximum square sub-matrix with all 0s. You need to return the 
 *      size of the square matrix with all 0s.
 * 
 *  Input format :
 *      The first line of the test case contains two integer values, 'N' 
 *      and 'M', separated by a single space. They represent the 'rows' and 
 *      'columns' respectively.
 *      Second-line onwards, the next 'N' lines or rows represent the ith row values.
 *      Each of the ith rows constitutes column values separated by a single 
 *      space (Either 0 or 1).
 *  Output Format:
 *      Print the size of maximum square sub-matrix.
 *      
 *  Constraints :
 *      0 <= N <= 10^4
 *      0 <= M <= 10^4
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      3 3
 *      1 1 0
 *      1 1 1
 *      1 1 1
 *  Sample Output 1:
 *      1
 * 
 *  Sample Input 2:
 *      4 4
 *      0 0 0 0
 *      0 0 0 0
 *      0 0 0 0
 *      0 0 0 0
 *  Sample Output 2:
 *      4
 */
int findMaxSquareWithAllZeros(int **arr, int n, int m){
    int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if((i==0 || j==0) && arr[i][j] == 0){
                dp[i][j] = 1;
            } else if(i==0 || j==0) {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
    	for(int j=1; j<n; j++){
            if(arr[i][j] == 0){
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            } else {
                dp[i][j] = 0;
            }
        }  
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
	return ans;
}

int main(){
    int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	for (i = 0; i < n; i++){
		arr[i] = new int[m];
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
	delete[] arr;

    return 0;
}