#include<bits/stdc++.h>

using namespace std;

/**
 *  Minimum Count
 *  -   Given an integer N, find and return the count of minimum numbers required to 
 *      represent N as a sum of squares.
 *  -   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and 
 *      {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
 * 
 *  Input format :
 *      The first and the only line of input contains an integer value, 'N'.
 *  Output format :
 *      Print the minimum count of numbers required.
 * 
 *  Constraints :
 *      0 <= n <= 10 ^ 4
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      12
 *  Sample Output 1 :
 *      3
 *  Explanation of Sample Output 1 :
 *      12 can be represented as : 
 *      A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)
 *      B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)
 *      C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)
 *      D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)
 *  As we can see, the output should be 3.
 *  
 *  Sample Input 2 :
 *      9
 *  Sample Output 2 :
 *      1
 */
bool isPerfectSquare(int n){
    for(int i=1; i<=32; i++){
        if(n == i*i){
            return true;
        }
    }
    return false;
}

int minCount(int n, int* arr){
    if(isPerfectSquare(n)){
        return 1;
    }
    if(n <= 3){
        return n;
    }
    
    int count = n;
    if(arr[n] > 0){
        return arr[n];
    }
    for(int i=1; i<=n; i++){
        int temp = i*i;
        if(temp > n){
            break;
        } else {
            count = min(count, 1+minCount(n-temp, arr));
        }
    }
    arr[n] = count;
    return count;
}

int minCount(int n){
	int* out = new int[1001]();
	return minCount(n, out);
}

int main() {
    int n;
	cin >> n;
	cout << minCount(n);

    return 0;
}