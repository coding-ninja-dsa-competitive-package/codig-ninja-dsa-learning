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

int main(){
    problem1();
    problem3();
}