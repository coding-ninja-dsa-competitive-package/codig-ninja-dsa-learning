/**
 *  Help Pradyumana!
 *  -   Pradyumn is tired of using auto - correct feature in his smartphone. 
 *      He needs to correct his auto - correct more times than the auto - correct 
 *      corrects him. Pradyumn is thinking to make his own app for mobile which 
 *      will restrict auto - correct feature, instead it will provide 
 *      auto - completion. Whenever Pradyumn types factorial, auto - correct changes 
 *      it to fact. Pradyumn's App will show options such as fact, factorial, factory. 
 *      Now, he can chose from any of these options. As Pradyumn is busy with his 
 *      front - end work of his App. He asks you to help him. He said "You will be 
 *      given set of words(words may repeat too but counted as one only). Now, as 
 *      user starts the app, he will make queries(in lowercase letters only). So, you 
 *      have to print all the words of dictionary which have the prefix same as given 
 *      by user as input. And if no such words are available, add this word to your 
 *      dictionary." As you know, Pradyumn want this app to be as smart as him :P So, 
 *      implement a program for him such that he can release it on Fun Store.
 *  
 *  Input Format:
 *      Single integer N which denotes the size of words which are input as dictionary
 *      N lines of input, where each line is a string of consisting lowercase letter
 *      Single integer Q which denotes the number of queries.
 *      Q number of lines describing the query string on each line given by user
 *  Constraints:
 *      1 ≤ N ≤ 30000
 *      sum(len(string[i])) ≤ 2∗10^5
 *      1 ≤ Q ≤ 10^3
 *  
 *  Output Format:
 *      If auto - completions exists, output all of them in lexicographical order 
 *      else output "No suggestions" without quotes
 *  
 *  Sample Input 1:
 *      3
 *      fact
 *      factorial
 *      factory
 *      2
 *      fact
 *      pradyumn
 *  
 *  Sample Output 1:
 *      fact
 *      factorial
 *      factory
 *      No suggestions
 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node** children;
        bool isComplete;

        Node(char data){
            this->data = data;
            this->isComplete = false;
            this->children = new Node*[26];
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
};
class Trie{
    Node* root;

    void insert(Node* root, string word){
        if(word.empty()){
            root->isComplete = true;
            return;
        }
        int index = word[0]-'a';
        Node* child = root->children[index];
        if(child == NULL){
            child = new Node(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }

    public:

        Trie(){
            this->root = new Node('\0');
        }

        void insert(string word){
            insert(root, word);
        }

        void autoComplete(string word, string pattern);
        void autoComplete(Node* root, string word, string pattern);
};

void Trie::autoComplete(Node* root, string word, string pattern){
    if(word.empty()){
        if(root->isComplete){
            cout << pattern << endl;
        }
        Node* child;
        for(int i=0; i<26; i++){
            child = root->children[i];
            if(child != NULL){
                autoComplete(child, "", pattern+child->data);
            }
        }
        return;
    }
    int index = word[0]-'a';
    Node* child = root->children[index];
    if(child != NULL){
        autoComplete(child, word.substr(1), pattern);
    } else {
        cout << "No suggestions" << endl;
        insert(pattern);
    }
}   

void Trie::autoComplete(string word, string pattern){
    autoComplete(this->root, word, pattern);
}

int main(){

    int n; 
    cin >> n;
    Trie trie;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        trie.insert(word);
    }

    
    int q; 
    cin >> q;
    for(int i=0; i<q; i++){
        string query; 
        cin >> query; 
        trie.autoComplete(query, query);
    }
    
    return 0;
}