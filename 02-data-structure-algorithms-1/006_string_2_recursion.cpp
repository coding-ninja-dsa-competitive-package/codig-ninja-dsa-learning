#include<iostream>
#include<cstring>
using namespace std;

/**
 *  Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive 
 *  function that checks if the string was generated using the following rules:
 *  a. The string begins with an 'a'
 *  b. Each 'a' is followed by nothing or an 'a' or "bb"
 *  c. Each "bb" is followed by nothing or an 'a'
 *  If all the rules are followed by the given string, return true otherwise return false.
 */
bool check_ab(char input[], int startIndex) {
    if(input[startIndex] == '\0'){
        return true;
    }
    if(input[startIndex] != 'a'){
        return false;
    }
    if(input[startIndex + 1] != '\0' && input[startIndex + 2] != '\0'){
        if( input[startIndex + 1] == 'b' && input[startIndex + 2] == 'b'){
            return check_ab(input, startIndex + 3);
        }
    }
    return check_ab(input, startIndex + 1);
}
bool checkAB(char input[]){
    bool ans;
    ans = check_ab(input, 0);
    return ans;
}
void assignment1() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}

/**
 *  A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 
 *  steps at a time. Implement a method to count how many possible ways the child can run up 
 *  to the stairs. You need to return number of possible ways W.
 */
int staircase(int n){
    if(n ==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int step1 = staircase(n-1);
    int step2 = staircase(n-2);
    int step3 = staircase(n-3);
    return step1+step2+step3;
}
void assignment2() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

/**
 *  Binary Search 
 */
int binary(int input[], int start, int end, int element){
    if(start > end){
        return -1;
    }
    int mid = (start+end)/2;
    if(input[mid] == element){
        return mid;
    } else if(input[mid] < element){
        return binary(input, mid+1, end,  element);
    } else{
        return binary(input, start, mid-1,  element);
    }
}
int binarySearch(int input[], int size, int element) {
    return binary(input, 0, size-1, element);
}
void assignment3() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++){ 
        cin >> input[i];;
    }
    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

/**
 *  Given an integer array (of length n), find and return all the subsets of input array.
 *  Subsets are of length varying from 0 to n, that contain elements of the array. But the order of 
 *  elements should remain same as in the input array.
 *  Note : The order of subsets are not important.
 *      Input format :
 *      Line 1 : Size of array
 *      Line 2 : Array elements (separated by space)
 */
int subset(int input[], int n, int output[][20]) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    int s=subset(input+1,n-1,output);
    for(int i=0;i<s;i++){
        output[i+s][0]=output[i][0]+1;
        output[i+s][1]=input[0];
        for(int j=1;j<=output[i][0];j++){
            output[i+s][j+1]=output[i][j];
        }

    }
    return 2*s;
}
void assignment4() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 *  Given an integer array (of length n), find and print all the subsets of input array.
 *  Subsets are of length varying from 0 to n, that contain elements of the array. But the order 
 *  of elements should remain same as in the input array.
 *  Note : The order of subsets are not important. Just print the subsets in different lines.
 *  Input format :
 *      Line 1 : Integer n, Size of array
 *      Line 2 : Array elements (separated by space)
 */
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void subsetsOfArray(int input[], int n, int output[] , int m){
    if(n==0){
        printArray(output, m);
        return;
    }
    subsetsOfArray(input+1, n-1, output, m);
    int i;
    int out[m+1];
    for(i=0; i<m; i++){
        out[i] = output[i];
    }
    out[i] = input[0]; 
    subsetsOfArray(input+1, n-1, out, m+1);
}
void printSubsetsOfArray(int input[], int size) {
    int output[35000];
    subsetsOfArray(input, size, output, 0);
}
void assignment5() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

/**
 *  Given an array A of size n and an integer K, return all subsets of A which sum to K.
 *  Subsets are of length varying from 0 to n, that contain elements of the array. But the order of 
 *  elements should remain same as in the input array.
 *  Note : The order of subsets are not important.
 *  Input format :
 *      Line 1 : Integer n, Size of input array
 *      Line 2 : Array elements separated by space
 *      Line 3 : K 
 */
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        if(k==0) {
            output[0][0] = 0;
            return 1;
        } else{
            return 0;
        }
    }
    int out1[10000][50] , out2[10000][50];
    int ans1 = subsetSumToK(input+1, n-1, out1, k);
    int ans2 = subsetSumToK(input+1, n-1, out2, k-input[0]);
    int i=0;
    for(int j=0; j<ans1; j++){
        for(int k=0; k<=out1[j][0]; k++){
            output[i][k] = out1[j][k];
        }
        i++;
    }
    for(int j=0; j<ans2; j++){
        output[i][0]=out2[j][0]+1;
        for(int k=output[i][0]; k>1; k--){
            output[i][k] = out2[j][k-1];
        }
        output[i][1]=input[0];
        i++;
    }
    return i;
}
void assignment6() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 *  Given an array A and an integer K, print all subsets of A which sum to K.
 *  Subsets are of length varying from 0 to n, that contain elements of the array. But the order of 
 *  elements should remain same as in the input array.
 *  Note : The order of subsets are not important. Just print them in different lines.
 *  Input format :
 *      Line 1 : Size of input array
 *      Line 2 : Array elements separated by space
 *      Line 3 : K 
 */
void subsetSumToK(int input[], int n, int output[], int m, int k){
    if(n==0){
        if(k==0){
            printArray(output, m);
        }
        return;
    }
    subsetSumToK(input+1, n-1, output, m, k);
    int i;
    int out[10000];
    for(i=0; i<m; i++){
        out[i] = output[i];
    }
    out[i] = input[0];
    subsetSumToK(input+1, n-1, out, m+1, k-input[0]);
}
void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    subsetSumToK(input, size, output, 0, k);
}
void assignment7() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}

/**
 *  Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
 *  Write a program to return the list of all possible codes that can be generated from the given string.
 */
#include<string.h>
int getCodes(string input, string output[10000]) {
	if(input.length() == 0){
        output[0] = "";
        return 1;
    }
    string out1[10000], out2[10000];
    int ans1 = getCodes(input.substr(1), out1);
    int j=0;
    char ch1 = ( input[0] - '0' ) + 'a' - 1;
    for(int i=0;i<ans1; i++){
        output[j++] = ch1+out1[i];
    }
    if(input.length() >= 2){
        int ans2 = getCodes(input.substr(2), out2);
        int num = (input[0] - '0')*10 + (input[1] - '0');
        if(num >= 10 && num <= 26){
         	char ch2 = num + 'a' - 1;
            for(int i=0;i<ans2; i++){
                output[j++] = ch2+out2[i];
            }   
        }
    }
    return j;
}
void assignment8(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
}

/**
 *  Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
 *  Write a program to print the list of all possible codes that can be generated from the given string.
 */
#include <string.h>
using namespace std;

void possibleCodes(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    char ch1 = ( input[0] - '0' ) + 'a' - 1;
    possibleCodes(input.substr(1), output+ch1);
    if(input.length() >= 2){
        int number = (input[0] - '0')*10 + (input[1] - '0');
        if(number >= 10 && number <= 26){
         	char ch2 = number + 'a' - 1;
    		possibleCodes(input.substr(2), output+ch2);     
        } 
    }
}
void printAllPossibleCodes(string input) {
    string output="";
    possibleCodes(input, output);
}
void assignment9(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
}


/**
 *  Given a string S, find and return all the possible permutations of the input string.
 *  Note 1 : The order of permutations is not important.
 *  Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
 */
int returnPermutations(string input, string output[]){
   	if(input.size() == 0){
        output[0] = "";
        return 1;
    }
    int i = 0, k=0;
    while(i < input.size()){
        string out[10000];
        string smallString = input.substr(0,i) + input.substr(i+1);
        int ans = returnPermutations(smallString, out);
        for(int j=0; j<ans; j++){
        	output[k++] = input[i]+out[j];
    	}
        i++;
    }
    return k;
}
void assignment10(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
}

/**
 *  Given an input string (STR), find and return all possible permutations of the input string.
 */
void permutations(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    for(int i=0; i<input.size(); i++){
        string smallString = input.substr(0,i) + input.substr(i+1);
        permutations(smallString, input[i]+output);
    }
}
void printPermutations(string input){
	string output="";
    permutations(input, output);
}
void assignment11() {
    string input;
    cin >> input;
    printPermutations(input);
}

int main(){
    //assignment1();
    //assignment2();
    //assignment3();
    //assignment4();
    //assignment5();
    //assignment6();
    //assignment7();
    //assignment8();
    //assignment9();
    //assignment10();
    assignment11();

    return 0;
}