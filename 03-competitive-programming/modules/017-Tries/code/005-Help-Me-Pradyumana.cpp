#include<bits/stdc++.h>

using namespace std;

/**
 *  Help Me Pradyumana!
 *  -   Pradyumn is tired of using auto - correct feature in his smartphone. He 
 *      needs to correct his auto - correct more times than the auto - correct 
 *      corrects him. Pradyumn is thinking to make his own app for mobile which 
 *      will restrict auto - correct feature, instead it will provide auto - 
 *      completion. Whenever Pradyumn types factorial, auto - correct changes it 
 *      to fact. Pradyumn's App will show options such as fact, factorial, factory. 
 *      Now, he can chose from any of these options. As Pradyumn is busy with his 
 *      front - end work of his App. He asks you to help him. He said "You will 
 *      be given set of words(words may repeat too but counted as one only). Now, 
 *      as user starts the app, he will make queries(in lowercase letters only). 
 *      So, you have to print all the words of dictionary which have the prefix 
 *      same as given by user as input. And if no such words are available, add 
 *      this word to your dictionary." As you know, Pradyumn want this app to be 
 *      as smart as him :P So, implement a program for him such that he can release 
 *      it on Fun Store.
 *  
 *  INPUT CONSTRAINTS
 *      1≤N≤30000
 *      sum(len(string[i]))≤2∗10^5
 *      1≤Q≤10^3
 *  
 *  INPUT FORMAT
 *      Single integer N which denotes the size of words which are input as dictionary
 *      N lines of input, where each line is a string of consisting lowercase letter
 *      Single integer Q which denotes the number of queries.
 *      Q number of lines describing the query string on each line given by user
 *  OUTPUT FORMAT
 *      If auto - completions exists, output all of them in lexicographical order 
 *      else output "No suggestions" without quotes
 *  
 *  NOTE: All strings are lowercase
 *  
 *  SAMPLE INPUT
 *      3
 *      fact
 *      factorial
 *      factory
 *      2
 *      fact
 *      pradyumn
 *  SAMPLE OUTPUT
 *      fact
 *      factorial
 *      factory
 *      No suggestions
 */

class TrieNode{
    public:
        TrieNode** children;
        bool isLeaf;

        TrieNode(){
            this->children = new TrieNode*[26];
            this->isLeaf = false;
            for(int i=0; i<26; i++){
                this->children[i] = NULL;
            }
        }
};

void insert(TrieNode* root, string str){
    if(str.empty()){
        root->isLeaf = true;
        return;
    }
    TrieNode* child;
    int index = str[0] - 'a';
    if(root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = new TrieNode();
        root->children[index] = child;
        child = root->children[index];
    }
    insert(child, str.substr(1));
}

void printString(TrieNode* current, string prefix){
    if(current->isLeaf){
        cout << prefix << endl;
    }
    for(int i=0; i<26; i++){
        TrieNode* temp = current;
        if(temp->children[i] != NULL){
            char suffix = (int)i + (int)'a';
            printString(current->children[i], prefix+suffix);
        }
    }
}

void printStringsWithPrefix(TrieNode* root, string s){
    TrieNode* current = root;
    for(int i=0; i<s.length(); i++){
        int index = s[i] - 'a';
        if(current->children[index] != NULL){
            current = current->children[index];
        } else {
            cout << "No suggestions" << endl;
            insert(root, s);
            return;
        }
    }
    printString(current, s);
}

int main() {
    int n;
    cin >> n;
    TrieNode* root = new TrieNode();
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        insert(root, s);
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        string s; 
        cin >> s;
        printStringsWithPrefix(root, s);
    }

    return 0;
}