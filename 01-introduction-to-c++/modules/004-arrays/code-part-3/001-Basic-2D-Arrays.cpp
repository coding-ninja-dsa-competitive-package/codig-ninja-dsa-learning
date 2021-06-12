#include<iostream>
using namespace std;

//2-D array
int main(){
    int a[100][100];
    int m, n;
    cin >> m >> n;

    //taking input
    for(int i=0; i<m; i++){
        for(int j=0; j<n ; j++){
            cin >> a[i][j];
        }
    }

    //print array row wise
    cout << "Print array row wise : " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n ; j++){
            cout << a[i][j] << "\t\t";
        }
        cout << endl;
    }

    //print array column wise
    cout << "Print array column wise : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m ; j++){
            cout << a[i][j] << "\t\t";
        }
        cout << endl;
    }
}