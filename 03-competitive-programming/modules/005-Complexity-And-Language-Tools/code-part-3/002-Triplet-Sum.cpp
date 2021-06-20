#include<bits/stdc++.h>

using namespace std;

/**
 *  Triplet sum
 *  -   You have been given a random integer array/list(ARR) and a number X. 
 *      Find and return the triplet(s) in the array/list which sum to X.
 *  Note :
 *      Given array/list can contain duplicate elements.
 *  Input format :
 *      The first line contains an Integer 't' which denotes the number of 
 *      test cases or queries to be run. Then the test cases follow.
 *      First line of each test case or query contains an integer 'N' representing 
 *      the size of the first array/list.
 *      Second line contains 'N' single space separated integers representing 
 *      the elements in the array/list.
 *      Third line contains an integer 'X'.
 *  Output format :
 *      For each test case, print the total number of triplets present in the 
 *      array/list.
 *      Output for every test case will be printed in a separate line.
 *  
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= N <= 10^3
 *      0 <= X <= 10^9
 *  Time Limit: 1 sec
 *  
 *  Sample Input 1:
 *      1
 *      7
 *      1 2 3 4 5 6 7 
 *      12
 *  Sample Output 1:
 *      5
 *  
 *  Sample Input 2: 
 *      2
 *      7
 *      1 2 3 4 5 6 7 
 *      19
 *      9
 *      2 -5 8 -6 0 5 10 11 -3
 *      10
 *  Sample Output 2:
 *      0
 *      5
 *  Explanation for Input 2:
 *      Since there doesn't exist any triplet with sum equal to 19 for the 
 *      first query, we print 0.
 *      For the second query, we have 5 triplets in total that sum up to 10. 
 *      They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
 */

int tripletSum(int *arr, int n, int num){
    int count = 0;
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        int sum = num - arr[i];
        int l = i+1, r = n-1;
        while (l < r) {
            if (arr[l] + arr[r] < sum)
                l++;
            else if (arr[l] + arr[r] > sum)
                r--;
            else {
                int x = arr[l], temp_l = l;
                while (l < r && arr[l] == x){
                    l++;
                }
                int y = arr[r], temp_r = r;
                while (r >= l && arr[r] == y){
                    r--;
                }
                if (x == y) {
                    int n = l - temp_l + temp_r - r - 1;
                    count += (n * (n + 1)) / 2;
                }
                else{
                    count += (l - temp_l) * (temp_r - r);
                }
            }
        }
    }
    return count;
}

int main() {
    int t;
	cin >> t;
	while (t--){
		int size;
		int x;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		cin >> x;
		cout << tripletSum(input, size, x) << endl;
		delete[] input;
	}

    return 0;
}