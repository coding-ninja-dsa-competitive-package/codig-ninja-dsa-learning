#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

/**
 *  Fill The Matrix
 *  -   A matrix B (consisting of integers) of dimension N × N is said to be 
 *      good if there exists an array A (consisting of integers) such that 
 *      B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.
 *  -   You are given a partially filled matrix B of dimension N × N. Q of the 
 *      entries of this matrix are filled by either 0 or 1. You have to identify 
 *      whether it is possible to fill the remaining entries of matrix B (the 
 *      entries can be filled by any integer, not necessarily by 0 or 1) such 
 *      that the resulting fully filled matrix B is good.
 *  
 *  Input
 *      The first line of the input contains an integer T denoting the number 
 *      of test cases.
 *      The first line of each test case contains two space separated integers 
 *      N, Q.
 *      Each of the next Q lines contain three space separated integers i, j, 
 *      val, which means that B[i][j] is filled with value val.
 *  Output
 *      For each test case, output "yes" or "no" (without quotes) in a single 
 *      line corresponding to the answer of the problem.
 *  Constraints
 *      1 ≤ T ≤ 10^6
 *      2 ≤ N ≤ 10^5
 *      1 ≤ Q ≤ 10^6
 *      1 ≤ i, j ≤ N
 *      0 ≤ val ≤ 1
 *      Sum of each of N, Q over all test cases doesn't exceed 106
 *  
 *  Input
 *      4       
 *      2 2 
 *      1 1 0
 *      1 2 1
 *      2 3
 *      1 1 0
 *      1 2 1   
 *      2 1 0
 *      3 2
 *      2 2 0
 *      2 3 1
 *      3 3
 *      1 2 1
 *      2 3 1
 *      1 3 1
 *  Output
 *      yes
 *      no
 *      yes
 *      no
 */

bool bipartite(vector<int>* edges, int n){
    if(n == 0){
        return true;
    }
    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);
    while(pending.size() > 0){
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current) > 0 ? 0 : 1;
        for(int i=0; i<edges[current].size(); i++){
            int neighbour = edges[current][i];
            if(sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0){
                sets[1-currentSet].insert(neighbour);
                pending.push_back(neighbour);
            } else if(sets[currentSet].count(neighbour) > 0){
                return false;
            }
        }
    }
    return true;
}

int rep(int x, int *parent){
    if (x != parent[x]){
        parent[x] = rep(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, int *parent, int *rank){
    int px = rep(x, parent);
    int py = rep(y, parent);
    if (px == py){
        return;
    }
    if (rank[px] < rank[py]){
        parent[px] = py;
    } else if (rank[py] < rank[px]){
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, q, x, y, val;
        cin >> n >> q;
        vector<int> *edges = new vector<int>[n];
        int parent[n];
        int rank[] = {0};
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        int setcnt = 0;
        int flag = 0;
        for (int i = 0; i < q; i++){
            cin >> x >> y >> val;
            x--;
            y--;
            if (x == y and val == 1){
                flag = 1;
            }
            if (val == 0){
                unite(x, y, parent, rank);
            } else {
                edges[x].push_back(y);
                edges[y].push_back(x);
            }
        }
        if (flag == 1){
            cout << "no" << endl;
            continue;
        }
        vector<int> *nedges = new vector<int>[n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < edges[i].size(); j++){
                int curr = edges[i][j];
                int p1 = rep(i, parent);
                int p2 = rep(curr, parent);
                if (p1 == p2){
                    flag = 1;
                    break;
                } else {
                    nedges[p1].push_back(p2);
                    nedges[p2].push_back(p1);
                }
            }
            if (flag == 1){
                break;
            }
        }
        if (flag == 1){
            cout << "no" << endl;
            continue;
        }
        bipartite(nedges, n) ? cout << "yes" << endl : cout << "no" << endl;

        delete[] edges;
        delete[] nedges;
    }
    return 0;
}