#include<bits/stdc++.h>

using namespace std;

/**
 *  Murder
 *  -   Once detective Saikat was solving a murder case. While going to the 
 *      crime scene he took the stairs and saw that a number is written on 
 *      every stair. He found it suspicious and decides to remember all the 
 *      numbers that he has seen till now. While remembering the numbers he 
 *      found that he can find some pattern in those numbers. So he decides 
 *      that for each number on the stairs he will note down the sum of all 
 *      the numbers previously seen on the stairs which are smaller than the 
 *      present number. Calculate the sum of all the numbers written on his 
 *      notes diary.
 *  -   Answer may not fit in integer . You have to take long.
 * 
 *  Input
 *      First line gives T, number of test cases.
 *      2T lines follow.
 *      First line gives you the number of stairs N
 *      Next line gives you N numbers written on the stairs.
 *  Output
 *      For each test case output one line giving the final sum for each test case.
 *  
 *  Constraints
 *      T<=10
 *      1<=N<=10^5
 *      All numbers will be between 0 and 10^6.
 *  
 *  Sample Input:
 *      1
 *      5
 *      1 5 3 6 4
 *  Sample Output:
 *      15
 *  Explanation:
 *      For the first number, the contribution to the sum is 0.
 *      For the second number, the contribution to the sum is 1.
 *      For the third number, the contribution to the sum is 1.
 *      For the fourth number, the contribution to the sum is 9 (1+5+3).
 *      For the fifth number, the contribution to the sum is 4 (1+3).
 *      Hence the sum is 15 (0+1+1+9+4).
 */

typedef long long ll;

ll merge(int arr[], int start, int end, int mid){
    ll count = 0;
    int temp[end-start+1];
    int is=start, ie=mid, js=mid+1, je=end, k=0;
    while(is <= ie && js <= je){
        if(arr[is] < arr[js]){
            count += (end-js+1)*arr[is];
            temp[k++] = arr[is++];
        } else{
            temp[k++] = arr[js++];
        }
    }
    while(is <= ie){
        temp[k++] = arr[is++];
    }
    while(js <= je){
        temp[k++] = arr[js++];
    }
    for(int i=start, k=0; i<=end; i++, k++){
        arr[i] = temp[k];
    }
    return count;
}

ll mergeSort(int arr[] , int start, int end){
    ll count = 0;
    if(start >= end){
        return count;
    }
    int mid = start + (end-start)/2;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid+1, end);
    count += merge(arr, start, end , mid);
    return count;
}

int main() {
	int t;
    cin >> t;
    while(t--){
        int n;
        int arr[n];
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        ll count = mergeSort(arr, 0, n-1);
        cout << count << endl;
    }
}