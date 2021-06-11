#include<iostream>
using namespace std;

/**
 *  Reverse Triangle
 *      N=4 , 
 *              *
 *             **
 *            ***
 *           ****
 */
void pattern1(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int spaces = 1; 
        while(spaces <= N - i){
            cout << " ";
            spaces++;
        }
        int stars = 1;
        while(stars <= i){
            cout << "*";
            stars++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Mirror Number Pattern
 *      N=4, 
 *              1
 *             12
 *            123
 *           1234
 */
void pattern2(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int spaces = 1; 
        while(spaces <= N-i){
            cout << " ";
            spaces++;
        }
        int j=1;
        while(j <= i){
            cout << j;
            j++;
        }

        cout<<endl;
        i++;
    }
}

/**
 *  Inverted Triangle
 *      N=4, 
 *          ****
 *          ***
 *          **
 *          *
 */
void pattern3(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i+1){
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }
}

/**
 *  Inverted Number Pattern
 *      N=4, 
 *          4444
 *          333
 *          22
 *          1
 */
void pattern4(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i+1){
            cout << N-i+1;
            j++;
        }
        cout << endl;
        i++;
    }
}

/**
 *  Isoceles Triangle
 *      N=4,
 *          1
 *         121
 *        12321
 *       1234321
 */
void pattern5(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i){
            cout << " ";
            j++;
        }
        int k = 1;
        while(k <= i){
            cout << k ;
            k++;
        }
        int l=i-1;
        while(l > 0){
            cout << l;
            l--;
        }

        cout << endl;
        i++;
    }
}

/**
 *  Star Pattern
 *      N=4
 *              *
 *             ***
 *            *****
 *           *******
 */
void  pattern6(){
    int N;
    cin >> N;

    int i=1;
    while(i <= N){
        int j = 1;
        while(j <= N-i){
            cout << " ";
            j++;
        }
        int k =1;
        while(k <= 2*i - 1){
            cout << "*";
            k++;
        }

        cout << endl;
        i++;
    }
}

/**
 *  Triangle of Numbers
 *      N=4
 *              1
 *             232
 *            34543
 *           4567654
 */
void pattern7(){
    int N;
    cin >>N;

    int i = 1;
    while(i <= N){
        int spaces = 1;
        while(spaces <= N-i){
            cout << " ";
            spaces++;
        }
        int j = 1, m= i;
        while(j <= i){
            cout << m;
            j++;
            m++;
        }
        int k = i-1, n = 2*(i-1);
        while(k > 0){
            cout << n;
            n--;
            k--;
        }

        cout << endl;
        i++;
    }
}

/**
 *  Diamond of stars : N will be always odd.
 *      N = 5
 *              *
 *             ***
 *            *****
 *             ***
 *              *
 */
void pattern8(){
    int N;
    cin >> N;

    int i = 1;
    while(i <= N/2+1){
        int j = 1; 
        while(j <= (N/2+1)-i){
            cout << " ";
            j++;
        }
        int k=1;
        while(k <= 2*i -1){
            cout << "*";
            k++;
        }
        cout << endl;
        i++;
    }

    N = N - (N/2 + 1);
    int row = 1;
    int m = N;
    while(m >= 1){
        int n = 1;
        while(n <= row){
            cout << " ";
            n++;
        }
        int p = 1;
        while(p <= 2*m -1 ){
            cout << "*";
            p++;
        }
        cout << endl;
        row++;
        m--;
    }
}

int main(){
    // pattern1();

    // pattern2();

    // pattern3();

    // pattern4();

    // pattern5();

    // pattern6();

    // pattern7();

    pattern8();

    return 0;
}