#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

/**
 *  Code : Print Intersection
 *  -   You have been given two integer arrays/lists (ARR1 and ARR2) of size 
 *      N and M, respectively. You need to print their intersection; An intersection 
 *      for this problem can be defined when both the arrays/lists contain a 
 *      particular value or to put it in other words, when there is a common value 
 *      that exists in both the arrays/lists.
 *  Note:
 *  -   Input arrays/lists can contain duplicate elements.
 *  -   The intersection elements printed would be in the order they appear in the 
 *      first sorted array/list (ARR1).
 * 
 *  Input format :
 *      The first line of input contains an integer 'N' representing the size 
 *      of the first array/list.
 *      The second line contains 'N' single space separated integers representing 
 *      the elements of the first the array/list.
 *      The third line contains an integer 'M' representing the size of the 
 *      second array/list.
 *      The fourth line contains 'M' single space separated integers representing 
 *      the elements of the second array/list.
 *  Output format :
 *      Print the intersection elements. Each element is printed in a separate line.
 * 
 *  Constraints :
 *      0 <= N <= 10^6
 *      0 <= M <= 10^6
 * 
 *  Time Limit: 1 sec 
 *  Sample Input 1 :
 *      6
 *      2 6 8 5 4 3
 *      4
 *      2 3 4 7 
 *  Sample Output 1 :    
 *      2   
 *      3 
 *      4
 *  
 *  Sample Input 2 :
 *      4
 *      2 6 1 2
 *      5
 *      1 2 3 4 2
 *  Sample Output 2 :
 *      1 
 *      2 
 *      2
 */
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        if(mp.count(arr2[i]) > 0 && mp[arr2[i]] > 0){
            cout << arr2[i] << endl;
            mp[arr2[i]]--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int* arr1 = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int* arr2 = new int[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    printIntersection(arr1, arr2, n, m);
    delete[] arr1;
    delete[] arr2;

    return 0;
}