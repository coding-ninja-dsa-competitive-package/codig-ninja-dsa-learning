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
 *  Extract Unique characters
 *  -   Given a string S, you need to remove all the duplicates. That means, 
 *      the output string should contain each character only once. The respective 
 *      order of characters should remain same, as in the input string.
 */
string uniqueChar(string str) {
    unordered_map<char, bool> mp;
    string res="";
    for(int i=0; i<str.length(); i++){
        if(mp.find(str[i]) == mp.end()){
            mp[str[i]]=true;
            res += str[i];
        }
    }
    return res;
}
//approach 2
#include<unordered_set>
string uniqueCharSet(string str) {
    unordered_set<char> set;
    string res="";
    for(int i=0; i<str.length(); i++){
        if(set.find(str[i]) == set.end()){
            set.insert(str[i]);
            res.push_back(str[i]);
        }
    }
    return res;
}
void assignment1(){
    string str;
    cin >> str;
    cout << uniqueChar(str);
}

/**
 *  Longest Consecutive Sequence
 *  -   You are given an array of unique integers that contain numbers in 
 *      random order. You have to find the longest possible sequence of 
 *      consecutive numbers using the numbers from given array.
 *  -   You need to return the output array which contains starting and ending 
 *      element. If the length of the longest possible sequence is one, then 
 *      the output array must contain only single element.
 *  NOte:
 *  1. Best solution takes O(n) time.
 *  2. If two sequences are of equal length, then return the sequence starting 
 *     with the number whose occurrence is earlier in the array.
 */
void print(unordered_map<int, bool> mp){
    unordered_map<int, bool>::iterator it=mp.begin();
    cout << "[";
    for(; it!= mp.end();){
        cout << it->first << "-" << it->second;
        if(++it != mp.end()){
            cout << ", ";
        }
    }
    cout <<"]"<<endl;
}
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]=i;
    }
    vector<int> res;
    int maxLength=0;
    int startElement=0;
    int startIndex=n;
    for(int i=0; i<n; i++){
        int num = arr[i];
        int count;
        if(mp[num] != -1){
            count=0;
            int index = mp[num];
            while(mp.find(num) != mp.end() && mp[num] != -1){
                count++;
                mp[num] = -1;
                num++;
            }
            num = arr[i]-1;
            while(mp.find(num) != mp.end() && mp[num] != -1){
                count++;
                index = mp[num];
                mp[num] = -1;
                num--;
            }
            if(count > maxLength || (count==maxLength && index < startIndex)){
                //print(mp);
				maxLength = count;
                startElement = num+1;
                startIndex = index;
            }
            
        }
    }
    for(int i=startElement; i<startElement+maxLength; i++){
        res.push_back(i);
    }
    return res;
}
void assignment2(){
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);
    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }
    delete[] arr;
}

/**
 *  Pairs with difference K
 *  -   You are given with an array of integers and an integer K. You have 
 *      to find and print the count of all such pairs which have difference K.
 *  Note: Take absolute difference between the elements of the array.
 */
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int, int> mp;
    int count=0;
    for(int i=0; i<n; i++){
        int key = arr[i];
        int count2 = mp[key+k];
        count += count2;
        if (k != 0){
        	int count3 = mp[key-k]; 
            count += count3;
        }
        mp[key]++;
    }
    return count;
}
void assignment3(){
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int k;
    cin >> k;
    cout << getPairsWithDifferenceK(input, n, k);
    delete[] input;
}

/**
 *  Longest subset zero sum
 *  -   Given an array consisting of positive and negative integers, find 
 *      the length of the longest subarray whose sum is zero.
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
void assignment4(){
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << lengthOfLongestSubsetWithZeroSum(arr, size);
    delete[] arr;
}

int main() {
    // remove duplicates chars from string
    // assignment1();

    // Longest Consecutive Sequence
    // assignment2();

    // Pairs with difference K
    assignment3();

    // Longest subset zero sum
    // assignment4();

    return 0;
}