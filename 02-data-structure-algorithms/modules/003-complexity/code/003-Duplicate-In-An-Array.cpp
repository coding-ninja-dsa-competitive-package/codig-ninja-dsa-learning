#include<iostream>

using namespace std;

/**
 *  Duplicate in array
 *  -   You have been given an integer array/list(ARR) of size N which 
 *      contains numbers from 0 to (N - 2). Each number is present at least 
 *      once. That is, if N = 5, the array/list constitutes values ranging 
 *      from 0 to 3, and among these, there is a single integer value that 
 *      is present twice. You need to find and return that duplicate number 
 *      present in the array.
 *  Note :  Duplicate number is always present in the given array/list.
 * 
 *  Input format :  
 *      The first line contains an Integer 't' which denotes the number of test 
 *      cases or queries to be run. Then the test cases follow.
 *      First line of each test case or query contains an integer 'N' representing 
 *      the size of the array/list.
 *      Second line contains 'N' single space separated integers representing the 
 *      elements in the array/list.
 *  Output Format :
 *      For each test case, print the duplicate element in the array/list.
 *      Output for every test case will be printed in a separate line.
 * 
 *  Constraints :
 *      1 <= t <= 10^2
 *      0 <= N <= 10^6
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      1
 *      9
 *      0 7 2 5 4 7 1 3 6
 *  Sample Output 1:
 *      7
 * 
 *  Sample Input 2:
 *      2
 *      5
 *      0 2 1 3 1
 *      7
 *      0 3 1 5 4 3 2
 *  Sample Output 2:
 *      1
 *      3
 */
int findDuplicate(int *arr, int n){
    int min=INT_MAX, max=INT_MIN, actual_sum=0;
    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }else if(arr[i] > max){
            max = arr[i];
        }
        actual_sum += arr[i];
    }
    int expected_sum=0;
    for(int i=min; i<=max; i++){
        expected_sum += i;
    }
    return (actual_sum-expected_sum);
    
}

int main(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}
}