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
 *  Code : K largest elements
 *  -   You are given with an integer k and an array of integers that 
 *      contain numbers in random order. Write a program to find k largest 
 *      numbers from given array. You need to save them in an array and return it.
 *  -   Time complexity should be O(nlogk) and space complexity should 
 *      be not more than O(k).
 *  
 *  Input Format :
 *      Line 1 : Size of array (n)
 *      Line 2 : Array elements (separated by space)
 *      Line 3 : Integer k
 *  Output Format :
 *      k largest elements
 *  
 *  Sample Input :
 *      13
 *      2 12 9 16 10 5 3 20 25 11 1 8 6 
 *      4
 *  Sample Output :
 *      12
 *      16
 *      20
 *      25
 */
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> res;
    for(int i=0; i<k ; i++){
        pq.push(input[i]);
    }
    for(int i=k; i<n; i++){
        int min = pq.top();
        if(input[i] > min){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main(){
    int size;
	cin >> size;
	int *input = new int[1 + size];
	for(int i = 0; i < size; i++)
		cin >> input[i];
    int k;
    cin >> k;
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }

    return 0;
}