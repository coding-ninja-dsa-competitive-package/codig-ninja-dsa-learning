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
 *  Check redundant brackets
 *  -   For a given expression in the form of a string, find if there exist 
 *      any redundant brackets or not. It is given that the expression contains 
 *      only rounded brackets or parenthesis and the input expression will 
 *      always be balanced.
 *  -   A pair of the bracket is said to be redundant when a sub-expression is 
 *      surrounded by unnecessary or needless brackets.
 * 
 *  Input Format :
 *      The first and the only line of input contains a string expression, without 
 *      any spaces in between.
 *  Output Format :
 *      The first and the only line of output will print either 'true' or 'false'
 *      (without the quotes) denoting whether the input expression contains redundant 
 *      brackets or not.
 *  
 *  Constraints:
 *      0 <= N <= 10^6
 *      Where N is the length of the expression.
 *  
 *  Time Limit: 1 second
 *  
 *  Sample Input 1:
 *      a+(b)+c 
 *  Sample Output 1:
 *      true
 *  Explanation:
 *      The expression can be reduced to a+b+c. Hence, the brackets are redundant.
 * 
 *  Sample Input 2:
 *      (a+b)
 *  Sample Output 2:
 *      false
 */
bool checkRedundantBrackets(string expression) {
	stack<char> s;
    for(int i=0; i<expression.length() ; i++){
        if(expression[i] != ')'){
            s.push(expression[i]);
        } else {
            int count=0;
            while(s.top() != '('){
                count++;
                s.pop();
            }
            if(count<=1){
                return true;
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}