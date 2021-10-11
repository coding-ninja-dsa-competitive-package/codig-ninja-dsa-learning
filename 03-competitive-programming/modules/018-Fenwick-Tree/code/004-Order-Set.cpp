#include<bits/stdc++.h>

using namespace std;

/**
 *  OrderSet - Problem  
 *  -   In this problem, you have to maintain a dynamic set of numbers which support 
 *      the two fundamental operations
 *  -   INSERT(S,x): if x is not in S, insert x into S
 *      DELETE(S,x): if x is in S, delete x from S and the two type of queries
 *      K-TH(S) : return the k-th smallest element of S
 *      COUNT(S,x): return the number of elements of S smaller than x
 *  
 *  Input Format
 *      Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
 *      In the next Q lines, the first token of each line is a character I, D, K or 
 *      C meaning that the corresponding operation is INSERT, DELETE, K-TH or COUNT, 
 *      respectively, following by a whitespace and an integer which is the parameter 
 *      for that operation.
 *      If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. If the 
 *      parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
 *  Output  
 *      For each query, print the corresponding result in a single line. In particular, 
 *      for the queries K-TH, if k is larger than the number of elements in S, print 
 *      the word 'invalid'.
 *  
 *  Input Format
 *      8
 *      I -1
 *      I -1
 *      I 2
 *      C 0
 *      K 2
 *      D -1    
 *      K 1
 *      K 2
 *  Output Format
 *      1
 *      2
 *      2   
 *      invalid
 */

#define MAX 200005

pair<int, int> M[MAX], T[MAX];
int binaryIndexTree[MAX], arr[MAX], n;
char oper[MAX];
bool flag;

int query(int idx){
    int sum = 0;
    for (;idx > 0; idx -= idx & (-idx)){
        sum += binaryIndexTree[idx];
    }
    return sum;
}

void update(int idx, int val){
    for (;idx < MAX; idx += idx & (-idx)){
        binaryIndexTree[idx] += val;
    }
}

int binarySearch(int x){
    int start=0, end=n-1, mid, ans=-1;
    while (start <= end){
        mid = (start + end)/2;
        if (M[mid].first == x){
            flag = 1;
            return mid;
        } else if (M[mid].first > x) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    flag = 0;
    return ans;
}

int main(){
    int numQueries, idx, k = 0, start, end, mid;
    cin>>numQueries;
    for (int i = 0; i < numQueries; i++){
        oper[i] = getchar();
        while (oper[i] < 65 || oper[i] >= 91) {
            oper[i] = getchar();
        }
        cin>>arr[i];
        if (oper[i] == 'I'){
            T[k].first = arr[i];
            T[k++].second = 0;
        }
    }
    sort(T, T + k);

    M[0] = T[0];
    n = 1;
    for (int i = 1; i < k; i++){
        if (T[i].first != T[i - 1].first){
            M[n++] = T[i];
        }
    }
    for (int i = 0; i < numQueries; i++){
        if (oper[i] == 'I'){
            idx = binarySearch(arr[i]);
            if (M[idx].second == 0){
                M[idx].second = 1;
                update(idx + 1, 1);
            }
        } else if (oper[i] == 'D'){
            idx = binarySearch(arr[i]);
            if (idx != -1 && M[idx].second == 1 && flag){
                update(idx + 1, -1);
                M[idx].second = 0;
            }
        } else if (oper[i] == 'C') {
            idx = binarySearch(arr[i]);
            if (flag) {
                printf("%d\n", query(idx + 1 - 1));
            } else if (idx != -1) {
                printf("%d\n", query(idx + 1));
            } else {
                printf("0\n");
            }
        } else if (oper[i] == 'K') {
            k = arr[i];
            idx = -1;
            bool isValid = 0;
            start = 1;
            end = MAX - 1;
            while (start <= end) {
                mid = (start + end)/2;
                if (query(mid) == k && query(mid - 1) != k) {
                    isValid = 1;
                    idx = mid;
                    break;
                } else if (query(mid) < k) {
                    idx = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            if (!isValid) {
                cout << "invalid" << endl;
            } else {
                printf("%d\n", M[idx - 1].first);
            }
        }
    }
    return 0;
}