#include<iostream>
using namespace std;

/**
 *  Check if the number provided is prime or not.
 */
void checkPrime(){
    int num;
    cout << "Enter num : " << endl;
    cin >> num;

    int d = 2;
    bool flag = false;
    while(d < num ){
        if(num % d == 0){
            cout << "Not prime" << endl;
            flag = true;
            break;
        }
        d = d+1;
    }
    if(!flag){
        cout << "Prime" << endl;
    }
}
//===============================
/**
 *  Sum of Even Numbers till N
 *  -   Given a number N, print sum of all even numbers from 1 to N.
 */
void problem1(){
    int N;
    cin >> N;
    
    int sum = 0 , ptr = 2;
    while( ptr <= N ){
        sum += ptr;
        ptr = ptr+2;
    }
    cout << sum << endl;
}

/**
 *  Fahrenheit to Celsius Table
 *  -   Given three values - Start Fahrenheit Value (S), End Fahrenheit 
 *      value (E) and Step Size (W), you need to convert all Fahrenheit 
 *      values from Start to End at the gap of W, into their corresponding 
 *      Celsius values and print the table.
 */
void problem2(){
    int start, end , step;
    cin >> start >> end >> step;

    while(start <= end){
        int celcius = (start - 32) * 5/9;
        cout << start << "\t" << celcius << endl;
        start = start + step;
    }
    cout << endl;
}
//===============================

/**
 *  Nth term of Fibonacci series F(n) is calculated using the following formula -
 *      F(n) = F(n-1) + F(n-2), 
 *          Where, F(1) = F(2) = 1
 *  Provided N you have to find out the Nth Fibonacci Number.
 *  -> Sample Input , Output:
 *          6 , 8
 */
void problem3(){
    int N;
    cin >> N;

    if (N <= 2){
        cout << 1 << endl;
        return;
    }

    int a1 = 1, a2= 1;
    int next;
    for(int i = 2; i < N ; i++){
        next = a1+a2;
        a1 = a2;
        a2 = next;
    }
    cout << next << endl;
}

/**
 *  Assignment 1 : 
 *      All Prime Numbers: Given an integer N, print all the prime numbers that lie in the 
 *                         range 2 to N (both inclusive).
 *      Print the prime numbers in different lines.
 */
void assignment1(){
    int N;
    cin >> N;

    for(int i = 2; i<=N; i++){
        int j = i-1;
        while(j >= 2){
            if(i%j == 0){
                break;
            }
            j--;
        }
        if(j < 2){
            cout << i << endl;
        }
    }
}

int main(){
    //check if the number is Prime or not.
    //checkPrime();

    //sum of all even numbers between 1 and N.
    //problem1();

    //Fahrenheit to Celsius Table with start, end, batch
    //problem2();

    //Nth term of Fibonacci series
    //problem3();

    //prime numbers in range 2 to N
    assignment1();

    return 0;
}