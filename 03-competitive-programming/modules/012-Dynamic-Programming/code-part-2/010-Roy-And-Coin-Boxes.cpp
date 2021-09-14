#include<bits/stdc++.h>

using namespace std;

/**
 *  Roy and Coin Boxes
 *  -   Roy has N coin boxes numbered from 1 to N.
 *  -   Every day he selects two indices [L,R] and adds 1 coin to each coin box 
 *      starting from L to R (both inclusive).
 *  -   He does this for M number of days.
 *  -   After M days, Roy has a query: How many coin boxes have at least X coins.
 *  -   He has Q such queries.
 *  
 *  Input
 *      First line contains N - number of coin boxes.
 *      Second line contains M - number of days. Each of the next M lines consists 
 *      of two space separated integers L and R. Followed by integer Q - number of queries.
 *      Each of next Q lines contain a single integer X.a
 *  Output
 *      For each query output the result in a new line. 
 * 
 *  Constraints
 *      1 ≤ N ≤ 1000000
 *      1 ≤ M ≤ 1000000
 *      1 ≤ L ≤ R ≤ N
 *      1 ≤ Q ≤ 1000000
 *      1 ≤ X ≤ N
 *  
 *  Sample Input
 *      7
 *      4
 *      1 3
 *      2 5
 *      1 2
 *      5 6 
 *      4
 *      1
 *      7
 *      4
 *      2
 *  Sample Output
 *      6
 *      0
 *      0
 *      4
 */ 

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int numCoinBoxes;
    cin >> numCoinBoxes;
    
    int numDays;
    cin >> numDays;
    
    int size = 1000001;
    int *kStart = new int[size]();
    int *kEnd = new int[size]();
    while(numDays--){
        int start, end;
        cin >> start >> end;
        kStart[start]++;
        kEnd[end]++;
    }
    
    int *coinArr = new int[size];
    coinArr[0] = 0;
    coinArr[1] = kStart[1];
    for(int i=2; i<size; i++){
        coinArr[i] = kStart[i] - kEnd[i-1] + coinArr[i-1];
    }
    
    int *coinEqualArr = new int[size]();
    for(int i=0; i<size; i++){
        coinEqualArr[coinArr[i]]++;
    }
    
    int *coinAtleastArr = new int[numCoinBoxes+1]();
    coinAtleastArr[numCoinBoxes] = coinEqualArr[numCoinBoxes];
    for(int i=numCoinBoxes-1; i>=0; i--){
        coinAtleastArr[i] = coinEqualArr[i] + coinAtleastArr[i+1];
    }
    
    int queries;
    cin >> queries;
    while(queries--){
        int numCoins;
        cin >> numCoins;
        cout << coinAtleastArr[numCoins] << endl;
    }
    
    delete [] kStart;
    delete [] kEnd;
    delete [] coinArr;
    delete [] coinEqualArr;
    delete [] coinAtleastArr;
}
