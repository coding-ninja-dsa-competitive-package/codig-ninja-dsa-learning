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
 *  Map:
 *  -   We can store Key - Value pair in it.
 *  -   We can implement it using :
 *      1.  BST :
 *           map - implemented using BST - O(logn)
 *      2.  Hashtable:
 *           unordered_map - implemented using hashtable - O(1) 
 */
int main(){
    unordered_map<string, int> mp;
    //insert
    pair<string, int> p("abc", 1);
    mp.insert(p);
    mp["def"] = 2;

    // Find
    cout << mp["def"] << endl;
    cout << mp.at("abc") << endl;
    // cout << mp.at("ghi") << endl; // if not found, throw exception - key not found
    // cout << mp["ghi"] << endl;      // if not found, insert in map - with value 0
    if(mp.count("ghi")){ //check presence
        cout << "ghi is present." << endl;
    }

    // Size
    cout << mp.size() << endl;

    // Erase element
    mp.erase("ghi");
}