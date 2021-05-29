#include<iostream>
using namespace std;
#include<cstring>
#include<cmath>
#include<climits>

/**
 *  Given an input string S and two characters c1 and c2, you need to replace every 
 *  occurrence of character c1 with character c2 in the given string.
 */
void replaceCharacter(char input[], char c1, char c2) {
    if(input[0] == '\0'){
        return;
    }
    if(input[0] == c1){
        input[0] = c2;
    }
    replaceCharacter(input+1, c1, c2);
}
void assignment1() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}

/**
 *  Given a string S, remove consecutive duplicates from it recursively.
 */
void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0'){
        return;
    }
    removeConsecutiveDuplicates(input+1);
    if(input[0] == input[1]){
        int i;
        for(i=0; input[i] != '\0'; i++){
            input[i] = input[i+1];
        }
        input[i] = '\0';
    }
}
void assignment2() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}

/**
 *  Merge Sort
 */
void merge(int arr[], int start, int mid, int end){
    int *temp = new int[end-start+1];
    int k=0;
    int s1 = start, e1=mid, s2=mid+1, e2 = end;
    while(s1 <= e1 && s2 <= e2){
        if(arr[s1] < arr[s2]){
            temp[k++] = arr[s1++];
        } else {
            temp[k++] = arr[s2++];
        }
    }
    while(s1<=e1){
        temp[k++] = arr[s1++];
    }
    while(s2<=e2){
        temp[k++] = arr[s2++];
    }
    int index = start;
    for(int i=0; i<k;  i++){
        arr[index++] = temp[i];
    }
    delete [] temp;
}
void mergeSortFun(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSortFun(arr, start, mid);
    mergeSortFun(arr, mid+1, end);
    merge(arr, start, mid, end);
}
void mergeSort(int input[], int size){
	mergeSortFun(input, 0, size-1);        
}
void assignment3(){
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for(int i = 0; i < length; i++) {
        cout << input[i] << " ";
    }
}

/**
 *  Quick Sort
 */
int partition(int input[], int start, int end){
    int pivot = input[start], count=0;
    for(int i=start+1; i<=end; i++){
        if(input[i] <= pivot){
            count++;
        }
    }
    input[start] = input[start+count];
    input[start+count] = pivot;
    
    int i=start, j=end;
    while(i < start+count && j > start+count){
        if (input[i] <= pivot){
        	i++;
        }
        else if (input[j] > pivot){
            j--;
        }
        else{
         	int temp = input[i];
        	input[i] = input[j];
        	input[j] = temp;
        	i++;
        	j--;   
        }
    }
    return start+count;
    
}
void quickSortFun(int input[], int start, int end){
    if(start >= end){
        return;
    }
    int pivot = partition(input, start, end);
    quickSortFun(input , start, pivot-1);
    quickSortFun(input , pivot+1, end);
}
void quickSort(int input[], int size) {
	quickSortFun(input, 0, size-1);
}
void assignment4(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;
}

int main(){
    //assignment1();
    //assignment2();
    //assignment3();
    //assignment4();

    return 0;
}