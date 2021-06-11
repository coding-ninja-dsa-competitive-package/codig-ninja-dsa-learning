#include<iostream>
#include<cstring>
using namespace std;

/**
 *  Check permutation:
 *  ->  For a given two strings, 'str1' and 'str2', check whether they 
 *      are a permutation of each other or not.
 */
bool isPermutation(char input1[], char input2[]) {
    int temp[26]={0};
	int length = strlen(input1);
    for(int i=0; i<length; i++){
        temp[input1[i] - 97]++;
    }
    
    length = strlen(input1);
    for(int i=0; i<length; i++){
        if(temp[input2[i] - 97] <= 0){
            return false;
        } else {
            temp[input2[i] - 97]--;
        }
    }
    return true;
}
void assignment1(){
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}

/**
 *  Remove Consecutive Duplicates
 *  ->  For a given string(str), remove all the consecutive duplicate characters.
 */

void removeConsecutiveDuplicates(char input[]) {
	int i=0, j=i+1; 
    while(input[j] != '\0'){
        while(input[j] == input[i]){
            j++;
        }
        input[i+1] = input[j];
        j++;
        i++;
    }
    input[i+1] = '\0';
}
void assignment2(){
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}

/**
 *  Reverse Each Word
 *  ->  Aadil has been provided with a sentence in the form of a string as a function parameter. 
 *      The task is to implement a function so as to print the sentence such that each word in 
 *      the sentence is reversed.
 */
void reverse(char input[], int start, int end){
     while(start <= end){
        char temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}
void reverseEachWord(char input[]) {
    int start=0, end=0;
    while(input[start] != '\0'){
	    while(input[end] != ' ' && input[end] != '\0'){
    	    end++;
        }
        reverse(input, start, end-1);
        end++;
        start = end;
    }
    cout << "reversed string : " << input <<endl;
}
void assignment3(){
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}

/**
 *  Remove character
 *  ->  For a given a string(str) and a character X, write a function to remove all the occurrences of 
 *      X from the given string.
*   ->  The input string will remain unchanged if the given character(X) doesn't exist in the input string.
 */
void removeAllOccurrencesOfChar(char input[], char c) {
    int i=0, j=0;
    while(input[j] != '\0'){
        while(input[j] == c){
            j++;
        }
        if(input[j] != '\0'){
         	int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j++;   
        }
    }
    input[i] = '\0';
}
void assignment4(){
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}

/**
 *  Highest Occuring Character
 *  ->  For a given a string(str), find and return the highest occurring character.
 *  ->  Assume all the characters in the given string to be in lowercase always.
 */
char highestOccurringChar(char input[]) {
    int arr[26] = {0};
    int i=0;
    while(input[i] != '\0'){
        arr[input[i] - 97]++;
        i++;
    }
    
    char max_occuring_char;
    int max=INT_MIN;
    for(int i=0; i<26; i++){
        if(arr[i] > max){
            max = arr[i];
            max_occuring_char = i+97;
        }
    }
    return max_occuring_char;
}
void assignment5(){
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}

/**
 *  Compress the String
 *  ->  Write a program to do basic string compression. For a character which is consecutively 
 *      repeated more than once, replace consecutive duplicate occurrences with the count of 
 *      repetitions.
 *  ->  Consecutive count of every character in the input string is less than or equal to 9.
 */
void stringCompression(char input[]){
    int i=0 , j=0, count;  
    while(input[j] != '\0'){
        count=0;
        while(input[j] == input[i]){
            count++;
            j++;
        }
        if(count > 1){
            i++;
            input[i] = count+48;
        }
        i++;
        input[i] = input[j];
    }
    input[i] ='\0';
}
void assignment6(){
    int size = 1e6;
    char str[size];
    cin >> str;
    stringCompression(str);
    cout << str;
}   

int main(){
    // Check permutation
    // assignment1();

    // Reverse Consecutive Duplicates
    // assignment2();

    // Reverse Each Word
    // assignment3();

    // Remove Character
    // assignment4();

    // Highest Occuring Character
    // assignment5();

    // Compress the String
    assignment6();

    return 0;
}