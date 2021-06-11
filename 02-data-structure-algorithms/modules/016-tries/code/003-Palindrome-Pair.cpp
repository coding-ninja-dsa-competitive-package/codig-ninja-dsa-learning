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
 *  Palindrome Pair
 *  -   Given 'n' number of words, you need to find if there exist any 
 *      two words which can be joined to make a palindrome or any word, 
 *      which itself is a palindrome.
 *  -   The function should return either true or false. You don't have 
 *      to print anything.
 * 
 *  Input Format :
 *      The first line of the test case contains an integer value denoting 'n'.
 *      The following contains 'n' number of words each separated by a single space.
 *  Output Format :
 *      The first and only line of output contains true if the conditions 
 *      described in the task are met and false otherwise.
 * 
 *  Constraints:
 *      0 <= n <= 10^5
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      4
 *      abc def ghi cba
 *  Sample Output 1 :
 *      true
 *  Explanation of Sample Input 1:
 *      "abc" and "cba" forms a palindrome
 *  
 *  Sample Input 2 :
 *      2
 *      abc def
 *  Sample Output 2 :   
 *      false
 *  Explanation of Sample Input 2:
 *      Neither their exists a pair which forms a palindrome, nor any of the words 
 *      is a palindrome in itself. Hence, the output is 'false.'
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

    bool isPalindromePair(vector<string> words);
};

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

int main(){
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    cout << (t.isPalindromePair(words) ? "true" : "false");

    return 0;
}