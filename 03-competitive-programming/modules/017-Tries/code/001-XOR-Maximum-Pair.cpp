#include<bits/stdc++.h>

using namespace std;

class TrieNode{
    public:
        TrieNode* left;
        TrieNode* right;
};

void insert(TrieNode* head, int n){
    TrieNode* curr = head;
    for(int i=31; i>=0; i--){
        int bit = (n >> i) & 1;
        if(bit==0) {
            if(!curr->left){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        } else {
            if(!curr->right){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(TrieNode* head, int* arr, int n){
    int max_xor = INT_MIN;
    for(int i=0; i<n; i++){
        int value = arr[i];
        TrieNode* curr = head;
        int curr_xor = 0;
        for(int j=31; j>=0; j--){
            int bit = (value >> j) & 1;
            if(bit==0){
                if(curr->right){
                    curr_xor += pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left){
                    curr_xor += pow(2, j);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        if(curr_xor > max_xor){
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

int main() {
    int arr[6] = {8, 1, 3, 15, 10, 5};
    TrieNode* head = new TrieNode();
    for(int i=0 ;i<6; i++){
        insert(head, arr[i]);
    }
    cout << findMaxXorPair(head, arr, 6) << endl;
    
    return 0;
}