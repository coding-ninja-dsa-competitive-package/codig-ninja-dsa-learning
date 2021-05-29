#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/**
 *  Print 2D array
 *  -   Given a 2D integer array with n rows and m columns. Print the 0th 
 *      row from input n times, 1st row n-1 times…..(n-1)th row will be 
 *      printed 1 time.
 */
void print2DArray(int **input, int row, int col) {
	for(int i=0; i<row; i++){
        int count = 0;
        while(count < row-i){
            for(int j=0; j<col; j++){
                cout << input[i][j] << " ";
            }
            count++;
            cout << endl;
        }
    }
}
void problem1(){
    int row, col;
    cin >> row >> col;
    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
}

/**
 *  Minimum Length Word
 *  -   Given a string S (that can contain multiple words), you need to 
 *      find the word which has minimum length.
 */
void minLengthWord(char input[], char output[]){
	int i, j=0, min = INT_MAX;
    while(input[j] != '\0'){
        i = j;
        while(input[j] != ' ' && input[j] != '\0'){
        	j++;
    	}
        if(min > j-i){
            min = j-i;
            int k;
            for(k=0; k<min; k++){
                output[k] = input[i];
                i++;
            }
            output[k] ='\0';
        }
        j++;
    }
}
void problem2(){
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}

/**
 *  Leaders in array
 *  -   Given an integer array A of size n. Find and print all the leaders 
 *      present in the input array. An array element A[i] is called Leader, 
 *      if all the elements following it (i.e. present at its right) are 
 *      less than or equal to A[i].
 *  -   Print all the leader elements separated by space and in the same 
 *      order they are present in the input array.
 */
void Leaders(int* arr,int len){
    for(int i=0; i<len; i++){
        for(int j=len-1;j>=i; j--){
            if(arr[j] > arr[i]){
                break;
            }
            if(j == i){
                cout << arr[i] << " ";
            }
        }
    }
}
void problem3(){
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}
	Leaders(arr,len);
}

int main() {
    // Print 2D array 
    // problem1();

    // Minimum Length Word
    // problem2();

    // Leaders in array
    problem3();

    return 0;
}