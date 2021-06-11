#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Minimum bracket Reversal
 *  -   For a given expression in the form of a string, find the minimum 
 *      number of brackets that can be reversed in order to make the expression 
 *      balanced. The expression will only contain curly brackets.
 *  -   If the expression can't be balanced, return -1.
 * 
 *  Example:
 *      Expression: {{{{
 *      If we reverse the second and the fourth opening brackets, the whole 
 *      expression will get balanced. Since we have to reverse two brackets 
 *      to make the expression balanced, the expected output will be 2.
 *      Expression: {{{
 *      In this example, even if we reverse the last opening bracket, we would 
 *      be left with the first opening bracket and hence will not be able to make 
 *      the expression balanced and the output will be -1.
 * 
 *  Input Format :
 *      The first and the only line of input contains a string expression, without 
 *      any spaces in between.
 *  Output Format :
 *      The only line of output will print the number of reversals required to 
 *      balance the whole expression. Prints -1, otherwise.
 *  
 *  Constraints:    
 *      0 <= N <= 10^6
 *      Where N is the length of the expression.
 *  
 *  Time Limit: 1sec
 *    
 *  Sample Input 1:
 *      {{{
 *  Sample Output 1:
 *      -1
 * 
 *  Sample Input 2:
 *      {{{{}}
 *  Sample Output 2:
 *      1
 */
int countBracketReversals(string input) {
    if(input.size() % 2 != 0){
        return -1;
    }
    stack<char> s;
    int count=0;
	for(int i=0; i<input.length() ; i++){
        if(input[i] == '{'){
            s.push('{');
        } else {
            if(s.empty()){
                count++;
                s.push('{');
            } else{
                s.pop();
            }
        }
    }
    if(!s.empty()){
        count += s.size()/2;
    }
    return count;
}

int main(){
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}