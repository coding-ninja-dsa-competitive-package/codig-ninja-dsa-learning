#include<iostream>
using namespace std;

/**
 *  Array Sum
 *  -   Given an array of length N, you need to find and print the sum of all 
 *      elements of the array.
 * 
 *  Input Format :
 *      Line 1 : An Integer N i.e. size of array
 *      Line 2 : N integers which are elements of the array, separated by spaces
 *  Output Format :
 *      Sum
 *  
 *  Constraints :
 *      1 <= N <= 10^6
 *  
 *  Sample Input :
 *      3
 *      9 8 9
 *  Sample Output :
 *      26
 */

int main(){
    int N;
    cin >> N;
    
    int array[N];
    int i=0;
    while(i < N){
        int num;
        cin >> num;
        
        array[i] = num;
        i++;
    }
    
    int sum=0;
    for(int i=0; i<N; i++){
        sum += array[i];
    }
    cout << sum << endl;
}