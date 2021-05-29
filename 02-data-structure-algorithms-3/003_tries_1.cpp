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
 *  Trie:
 *  =====
 *  -   Tree like data structure and used to store data like dictionary words.
 *  -   The first letter would be at first letter and so on...
 *  -   Each node can have maximum 26 childred since we have 26 letters only.
 *      Ex:                root
 *                          |
 *                          T           THE, THIS, TOM 
 *                         / \
 *                        H   O
 *                       / \  |
 *                      E  I  M
 *                         |
 *                         S
 *  Reason to choose Tries over HashMap for Dictionary:
 *  ---------------------------------------------------
 *  -   Due to space optimization, Trie is preferred over hashmap.
 *  -   Fast Searching
 * 
 *  Types of Tries:
 *  --------------
 *  1.  Compressed Tries : 
 *      -   Space optimization.
 *      -   Merge the nodes which have only one child.
 *          Ex: bend and bean will stored as :
 *                      be
 *                     /  \
 *                    nd  an 
 *  2.  Suffix Tries : 
 *      -   store all the suffix as well in the trie.
 *      -   Ex: bend - we will store bend, end, en, nd, d
 */
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

void problem1(){
    Trie t;
    t.insert("and");
    t.insert("are");
    t.insert("dot");

    cout << t.search("and") << endl;

    t.remove("and");
    cout << t.search("and") << endl;
}

/**
 *  Huffman Coding:
 *  ==============
 *  1.  Count frequency of chars
 *  2.  Min priority queue to save for getting the 2 minimum elements.
 *      Take 2 elements out - calculate sum and add it as root of the 
 *      above 2 elements and push the sum in priority queue.
 *  3.  Form a Binary Tree like Structure using the nodes/data.
 *  4.  And form a hashmap for the code for each character using root
 *      to leaf path.
 *  5.  Encode the file/string.
 * 
 *  For Decompression:
 *  5.  Form the inverted hashmap for code->character from step 4.
 *  6.  Decode the file/string.
 */

int main() {
    // Trie Basics Usage
    // problem1();

    return 0;
}