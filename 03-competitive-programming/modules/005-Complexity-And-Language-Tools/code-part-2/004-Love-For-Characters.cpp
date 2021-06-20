#include<bits/stdc++.h>

using namespace std;

/**
 *  Love for Characters
 *  -   Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of 
 *      lowercase letters and he wants to find out how many times characters 
 *      ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
 *  Input:
 *      First line contains an integer denoting length of the string.
 *      Next line contains the string.
 *  Constraints:
 *      1<=n<=10^5
 *      ‘a’<= each character of string <= ‘z’
 *  Output:
 *      Three space separated integers denoting the occurrence of letters 
 *      ‘a’, ‘s’ and ‘p’ respectively.
 *  
 *  Sample Input:
 *      6
 *      aabsas
 *  Sample output:
 *      3 2 0
 */

// Approach 1 - using 3 variables
void count_sol1(string str, int n){
    int count_a=0, count_s=0, count_p=0;
    for(int i=0; i<n; i++){
        if(str[i] == 'a'){
            count_a++;
        } else if(str[i] == 's'){
            count_s++;
        } else if(str[i] == 'p'){
            count_p++;
        }
    }
    cout << count_a << " " << count_s << " " << count_p << endl;
}

// Approach 2 - using map 
#include<unordered_map>

void count_sol2(string str, int n){
    unordered_map<char, int> hm;
    for(int i=0; i<n; i++){
        hm[str[i]]++;
    }
    cout << hm['a'] << " " << hm['s'] << " " << hm['p'] << endl;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    count_sol1(str, n);
    count_sol2(str, n);

    return 0;
}