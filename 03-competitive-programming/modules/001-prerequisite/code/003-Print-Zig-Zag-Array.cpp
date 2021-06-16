#include<bits/stdc++.h>

using namespace std;

/**
 *  Zig Zag
 *  -   Print the 2D array in zig zag format i.e. first column from top->down , 
 *      second column, down->up and so on ...
 * 
 *  Input Format : 
 *      n, m for rows and cols.
 *      elements in 2D array provided
 *  Output Format : 
 *      print array in  zig zag format
 *  
 *  -   For Example : 
 *          1 1 3 4 
 *          2 3 6 7
 *      Output : 1 2 3 1 3 6 7 4
 */

int main() {
    freopen("../io/zigzag_array_in.txt", "r", stdin);
    freopen("../io/zigzag_array_out.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for(int col=0; col<m; col++){
        if(col%2 == 0){
            for(int row=0; row<n; row++){
                cout << arr[row][col] << " ";
            }
        } else {
            for(int row=n-1; row>=0; row--){
                cout << arr[row][col] << " ";
            }
        }
    }

    for(int i=0; i<n; i++){
        delete  arr[i];
    }
    delete [] arr;


    return 0;
}