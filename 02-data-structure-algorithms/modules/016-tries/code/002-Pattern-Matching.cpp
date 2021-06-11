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
 *  Pattern Matching
 *  -   Given a list of n words and a pattern p that we want to search. 
 *      Check if the pattern p is present the given words or not. Return 
 *      true if the pattern is present and false otherwise.
 *  
 *  Input Format :
 *      The first line of input contains an integer, that denotes the value of n.
 *      The following line contains n space separated words.
 *      The following line contains a string, that denotes the value of the pattern p.
 *  Output Format :
 *      The first and only line of output contains true if the pattern is present 
 *      and false otherwise.
 *      
 *  Constraints:
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      4
 *      abc def ghi cba
 *      de
 *  Sample Output 1 :
 *      true
 *  
 *  Sample Input 2 :
 *      4
 *      abc def ghi hg
 *      hi
 *  Sample Output 2 :
 *      true
 * 
 *  Sample Input 3 :
 *      4
 *      abc def ghi hg
 *      hif
 *  Sample Output 3 :
 *      false
 */

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }
        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    bool patternMatching(vector<string> vect, string pattern);
};

bool isPatternMatched(TrieNode* root, string word){
    if(word.length() == 0){
        return true;
    }
    int index = word[0] - 'a';
    TrieNode* child = root->children[index];
    if(child != NULL){
        return isPatternMatched(child, word.substr(1));
    }
    return false;
}
bool Trie::patternMatching(vector<string> vect, string pattern){
    for(int i=0; i<vect.size(); i++){
        string str = vect[i];
        while(!str.empty()){
            insertWord(str);
            str = str.substr(1);
        }
    }
    return isPatternMatched(root, pattern);
}
int main(){
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    cout << (t.patternMatching(vect, pattern) ? "true" : "false");

    return 0;
}