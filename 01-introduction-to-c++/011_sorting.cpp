#include<iostream>
#include<cmath>
using namespace std;

/**
 *  Selection Sort:
 *  1.  From all elements, go in loop and find the min.
 *  2.  Put a pointer at start , and swap the min element with start index.
 *  3.  increment the index . 
 *  4.  Repeat steps 1-3.
 */
void selectionSort(int* arr, int n){
    for(int start=0; start<n-1; start++){
        int min=arr[start], min_idx=start;
        for(int j=min_idx+1; j<n; j++){
            if(arr[j] < min){
                min = arr[j];
                min_idx = j;
            }
        }
        int temp = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
void problem1(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		selectionSort(input, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
}

/**
 *  Bubble Sort:
 *  1.  Compare adjacent elements and sort. This way, biggest element will be 
 *      placed at end position.
 *  2.  Now end will become end-1. Repeat step 1.
 *  3.  Do it till end become start.
 */
void bubbleSort(int *input, int size){
    for(int i=0; i<size-1; i++){
        for(int j=1; j<size-i; j++){
            if(input[j] < input[j-1]){
                int temp = input[j];
                input[j] = input[j-1];
                input[j-1] = temp;
            }
        }
    }
}
void problem2(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		bubbleSort(input, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
}

/**
 *  Insertion Sort:
 *  1.  Start from index 1, and compare the element with all previous elements which are 
 *      already sorted.
 *  2.  if element is smaller than previous elements , shift all the bigger elements.
 *  3.  Place the element att correct place.
 */
void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int element = arr[i];
        int j;
        for(j=i-1; j>=0 ; j--){
            if(element < arr[j]){
                arr[j+1] = arr[j];
            } else{
                break;
            }
        }
        arr[j+1] = element;
    }
}
void problem3(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; ++i){
			cin >> input[i];
		}
		insertionSort(input, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		delete[] input;
		cout << endl;
	}
}

/**
 *  Code Merge Two Sorted Arrays
 *  ->  You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, 
 *      merge them into a third array/list such that the third array is also sorted.
 */
void merge(int *arr1, int size1, int *arr2, int size2, int *ans){
    int i=0, j=0, k=0;
    while(i < size1 && j < size2){
        if(arr1[i] <=  arr2[j]){
            ans[k++] = arr1[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }
    while( i < size1){
        ans[k++] = arr1[i++];
    }
    while( j < size2){
        ans[k++] = arr2[j++];
    }    
}
void problem4(){
    int t;
	cin >> t;
	while (t--){
		int size1;
		cin >> size1;
		int *arr1 = new int[size1];
		for (int i = 0; i < size1; i++){
			cin >> arr1[i];
		}
		int size2;
		cin >> size2;
		int *arr2 = new int[size2];
		for (int i = 0; i < size2; i++){
			cin >> arr2[i];
		}
		int *ans = new int[size1 + size2];
		merge(arr1, size1, arr2, size2, ans);
		for (int i = 0; i < size1 + size2; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		delete[] arr1;
		delete[] arr2;
		delete[] ans;
	}
}

/**
 *  Push Zeros to end :
 *  ->  You have been given a random integer array/list(ARR) of size N. You have 
 *      been required to push all the zeros that are present in the array/list to 
 *      the end of it. Also, make sure to maintain the relative order of the non-zero 
 *      elements.
 */
void pushZeroesEnd(int *input, int size){
    int i=0,k=0;
    while(k<size){
       	if(input[i]!=0 && input[k]!=0){
        	i++;
           	k++;
       	}
        else if(input[i]==0 && input[k]==0){
        	k++;
    	}
        else if(input[i]==0 && input[k]!=0){
        	int temp=input[i];
        	input[i]=input[k];
        	input[k]=temp;
     	}
        else if(input[i]!=0 && input[k]==0){
         	i++;
            k++;
    	}     
	}
}
void assignment1(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		pushZeroesEnd(input, size);
		for (int i = 0; i < size; i++){
			cout << input[i] << " ";
        }
		cout << endl;
		delete[] input;
	}
}    

/**
 *  Rotate array :
 *  ->  You have been given a random integer array/list(ARR) of size N. Write a function 
 *      that rotates the given array/list by D elements(towards the left).
 */
void rotate(int *input, int d, int n){
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i] = input[i];
    }
    for(int i=0; i<n-d; i++){
        input[i] = input[i+d];
    }
    int j=0;
    for(int i=n-d; i<n; i++){
        input[i] = temp[j++];
    }
}
void assignment2(){
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
 *  Second Largest in array
 *  -   You have been given a random integer array/list(ARR) of size N. You 
 *      are required to find and return the second largest element present 
 *      in the array/list.
 *  -   If N <= 1 or all the elements are same in the array/list then return 
 *      -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)
 */
#include<climits>
int findSecondLargest(int *input, int n)
{
    int largest=INT_MIN, second=INT_MIN;
    for(int i=0; i<n; i++){
        if(input[i] > largest){
            second = largest;
            largest = input[i];
        } else if(input[i] > second && input[i] != largest){
            second = input[i];
        }
    }
    return second;
}
void assignment3(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			cin >> input[i];
		}
		cout << findSecondLargest(input, size) << endl;
		delete[] input;
	}
}

/**
 *  Check Array Rotation
 *  -   You have been given an integer array/list(ARR) of size N. It has been 
 *      sorted(in increasing order) and then rotated by some number 'K' in 
 *      the right hand direction.
 *  -   Your task is to write a function that returns the value of 'K', that 
 *      means, the index from which the array/list has been rotated.
 */
int arrayRotateCheck(int *input, int size){
    int i=0;
    for(; i<size-1; i++){
        if(input[i] > input[i+1]){
            return i+1;
        }
    }
    return 0;
}
void assignment4(){
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

/**
 *  Sort 0 1 2
 *  -   You are given an integer array/list(ARR) of size N. It contains only 0s, 
 *      1s and 2s. Write a solution to sort this array/list in a 'single scan'.
 *  -   'Single Scan' refers to iterating over the array/list just once or to put 
 *      it in other words, you will be visiting each element in the array/list just once.
 */
void sort012(int *arr, int n){
    int temp[n];
    int tempStart=0, tempEnd=n-1;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            temp[tempStart++] = arr[i];
        } else if(arr[i] == 2){
            temp[tempEnd--] = arr[i];
        }
    }
	while(tempStart <= tempEnd){
    	temp[tempStart++] = 1;
    }
    
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}
void assignment5(){
    int t;
	cin >> t;
	while (t--){
		int size;
		cin >> size;
		int *arr = new int[size];
		for (int i = 0; i < size; i++){
			cin >> arr[i];
		}
		sort012(arr, size);
		for (int i = 0; i < size; i++){
			cout << arr[i] << " ";
		}
		delete[] arr;
		cout << endl;
	}
}

/**
 *  Sum of Two Arrays
 *  ->  Two random integer arrays/lists have been given as ARR1 and ARR2 of size N 
 *      and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single 
 *      digit integer is present at every index). The idea here is to represent each 
 *      array/list as an integer in itself of digits N and M.
 *  ->  You need to find the sum of both the input arrays/list treating them as two integers 
 *      and put the result in another array/list i.e. output array/list will also contain 
 *      only single digit at every index.
 */
void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output){
    int i=size1-1, j=size2-1, carry=0;
    int size3 = (size1>size2) ? size1+1 : size2+1;
    int k = size3-1;
    for(; i>=0 && j>=0 ; i--, j--){
        int sum = input1[i] + input2[j] + carry;
        output[k--] = sum%10;
        carry = sum/10;
    }
    while(i>=0){
        int sum = input1[i] + carry;
        output[k--] = sum%10;
        carry = sum/10;
        i--;
    }
    while(j>=0){
        int sum = input2[j] + carry;
        output[k--] = sum%10;
        carry = sum/10;
        j--;
    }
    if(carry > 0){
        output[k] = carry;
    } else{
        output[k] = 0;
    }
}
void assignment6(){
    int t;
	cin >> t;
	while (t--){
		int size1;
		cin >> size1;
		int *input1 = new int[size1];
		for (int i = 0; i < size1; ++i){
			cin >> input1[i];
		}
		int size2;
		cin >> size2;
		int *input2 = new int[size2];
		for (int i = 0; i < size2; ++i){
			cin >> input2[i];
		}
		int outsize = 1 + max(size1, size2);
		int *output = new int[outsize];
		sumOfTwoArrays(input1, size1, input2, size2, output);
		for (int i = 0; i < outsize; ++i){
			cout << output[i] << " ";
		}
		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}
}

int main(){
    // Selection Sort
    // problem1();

    // Bubble Sort 
    // problem2();

    // Insertion Sort
    // problem3();

    // Merge Two Sorted Arrays
    // problem4();

    // Push Zeros to end
    // assignment1();

    // Rotate Array
    // assignment2();

    // Second Largest in Array
    // assignment3();

    //Check Array rotation
    // assignment4();

    // Sort 0 1 2
    // assignment5();

    // Sum of two arrays
    assignment6();

    return 0;
}