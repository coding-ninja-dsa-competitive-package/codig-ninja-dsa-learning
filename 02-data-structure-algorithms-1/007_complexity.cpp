#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

/**
 *  What will be the Time Complexity of following code in terms of ‘n’ ?
 *  Time - O(n)
 *  Space - O(1)
 */
void problem1(){
    int n, k;
    //Time - O(n)
    //Space - O(1)
    for(int i = 0; i < n; i++){
        for(; i < n; i++){
            cout << i << endl;
        }
    }     
    //Time - O(n*k) => O(n) as K is constant
    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < k; j++){
            cout << (i + j ) << endl;
        }
    }
    //Recurrence for merge sort
    //  T(n) = 2T(n/2) + O(n) => O(nlogn)
    //  S(n) = O(n) (n elements array is required at max while merge)
}

//Time - O(n)
int multiplyRec(int m, int n){
    if(n == 1)
        return m;
    return m + multiplyRec(m,  n - 1);  
}

//Time - O(logn) => log is to base 10
int sumOfDigits(int n){
    int sum;
    if(n < 10){
        return n;
    }
    sum = (n % 10) + sumOfDigits(n / 10);
    return sum;
}

//Time - O(2^n)
//Space - O(n)
long fib(int n){
    if(n == 0 || n == 1){
         return n;
    }
    return fib(n - 1) + fib(n - 2);
}

/**
 *  Find the Unique Element:
 *  You have been given an integer array/list(ARR) of size N. Where N is
 *  equal to [2M + 1]. Now, in the given array/list, 'M' numbers are present 
 *  twice and one number is present only once. You need to find and return that 
 *  number which is unique in the array/list.
 *  -   Unique element is always present in the array/list according to the 
 *      given condition.
 */
int findUnique(int *arr, int n) {
    int num=0;
    for(int i=0; i<n; i++){
        num ^= arr[i];
    }
    return num;
}
void assignment1(){
    int t;
    cin >> t;
    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }
        cout << findUnique(input, size) << endl;
    }
}

/**
 *  Duplicate in array
 *  -   You have been given an integer array/list(ARR) of size N which 
 *      contains numbers from 0 to (N - 2). Each number is present at least 
 *      once. That is, if N = 5, the array/list constitutes values ranging 
 *      from 0 to 3, and among these, there is a single integer value that 
 *      is present twice. You need to find and return that duplicate number 
 *      present in the array.
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
void assignment2(){
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

/**
 *  Array Intersection
 *  -   You have been given two integer arrays/list(ARR1 and ARR2) of 
 *      size N and M, respectively. You need to print their intersection; 
 *      An intersection for this problem can be defined when both the 
 *      arrays/lists contain a particular value or to put it in other words, 
 *      when there is a common value that exists in both the arrays/lists.
 *  -   Input arrays/lists can contain duplicate elements.
 *  -   The intersection elements printed would be in the order they appear 
 *      in the first sorted array/list(ARR1).
 */
void intersection(int *arr1, int *arr2, int n, int m) {
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++; j++;
        } else if(arr1[i] > arr2[j]){
            j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        }
    }
}
void assignment3(){
    int t;
	cin >> t;
	while (t--){
		int size1, size2;
		cin >> size1;
		int *input1 = new int[size1];
		for (int i = 0; i < size1; i++){
			cin >> input1[i];
		}
		cin >> size2;
		int *input2 = new int[size2];
		for (int i = 0; i < size2; i++){
			cin >> input2[i];
		}
		intersection(input1, input2, size1, size2);
		delete[] input1;
		delete[] input2;
		cout << endl;
	}
}

/**
 *  Pair sum in array:
 *  -   You have been given an integer array/list(ARR) and a number 
 *      'num'. Find and return the total number of pairs in the 
 *      array/list which sum to 'num'.
 *  -   Given array/list can contain duplicate elements. 
 */
int pairSum(int *arr, int n, int num){
    int pairCount=0;
	for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] == num-arr[i]){
                pairCount++;
            }
        }
    }	
    return pairCount;
}
void assignment4(){
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
		cout << pairSum(input, size, x) << endl;
		delete[] input;
	}
}

/**
 *  Triplet sum
 *  -   You have been given a random integer array/list(ARR) and 
 *      a number X. Find and return the triplet(s) in the array/list 
 *      which sum to X.
 *  -   Given array/list can contain duplicate elements.
 */

// Brute Force approach
/*
int tripletSum(int *arr, int n, int num)
{
	int count =0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n ; k++){
                if(arr[i] + arr[j] + arr[k] == num){
                    count++;
                }
            }
        }
    }
    return count;
}
*/
int tripletSum(int *arr, int n, int num){
	int count=0;
	sort(arr, arr+n);  
    for(int i=0; i<n-1; i++){
        int start = i+1, end = n-1;
        while(start<end){
            if(arr[start]+arr[end] == num-arr[i]){
               int index = end;
                while(arr[index] == arr[end] && index > start){
                    count ++;
                    index--;
                }
                start++;
            } else if(arr[start]+arr[end] > num-arr[i]){
            	end--;
            } else {
                start++;
            }
        }
    }
    return count;
}
void assignment5(){
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
}

/**
 *  Rotate array
 *  -   You have been given a random integer array/list(ARR) of size N. 
 *      Write a function that rotates the given array/list by D elements
 *      (towards the left).
 */
//Approach 1 - Rotate One by One
// Time - O(n*d) , Space - O(1)
/*
void rotateByOne(int *input, int n){
    int temp=input[0], i;
    for(i=0; i<n-1; i++){
        input[i] = input[i+1];
    }
    input[i] = temp;
}

void rotate(int *input, int d, int n){
    for(int i=0; i<d; i++){
        rotateByOne(input, n);
    }
} 
*/

//Approach 2 - Reversal approach
// Time - O(n) , Space - O(1)
void reverse(int *arr,int n){
    int start=0, end=n-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int *input, int d, int n){
    if (n==0 || n==1){
        return;
    }
    d %= n;
    reverse(input, d);
    reverse(input+d, n-d);
    reverse(input, n);
}
void assignment6(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){	
			cin >> input[i];
		}
		int d;
		cin >> d;
		rotate(input, d, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}	
		delete[] input;
		cout << endl;
	}
}

/**
 *  Check Array Rotation
 *  -   You have been given an integer array/list(ARR) of size N. It 
 *      has been sorted(in increasing order) and then rotated by some 
 *      number 'K' in the clockwise direction.
 *  -   Your task is to write a function that returns the value of 'K', 
 *      that means, the index from which the array/list has been rotated.
 */
int rotateCheck(int *arr, int low, int high){
    if (high < low)
        return 0;
 
    if (high == low)
        return low;
 
    int mid = (high + low)/2;
    if (mid < high && arr[mid+1] < arr[mid]){
       return (mid+1);
    }
    if (mid > low && arr[mid] < arr[mid - 1]){
       return mid;
    }
    if (arr[high] > arr[mid]){
       return rotateCheck(arr, low, mid-1);
    }
    return rotateCheck(arr, mid+1, high);
}
int arrayRotateCheck(int *input, int size){
	rotateCheck(input, 0, size-1);
}
void assignment7(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
}

int main() {
    problem1();
    //Find the Unique Element:
    //assignment1();

    //Duplicate in array
    //assignment2();

    //Array Intersection
    //assignment3();

    //Pair sum in array
    //assignment4();

    //Triplet sum
    //assignment5();

    //Rotate array
    //assignment6();

    //Check Array Rotation
    //assignment7();

    return 0;
}