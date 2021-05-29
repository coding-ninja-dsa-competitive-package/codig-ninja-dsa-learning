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

#include <string>
#include <vector>

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

    bool isPalindromePair(vector<string> words);

    void autoComplete(vector<string> input, string pattern);
};

/**
 *  Pattern Matching
 *  -   Given a list of n words and a pattern p that we want to search. 
 *      Check if the pattern p is present the given words or not. Return 
 *      true if the pattern is present and false otherwise.
 */
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
void assignment1(){
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
}

/**
 *  Palindrome Pair
 *  -   Given 'n' number of words, you need to find if there exist any 
 *      two words which can be joined to make a palindrome or any word, 
 *      which itself is a palindrome.
 *  -   The function should return either true or false. You don't have 
 *      to print anything.
 */
bool isPalindrome(string str){
    int l=0, r=str.length()-1;
    while(l<r){
        if(str[l] != str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
bool isPatternFound(TrieNode* root, string word){
    if(root->isTerminal && isPalindrome(word)){
        return true;
    }
    bool res = false;
    for(int i=0; i<26; i++){
        TrieNode* child = root->children[i];
        if(child != NULL){
            res = res || isPatternFound(child, word+child->data);
        }
    }
    return res;
}
bool Trie::isPalindromePair(vector<string> words){
    if(root==NULL || words.size()==0){
        return false;
    }
    for(int i=0; i<words.size(); i++){
        if(isPalindrome(words[i])){
            return true;
        }
        insertWord(words[i]);
    }
    for(int i=0; i<words.size(); i++){
        return isPatternFound(root, words[i]);
    }
    return false;
}
void assignment2(){
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    cout << (t.isPalindromePair(words) ? "true" : "false");
}

/**
 *  Auto complete
 *  -   Given n number of words and an incomplete word w. You need to 
 *      auto-complete that word w.
 *  -   That means, find and print all the possible words which can be 
 *      formed using the incomplete word w.
 *  Note : Order of words does not matter.
 */
void printPossibleWords(TrieNode* root,string pattern,string word){
    if(pattern.empty()){
        if(root->isTerminal){
            cout << word << endl;
        }
        for(int i=0; i<26 ;i++){
            TrieNode* child = root->children[i];
            if(child != NULL){
                printPossibleWords(child, "" , word + child->data);
            }
        }
        return;
    }

    int index = pattern[0]-'a';
    TrieNode* child = root->children[index];
    if(child != NULL){
        printPossibleWords(child, pattern.substr(1), word);
    }
}
void Trie::autoComplete(vector<string> input, string pattern) {
    for(int i=0; i<input.size(); i++){
        insertWord(input[i]);
    }
    printPossibleWords(root, pattern, pattern);
}
void assignment3(){
    Trie t;
    int n;
    cin >> n;
    vector<string> vect;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    string pattern;
    cin >> pattern;
    t.autoComplete(vect, pattern);
}


int main() {
    // Pattern Matching
    // assignment1();

    // Palindrome Pair
    assignment2();

    // Auto complete
    // assignment3();

    return 0;
}