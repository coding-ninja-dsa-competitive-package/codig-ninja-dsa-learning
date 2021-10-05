#include<bits/stdc++.h>

using namespace std;

/**
 *  Monk and the Islands    
 *  -   Monk visits the land of Islands. There are a total of N islands     
 *      numbered from 1 to N. Some pairs of islands are connected to each 
 *      other by Bidirectional bridges running over water.
 *  -   Monk hates to cross these bridges as they require a lot of efforts. 
 *      He is standing at Island #1 and wants to reach the Island #N. Find 
 *      the minimum the number of bridges that he shall have to cross, if he 
 *      takes the optimal route.
 *  
 *  Input:
 *      First line contains T. T testcases follow.
 *      First line of each test case contains two space-separated integers N, M.
 *      Each of the next M lines contains two space-separated integers X and Y , 
 *      denoting that there is a bridge between Island X and Island Y.
 *  Output:
 *      Print the answer to each test case in a new line.
 *  
 *  Constraints:
 *      1 ≤ T ≤ 10
 *      1 ≤ N ≤ 10000
 *      1 ≤ M ≤ 100000
 *      1 ≤ X, Y ≤ N
 *  
 *  SAMPLE INPUT
 *      2
 *      3 2
 *      1 2
 *      2 3 
 *      4 4
 *      1 2
 *      2 3 
 *      3 4
 *      4 2
 *  SAMPLE OUTPUT
 *      2
 *      2
 */
int numOfBridges(vector<vector<int> >& edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    int *level = new int[n+1]();

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int currVertex = q.front();
        q.pop();
        for(int i=0; i<edges[currVertex].size(); i++){
            int nextVertex = edges[currVertex][i];
            if(!visited[nextVertex]){
                q.push(nextVertex);
                visited[nextVertex] = true;
                level[nextVertex] = level[currVertex]+1;
            }
        }
    }
    return level[n-1];
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        vector<vector<int> > edges(n);
        for(int i=0; i<e; i++){
            int x, y;
            cin >> x >> y;
            edges[x-1].push_back(y-1);
            edges[y-1].push_back(x-1);
        }

        cout << numOfBridges(edges, n) << endl;
    }

    return 0;
}