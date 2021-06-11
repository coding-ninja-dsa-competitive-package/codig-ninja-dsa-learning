#include<iostream>
using namespace std;

/**
 *     N= 4, 
 *      1 2 3 4
 *      9 10 11 12
 *      13 14 15 16
 *      5 6 7 8
 */
void pattern1()
{
    int n;
    cin >> n;
    
	// Write your code here
    int n1, n2;
    if(n%2 == 0){
        n1 = n2 = n/2;
    } else {
        n1 = n/2+1;
        n2 = n/2;
    }
    
    int i=1;
    int num = 1;
    while(i <= n1){
        int j = 1;
        while(j <= n){
            cout << num << " ";
            num++;
            j++;
        }
        i++;
        num = num+n;
        cout<< endl;
    }

    if(n%2 == 0){
        num = num - n;
    } else {
        num = num - 3*n;
    }

    int k= 1;
    while(k <= n2){
        int j = 1;
        while(j <= n){
            cout << num << " ";
            num++;
            j++;
        }
        num = num - 3*n;
        k++;
        cout << endl;
    }


}

/**
 *  N=4,
 *          4444444
 *          4333334
 *          4322234
 *          4321234
 *          4322234
 *          4333334  
 *          4444444
 */
void pattern2(){
    int N;
    cin >> N;

    int i =1;
    int num = N;
    while(i <= N){
        int k = 0;
        int m = N;
        while(k < i-1){
            cout << m;
            k++;
            m--;
        }

        int j = 1;
        while(j <= 2*num -1 ){
            cout << num;
            j++;
        }
        num--;

        int p = 0;
        int q = N-i+2;
        while(p < i-1){
            cout << q;
            p++;
            q++;
        }
        i++;
        cout << endl;
    }

    int n = N-1;
    int a = n-1;
    int b = 2;
    int row = 1;
    while(a >=0){
        int j=1, num=N;
        while(j <= a){
            cout << num;
            num--;
            j++;
        }
        int k = 1;
        while(k <= 2*row+1){
            cout << b;
            k++;
        }
        b++;

        int l=1, num1=N-a+1;
        while(l <= a){
            cout << num1;
            num1++;
            l++;
        }

        a--;
        row++;
        cout << endl;
    }

}

/**
 *      N=5,
 *          *****
 *          ** **
 *          *   *
 *          ** **
 *          *****
 */
void pattern3(){
    int n;
    cin >> n;

    if(n%2 == 0){
        n = n+1;
    }
    int i = 1;
    int n1= n/2+1;
    while(i <= n1){
        int j=n1;
        int count =0;
        while(j >= i){
            cout << "*";
            j--;
            count++;
        }
        int space=1;
        while(space <= 2*i-3){
            cout << " ";
            space++;
            count++;
        }
        while(count < n){
            cout << "*";
            count++;
        }
        
        i++;
        cout << endl;
    }
    int n2 = n/2;
    int j = n2, row=1;
    while(row <= n2){
        int k = row+1;
        int count=0;
        while(k >= 1){
            cout << "*";
            k--;
            count++;
        }
        int space = 1;
        while(space <= 2*j-3){
            cout << " ";
            space++;
            count++;
        }
        while(count < n){
            cout << "*";
            count++;
        }

        row++;
        j--;
        cout << endl;
    }
}

int main(){
    // pattern1();

    // pattern2();

    // pattern3();
    
    return 0;
}