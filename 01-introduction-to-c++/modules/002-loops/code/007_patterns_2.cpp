#include<iostream>
using namespace std;

/**
 *  Character Pattern:
 *  N = 4 ,print :
 *      ABCD
 *      ABCD
 *      ABCD
 *      ABCD
 */
void pattern1(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j=1;
        char startChar = 'A';
        while(j <= N){
            char ch = startChar + j -1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Character Pattern:
 *  N = 4 ,print :
 *      ABCD
 *      BCDE
 *      CDEF
 *      DEFG
 */
void pattern2(){
    int N;
    cin >> N;

    int i = 1;
    while(i <= N){
        int j =1;
        char startChar = 'A' + i - 1;
        while(j <= N){
            char ch = startChar + j - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Alpha Pattern
 *   N=3, 
 *      A
 *      BB
 *      CCC
 */
void pattern3(){
    int N ;
    cin >> N;
    
    int i=1;
    while(i <= N){
        int j=1;
        while(j <= i){
            char ch = 'A' + i - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Character Pattern
 *      N=4, 
 *          A
 *          BC
 *          CDE
 *          DEFG
 */
void pattern4(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1; 
        char startChar = 'A' + i -1;
        while(j <= i){
            char ch = startChar + j - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Interesting Alphabets
 *      N=5, 
 *          E
 *          DE
 *          CDE
 *          BCDE
 *          ABCDE
 */
void pattern5(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        char startChar = 'A' + N - i;
        while(j <= i){
            char ch = startChar + j - 1;
            cout << ch;
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

    pattern5();

    return 0;
}