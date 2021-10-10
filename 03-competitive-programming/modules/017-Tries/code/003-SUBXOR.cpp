#include<bits/stdc++.h>

using namespace std;

/**
 *  SUBXOR
 *  -   A straightforward question. Given an array of positive integers you have 
 *      to print the number of subarrays whose XOR is less than K. Subarrays are 
 *      defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of 
 *      a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
 *  
 *  Input Format
 *      First line contains T, the number of test cases. 
 *      Each of the test case consists of N and K in one line, followed by N space 
 *      separated integers in next line.
 *  Output Format
 *      For each test case, print the required answer.
 *  Constraints:
 *      1 ≤ T ≤ 5
 *      1 ≤ N ≤ 10^5
 *      1 ≤ A[i] ≤ 10^5
 *      1 ≤ K ≤ 10^6
 *  
 *  Sample Input
 *      1
 *      5 2
 *      4 1 3 2 7   
 *  Sample Output
 *      3
 */
typedef long long int ll;

class TrieNode{
    public:
        TrieNode *left=NULL;
        TrieNode *right=NULL;
        ll leftCount=0;
    	ll rightCount=0;
};

void insert(ll num,TrieNode *head){
    TrieNode *curr=head;
    for(int i=31; i>=0; i--){
        int bit=(num >> i) & 1;
        if(bit==1){
            curr->rightCount++;
            if(!curr->right){
                curr->right=new TrieNode();
            }
            curr=curr->right;
        }else{
            curr->leftCount++;
            if(!curr->left){
                curr->left=new TrieNode();
            }
            curr=curr->left;
        }
    }
}

ll numSubArrayXorLessThanK(ll *arr,int n,int k){
    ll countSubArrayLessThanK = 0;
    ll xorTillNow = 0;
    TrieNode *head=new TrieNode();
    insert(0,head);

    for(int i=0; i<n; i++){
        xorTillNow = xorTillNow^arr[i];
        TrieNode *curr = head;
        if(!curr){
            return 0;
        }
        for(int j=31;j>=0;j--){
            int bitX = (xorTillNow >> j) & 1;
            int bitK = (k >> j) & 1;
            if(bitX==1 & bitK==1){
                countSubArrayLessThanK += curr->rightCount;
                if(curr->left){
                    curr = curr->left;
                }else{
                    break;
                }
            }else if(bitX==0 & bitK==1){
                countSubArrayLessThanK += curr->leftCount;
                if(curr->right){
                    curr = curr->right;
                }else{
                    break;
                }
            }else if(bitX==0 & bitK==0){
                if(curr->left){
                    curr = curr->left;
                }else{
                    break;
                }
            }else if(bitX==1 & bitK==0){
                if(curr->right){
                    curr = curr->right;
                }else{
                    break;
                }
            }
        }
        insert(xorTillNow, head);
    }
    return countSubArrayLessThanK;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ll *arr=new ll[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout << numSubArrayXorLessThanK(arr, n, k) << endl;
    }
    return 0;
}