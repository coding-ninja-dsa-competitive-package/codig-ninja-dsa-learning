#include<iostream>
using namespace std;

/**
 *  Find the output.
 *  Ans :  No Output
 */
void problem1(){
    int p = 100;
    if(p > 20) {
        if(p < 20) {
            printf("coding");
        }
    } else {
        printf("ninjas");
    }
}

/**
 *  Write the correct order(s) of statements.
 *  We want to print "Coding Ninjas" 10 times.
 * 
 *      1.  while(x <= 10) {
 *      2.  int x = 1;
 *      3.  x += 1;
 *      4.  print("Coding Ninjas\n");
 *      5.  }
 * 
 *  Ans :  2 1 3 4 5 
 *         2 1 4 3 5
 */

/**
 *  Figure out the output
 *  Ans : 97531-1
 */
void problem3(){
    int x = 10;
    while(x >= 0) {
        x = x - 1;
        printf("%d" , x);
        x--;
    }
}

/**
 *  Pyramid Number Pattern : Print the following pattern for the given number of rows.
 *      N=4,
 *               1
 *              212
 *             32123
 *            4321234
 */
void assignment1(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1;
        while(j <= N-i){
            cout << " ";
            j++;
        }

        int k=i;
        while(k>=1){
            cout << k;
            k--;
        }
        int a=1 , b=2;
        while(a <= i-1){
            cout << b;
            b++;
            a++;
        }

        i++;
        cout << endl;
    }
}

/**
 *  Number Star Pattern
 *  -   Print the following pattern for given number of rows.
 *      N=5, 
 *          1234554321
 *          1234**4321
 *          123****321
 *          12******21
 *          1********1
 */
void assignment2(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1;
        while(j <= N-i+1){
            cout << j;
            j++;
        }
        int k=1;
        while(k <= 2*i-2){
            cout << "*";
            k++;
        }
        int l=N-i+1;
        while(l >=1){
            cout << l;
            l--;
        }

        i++;
        cout << endl;
    }
}

/**
 *  Second Largest
 *  -   Take input a stream of n integer elements, find the second largest 
 *      element present.
 *  -   The given elements can contain duplicate elements as well. If only 
 *      0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).
 *      
 *      Input format :
 *          Line 1 : Total number of elements (n)
 *          Line 2 : N elements (separated by space)
 */
void assignment3(){
    int N;
    cin >> N;

    int largest = INT_MIN, second = INT_MIN;
    while(N){
        int num;
        cin >> num;

        if(num > largest){
            second = largest;
            largest = num;
        } else if( num != largest && num > second){
            second = num;
        }
        N--;
    }
    cout << second;
}

int main() {

    //problem1();

    //problem3();

    //Pyramid Number Pattern
    //assignment1();
    
    //Number Star Pattern
    //assignment2();

    //Second Largest
    assignment3();

    return 0;
}