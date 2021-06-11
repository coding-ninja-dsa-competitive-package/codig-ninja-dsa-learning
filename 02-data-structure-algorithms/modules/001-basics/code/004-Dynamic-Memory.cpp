#include<iostream>
using namespace std;

void problem1(){
    int *p = new int;
    *p = 10;
    cout << "*p : " << *p << endl;
    delete p;
    cout<<"========================"<<endl;

    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Array created : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
    cout<<"========================"<<endl;
}

/**
 *  Total memory allocated: 
 *  Example : m=5, n=10;
 *  -   For each row, we have 10 elements so 40 bytes in heap and 8 bytes in stack
 *      i.e. 200 bytes in heap , 40 bytes in stack.
 *  -   For double pointer, 8 bytes in stack. 
 *  -   Total : 200 bytes in heap, 48 in stack.
 */
void problem2(){
    int m,n;
    cin >> m >> n;
    int **p = new int*[m];
    for(int i=0; i<m; i++){
        p[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> p[i][j];
        }
    }
    //delete memory
    for(int i=0; i<m; i++){
        delete [] p[i];
    }
    delete [] p;
}

int main(){
    problem1();
    //2D arrray
    problem2();
    
    return 0;
}