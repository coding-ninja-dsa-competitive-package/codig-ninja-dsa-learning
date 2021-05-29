#include<iostream>
using namespace std;

/**
 *  Works on thre principle of mathematical induction.
 *  1.  Prove that F(0) , F(1) true.
 *  2.  Assume that F(K)  is true.
 *  3.  Prove that F(K+1) is true.
 * 
 *  For Recusrsion problems:
 *  1.  Write base case.
 *  2.  Assume it will work for smaller problem.
 *  3.  Solve big problem using the smaller problem output.
 */
int factorial(int n){
    if(n == 0){
        return 1;
    }
    int smallerOutput = factorial(n-1);
    return n*smallerOutput;
}

void problem1(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout<<"========================"<<endl;
}

/**
 *  Write a program to find x to the power n (i.e. x^n). Take x and n from the user. 
 *  You need to return the answer. Do this recursively.
 */
int power(int x, int n) {
    if(n==0){
        return 1;
    }
    return x*power(x, n-1);
}

void problem2(){
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    cout<<"========================"<<endl;
}

/**
 *  Given is the code to print numbers from 1 to n in increasing order recursively
 */
void print(int n){
    if(n == 1){
        cout << n << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
}

void problem3(){
    int n;
    cin >> n;
    print(n);
    cout<<endl << "========================"<<endl;
}

/**
 *  Given the code to find out and return the number of digits present in a number recursively
 */
int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}

void problem4(){
    int n;
    cin >> n;
    cout << count(n) << endl;
    cout<<"========================"<<endl;
}

/**
 *  Nth Fibinacci Number
 */
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smallerOutput1 = fib(n-1);
    int smallerOutput2 = fib(n-2);
    return smallerOutput1 + smallerOutput2;
}

void problem5(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    cout<<"========================"<<endl;
}

/**
 *  Check if array is sorted or not
 */
bool isArraySorted(int arr[], int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    return isArraySorted(arr+1, size-1);
}

void problem6(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << isArraySorted(arr, n) << endl;
    cout<<"========================"<<endl;
}

/**
 *  Given an array of length N, you need to find and return the sum of all elements of the array.
 */
int sum(int input[], int n) {
    if(n == 0){
        return 0;
    }
    int smallerOutput = sum(input+1, n-1);
    return input[0] + smallerOutput;
}

void problem7(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << sum(input, n) << endl;
}

/**
 *  Given an array of length N and an integer x, you need to find if x is present in the array or not. 
 *  Return true or false.
 */
bool checkNumber(int input[], int size, int x) {
    if(size==0){
        return false;
    }
    if(input[0] == x){
        return true;
    }
    return checkNumber(input+1, size-1, x);
}

void problem8(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }    
    int x;
    cin >> x;
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/**
 *  Given an array of length N and an integer x, you need to find and return the 
 *  first index of integer x present in the array. Return -1 if it is not present in the array.
 *  First index means, the index of first occurrence of x in the input array.
 *  Do this recursively. Indexing in the array starts from 0.
 */
int firstIndex(int input[], int size, int x) {
	if(size == 0){
        return -1;
    }
    if(input[0] == x){
        return 0;
    }
    int ans = firstIndex(input+1, size-1, x);
    if(ans == -1){
        return -1;
    }
    return ans+1;
}

void problem9(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    cout << firstIndex(input, n, x) << endl;

}

/**
 *  Given an array of length N and an integer x, you need to find and return the last index of 
 *  integer x present in the array. Return -1 if it is not present in the array.
 *  Last index means - if x is present multiple times in the array, return the index at which 
 *  x comes last in the array. You should start traversing your array from 0, not from (N - 1).
 *  Do this recursively. Indexing in the array starts from 0. 
 */
int lastIndex(int input[], int size, int x) {
    if(size == 0){
        return -1;
    }
    int ans = lastIndex(input+1, size-1, x);
    if(input[0] == x && ans == -1){
        return 0;
    }
    if(ans == -1){
        return -1;
    }
    return ans+1;
}
void problem10(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    cout << lastIndex(input, n, x) << endl;

}

/**
 *  Given an array of length N and an integer x, you need to find all the indexes where x is 
 *  present in the input array. Save all the indexes in an array (in increasing order).
 *  Do this recursively. Indexing in the array starts from 0.
 */
int allIndexes1(int input[], int size, int x, int output[]) {
    if(size == 0){
        return 0;
    }
    int ans = allIndexes1(input+1, size-1, x, output);
    for(int i=0; i<ans; i++){
        output[i]++;
    }
    if(input[0] == x){
        for(int j=ans; j>0; j--){
            output[j] = output[j-1];
        }
        output[0] = 0;
        return ans+1;
    }
    return ans;
}
int allIndexes2(int input[], int size, int x, int output[]) {
    if(size == 0){
        return 0;
    }
    int ans = allIndexes2(input, size-1, x, output);
    if(input[size-1] == x){
        output[ans] = size-1;
        return ans+1;
    }
    return ans;
}
void problem11(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int x;
    cin >> x;
    int *output = new int[n];
    int size = allIndexes1(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    delete [] input;
    delete [] output;
}

int main(){
    //Factorial of n
    //problem1();
    
    //Exponential Power
    //problem2();

    //print 1 to n
    //problem3();

    //count number of digits in a number
    //problem4();

    //nth fibonacci number
    //problem5();

    //check if array is sorted
    //problem6();

    //sum of array
    //problem7();

    //check if number is present in array
    //problem8();

    //return first index for an element in array
    //problem9();

    //return last index for an element in array
    //problem10();

    //return all indices of a number in array and return size of output array
    problem11();
    
    return 0;  
}