#include<bits/stdc++.h>

using namespace std;

/**
 *  Search Engine
 *  -   Let us see how search engines work. Consider the following simple auto 
 *      complete feature. When you type some characters in the text bar, the engine 
 *      automatically gives best matching options among it's database. Your job is 
 *      simple. Given an incomplete search text, output the best search result.
 *  -   Each entry in engine's database has a priority factor attached to it. We 
 *      consider a result / search suggestion best if it has maximum weight and 
 *      completes the given incomplete search query. For each query in the input, 
 *      print the maximum weight of the string in the database, that completes the  
 *      given incomplete search string. In case no such string exists, print -1.
 *  
 *  INPUT
 *      First line contains two integers n and q, which represent number of database 
 *      entries and number of search queries need to be completed. Next n lines 
 *      contain a string s and an integer weight, which are the database entry and 
 *      it's corresponding priority.
 *      Next q lines follow, each line having a string t, which needs to be completed.
 *  OUTPUT
 *      Output q lines, each line containing the maximum possible weight of the 
 *      match for given query, else -1, in case no valid result is obtained.
 *  CONSTRAINTS
 *      1 ≤ n, weight, len(s), len(t) ≤ 10^6
 *      1 ≤ q ≤ 10^5
 *      total length of all strings in database entries ≤ 10^6  
 *      total length of all query strings ≤ 10^6
 *  
 *  SAMPLE INPUT
 *      2 1
 *      hackerearth 10
 *      hackerrank 9
 *      hacker
 *  SAMPLE OUTPUT
 *      10
 */

class TrieNode{
    public:
        TrieNode** children;
        int weight;

        TrieNode(){
            children = new TrieNode*[26];
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            weight = 0;
        }
};

void insert(string s, int weight, TrieNode* root){
    if(s.empty()){
        return;
    }
    int index = s[0] - 'a';
    TrieNode* child;
    if(root->children[index]){
        child = root->children[index];
    } else {
        child = new TrieNode();
        root->children[index] = child;
    }

    if(weight > root->weight){
        root->weight = weight;
    }
    insert(s.substr(1), weight, child);
}

int searchBest(string s, TrieNode* root){
    int bestWeight = -1;
    TrieNode* current = root;
    for(int i=0; i<s.length(); i++){
        int index = s[i] -'a';
        TrieNode* child = current->children[index];
        if(child){
            current = child;
            bestWeight = child->weight;
        } else {
            return -1;
        }
    }
    return bestWeight;
}

int main() {
    int n, q;
    cin >> n >> q;
    TrieNode* root = new TrieNode();
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int weight;
        cin >> weight;
        insert(s, weight, root);
    }
    for(int i=0; i<q; i++){
        string pre;
        cin >> pre;
        cout << searchBest(pre, root) << endl;
    }

    return 0;
}