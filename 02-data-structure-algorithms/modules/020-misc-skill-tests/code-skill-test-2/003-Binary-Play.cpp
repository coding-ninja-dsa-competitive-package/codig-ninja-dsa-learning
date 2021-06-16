#include<iostream>

using namespace std;

/**
 *  Binary Play
 *  -   We are given a series of Binary Strings. The first term in this series 
 *      is 0. Hence, T1 = '0'.
 *  -   To find the string at any given Ti, we look at Ti - 1 and replace all 
 *      occurances of '0' with '01' and '1' with '10'.
 *  -   You are given two integers N and X, your job is to find TN and return 
 *      its Xth index.
 *  Note: Ti are 1-indexed.
 * 
 *  Input Format:
 *      First line of input contains an integer T, representing the number of test cases.
 *      The next T lines contains two space separated integers, N and X.
 *  
 *  Constraints:
 *      
 *  Output Format:
 *      Print the Xth index in Nth row
 *  
 *  Sample Input:
 *      1
 *      4 5 
 *  Sample Output:  
 *      1
 *  
 *  Explanation:
 *      T1: '0'
 *      T2: '01'
 *      T3: '0110'
 *      T4: '01101001'
 *      The 5th element in T4 is '1'.
 */
char flip(char c) {
    return (c == '0')? '1': '0';
}

int binarySequence(int N, int X) {
    string previous = "0";
    for(int i=1; i<N; i++){
        string str = previous;
        string compliment = "";
        for (int j = 0; j < str.length(); j++){
            compliment += flip(str[j]);
        }
        previous = str + compliment;
    }
    return previous[X-1] - '0';
}

int main(){
    int t, n, x;
    cin >> t;
    while (t != 0){
        cin >> n >> x;
        cout << binarySequence(n, x) << endl;
        t--;
    }
}