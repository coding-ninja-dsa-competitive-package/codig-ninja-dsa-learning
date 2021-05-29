#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

/**
 *  Map:
 *  -   We can store Key - Value pair in it.
 *  -   We can implement it using :
 *      1.  BST :
 *           map - implemented using BST - O(logn)
 *      2.  Hashtable:
 *           unordered_map - implemented using hashtable - O(1) 
 */
void problem1(){
    unordered_map<string, int> mp;
    //insert
    pair<string, int> p("abc", 1);
    mp.insert(p);
    mp["def"] = 2;

    // Find
    cout << mp["def"] << endl;
    cout << mp.at("abc") << endl;
    // cout << mp.at("ghi") << endl; // if not found, throw exception - key not found
    // cout << mp["ghi"] << endl;      // if not found, insert in map - with value 0
    if(mp.count("ghi")){ //check presence
        cout << "ghi is present." << endl;
    }

    // Size
    cout << mp.size() << endl;

    // Erase element
    mp.erase("ghi");
}

/**
 *  Remove Duplicates
 */ 
vector<int> removeDuplicates(int *arr, int n){
    vector<int> res;
    unordered_map<int, bool> mp;
    for(int i=0; i<n; i++){
        if(mp.count(arr[i]) > 0){
            continue;
        }
        mp[arr[i]] = true;
        res.push_back(arr[i]);
    }
    return res;
}
void problem2(){
    int n;
    cin >> n;
    int *arr  = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> res = removeDuplicates(arr, n);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

/**
 *  Code : Maximum Frequency Number
 *  -   You are given an array of integers that contain numbers in random 
 *      order. Write a program to find and return the number which occurs 
 *      the maximum times in the given input.
 *  -   If two or more elements contend for the maximum frequency, return 
 *      the element which occurs in the array first.
 */
int highestFrequency(int arr[], int n) {
	unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    int freq=0, res=0;
    for(int i=0; i<n; i++){
        if(mp[arr[i]]>freq){
            freq = mp[arr[i]];
            res = arr[i];
        }
    }
    return res;
}
void problem3(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << highestFrequency(arr, n);
    delete[] arr;
}

/**
 *  Code : Print Intersection
 *  -   You have been given two integer arrays/lists (ARR1 and ARR2) of size 
 *      N and M, respectively. You need to print their intersection; An intersection 
 *      for this problem can be defined when both the arrays/lists contain a 
 *      particular value or to put it in other words, when there is a common value 
 *      that exists in both the arrays/lists.
 *  Note:
 *  -   Input arrays/lists can contain duplicate elements.
 *  -   The intersection elements printed would be in the order they appear in the 
 *      first sorted array/list (ARR1).
 */
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        if(mp.count(arr2[i]) > 0 && mp[arr2[i]] > 0){
            cout << arr2[i] << endl;
            mp[arr2[i]]--;
        }
    }
}
void problem4(){
    int n;
    cin >> n;
    int* arr1 = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int* arr2 = new int[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    printIntersection(arr1, arr2, n, m);
    delete[] arr1;
    delete[] arr2;
}

/**
 *  Code : Pair Sum to 0
 *  -   Given a random integer array A of size N. Find and print the count of 
 *      pair of elements in the array which sum up to 0.
 *  Note: Array A can contain duplicate elements as well.
 */
int pairSum(int *arr, int n) {
	unordered_map<int,int> mp;
    int count = 0;
    for(int i=0; i<n; i++){
        int rem = 0 - arr[i];
        if(mp.count(rem) > 0){
            count += mp[rem];
        }
        mp[arr[i]]++;
    }
    return count;
}
void problem5(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << pairSum(arr, n);
    delete[] arr;
}

int main() {
    // Basic map operation present in c++ library
    // problem1();
    
    // Remove Duplicates from array
    // problem2();

    // Code : Maximum Frequency Number
    // problem3();

    // Print Intersection
    // problem4();

    // pair sum to zero
    problem5();

    return 0;
}