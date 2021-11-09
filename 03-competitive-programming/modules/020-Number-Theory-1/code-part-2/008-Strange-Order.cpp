#include<bits/stdc++.h>

using namespace std;

/**
 *  Strange order
 *  -   Given an integer n . Initially you have permutation p of size n : p[i] = i. 
 *      To build new array a from p following steps are done while permutation p is 
 *      not empty:
 *  -   Choose maximum existing element in p and define it as x ; Choose all such y 
 *      in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing 
 *      order and remove them from permutation. Your task is to find a after p became 
 *      empty.
 *  -   Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
 * 
 *  Input format
 *      Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation 
 *      p p.
 *  Output format
 *      Print n integers — array a .
 *  
 *  Sample Input:
 *      5
 *  Sample Output:
 *      5 4 2 3 1
 *  Explanation
 *      It's needed 4 iterations to create array a:
 *      Add 5
 *      Add 4 and 2
 *      Add 3
 *      Add 1
 */

#define MAX 2000001

int* makeSieve(){
    int* sieve = new int[SIZE];
    for (int i = 0; i <= SIZE; i++){
        sieve[i] = i;
    }
    for (int i=2; i*i<=SIZE; i++){
        for (int j=i*i; j<=SIZE; j+=i){
            if (sieve[j] > i){
                sieve[j] = i;
            }
        }
    }
    return sieve;
}

int main(){
    int* sieve = makeSieve();
    int n, k=0;
    cin >> n;
    int* res = new int[n];
    bool* visited = new bool[n+1];
    for (int i=0; i<=n; i++){
        visited[i] = false;
    }
    for (int i=n; i>=1; i--){
        if (!visited[i]){
            int lowestPrimeDivisor = sieve[i];
            int x=i;
            vector<int> v;
            visited[i] = true;
            v.push_back(i);
            while (x != 1){
                for (int j=i-lowestPrimeDivisor; j>=1; j=j-lowestPrimeDivisor){
                    if (!visited[j]){
                        visited[j] = true;
                        v.push_back(j);
                    }
                }
                while (x%lowestPrimeDivisor == 0){
                    x = x/lowestPrimeDivisor;
                }
                lowestPrimeDivisor = sieve[x];
            }
            sort(v.begin(), v.end(), greater<int>());
            for (int i=0; i<v.size(); i++){
                res[k] = v[i];
                k++;
            }
        }
    }
    res[n-1] = 1;
    for (int i=0; i<n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}