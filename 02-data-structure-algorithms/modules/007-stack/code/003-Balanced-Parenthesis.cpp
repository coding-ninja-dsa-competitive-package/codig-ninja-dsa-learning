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
 *  Code : Balanced Parenthesis
 *  -   For a given a string expression containing only round brackets or 
 *      parentheses, check if they are balanced or not. Brackets are said 
 *      to be balanced if the bracket which opens last, closes first.
 *  -   You need to return a boolean value indicating whether the expression 
 *      is balanced or not.
 * 
 *  Note:   The input expression will not contain spaces in between.
 *      
 *  Input Format:
 *      The first and the only line of input contains a string expression without 
 *      any spaces in between.
 *  Output Format:
 *      The only line of output prints 'true' or 'false'.
 * 
 * 
 *  Constraints:    
 *      1 <= N <= 10^7
 *      Where N is the length of the expression.
 *  
 *  Time Limit: 1sec
 *  
 *  Sample Input 1 :
 *      (()()())
 *  Sample Output 1 :
 *      true
 * 
 *  Sample Input 2 :
 *      ()()(()
 *  Sample Output 2 :
 *      false
 *  
 *  Explanation to Sample Input 2:
 *      The initial two pairs of brackets are balanced. But when you see, the opening 
 *      bracket at the fourth index doesn't have its corresponding closing bracket 
 *      which makes it imbalanced and in turn, making the whole expression imbalanced. 
 *      Hence the output prints 'false'.
 */
bool isBalanced(string expression) 
{
    int len = expression.length();
    stack<char> s;
    for(int i=0; i<len; i++){
        if(expression[i] == '('){
            s.push(expression[i]);
        } else{
            if(s.empty()){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false") << endl;
}