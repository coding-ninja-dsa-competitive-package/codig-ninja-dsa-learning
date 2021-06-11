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
 *  Auto complete
 *  -   Given n number of words and an incomplete word w. You need to 
 *      auto-complete that word w.
 *  -   That means, find and print all the possible words which can be 
 *      formed using the incomplete word w.
 *  Note : Order of words does not matter.
 * 
 *  Input Format :
 *      The first line of input contains an integer, that denotes the value of n.
 *      The following line contains n space separated words.
 *      The following line contains the word w, that has to be auto-completed.
 * 
 *  Output Format :
 *      Print all possible words in separate lines.
 * 
 *  Constraints:
 *  
 *  Time Limit: 1 sec
 * 
 *  Sample Input 1 :
 *      7
 *      do dont no not note notes den
 *      no
 *  Sample Output 2 :
 *      no
 *      not
 *      note
 *      notes
 * 
 *  Sample Input 2 :
 *      7
 *      do dont no not note notes den
 *      de
 *  Sample Output 2 :
 *      den
 * 
 *  Sample Input 3 :
 *      7
 *      do dont no not note notes den
 *      nom
 *  Sample Output 3 :
 *      (Empty) There is no word which starts with "nom"
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

    void autoComplete(vector<string> input, string pattern);
};

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

int main(){
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

    return 0;
}