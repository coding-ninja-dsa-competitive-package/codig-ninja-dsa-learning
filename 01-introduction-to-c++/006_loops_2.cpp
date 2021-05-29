#include<iostream>
using namespace std;

/**
 *  Sum or Product:
 *  ->  Write a program that asks the user for a number N and a choice C. And then give 
 *      them the possibility to choose between computing the sum and computing the product 
 *      of all integers in the range 1 to N (both inclusive).
 *  ->  If C is equal to -
 *      1.  then print the sum
 *      2. then print the product
 *      Any other number, then print '-1' (without the quotes)
 *  ->  Sample Input, Output
 *          10 1, 55
 */
void assignment1(){
    int N, C;
    cin >> N >> C;

    int i=1,sum=0, product=1;
    if(C == 1){
        while(i <= N){
            sum += i;
            i++;
        }
        cout << sum << endl;
    } else if (C == 2){
        while(i <= N){
            product *= i;
            i++;
        }
        cout << product << endl;
    } else {
        cout << "-1" << endl;
    }
}

/**
 *  Terms of AP
 *  ->  Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
 *  ->  Sample I/O
 *          if x=4, 5 11 14 17
 */
void assignment2(){
    int x;
    cin >> x;

    int N = 1, count = 0;
    while(count < x){
        int num = 3*N + 2;
        if(num % 4 == 0){
            N++;
            continue;
        }
        cout << num << " ";
        N++;
        count++;
    }
    cout << endl;
}

/**
 *  Reverse of a number
 *  ->  Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
 *      Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse 
 *             of 10400 will be 401 instead of 00401.
 */
void assignment3(){
    int N;
    cin >> N;

    int reverse = 0;
    while(N){
        reverse = reverse*10 + N%10;
        N = N/10;
    }
    cout << reverse << endl;
}
int power(int n, int p){
    int result = 1;
    for(int i=1; i<=p ; i++){
        result *= n;
    }
    return result;
}

/**
 *  Binary to decimal
 *  ->  Given a binary number as an integer N, convert it into decimal and print.
 *  ->  Sample I/O:
 *          1100, 12
 */
void assignment4(){
    int N;
    cin >> N;

    int i = 0, result = 0;
    while(N){
        if(N%10 == 1){
            result += power(2, i);
        }
        i++;
        N = N/10;
    }
    cout << result << endl;
}

/**
 *  Decimal to Binary
 *  ->  Given a decimal number (integer N), convert it into binary and print.
 *      The binary number should be in the form of an integer.
 *      Note: The given input number could be large, so the corresponding binary number can exceed 
 *            the integer range. So you may want to take the answer as long for CPP and Java.
 *      Note for C++ coders: Do not use the inbuilt implementation of "pow" function. The implementation 
 *          of that function is done for 'double's and it may fail when used for 'int's, 'long's, or 
 *          'long long's. Implement your own "pow" function to work for non-float data types.
 */
void assignment5(){
    int n;
    cin>>n;
    int rem;
    long ans=0;
    long pv=1;
    while(n)
    {
        rem=n%2;
        ans=ans+(rem*pv);
        pv=pv*10;
        n=n/2;
    }
    cout<<ans<<endl;
}    

/**
 *  Square Root (Integral)
 *  ->  Given a number N, find its square root. You need to find and print only the integral 
 *      part of square root of N.
 *      For eg. if number given is 18, answer is 4.
 */
void assignment6(){
    int N;
    cin >> N;
    
    int i=1;
    while(power(i, 2) <= N){
        i++;
    }
	cout << i-1 <<endl;
}

/**
 * Check Number sequence - Decreasing Incresing 
 */
void assignment7(){
    int N;
    cin >> N;
    
   	int previous;
    cin >> previous;
    
    int i = 1;
    bool flag = true;
    while(i < N){
        int current;
        cin >> current;
        if(current == previous){
            cout << "false" << endl;
            exit(0);
        } else if (current > previous){
            flag = false;
        } else if(current < previous) {
            if(flag == false){
                cout << "false" << endl;
                exit(0);
            }
        }
        previous = current;
        i++;
    }
    cout << "true" << endl;
}
int main(){

    // Sum or Product
    // assignment1();

    // Terms of AP
    // assignment2();

    // Reverse of a number
    // assignment3();

    // Binary to decimal
    // assignment4();

    // Decimal to Binary
    // assignment5();

    // Square Root (Integral)
    // assignment6();

    // Check Number sequence - Decreasing Incresing
    assignment7();
        
    return 0;
}

