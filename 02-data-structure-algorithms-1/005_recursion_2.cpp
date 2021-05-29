#include<iostream>
#include<cstring>

using namespace std;

/**
 *  Multiplication (Recursive)
 *  -   Given two integers M & N, calculate and return their multiplication 
 *      using recursion. 
 *  -   You can only use subtraction and addition for your calculation. No 
 *      other operators are allowed.
 */
int multiplyNumbers(int m, int n) {
    if(n == 0){
        return 0;
    }
    return m+multiplyNumbers(m, n-1);
}
void assignment1(){
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}

/**
 *  Count Zeros
 *  -   Given an integer N, count and return the number of zeros that are present 
 *      in the given integer using recursion.
 */
int countZeros(int n) {
   if(n<10){
       if(n==0){
           return 1;
       } 
       return 0;
   }
   int ans = countZeros(n/10);
   if(n%10 == 0){
       return ans+1;
   } else{
       return ans;
   }
}
// int countZeros(int n) {
//    if(n == 0){
//        return 1;
//    }
//    if(n < 10){
//        return 0;
//    } else{
//        return countZeros(n/10) + countZeros(n%10);
//    }
// }
void assignment2(){
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

/**
 *  Geometric Sum
 *  -   Given k, find the geometric sum i.e.
 *          1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
 */
#include<cmath>
#include<iomanip>
double geometricSum(int k) {
	if(k == 0){
        return 1;
    }
    double ans = geometricSum(k-1);
    return ans+ 1/pow(2,k);
}
void assignment3() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}

/**
 *  Check Palindrome (recursive)
 *  -   Check whether a given String S is a palindrome using recursion. 
 *      Return true or false.
 */
#include<cstring>
bool isPalindrome(char input[], int start , int end){
    if(start > end){
        return true;
    }
    if(input[start] != input[end]){
        return false;
    }
    return isPalindrome(input, start+1, end-1);
}
bool checkPalindrome(char input[]) {
    int len = strlen(input);
    int start = 0, end = len-1;
	return isPalindrome(input, start, end);
}
void assignment4(){
    char input[50];
    cin >> input;
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

/**
 *  Sum of digits (recursive)
 *  -   Write a recursive function that returns the sum of the digits of a given integer.
 */
int sumOfDigits(int n) {
	if(n == 0){
        return 0;
    }
	int ans = sumOfDigits(n/10);
    return ans + n%10;
}
void assignment5() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}

/**
 *  Replace pi (recursive)
 *  -   Given a string, compute recursively a new string where all 
 *      appearances of "pi" have been replaced by "3.14".
 */
void replacePi(char input[]) {
	if(input[0] == '\0'){
        return;
    }
    replacePi(input+1);
    int len = strlen(input);
    if(input[0] == 'p' && input[1] == 'i'){
        for(int i=len+1; i>3; i--){
            input[i] = input[i-2];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
}
string replacePiV2(string input) {
	if(input.empty()){
        return "";
    }
    string res = replacePiV2(input.substr(1));
    if(input[0] == 'p' && res[0] == 'i'){
        return "3.14" + res.substr(1);
    }
    return input[0]+res;
}
void assignment6(){
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

/**
 *  Remove X
 *  -   Given a string, compute recursively a new string where all 'x' chars 
 *      have been removed.
 */
void removeX(char input[]) {
    if(input[0] == '\0'){
        return;
    }
    removeX(input+1);
	if(input[0] == 'x'){
     	int len=strlen(input);
        int i;
        for(i=0; i<len-1; i++){
            input[i] = input[i+1];
        }
        input[i] ='\0';
    }
}
void assignment7(){
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

/**
 *  String to Integer
 *  -   Write a recursive function to convert a given string into the number 
 *      it represents. That is input will be a numeric string that contains 
 *      only numbers, you need to convert the string into corresponding integer 
 *      and return the answer.
 */
#include<cmath>
int stringToNumber(char input[]) {
    if(input[0]== '\0'){
        return 0;
    }
    int ans = stringToNumber(input+1);
    int len = strlen(input);
    return ((input[0]-48) * pow(10, len-1)) + ans; 
}
void assignment8(){
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

/**
 *  Pair Star
 *  -   Given a string S, compute recursively a new string where identical 
 *      chars that are adjacent in the original string are separated from 
 *      each other by a "*".
 */
void pairStar(char input[]) {
    if(input[0] == '\0'){
        return;
    }
    pairStar(input+1);
    if(input[0] == input[1]){
        int len = strlen(input);
        input[len+1] ='\0';
        int i;
        for( i=len;i>1; i--){
            input[i] = input[i-1];
        }
        input[i] = '*';
    }
}
void assignment9(){
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}

/**
 *  Tower of Hanoi
 *  -   Tower of Hanoi is a mathematical puzzle where we have three rods and n 
 *      disks. The objective of the puzzle is to move all disks from source rod 
 *      to destination rod using third rod (say auxiliary). The rules are :]
 *      1.  Only one disk can be moved at a time.
 *      2.  A disk can be moved only if it is on the top of a rod.
 *      3.  No disk can be placed on the top of a smaller disk.
 *  -   Print the steps required to move n disks from source rod to destination rod.
 *  -   Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.
 */
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0){
        return;
    }
    if(n == 1){
        cout << source << " " << destination << endl;
        return;
    }
    towerOfHanoi(n-1, source , destination, auxiliary);
    cout << source << " " << destination << endl;
    towerOfHanoi(n-1, auxiliary , source , destination);
}
void assignment10(){
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}

int main() {
    // Multiplication (Recursive)
    // assignment1();
    
    // Count Zeros
    // assignment2();

    // Geometric Sum
    // assignment3();

    // Check Palindrome (recursive)
    // assignment4();
    
    // Sum of digits (recursive)
    // assignment5();

    // Replace pi (recursive)
    // assignment6();

    // Remove X
    // assignment7();

    // String to Integer
    // assignment8();

    // Pair Star
    // assignment9();

    // Tower of Hanoi
    assignment10();

    return 0;
}