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
 *  Running Median
 *  -   You are given a stream of N integers. For every i-th integer added 
 *      to the running list of integers, print the resulting median.
 *  -   Print only the integer part of the median.
 * 
 *  Input Format :
 *      The first line of input contains an integer 'N', denoting the number 
 *      of integers in the stream.
 *      The second line of input contains 'N' integers separated by a single space.
 *  Output Format :
 *      Print the running median for every integer added to the running list 
 *      in one line (space-separated).
 *  
 *  Input Constraints
 *      0 <= N <= 10 ^ 5
 *      1 <= ARR[i] <= 10 ^ 5
 * 
 *  Time Limit: 1 sec
 *      
 *  Sample Input 1 :
 *      6
 *      6 2 1 3 7 5
 *  Sample Output 1 :
 *      6 4 2 2 3 4 
 *  Explanation of Sample Output 1 :
 *      S = {6}, median = 6
 *      S = {6, 2} -> {2, 6}, median = 4
 *      S = {6, 2, 1} -> {1, 2, 6}, median = 2
 *      S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
 *      S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
 *      S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
 *  
 *  Sample Input 2 :
 *      5
 *      5 4 3 2 1
 *  Sample Output 2 :
 *      5 4 4 3 3
 */

void printRunningMedian(int *arr, int n) {
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int> > min_pq;
    for(int i=0; i<n; i++){
        if(min_pq.empty() && max_pq.empty()){
            max_pq.push(arr[i]);
        } else if(!max_pq.empty() && arr[i] < max_pq.top()){
            max_pq.push(arr[i]);
        } else{
            min_pq.push(arr[i]);
        }
        
        if(abs(max_pq.size() - min_pq.size() > 1)){
            if(max_pq.size() > min_pq.size()){
                min_pq.push(max_pq.top());
                max_pq.pop();
            } else {
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
        
        if(max_pq.size() > min_pq.size()){
            cout << max_pq.top() << " ";
        } else if(max_pq.size() < min_pq.size()){
            cout << min_pq.top() << " ";
        } else {
            int median = (max_pq.top() + min_pq.top())/2;
            cout << median << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    printRunningMedian(arr, n);
    delete[] arr;

    return 0;
}