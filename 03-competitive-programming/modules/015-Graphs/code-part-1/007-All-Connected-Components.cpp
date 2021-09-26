#include<bits/stdc++.h>

using namespace std;

/**
 *  Code : All connected components
 *  -   Given an undirected graph G(V,E), find and print all the connected 
 *      components of the given graph G.
 *  Note:
 *  1.  V is the number of vertices present in graph G and vertices are numbered 
 *      from 0 to V-1. 
 *  2.  E is the number of edges present in graph G.
 *  3.  You need to take input in main and create a function which should 
 *      return all the connected components. And then print them in the main, 
 *      not inside function.
 *  Print different components in new line. And each component should be printed 
 *  in increasing order (separated by space). Order of different components 
 *  doesn't matter.
 * 
 *  Input Format :
 *      The first line of input contains two integers, that denote the value 
 *      of V and E. Each of the following E lines contains two space separated 
 *      integers, that denote that there exists an edge between vertex a and b.
 *  Output Format :
 *      Print different components in new line. And each component should be 
 *      printed in increasing order of vertices (separated by space). Order of 
 *      different components doesn't matter.
 *  
 *  Constraints :
 *      0 <= V <= 1000
 *      0 <= E <= (V * (V - 1)) / 2
 *      0 <= a <= V - 1
 *      0 <= b <= V - 1
 *  
 *  Sample Input 1:
 *      4 2
 *      0 1
 *      2 3
 *  Sample Output 1:
 *      0 1 
 *      2 3 
 *  
 *  Sample Input 2:
 *      4 3
 *      0 1
 *      1 3     
 *      0 3
 *  Sample Output 2:
 *      0 1 3 
 *      2
 */
void getComponent(vector<vector<int> >& edges, int n, int start, vector<bool>& visited, vector<int>& res){
    for(int i=0; i<n; i++){
        if(i != start && !visited[i] && edges[start][i] == 1){
            visited[i] = true;
            res.push_back(i);
            getComponent(edges, n, i, visited, res);
        }
    }
}

void allConnectedComponents(vector<vector<int> >& edges, int n, vector<bool>& visited){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> res; 
            res.push_back(i);
    		visited[i] = true;
            getComponent(edges, n, i, visited, res);
            sort(res.begin(), res.end());
            for(int i=0; i<res.size(); i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
	int n, e;
    cin >> n >> e;
    vector<vector<int> > edges(n, vector<int>(n));
    for(int i=0; i<e; i++){
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = edges[ev][sv] = 1;
    }
    
    vector<bool> visited(n);
    allConnectedComponents(edges, n, visited);
}