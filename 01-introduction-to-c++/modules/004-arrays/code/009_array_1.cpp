#include<iostream>
using namespace std;

/**
 *  Array Sum
 *  -   Given an array of length N, you need to find and print the sum of all 
 *      elements of the array.
 */
void problem1(){
    int N;
    cin >> N;
    
    int array[N];
    int i=0;
    while(i < N){
        int num;
        cin >> num;
        
        array[i] = num;
        i++;
    }
    
    int sum=0;
    for(int i=0; i<N; i++){
        sum += array[i];
    }
    cout << sum << endl;
}

/**
 *  Arrange Numbers in Array
 *  ->  You have been given an empty array(ARR) and its size N. The only input taken from the 
 *      user will be N and you need not worry about the array.
 *  ->  Your task is to populate the array using the integer values in the range 1 to N(both inclusive) 
 *      in the order - 1,3,.......4,2.
 */
void arrange(int *arr, int n)
{
    int start= 0, end = n-1;
    int number =1;
    for(; start <= end ; ){
        if(start == end){
            arr[start++] = number++;
        } else {
         	arr[start++] = number++;
        	arr[end--] = number++;   
        }
    }
}
void problem2(){
    int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int *arr = new int[n];
		arrange(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete [] arr;
	}
}

/**
 *  Swap Alternate
 *  ->  You have been given an array/list(ARR) of size N. You need to swap every pair of alternate 
 *      elements in the array/list. You don't need to print or return anything, just change in the 
 *      input array itself.
 */
void swapAlternate(int *arr, int size)
{
    for(int k=0 ; k<size-1 ;){
        int temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
        k= k+2;
    }
}
void problem3(){
    int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int *arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		swapAlternate(arr, size);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete [] arr;
    }
}

/**
 *  Find Unique
 *  -   You have been given an integer array/list(ARR) of size N. 
 *      Where N is equal to [2M + 1].
 *  -   Now, in the given array/list, 'M' numbers are present twice and 
 *      one number is present only once.
 *  -   You need to find and return that number which is unique in the array/list.  
 */
int findUnique(int *arr, int size)
{
    for(int i=0; i<size; i++){
        int j=0;
        for (; j < size; j++) {
            if(i==j){
                continue;
            }
            if(arr[i] == arr[j]){
                break;
            }
        }
        
        if(j >= size){
            return arr[i];
        }
    }
    return -1;
}
int findUniqueXOR(int *arr, int size){
    int res = 0;
    for(int i=0; i<size; i++){
        res = res^arr[i];
    }
    return res;
}
void assignment1(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		//cout << findUnique(input, size) << endl;
        cout << findUniqueXOR(input, size) << endl;
	}
}

/**
 *  Find Duplicate
 *  ->  You have been given an integer array/list(ARR) of size N which contains numbers from 
 *      0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list 
 *      constitutes values ranging from 0 to 3 and among these, there is a single integer value 
 *      that is present twice. You need to find and return that duplicate number present in the 
 *      array.
 */
int duplicateNumber(int *arr, int size)
{
    for(int i=0; i<size; i++){
        int j = i+1, count=1;
        for(; j<size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count == 2){
            return arr[i];
        }
    }
    return -1;
}
//Approach 2 - Using Sum - O(n)
int duplicateNumberEfficient(int *arr, int size){
    int actual_sum=0;
    for(int i=0; i<size; i++){
        actual_sum += arr[i];
    }
    int expected_sum=0;
    for(int i=0; i<=size-2; i++){
        expected_sum += i;
    }
    return actual_sum-expected_sum;
}
void assignment2(){
    int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << duplicateNumber(input, size) << endl;
	}
}

/**
 *  Array Intersection
 *  ->  You have been given two integer arrays/list(ARR1 and ARR2) of size M and N, respectively. 
 *      You need to print their intersection; An intersection for this problem can be defined 
 *      when both the arrays/lists contain a particular value or to put it in other words, when 
 *      there is a common value that exists in both the arrays/lists.
 */
void intersection(int *input1, int *input2, int size1, int size2)
{
    for(int i=0; i<size1; ++i){
        int j=0;
        for(; j<size2; ++j){
            if(input1[i] == input2[j]){
                cout << input1[i] << " ";
                input2[j] = INT_MIN;
                break;
            }
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
 *  Pair Sum
 *  ->  You have been given an integer array/list(ARR) and a number X. Find and return 
 *      the total number of pairs in the array/list which sum to X.
 */
int pairSum(int *input, int size, int x)
{
    int count = 0;
	for(int i=0; i<size; i++){
        int j = i+1;
        for(;j<size; ++j){
            if(input[i] + input[j] == x){
                count++;
            }
        }
    }
    return count;
}
//approach 2 - one pass
int pairSumEfficient(int *arr, int size, int x){
    sort(arr, arr+size);
    int l = 0, r = size-1, count =0;
    while(l<r){
        if(arr[l] + arr[r] == x){
            count++;
            l++;
            r--;
        } else if(arr[l] + arr[r] < x){
            l++;
        } else {
            r--;
        }
    }
    return count;
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
 *  Tripet Sum
 *  ->  You have been given a random integer array/list(ARR) and a number X. 
 *      Find and return the number of triplets in the array/list which sum to X.
 */
int tripletSum(int *input, int size, int x){
    int count=0;
	for(int i=0; i< size; ++i){
        int j=i+1;
        for(; j<size; ++j){
            int k = j+1;
            for(; k<size; ++k){
                if(input[i] + input[j] + input[k] == x){
                    count++;
                }
            }
        }
	}
    return count;
}
//Approach 2
int tripletSumEfficient(int *arr, int size, int x){
    int count=0;
    sort(arr, arr+size);
	for(int i=0; i< size; ++i){
        int l = i+1, r = size-1, count =0;
        while(l<r){
            if(arr[i] + arr[l] + arr[r] == x){
                count++;
                l++;
                r--;
            } else if(arr[i] + arr[l] + arr[r] < x){
                l++;
            } else {
                r--;
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
 *  Sort 0 & 1 in a one loop
 */
void sortZeroesAndOne(int *input, int size){
    int start=0, end=size-1;
    while(start < end){
        while(input[start] == 0){
            start++;
        }
        while(input[end] == 1){
            end--;
        }
        if(start<end){
         	int temp = input[start];
            input[start] = input[end];
            input[end] = temp;
            start++;
            end--;   
        }
    }
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
		sortZeroesAndOne(input, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		cout << endl;
		delete[] input;
	}
}

int main(){
    // Array Sum
    // problem1();

    // Arrange Numbers in Array
    // problem2();

    // Swap Alternate
    // problem3();

    // Find Unique
    //assignment1();

    // Find Duplicate
    // assignment2();

    // Array Intersection
    // assignment3();

    // Pair Sum
    // assignment4();

    // Triplet Sum
    // assignment5();

    // Sort 0 1
    assignment6();

}


