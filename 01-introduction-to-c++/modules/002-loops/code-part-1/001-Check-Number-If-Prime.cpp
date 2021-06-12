#include<iostream>

using namespace std;

/**
 *  Check if the number provided is prime or not.
 */
void checkPrime(){
    int num;
    cout << "Enter num : " << endl;
    cin >> num;

    int d = 2;
    bool flag = false;
    while(d < num ){
        if(num % d == 0){
            cout << "Not prime" << endl;
            flag = true;
            break;
        }
        d = d+1;
    }
    if(!flag){
        cout << "Prime" << endl;
    }
}

int main(){
    checkPrime();
}