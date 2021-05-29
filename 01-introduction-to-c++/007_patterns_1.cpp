#include<iostream>
#include<cmath>
using namespace std;

/**
 *  pattern1 - Print below pattern :
 *          1
 *          1 2
 *          1 2 3
 *          1 2 3 4
 */
void pattern1(){
    int N;
    cout << "Enter the number for pattern 1 : " << endl;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1 ;
        while(j <= i){
            cout << j << " ";
            j = j+1;
        }
        cout << endl;
        i = i+1;
    }
}

/**
 *  pattern2 - Print below pattern :
 *                1
 *              1 2
 *            1 2 3
 *          1 2 3 4
 */
void pattern2(){
    int N;
    cout << "Enter the number for pattern 2 : " << endl;
    cin >> N;

    int i=1;
    while(i <= N){
        int k = 1;
        while(k <= N-i){
            cout << "  ";
            k = k+1;
        }
        int j=1 ;
        while(j <= i){
            cout << j << " ";
            j = j+1;
        }
        cout << endl;
        i = i+1;
    }
}

/**
 *  pattern3 - Print below pattern :
 *          1
 *          2 3
 *          3 4 5
 *          4 5 6 7
 */
void pattern3(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = i, k =1;
        while(k <= i){
            cout << j;
            j = j+1;
            k = k+1;
        }
        cout << endl;
        i = i+1;
    }
}

/**
 *  pattern3 - Print below pattern :
 *                1
 *              2 3
 *            3 4 5
 *          4 5 6 7
 */
void pattern4(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int l = 1;
        while(l <= N-i){
            cout << " ";
            l = l+1;
        }
        int j=i, k=1;
        while(k <= i){
            cout << j;
            j = j+1;
            k = k+1;
        }
        cout << endl;
        i = i+1;
    }
}

/**
 *  pattern5 - Print below pattern:
 *                 *
 *                ***
 *               *****
 *              *******     
 * 
 */
void pattern5(){
    int N;
    cin >> N;

    int i =1;
    while(i <= N){
        int j = 1;
        while(j <= N-i){
            cout << " ";
            j = j+1;
        }
        int k = 1;
        while(k <= 2*i-1){
            cout << "*";
            k = k+1;
        }
        cout << endl;
        i = i+1;
    }
}

/**
 *  Assignment 1 : 
 *  ->  Write a program to calculate the total salary of a person. The user has to enter the 
 *      basic salary (an integer) and the grade (an uppercase character), and depending upon 
 *      which the total salary is calculated as :
 *            totalSalary = basic + hra + da + allow – pf;
 *      where :
 *          hra   = 20% of basic
 *          da    = 50% of basic
 *          allow = 1700 if grade = ‘A’
 *          allow = 1500 if grade = ‘B’
 *          allow = 1300 if grade = ‘C' or any other character
 *          pf    = 11% of basic.
 * 
 *      0 <= Basic Salary <= 7,500,000
 *      
 *      Round off the total salary and then print the integral part only.
 *      Note: Try finding out a function on the internet to do so.
 *  ->  Sample Input & output:
 *      1.  10000 A  , 17600
 *      2.  4567 B , 8762
 */
void assignment1(){
    int basicSalary;
    char ch;
    cin >> basicSalary >> ch;

    double hra = 0.2 * basicSalary;
    double da = 0.5 * basicSalary;
    double pf = 0.11 * basicSalary;

    int allow;
    if(ch == 'A'){
        allow = 1700;
    } else if (ch == 'B'){
        allow = 1500;
    } else {
        allow = 1300;
    }

    double totalSalary = basicSalary + hra + da + allow - pf;
    int total = round(totalSalary);
    cout << total << endl;

}

/**
 *  Assignment 2:
 *  ->  Write a program to input an integer N and print the sum of all its even digits and 
 *      sum of all its odd digits separately.
 *  ->  Digits mean numbers, not the places! That is, if the given integer is "13245", even 
 *      digits are 2 & 4 and odd digits are 1, 3 & 5.
 *  ->  Sample Input, output:
 *      1.  1234 , 6 4
 *      2.  552245 , 8 15
 */
void assignment2(){
    int N;
    cin >> N;

    long int sumEven = 0 , sumOdd = 0; 
    while(N){
        int digit = N % 10;
        if(digit % 2 == 0){
            sumEven += digit;
        } else{
            sumOdd += digit;
        }
        N = N / 10;
    }
    cout << sumEven << " " << sumOdd;
}

/**
 *  Find power of a number
 *  ->  Write a program to find x to the power n (i.e. x^n). Take x and n from the user. 
 *      You need to print the answer.
 *  ->  Note : For this question, you can assume that 0 raised to the power of 0 is 1.
 *          0 <= x <= 8 
 *          0 <= n <= 9
 *  ->  Sample Input, Output :
 *      1.  3 4 , 81
 *      2.  2 5, 32 
 * 
 */
void assignment3(){
    int x, n;
    cin >> x >> n ;

    int i=0, result = 1;
    while( i < n){
        result *= x;
        i = i+1;
    }
    cout << result << endl;
}

/**
 *  Sqaure Pattern:
 *  Ex : N = 3 , print pattern as below:
 *      333
 *      333
 *      333
 */
void pattern6() {
    int N;
    cin >> N;
    
    int i=1;
    while(i<=N){
        int j = 1;
        while(j <= N){
            cout << N;
            j++;
        }
        cout<<endl;
        i++;
    }
}

/**
 *  Triangular Pattern: Print below if N=4
 *      *
 *      **
 *      ***
 *      ****
 */
void pattern7(){
    int N;
	cin >> N;
    
    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= i){
            cout << "*";
            j = j+1;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Reverse Number pattern - Print below pattern :
 *          1
 *          2 1
 *          3 2 1
 *          4 3 2 1
 */
void pattern8(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= i){
            cout << i-j+1;
            j++;
        }
        cout << endl;
        i++;
    }
}

int main(){
    // pattern1();

    // pattern2();

    // pattern3();

    // pattern4();

    // pattern5();

    //assignment1();

    // assignment2();
    // cout<<endl;

    // assignment3();

    // pattern6();

    // pattern7();

    pattern8();

    return 0;
}