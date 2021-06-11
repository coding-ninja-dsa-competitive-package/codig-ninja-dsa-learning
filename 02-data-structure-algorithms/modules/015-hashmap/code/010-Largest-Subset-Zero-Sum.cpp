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
 *  Longest subset zero sum
 *  -   Given an array consisting of positive and negative integers, find 
 *      the length of the longest subarray whose sum is zero.
 *  
 *  Input Format:
 *      The first line of input contains an integer, that denotes the value of 
 *      the size of the array. Let us denote it with the symbol N.
 *      The following line contains N space separated integers, that denote the 
 *      value of the elements of the array.
 *  Output Format
 *      The first and only line of output contains length of the longest subarray 
 *      whose sum is zero.
 * 
 *  Constraints:
 *      0 <= N <= 10^8
 * 
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1:
 *      10 
 *      95 -97 -387 -435 -5 -70 897 127 23 284
 *  Sample Output 1:
 *      5
 *  Explanation:
 *      The five elements that form the longest subarray that sum up to zero 
 *      are: -387, -435, -5, -70, 897 
 */
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> mp;
    int sum=0;
    int maxLength = 0;
    for(int i=0; i<n; i++){
    	sum += arr[i];
        if(sum==0){
            maxLength = max(maxLength, i+1);
        } else if(mp.find(sum) != mp.end()){
            maxLength = max(maxLength, i-mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return maxLength;
}

int main (){
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << lengthOfLongestSubsetWithZeroSum(arr, size);
    delete[] arr;

    return 0;
}