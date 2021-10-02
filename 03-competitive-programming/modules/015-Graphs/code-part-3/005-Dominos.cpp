#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

/**
 *  Dominos
 *  -   Dominos are lots of fun. Children like to stand the tiles on their side 
 *      in long lines. When one domino falls, it knocks down the next one, which 
 *      knocks down the one after that, all the way down the line.
 *  -   However, sometimes a domino fails to knock the next one down. In that case, 
 *      we have to knock it down by hand to get the dominos falling again.
 *  -   Your task is to determine, given the layout of some domino tiles, the 
 *      minimum number of dominos that must be knocked down by hand in order for 
 *      all of the dominos to fall.
 *  
 *  Input
 *      The first line of input contains one integer specifying the number of 
 *      test cases to follow.Each test case begins with a line containing two 
 *      integers,each no larger than 100 000. The first integer n is the number 
 *      of domino tiles and the second integer m is the number of lines to follow 
 *      in the test case. The domino tiles are numbered from 1 to n.    
 * 
 *      Each of the following lines contains two integers x and y indicating that 
 *      if domino number x falls, it will cause domino number y to fall as well.
 *  Output
 *      For each test case, output a line containing one integer, the minimum number 
 *      of dominos that must be knocked over by hand in order for all the dominos to 
 *      fall.
 *  
 *  Sample Input
 *      1
 *      3 2 
 *      1 2
 *      2 3
 *  Sample Output
 *      1
 */
vector<int> graph[100001];

void dfs(int start, stack<int>& finishedStack, bool* visited){
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++){
        int adj = graph[start][i];
        if(!visited[adj]) {
            dfs(adj,finishedStack,visited);
        }
    }
    finishedStack.push(start);
}

void dfsRev(int start, unordered_set<int>& visitedSet){
    visitedSet.insert(start);
    for(int i = 0; i < graph[start].size(); i++){
        int adj = graph[start][i];
        if(visitedSet.count(adj) == 0){
            dfsRev(adj,visitedSet);
        }
    }
}

void getSCC(int n){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    stack<int> finishedStack;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i,finishedStack,visited);
        }
    }

    unordered_set<int> visitedSet;
    int count = 0;
    while(!finishedStack.empty()){
        int t = finishedStack.top();
        finishedStack.pop();

        if(visitedSet.count(t) == 0){
            dfsRev(t, visitedSet);
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            graph[i].clear();
        }
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
        }
        getSCC(n);
    }

    return 0;
}