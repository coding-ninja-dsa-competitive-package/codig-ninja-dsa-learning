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

int main(){
    pattern1();
    pattern2();
}