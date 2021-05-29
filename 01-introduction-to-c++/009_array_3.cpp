#include<iostream>
using namespace std;

//2-D array
void array_2d(){
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

/**
 *  Column Wise Sum
 *  ->  Given a 2D integer array of size M*N, find and print the sum of ith column elements 
 *      separated by space.
 */
void problem1(){
    int a[100][100];
    int m,n;
    cin >> m >> n;
    //taking input
    for(int i=0; i<m; i++){
        for(int j=0; j<n ; j++){
            cin >> a[i][j];
        }
    }
    // Print sum column wise
    int result[n];
    for(int i=0; i<n; i++){
        result[i] = 0;
        for(int j=0; j<m ; j++){
            result[i] += a[j][i];
        }
    }
    for(int i=0; i<n ; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

/**
 *  Largest Row or Column
 *  ->  For a given two-dimensional integer array/list of size (N x M), you need to find out 
 *      which row or column has the largest sum(sum of all the elements in a row/column) amongst 
 *      all the rows and columns.
 */
void findLargest(int **input, int nRows, int mCols)
{
    int max_sum=0;
    int max_idx=0;
    
    //row wise sum
    for(int i=0; i<nRows; i++){
        int sum=0;
        for(int j=0; j<mCols; j++){
         	sum+= input[i][j];   
        }
        if(sum > max_sum){
            max_sum=sum;
            max_idx = i;
        }
    }
    
    //column wise sum
    int max_sum2=0;
    int max_idx2=0;
    for(int i1=0; i1<mCols; i1++){
        int sum1=0;
        for(int j1=0; j1<nRows; j1++){
         	sum1 += input[j1][i1];   
        }
        if(sum1 > max_sum2){
            max_sum2=sum1;
            max_idx2 = i1;
        }
    }
    
    if(max_sum<max_sum2){
        cout<<"column"<<" "<<max_idx2<<" "<<max_sum2;
    }else if(max_sum>max_sum2){
        cout<<"row"<<" "<<max_idx<<" "<<max_sum;
    }else if(max_sum2==0 && max_sum==0){
        cout<<"row"<<" "<<max_idx<<" "<<-2147483648;
    }else if(max_sum2==max_sum){
          cout<<"row"<<" "<<max_idx<<" "<<max_sum;
    }
}
void problem2(){
    int t;
	cin >> t;
	while (t--)	{
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++){
			input[i] = new int[col];
			for (int j = 0; j < col; j++){
				cin >> input[i][j];
			}
		}
		findLargest(input, row, col);
		cout << endl;
	}
}

/**
 *  Wave print
 *  ->  For a given two-dimensional integer array/list of size (N x M), print the array/list 
 *      in a sine wave order, i.e, print the first column top to bottom, next column bottom 
 *      to top and so on.
 */
void wavePrint(int **input, int nRows, int mCols){
	for(int col=0; col<mCols; col++){
        if(col%2 == 0){
            int row=0;
            while(row < nRows){
            	cout << input[row][col] << " ";
            	row++;
        	}
        } else {
            int row = nRows-1;
            while(row >= 0){
                cout << input[row][col] << " ";
            	row--;
            }
        }
    }
}
void problem3(){
    int t;
	cin >> t;
	while (t--){
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++){
			input[i] = new int[col];
			for (int j = 0; j < col; j++){
				cin >> input[i][j];
			}
		}
		wavePrint(input, row, col);
		cout << endl;
	}
}

/**
 *  Spiral Print
 *  ->  For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. 
 *      That is, you need to print in the order followed for every iteration:
 *      -   First row(left to right)
 *      -   Last column(top to bottom)
 *      -   Last row(right to left)
 *      -   First column(bottom to top)
 */
void spiralPrint(int **input, int nRows, int nCols)
{
    int total = nRows*nCols;
    int i=0;
    int col_start = 0, col_end = nCols-1, row_start = 0, row_end = nRows-1;
	while(i < total){
        for(int a=col_start; a <= col_end; a++){
            cout << input[row_start][a] << " ";
            i++;
        }
        row_start++;
        for(int b=row_start; b <= row_end; b++){
            cout << input[b][col_end] << " ";
            i++;
        }
        col_end--;
        for(int c=col_end; c >= col_start; c--){
            cout << input[row_end][c] << " ";
            i++;
        }
        row_end--;
        for(int d=row_end; d >= row_start; d--){
            cout << input[d][col_start] << " ";
            i++;
        }
        col_start++;
    }
}
void problem4(){
    int t;
    cin >> t;
    while (t--){
        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];
        for (int i = 0; i < row; i++){
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++){
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);
        for (int i = 0; i < row; ++i){
            delete[] matrix[i];
        }
        delete[] matrix;
        cout << endl;
    }
}

int main(){
    // array_2d();

    // Row wise Sum or Column wise Sum
    // problem1();

    // Largest Row or Column
    // problem2();

    // Wave Print
    // problem3();

    // Spiral Print
    // problem4();

    return 0;
}