#include<bits/stdc++.h>

using namespace std;

/**
 *  Maximum XOR Subarray
 *  -   Given an array of n integers, find subarray whose xor is maximum.
 *  
 *  Input Format
 *      First line contains single integer n (1<=n<=1000000).
 *      Next line contains n space separated integers.
 *  Output Format
 *      Print xor of the subarray whose xor of all elements in subarray is maximum 
 *      over all subarrays.
 *  Constraints
 *      1 <= n <= 1000000
 *      1 <= A[i] <=100000 
 *  
 *  Sample Input    
 *      4
 *      1 2 3 4
 *  Sample Output
 *      7
 */

class TrieNode {
    public:
        TrieNode* left;
        TrieNode* right;
};

void insert(TrieNode* head, int n){
    TrieNode* curr = head;
    for(int i=31; i>=0; i--){
        int bit = (n >> i) & 1;
        if(bit == 0){
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

int findMaxXorSubarray(TrieNode* head, int* arr, int n){
    int max_xor = arr[0];
    int xor_till_now = arr[0];
    for(int i=1; i<n; i++){
        xor_till_now = xor_till_now ^ arr[i];
        
        TrieNode* curr = head;
        int curr_max_xor=0;
        for(int j=31; j>=0; j--){
            int bit = (xor_till_now >> j) & 1;
            if(bit==0){
                if(curr->right){
                    curr_max_xor += pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left){
                    curr_max_xor += pow(2, j);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        if(curr_max_xor > max_xor){
            max_xor = curr_max_xor;
        }
        insert(head, xor_till_now);
    }
    return max_xor;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    TrieNode* head = new TrieNode();
    for(int i=0; i<n; i++){
        cin >> arr[i];
        insert(head, arr[i]);
    }

    cout << findMaxXorSubarray(head, arr, n) << endl;

    return 0;
}