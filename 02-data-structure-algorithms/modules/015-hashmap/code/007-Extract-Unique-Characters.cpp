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
 *  Extract Unique characters
 *  -   Given a string S, you need to remove all the duplicates. That means, 
 *      the output string should contain each character only once. The respective 
 *      order of characters should remain same, as in the input string.
 * 
 *  Input format:
 *      The first and only line of input contains a string, that denotes the value of S.
 *  Output format :
 *      The first and only line of output contains the updated string, as described 
 *      in the task.
 *  
 *  Constraints :
 *      0 <= Length of S <= 10^8
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :    
 *      ababacd
 *  Sample Output 1 :
 *      abcd
 * 
 *  Sample Input 2 :
 *      abcde
 *  Sample Output 2 :
 *      abcde
 */
string uniqueChar(string str) {
    unordered_map<char, bool> mp;
    string res="";
    for(int i=0; i<str.length(); i++){
        if(mp.find(str[i]) == mp.end()){
            mp[str[i]]=true;
            res += str[i];
        }
    }
    return res;
}
//approach 2
#include<unordered_set>
string uniqueCharSet(string str) {
    unordered_set<char> set;
    string res="";
    for(int i=0; i<str.length(); i++){
        if(set.find(str[i]) == set.end()){
            set.insert(str[i]);
            res.push_back(str[i]);
        }
    }
    return res;
}

int main(){
    string str;
    cin >> str;
    cout << uniqueChar(str);
    cout << uniqueCharSet(str);

    return 0;
}