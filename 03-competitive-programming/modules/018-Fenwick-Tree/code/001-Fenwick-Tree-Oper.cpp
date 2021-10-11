#include<bits/stdc++.h>

using namespace std;

/**
 *  Fenwick Tree
 *  -   Let, f be some reversible function and A be an array of integers of length N.
 *  -   Fenwick tree is a data structure which:
 *      -   calculates the value of function f in the given range [l,r] (i.e. 
 *          f(Al,Al+1,…,Ar)) in O(logn) time;
 *      -   updates the value of an element of A in O(logn) time;
 *      -   requires O(N) memory, or in other words, exactly the same memory 
 *          required for A;
 *      -   is easy to use and code, especially, in the case of multidimensional arrays.
 *  -   Fenwick tree is also called Binary Indexed Tree, or just BIT abbreviated.
 *  -   The most common application of Fenwick tree is calculating the sum of a 
 *      range (i.e. f(A1,A2,…,Ak)=A1+A2+⋯+Ak)
 *  -   Fenwick tree was first described in a paper titled "A new data structure 
 *      for cumulative frequency tables" (Peter M. Fenwick, 1994).
 */

void update(int index, int value, int* binaryIndexTree, int n){
    for(; index <= n ; index += index&(-index)){
        binaryIndexTree[index] += value;
    }
}

int query(int index, int* binaryIndexTree){
    int sum = 0;
    for(; index > 0; index -= index&(-index)){
        sum += binaryIndexTree[index];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];
    int* binaryIndexTree = new int[n+1];

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        update(i, arr[i], binaryIndexTree, n);
    }

    cout << "Sum of first 5 elements " << query(5, binaryIndexTree) << endl;
    cout << "Sum of elements from 2 index to 6 index " << query(6, binaryIndexTree) - query(1, binaryIndexTree) << endl;

    return 0;
}