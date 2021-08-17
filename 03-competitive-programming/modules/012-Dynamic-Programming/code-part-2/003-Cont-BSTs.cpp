#include<bits/stdc++.h>

using namespace std;

/**
 *  Count BSTs
 *  -   Given an integer N, find and return the count of unique Binary search 
 *      trees (BSTs) are possible with nodes valued from 1 to N.    
 *  -   Output count can be very large, so return the count modulo 10^9+7.
 *  
 *  Input Format :
 *      Integer n 
 *  Output Format : 
 *      Count of BSTs
 *  
 *  Contraints :
 *      1<= N <=1000
 *  
 *  Sample Input 1:
 *      8
 *  Sample Output 1:
 *      1430
 *  
 *  Sample Input 2:
 *      3
 *  Sample Output 2:
 *      5
 */
#define MOD 1000000007

int countBST(int n, int* arr){
    if(arr[n] != -1){
        return arr[n];
    }
    long long count=0;
	for(int i=1; i<=n; i++){
		long long left=countBST(i-1, arr)%MOD;
		arr[i-1]=left;
		long long right=countBST(n-i, arr)%MOD;
		arr[n-i]=right;
		count += (left*right)%MOD;
	}
	arr[n]=count%MOD;
    return arr[n];
}

int countBST(int n){
  	int* out = new int[n+1];
    out[0] = out[1] = 1;
    for(int i=2; i<=n; i++){
        out[i] = -1;
    }
    return countBST(n, out);
}

int main() {
    int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}