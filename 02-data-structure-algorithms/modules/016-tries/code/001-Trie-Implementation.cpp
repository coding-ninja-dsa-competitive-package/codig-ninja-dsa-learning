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

class TrieNode{
    public:
        char data;
        TrieNode** children;
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            this->children = new TrieNode*[26];
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

class Trie{
    TrieNode* root;

    void insert(TrieNode* root, string word){
        // Base Case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child= root->children[index];
        if(root->children[index] == NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive call
        insert(child, word.substr(1));
    }

    bool search(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        TrieNode* child = root->children[index];
        if(child == NULL){
            return false;
        }
        return search(child, word.substr(1));
    }

    void remove(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = false;
            return;
        }
        
        int index = word[0]-'a';
        TrieNode* child= root->children[index];
        if(child != NULL){
            remove(child, word.substr(1));
        }

        if(child != NULL && child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }

    public:
        Trie(){
            root = new TrieNode('\0');
        }

        void insert(string word){
            insert(root, word);
        }

        bool search(string word){
            return search(root, word);
        }

        void remove(string word){
            remove(root, word);
        }
};

int main(){
    Trie t;
    t.insert("and");
    t.insert("are");
    t.insert("dot");

    cout << t.search("and") << endl;

    t.remove("and");
    cout << t.search("and") << endl;
}