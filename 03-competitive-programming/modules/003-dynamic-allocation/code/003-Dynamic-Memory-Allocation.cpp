#include<iostream>

using namespace std;

void basics(){
    // dynamic allocation - 8 bytes for pointer in stack & 4 bytes in heap for int object
    int *p = new int;       
    *p = 10;
    cout << *p << endl;

    double *pd = new double;

    char *c = new char;

    //array
    int n;
    cin >> n;
    int *arr = new int[n];

    delete p;
    delete pd;
    delete c;
    delete [] arr;
}

/**
 *  Q/A
 *  1.  In CPP, dynamic memory allocation is done using ______________ operator.
 *  Ans : new
 * 
 *  2.  How will you free the memory allocated by following program -
 *                  int *a = new int;
 *  Ans : delete a;
 * 
 *  3.  Correct statement for creating an integer array of size 5, dynamically -
 *  Ans : int *arr = new int[5];
 * 
 *  4.  Correct statement for deallocating the array is -
 *  Ans : delete [] arr;
 * 
 *  5.  On deleting a dynamic memory, if the pointer value is not modified, then 
 *      the pointer points to?
 *  Ans : The same deleted memory location.
 */

void basics_2d_array(){
    int n,m;
    cin >> n >> m;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        delete [] arr[i];
    }
    delete [] arr;
}

/**
 *  Q/A
 *  1.  How to Dynamically create a Two Dimensional Array in C++?
 *  Ans : int** twoDArray = new int*[10];
 * 
 *  2.  Can we create Jagged Arrays in C++ ?
 *  Ans : yes
 *  
 *  3.  Given the following CPP Program. Select the CORRECT Syntax of 
 *      deleting this 2D array? Check all that apply.
 *      Options are -
 *      A.      delete twoDArray [][];
 *      B.      for(int i = 0; i < 10; i++)
 *              delete twoDArray[i];
 *              delete twoDArray[];
 *      C.      for(int i = 0; i < 10; i++) 
 *              delete [] twoDArray[i];
 *              delete[] twoDArray;
 *      D.      for(int i = 0; i < 10; i++)
 *              delete twoDArray[i][];
 *              delete[] twoDArray;
 *  Ans : C
 */

void problem1(){
    int **twoDArray = new int*[10];
    for(int i = 0; i < 10; i++)
        *(twoDArray + i) = new int[10];
}


int main() {
    // dynamic allocation
    basics();   

    // dynamic allocation for 2D array
    basics_2d_array();

    return 0;
}